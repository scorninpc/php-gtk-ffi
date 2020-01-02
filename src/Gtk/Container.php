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
		public function __call($name, $value)
		{
			$function_name = "gtk_container_" . $name;
		
			try {
				if(count($value) == 0)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->cdata_instance));
				}
				else if(count($value) == 1)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->cdata_instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->cdata_instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->cdata_instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
				}
			}
			catch(\FFI\Exception $e) {
				$return = parent::__call($name, $value);
			}

			

			return $return;
		}

		/**
		 *
		 */
		public function add($widget)
		{
			$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->cdata_instance), $this->ffi->cast("GtkWidget *", $widget->cdata_instance));
		}

		/**
		 *
		 */
		public function remove($widget)
		{
			$this->ffi->gtk_container_remove($this->ffi->cast("GtkContainer *", $this->cdata_instance), $this->ffi->cast("GtkWidget *", $widget->cdata_instance));
		}

		/**
		 *
		 */
		public function foreach($callback)
		{
			// Create the user data, removing callback argument
			$userdata = func_get_args();
			array_shift($userdata);

			// Call the method
			$this->ffi->gtk_container_foreach($this->ffi->cast("GtkContainer *", $this->cdata_instance), function($widget) use ($callback, $userdata) {

				// Get type of widget
				$object = $this->PHPGTK_OBJECT($widget);
				
				// Add the widget as the first parameter
				array_unshift($userdata, $object);
				
				// Call the user function
				call_user_func_array($callback, $userdata);

			}, NULL);
		}

		/**
		 *
		 */
		public function get_children()
		{
			$children = [];

			$this->foreach(function($widget) use (&$children) {
				$children[] = $widget;
			});

			return $children;
		}

		/**
		 *
		 */
		public function get_focus_child()
		{
			$children = [];

			$widget = $this->ffi->gtk_container_get_focus_child($this->ffi->cast("GtkContainer *", $this->cdata_instance));

			$object = $this->PHPGTK_OBJECT($widget);

			return $object;
		}

		/**
		 *
		 */
		public function set_focus_child($widget)
		{
			$this->ffi->gtk_container_set_focus_child($this->ffi->cast("GtkContainer *", $this->cdata_instance), $this->ffi->cast("GtkWidget *", $widget->cdata_instance));
		}

		/**
		 *
		 */
		public function child_type()
		{
			$a = $this->ffi->gtk_container_child_type($this->ffi->cast("GtkContainer *", $this->cdata_instance));
			return $a;
		}

		/**
		 *
		 */
		public function child_notify($widget, $child_property)
		{
			$this->ffi->gtk_container_child_notify($this->ffi->cast("GtkContainer *", $this->cdata_instance), $this->ffi->cast("GtkWidget *", $widget->cdata_instance), $child_property);
		}
	}
}