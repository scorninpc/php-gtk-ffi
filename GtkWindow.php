<?php

namespace Gtk {

	use FFI;

	/**
	 *
	 */
	class GtkWindow
	{
		public const TOPLEVEL = 0;
		public const POPUP = 1;

		public function __construct($window_type=GtkWindow::TOPLEVEL)
		{
			$this->ffi = FFI::cdef("

				typedef struct _GtkWidget GtkWidget;
				typedef struct _GtkWindow GtkWindow;

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
				typedef enum
				{
				  G_CONNECT_AFTER	= 1 << 0,
				  G_CONNECT_SWAPPED	= 1 << 1
				} GConnectFlags;

				gulong g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);
				

			", "libgtk-3.so");


			// $a = FFI::cdef("

			// 	typedef void* gpointer;

			// 	typedef void  (*GCallback)              (void);

			// 	void g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags););

			// ", "libglib-2.0.so.0");

			$this->instance = $this->ffi->gtk_window_new($window_type);

			
		}

		public function show_all()
		{
			$this->ffi->gtk_widget_show_all($this->instance);
		}

		public function set_title($title="")
		{
			$this->ffi->gtk_window_set_title($this->ffi->cast("GtkWindow *", $this->instance), $title);
		}

		public function connect($signal, $callback)
		{
			$this->ffi->g_signal_connect_object($this->ffi->cast("gpointer *", $this->instance), $signal, $callback, NULL, 1);
		}
	}
}