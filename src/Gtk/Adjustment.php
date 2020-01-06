<?php

namespace Gtk
{
	/**
	 *
	 */
	class Adjustment extends Widget
	{
		/**
		 *
		 */
		protected $name = "GtkAdjustment";

		public const ICON_PRIMARY = 0;
		public const ICON_SECONDARY = 1;

		/**
		 *
		 */
		public function __construct()
		{
			parent::__construct();

			// Create the window
			$this->cdata_instance = $this->ffi->gtk_adjustment_new();
		}

		/**
		 *
		 */
		public function __call($name, $value)
		{
			$function_name = "gtk_adjustment_" . $name;
			$widget_cast = "GtkAdjustment *";

			try {
				if(count($value) == 0)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance));
				}
				else if(count($value) == 1)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
				}
				else if(count($value) == 5)	 {
					$returned = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast($widget_cast, $this->cdata_instance), $value[0], $value[1], $value[2], $value[3], $value[4]);
				}

				$return = $this->parse_variable($returned, $name);
			}
			catch(\FFI\Exception $e) {
				if(strpos($e->getMessage(), "Attempt to call undefined C function") !== FALSE) {
					$return = parent::__call($name, $value);
				}

				throw $e;
			}

			return $return;
		}
	}
}