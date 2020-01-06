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
			typedef struct _GtkBox GtkBox;
			typedef struct _GtkButton GtkButton;
			typedef struct _GtkEntry GtkEntry;
			typedef struct _GtkWindow GtkWindow;
			typedef struct _GtkContainer GtkContainer;

			//typedef struct _GTypeInstanceError GError;
			//typedef struct _GdkPixbuf GdkPixbuf;
			//GdkPixbuf *gdk_pixbuf_new_from_file (const char *filename, GError **error);



			typedef enum
			{
			  GTK_WINDOW_TOPLEVEL,
			  GTK_WINDOW_POPUP
			} GtkWindowType;

			GtkWidget *gtk_window_new(GtkWindowType);
			void gtk_widget_show_all(GtkWidget *);
			void gtk_window_set_title(GtkWindow *, char *);


			typedef void* gpointer;
			typedef char   gchar;
			typedef bool   gboolean;
			typedef unsigned long   gulong;
			typedef unsigned int   guint;
			typedef signed char gint8;
			typedef unsigned int guint32;
			typedef double  gdouble;

			GtkEntry *gtk_entry_new ();
			GtkBox *gtk_box_new (int orientation, int spacing);
			GtkButton *gtk_button_new_with_label (const gchar *label);
			void gtk_button_set_label (GtkButton *button, const gchar *label);


			void gtk_box_pack_start(GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding);

			void gtk_container_add (GtkContainer *container, GtkWidget *widget);
			void gtk_container_set_border_width(GtkContainer *container, guint border_width);



		", ".\\gtk-3.dll");

		$this->instance = $this->ffi->gtk_window_new(0);

		$this->button = $this->ffi->gtk_button_new_with_label("BUTTON");
		$this->entry = $this->ffi->gtk_entry_new();
		$this->box = $this->ffi->gtk_box_new(1, 5);
		
		$this->ffi->gtk_box_pack_start($this->ffi->cast("GtkBox *", $this->box), $this->ffi->cast("GtkWidget *", $this->entry), true, true, 0);
		$this->ffi->gtk_box_pack_start($this->ffi->cast("GtkBox *", $this->box), $this->ffi->cast("GtkWidget *", $this->button), true, true, 0);

		$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $this->box));
		$this->ffi->gtk_container_set_border_width($this->ffi->cast("GtkContainer *", $this->instance), 5);



		


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
",".\\gtk-3.dll");

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