<?php

namespace Gtk
{
	/**
	 *
	 */
	class Widget
	{
		/**
		 * FFI Instance
		 */
		protected $ffi = "";

		/**
		 * Gtk Instance
		 */
		protected $instance = "";

		/**
		 *
		 */
		public function __construct()
		{
			//throw new \Exception("gtk_widget_new not implemented", 1);
			
			// Get instance of FFI
			$this->ffi = \Gtk::getFFI();
		}


		/**
		 *
		 */
		public function getInstance()
		{
			return $this->instance;
		}

		/**
		 *
		 */
		public function destroy()
		{
			$this->ffi->gtk_widget_destroy($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function in_destruction() : bool
		{
			return $this->ffi->gtk_widget_in_destruction($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function destroyed($widget)
		{
			$this->ffi->gtk_widget_destroyed($this->ffi->cast("GtkWidget *", $this->instance), $this->ffi->cast("GtkWidget **", FFI::addr($this->instance)));
		}

		/**
		 *
		 */
		public function unparent()
		{
			$this->ffi->gtk_widget_unparent($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function show()
		{
			$this->ffi->gtk_widget_show($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function show_now()
		{
			$this->ffi->gtk_widget_show_now($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function hide()
		{
			$this->ffi->gtk_widget_hide($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function show_all()
		{
			$this->ffi->gtk_widget_show_all($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function map()
		{
			$this->ffi->gtk_widget_map($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function unmap()
		{
			$this->ffi->gtk_widget_unmap($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function realize()
		{
			$this->ffi->gtk_widget_realize($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function queue_draw()
		{
			$this->ffi->gtk_widget_queue_draw($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function queue_resize()
		{
			$this->ffi->gtk_widget_queue_resize($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function queue_resize_no_redraw()
		{
			$this->ffi->gtk_widget_queue_resize_no_redraw($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function queue_allocate()
		{
			$this->ffi->gtk_widget_queue_allocate($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function get_scale_factor() : int
		{
			return $this->ffi->gtk_widget_get_scale_factor($this->ffi->cast("GtkWidget *", $this->instance));
		}

		/**
		 *
		 */
		public function size_allocate() : array
		{
			throw new \Exception("gtk_widget_size_allocate not implemented", 1);
			
			$allocate = \Gtk::getFFI()->new("GtkAllocation");
			$this->ffi->gtk_widget_size_allocate($this->ffi->cast("GtkWidget *", $this->instance), \FFI::addr($allocate));

			return [
				'x' => $allocate->x,
				'y' => $allocate->y,
				'width' => $allocate->width,
				'height' => $allocate->height,
			];
		}

	}

}