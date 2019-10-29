<?php

/**

Types:
	- https://developer.gnome.org/glib/stable/glib-Basic-Types.html

**/

/**
 *
 */
class GtkWindow
{
	public function __construct($tipo=1)
	{
		$this->ffi = FFI::cdef("

			typedef struct _GtkWidget GtkWidget;
			typedef struct _GtkButton GtkButton;
			typedef struct _GtkWindow GtkWindow;
			typedef struct _GtkContainer GtkContainer;
			typedef struct _GdkEvent GdkEvent;
			typedef struct _GdkWindow GdkWindow;
			typedef struct _GdkDevice GdkDevice;
			typedef struct _GList GList;
			typedef struct _GSList GSList;

			typedef enum
			{
			  GDK_NOTHING,
			  GDK_BUTTON_PRESS,
			  GDK_2BUTTON_PRESS,
			  GDK_DOUBLE_BUTTON_PRESS,
			  GDK_3BUTTON_PRESS,
			  GDK_TRIPLE_BUTTON_PRESS,
			  GDK_BUTTON_RELEASE
			} GdkEventType;

			

			typedef enum
			{
			  GTK_WINDOW_TOPLEVEL,
			  GTK_WINDOW_POPUP
			} GtkWindowType;

			GtkWidget *gtk_window_new(GtkWindowType);
			void gtk_widget_show_all(GtkWidget *);
			void gtk_window_set_title(GtkWindow *, char *);


			typedef void* gpointer;
			typedef void  (*GCallback)              (gpointer *widget, GdkEvent *data);
			typedef char   gchar;
			typedef bool   gboolean;
			typedef unsigned long   gulong;
			typedef unsigned int   guint;
			typedef signed char gint8;
			typedef unsigned int guint32;
			typedef double  gdouble;
			typedef enum
			{
			  G_CONNECT_AFTER	= 1 << 0,
			  G_CONNECT_SWAPPED	= 1 << 1
			} GConnectFlags;

			struct GdkEventButton {
				GdkEventType type;
				GdkWindow *window;
				gint8 send_event;
				guint32 time;
				gdouble x;
				gdouble y;
				gdouble *axes;
				guint state;
				guint button;
				GdkDevice *device;
				gdouble x_root, y_root;
			};

			typedef struct {
				guint in_marshal;
				guint is_invalid;
			} GClosure;
			typedef void (*GClosureNotify) (gpointer data, GClosure *closure);

			gulong g_signal_connect_object (gpointer instance, gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);
			gulong g_signal_connect_data (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer data, GClosureNotify destroy_data, GConnectFlags connect_flags);


			GtkWidget *gtk_button_new_with_label (const gchar *label);
			void gtk_button_set_label (GtkButton *button, const gchar *label);

			void gtk_container_add (GtkContainer *container, GtkWidget *widget);








			/* NEW WAY TO CONNECT */



			typedef gulong GType;


			/* http://soc.if.usp.br/manual/libglib2.0-doc/gobject/gobject-Signals.html#GSignalFlags */
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

			void g_signal_query (guint signal_id, GSignalQuery *query);




			guint g_signal_lookup (const gchar *name, GType itype);



			struct st_callback
			{
				guint signal_id;
				const gchar signal_name[10];
				GType itype;
				GSignalFlags signal_flags;
				GType return_type;
				guint n_params;
				const GType *param_types;
			};



			/* http://refspecs.linuxbase.org/LSB_3.1.0/LSB-Desktop-generic/LSB-Desktop-generic/libgobject-2.0-ddefs.html */
			
			typedef struct _GTypeClass {
			    GType g_type;
			} GTypeClass;

			typedef struct _GTypeInstance {
			    GTypeClass *g_class;
			} GTypeInstance;

			/* OK FOR HERE */


			
			GClosure *g_cclosure_new_swap (GCallback callback_func, gpointer user_data, GClosureNotify destroy_data);
			gulong g_signal_connect_closure (gpointer instance, const gchar *detailed_signal, GClosure *closure, gboolean after);




		", "libgtk-3.so");


		// $a = FFI::cdef("

		// 	typedef void* gpointer;

		// 	typedef void  (*GCallback)              (void);

		// 	void g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags););

		// ", "libglib-2.0.so.0");

		$this->instance = $this->ffi->gtk_window_new(0);

		$this->ffi->g_signal_connect_object($this->ffi->cast("gpointer *", $this->instance), "destroy", function($a=NULL) { global $ffi; $ffi->gtk_main_quit(); }, NULL, 1);



		$this->button = $this->ffi->gtk_button_new_with_label("BUTTON");
		$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $this->button));

