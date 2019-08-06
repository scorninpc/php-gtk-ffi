<?php

/**
 *
 */
class GtkWindow
{
	public function __construct($tipo=1)
	{
		$this->ffi = FFI::cdef("

			typedef struct _GtkWidget GtkWidget;
			typedef struct _GtkWindow GtkWindow;
			typedef struct _GtkContainer GtkContainer;

			typedef enum
			{
			  GTK_WINDOW_TOPLEVEL,
			  GTK_WINDOW_POPUP
			} GtkWindowType;

			GtkWidget *gtk_window_new(GtkWindowType);
			void gtk_widget_show_all(GtkWidget *);
			void gtk_window_set_title(GtkWindow *, char *);


			typedef void* gpointer;
			typedef void  (*GCallback)              (void);
			typedef char   gchar;
			typedef unsigned long   gulong;
			typedef unsigned int   guint;
			typedef enum
			{
			  G_CONNECT_AFTER	= 1 << 0,
			  G_CONNECT_SWAPPED	= 1 << 1
			} GConnectFlags;

			typedef struct {
				guint in_marshal;
				guint is_invalid;
			} GClosure;
			typedef void (*GClosureNotify) (gpointer data, GClosure *closure);

			gulong g_signal_connect_object (gpointer instance, gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);
			gulong g_signal_connect_data (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer data, GClosureNotify destroy_data, GConnectFlags connect_flags);


			GtkWidget *gtk_button_new_with_label (const gchar *label);

			void gtk_container_add (GtkContainer *container, GtkWidget *widget);


		", "libgtk-3.so");

		// $a = FFI::cdef("

		// 	typedef void* gpointer;

		// 	typedef void  (*GCallback)              (void);

		// 	void g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags););

		// ", "libglib-2.0.so.0");

		$this->instance = $this->ffi->gtk_window_new(0);

		$this->ffi->g_signal_connect_object($this->ffi->cast("gpointer *", $this->instance), "destroy", function($a=NULL) { 
			global $ffi; 
			
			echo "\n----\ndestroy\n----\n";
			var_dump($a); 
			
			$ffi->gtk_main_quit();

		}, NULL, 1);

		$parameter1 = FFI::new("char *", "Parameter 1");

		$this->button = $this->ffi->gtk_button_new_with_label("BUTTON");
		$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $this->button));

		$this->ffi->g_signal_connect_object($this->ffi->cast("gpointer *", $this->button), "clicked", function($a=NULL, $b=NULL) {
			
			echo "\n----\nclicked\n----\n";
			var_dump($a);
			var_dump($b);

		}, $parameter1, 1);
		// $this->ffi->g_signal_connect_data($this->ffi->cast("gpointer *", $this->button), "button-release-event", function($a=NULL) { echo "\n----\button-release-event\n----\n"; var_dump($a); }, NULL, NULL, 2);


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