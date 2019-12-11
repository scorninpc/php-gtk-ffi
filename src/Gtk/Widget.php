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
			// Get instance of FFI
			$this->ffi = \Gtk::getFFI();
		}

		/**
		 *
		 */
		public function show_all()
		{
			$this->ffi->gtk_widget_show_all($this->ffi->cast("GtkWidget *", $this->instance));
		}

	}

}