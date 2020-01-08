<?php

if(strtolower(PHP_OS_FAMILY) === "windows") {
	// define("GTK_LIB_PATH", "C:\\php7.4\\bin\\gtk-3.dll");
	define("GTK_LIB_PATH", "C:\\php7.4\\libgtk-3-0.dll");
	define("GOBJECT_LIB_PATH", "C:\\php7.4\\libgobject-2.0-0.dll");

}
elseif(strtolower(PHP_OS_FAMILY) === "linux") {
	define("GTK_LIB_PATH", "/usr/lib/x86_64-linux-gnu/libgtk-3.so.0");
	define("GOBJECT_LIB_PATH", "/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0");
}

putenv("GTK_CSD=0");
putenv("GTK_DEBUG=0");
putenv("GDK_DEBUG=0");
putenv("GTK_EXE_PREFIX=C:\\php7.4\\lib");

$glib = FFI::cdef("

	typedef void *GCallback(void);

	// Types
	typedef const void *gconstpointer;
	typedef unsigned int guint;
	typedef unsigned long gulong;
	typedef void* gpointer;
	typedef char gchar;
	typedef bool gboolean;
	typedef gulong GType;
	
	typedef struct _GTypeClass GTypeClass;
	typedef struct _GObject GObject;
	typedef struct _GTypeInstance GTypeInstance;
	typedef struct _GTypeClass GTypeClass;

	struct _GTypeClass
	{
		GType g_type;
	};
	struct _GTypeInstance
	{
		GTypeClass *g_class;
	};
	struct  _GObject
	{
	  GTypeInstance  g_type_instance;
	  guint ref_count;
	  // GData *qdata;
	};

	typedef enum {
		G_SIGNAL_RUN_FIRST = 1 << 0,
		G_SIGNAL_RUN_LAST = 1 << 1,
		G_SIGNAL_RUN_CLEANUP = 1 << 2,
		G_SIGNAL_NO_RECURSE = 1 << 3,
		G_SIGNAL_DETAILED = 1 << 4,
		G_SIGNAL_ACTION = 1 << 5,
		G_SIGNAL_NO_HOOKS = 1 << 6,
		G_SIGNAL_MUST_COLLECT = 1 << 7,
		G_SIGNAL_DEPRECATED   = 1 << 8
	} GSignalFlags;

	typedef struct
	{
		guint		signal_id;
		const gchar  *signal_name;
		GType		itype;
		GSignalFlags signal_flags;
		GType		return_type; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
		guint		n_params;
		const GType  *param_types; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
	} GSignalQuery;

	typedef struct {
		guint in_marshal;
		guint is_invalid;
	} GClosure;

	// Defs
	typedef enum
	{
		G_CONNECT_AFTER	= 1 << 0,
		G_CONNECT_SWAPPED	= 1 << 1
	} GConnectFlags;

	// 
	const gchar *g_type_name (GType type);
	GType g_type_fundamental (GType type_id);

	// Methods
	typedef void *GClosureNotify (gpointer data, GClosure *closure);
	guint g_signal_lookup (const gchar *name, GType itype);
	void g_signal_query (guint signal_id, GSignalQuery *query);
	GClosure *g_cclosure_new_swap (GCallback callback_func, gpointer user_data, GClosureNotify destroy_data);
	gulong g_signal_connect_closure (gpointer instance, const gchar *detailed_signal, GClosure *closure, gboolean after);

", GOBJECT_LIB_PATH);


$gtk = FFI::cdef("

	typedef void* gpointer;
	typedef unsigned int guint;

	// Types
	typedef enum
	{
		GTK_WINDOW_TOPLEVEL,
		GTK_WINDOW_POPUP
	} GtkWindowType;

	// Defs
	typedef struct _GtkWidget GtkWidget;
	typedef struct _GtkContainer GtkContainer;
	typedef struct _GtkWindow GtkWindow;

	// Methods
		void gtk_init(int *, char **[]);
		void gtk_main();
		void gtk_main_quit();

		// Widget
		void gtk_widget_show_all (GtkWidget *);

		// Container
		void gtk_container_add (GtkContainer *container, GtkWidget *widget);

		// Windows
		gpointer * gtk_window_new (GtkWindowType type);

		guint gtk_get_major_version (void);
		guint gtk_get_minor_version (void);
		guint gtk_get_micro_version (void);

", GTK_LIB_PATH);

// Return GType from Object
function G_OBJECT_TYPE($a)
{
	global $glib;

	echo "OK1.1\n";
	$g_class = $glib->cast("GTypeInstance *", $a)->g_class;
	var_dump($g_class);
	echo "OK1.2\n";
	$g_type = $g_class->g_type;
	var_dump($g_type);
	echo "OK1.3\n";
	$fundamental = $glib->g_type_fundamental($g_type);
	var_dump($fundamental);
	echo "OK1.4\n";

	var_dump($glib->g_type_name($g_type));
	echo "OK1.5\n";

	return $g_type;
}

// Working
$argc = FFI::new('int');
$argv = FFI::new('char[0]');
$pargv = FFI::addr($argv);
$gtk->gtk_init(FFI::addr($argc), FFI::addr($pargv));

// Version
echo "GTK: " . $gtk->gtk_get_major_version() . "." . $gtk->gtk_get_minor_version() . "." . $gtk->gtk_get_micro_version() . "\n";

	// Window
	$window = $gtk->gtk_window_new(0);
	$gtk->gtk_widget_show_all($gtk->cast("GtkWidget *", $window));

	// Connect
	$signal_name = "destroy";
	echo "OK1\n";
	$type = G_OBJECT_TYPE($glib->cast("gpointer", $window));
	echo "OK1.0\n";
	$lookup = $glib->g_signal_lookup ($signal_name, $type);
	echo "OK2\n";
	$signal_info = \FFI::addr($glib->new("GSignalQuery"));
	echo "OK3\n";
	$glib->g_signal_query($lookup, $signal_info);
	echo "OK4\n";
	$closure = $glib->g_cclosure_new_swap(function() use ($gtk, $glib) {

		var_dump("OK");

	}, NULL, NULL);
	$glib->g_signal_connect_closure($glib->cast("gpointer", $window), $signal_name, $closure, TRUE);

// Loop
$gtk->gtk_main();