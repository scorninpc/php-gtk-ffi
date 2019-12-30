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
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->instance));
				}
				else if(count($value) == 1)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkContainer *", $this->instance), $value[0], $value[1], $value[2], $value[3]);
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
			$this->ffi->gtk_container_add($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $widget->instance));
		}

		/**
		 *
		 */
		public function remove($widget)
		{
			$this->ffi->gtk_container_remove($this->ffi->cast("GtkContainer *", $this->instance), $this->ffi->cast("GtkWidget *", $widget->instance));
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
			$this->ffi->gtk_container_foreach($this->ffi->cast("GtkContainer *", $this->instance), function($widget) use ($callback, $userdata) {

				// Get type of widget
				$widget = $this->ffi->cast("GtkWidget *", $widget);
				$gtype = $this->G_OBJECT_TYPE($widget);
				$gtype_name = $this->ffi->g_type_name($gtype);
				
				// Convert it to PHP-GTK class
				$phpgtk_name = "\\Gtk\\" . substr($gtype_name, 3);
				$phpgtk_object = new $phpgtk_name();
				$phpgtk_object->setInstance($widget);
				
				// Add the widget as the first parameter
				array_unshift($userdata, $phpgtk_object);
				
				// Call the user function
				call_user_func_array($callback, $userdata);

			}, NULL);
		}
	}
}