		// $this->ffi->g_signal_connect_object($this->ffi->cast("gpointer *", $this->button), "button-release-event", function($a=NULL, $b=NULL) {
			

		// 	echo "\n----\nclicked\n----\n";

		// 	$this->ffi->gtk_button_set_label($this->ffi->cast("GtkButton *", $a), "OK");

		// 	echo "\n----\ncasting\n----\n";
		// 	$c = $this->ffi->cast("GdkEventButton", $b->button);
		// 	echo "\n----\ncasted\n----\n";

		// 	var_dump($c->x);

		// }, NULL, 1);
		// $this->ffi->g_signal_connect_data($this->ffi->cast("gpointer *", $this->button), "button-release-event", function($a=NULL) { echo "\n----\button-release-event\n----\n"; var_dump($a); }, NULL, NULL, 2);

		
		// NEW CALLBACK WAY
		// $lookup = $this->ffi->g_signal_lookup ("button-release-event", $this->G_OBJECT_TYPE($this->button));
		$lookup = $this->ffi->g_signal_lookup ("clicked", $this->G_OBJECT_TYPE($this->button));

		$signal_info = FFI::addr($this->ffi->new("GSignalQuery"));

		$this->ffi->g_signal_query($lookup, $signal_info);

		$function = function($a=NULL, $GdkEvent=NULL) {
			
			// --------
			// $parameters = $this->ffi->cast("struct st_callback", FFI::addr($a)); // WRONG POINTER
			
			// --------
			// echo "\n------\n";
			// $parameters = $this->ffi->cast("struct st_callback *", $a[0]); // GOT STRUCTURE, BUT WRONG DATA
			// var_dump($parameters);

			// --------
			echo "\n------\n";
			$parameters = $this->ffi->cast("struct st_callback *", $a[0]); // GOT STRUCTURE, BUT WRONG DATA
			var_dump($parameters);
			

			// --------
			var_dump($GdkEvent); 
		};

		// NICE ABOVE HERE
		$parameters = $this->ffi->new("struct st_callback");
		FFI::memset($parameters, 0, FFI::sizeof($parameters));

		$parameters->signal_id = $signal_info->signal_id;
		FFI::memcpy($parameters->signal_name, $signal_info->signal_name, strlen($signal_info->signal_name));

		$closure = $this->ffi->g_cclosure_new_swap($function, FFI::addr($this->ffi->cast("gpointer", FFI::addr($parameters))), NULL);
		$this->ffi->g_signal_connect_closure($this->ffi->cast("gpointer *", $this->button), "clicked", $closure, TRUE);



		


	}

	public function G_OBJECT_TYPE($a)
	{
		$g_class = $this->ffi->cast("GTypeInstance *", $a)->g_class;
		$g_type = $this->ffi->cast("GTypeClass *", $g_class)->g_type;
		// $c = $this->ffi->cast("GTypeInstance *", $a);

		// var_dump($g_type);

		return $g_type;
	}

	public function show_all()
	{
		$this->ffi->gtk_widget_show_all($this->instance);
	}

	public function set_title($title="")
	{
		$this->ffi->gtk_window_set_title($this->ffi->cast("GtkWindow *", $this->instance), $title);
	}
}

/**
 */
$ffi = FFI::cdef("
	void gtk_init(int *, char **[]);
	void gtk_main();
	void gtk_main_quit();
", "/usr/lib/x86_64-linux-gnu/libgtk-3.so");

/**
 */


$argc = FFI::new('int');
$argv = FFI::new('char[0]');
$pargv = FFI::addr($argv);

$ffi->gtk_init(FFI::addr($argc), FFI::addr($pargv));


$win = new GtkWindow();
$win->set_title("FFI PHP 7.4 Test");
$win->show_all();

$ffi->gtk_main();