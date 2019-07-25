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

			typedef enum
			{
			  GTK_WINDOW_TOPLEVEL,
			  GTK_WINDOW_POPUP
			} GtkWindowType;

			GtkWidget *gtk_window_new(GtkWindowType type);
			void gtk_widget_show_all(GtkWidget *widget);
			void gtk_window_set_title(GtkWindow *window, char *title);

		", "libgtk-3.so");

		$this->instance = $this->ffi->gtk_window_new(0);
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
	void gtk_init();
	void gtk_main();
	void gtk_main_quit();
", "/usr/lib/x86_64-linux-gnu/libgtk-3.so");

/**
 */
$ffi->gtk_init();

$win = new GtkWindow();
$win->set_title("FFI PHP 7.4 Test");
$win->show_all();

$ffi->gtk_main();