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
		
			try {
				if(count($value) == 0)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkWindow *", $this->cdata_instance));
				}
				else if(count($value) == 1)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkWindow *", $this->cdata_instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
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
		public function set_title(string $title)
		{
			$this->ffi->gtk_window_set_title($this->ffi->cast("GtkWindow *", $this->cdata_instance), $title);
		}

		/**
		 *
		 */
		public function get_title() : string
		{
			$a = $this->ffi->gtk_window_get_title($this->ffi->cast("GtkWindow *", $this->cdata_instance));

			return $a;
		}

		/**
		 *
		 */
		public function set_resizable(bool $resizable)
		{
			$this->ffi->gtk_window_set_resizable($this->ffi->cast("GtkWindow *", $this->cdata_instance), $resizable);
		}

		/**
		 *
		 */
		public function get_resizable() : bool
		{
			return $this->ffi->gtk_window_get_resizable($this->ffi->cast("GtkWindow *", $this->cdata_instance));
		}

		/**
		 *
		 */
		public function set_modal(bool $modal)
		{
			$this->ffi->gtk_window_set_modal($this->ffi->cast("GtkWindow *", $this->cdata_instance), $modal);
		}

		/**
		 *
		 */
		public function get_modal() : bool
		{
			return $this->ffi->gtk_window_get_modal($this->ffi->cast("GtkWindow *", $this->cdata_instance));
		}

		/**
		 *
		 */
		public function set_default_size(int $width, int $height)
		{
			$this->ffi->gtk_window_set_default_size($this->ffi->cast("GtkWindow *", $this->cdata_instance), $width, $height);
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
		public function set_position(int $position)
		{
			// $this->ffi->gtk_window_set_position($this->ffi->cast("GtkWindow *", $this->cdata_instance), $position);
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
		public function set_destroy_with_parent(bool $setting)
		{
			$this->ffi->gtk_window_set_destroy_with_parent($this->ffi->cast("GtkWindow *", $this->cdata_instance), $setting);
		}

		/**
		 *
		 */
		public function set_hide_titlebar_when_maximized(bool $setting)
		{
			$this->ffi->gtk_window_set_hide_titlebar_when_maximized($this->ffi->cast("GtkWindow *", $this->cdata_instance), $setting);
		}

	}

}