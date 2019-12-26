<?php

namespace Gtk
{
	/**
	 *
	 */
	class Container extends Widget
	{
		/**
		 *
		 */
		protected $name = "GtkContainer";

		/**
		 *
		 */
		public function __construct()
		{
			parent::__construct();
		}

		/**
		 *
		 */
		public function add($widget)
		{
			$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $widget->instance));
		}
	}
}