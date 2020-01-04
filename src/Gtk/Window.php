<?php

namespace Gtk
{
	/**
	 *
	 */
	class Window extends Container
	{

		/**
		 *
		 */
		protected $name = "GtkWindow";

		/**
		 * GtkWindowType
		 */
		const TOPLEVEL = 0;
		const POPUP = 1;

		/**
		 * GtkWindowPosition
		 */
		const POS_NONE = 0;
		const POS_CENTER = 1;
		const POS_MOUSE = 2;
		const POS_CENTER_ALWAYS = 3;
		const POS_CENTER_ON_PARENT = 4;

		/**
		 *
		 */
		public function __construct(int $GtkWindowType=self::TOPLEVEL)
		{
			parent::__construct();

			// Create the window
			$this->cdata_instance = $this->ffi->gtk_window_new($GtkWindowType);
		}

		/**
		 *
		 */
		public function __call($name, $value)
		{
			$function_name = "gtk_window_" . $name;
			$widget_cast = "GtkWindow *";
		
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

		/**
		 *
		 */
		public function get_default_size() : array
		{
			$width = $this->ffi->new("gint", FALSE);
			$height = $this->ffi->new("gint", FALSE);

			$this->ffi->gtk_window_get_default_size($this->ffi->cast("GtkWindow *", $this->cdata_instance), \FFI::addr($width), \FFI::addr($height));

			return [
				'width' => $width->cdata,
				'height' => $height->cdata,
			];
		}

		/**
		 *
		 */
		public function get_position() : array
		{
			$root_x = $this->ffi->new("gint", FALSE);
			$root_y = $this->ffi->new("gint", FALSE);

			$this->ffi->gtk_window_get_position($this->ffi->cast("GtkWindow *", $this->cdata_instance), \FFI::addr($root_x), \FFI::addr($root_y));

			return [
				'x' => $root_x->cdata,
				'y' => $root_y->cdata,
			];
		}

		/**
		 *
		 */
		public function set_transient_for($parent)
		{
			$this->ffi->gtk_window_set_transient_for($this->ffi->cast("GtkWindow *", $this->cdata_instance), $this->ffi->cast("GtkWindow *", $parent->cdata_instance));
		}

		/**
		 *
		 */
		public function set_attached_to($widget)
		{
			$this->ffi->gtk_window_set_attached_to($this->ffi->cast("GtkWindow *", $this->cdata_instance), $this->ffi->cast("GtkWidget *", $widget->cdata_instance));
		}
		
		/**
		 *
		 */
		public function add_accel_group($accel)
		{
			$this->ffi->gtk_window_add_accel_group($this->ffi->cast("GtkWindow *", $this->cdata_instance), $this->ffi->cast("GtkAccelGroup *", $accel->cdata_instance));
		}

	}

}