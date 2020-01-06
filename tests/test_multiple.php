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
		$ffi = FFI::cdef("
			typedef void* gpointer;
			typedef char   gchar;
			typedef bool   gboolean;
			typedef unsigned long   gulong;
			typedef unsigned int   guint;
			typedef signed char gint8;
			typedef unsigned int guint32;
			typedef double  gdouble;
		",
		"/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0");

		$this->ffi = $ffi->cdef("

			typedef struct _GtkWidget GtkWidget;
			typedef struct _GtkButton GtkButton;
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


			

			GtkWidget *gtk_button_new_with_label (const gchar *label);
			void gtk_button_set_label (GtkButton *button, const gchar *label);

			void gtk_container_add (GtkContainer *container, GtkWidget *widget);



		", "/usr/lib/x86_64-linux-gnu/libgtk-3.so.0");

		$this->instance = $this->ffi->gtk_window_new(0);

		$this->button = $this->ffi->gtk_button_new_with_label("BUTTON");
		$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $this->button));



		


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
","/usr/lib/x86_64-linux-gnu/libgtk-3.so.0");

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