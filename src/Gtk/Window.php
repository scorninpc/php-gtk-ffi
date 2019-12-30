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
			$this->cdata_instance = \Gtk::getFFI()->gtk_window_new($GtkWindowType);
		}

		/**
		 *
		 */
		public function __call($name, $value)
		{
			$function_name = "gtk_window_" . $name;
		
			try {
				if(count($value) == 0)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance));
				}
				else if(count($value) == 1)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$return = \Gtk::getFFI()->$function_name(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
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
			\Gtk::getFFI()->gtk_window_set_title(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $title);
		}

		/**
		 *
		 */
		public function get_title() : string
		{
			$a = \Gtk::getFFI()->gtk_window_get_title(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance));

			return $a;
		}

		/**
		 *
		 */
		public function set_resizable(bool $resizable)
		{
			\Gtk::getFFI()->gtk_window_set_resizable(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $resizable);
		}

		/**
		 *
		 */
		public function get_resizable() : bool
		{
			return \Gtk::getFFI()->gtk_window_get_resizable(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance));
		}

		/**
		 *
		 */
		public function set_modal(bool $modal)
		{
			\Gtk::getFFI()->gtk_window_set_modal(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $modal);
		}

		/**
		 *
		 */
		public function get_modal() : bool
		{
			return \Gtk::getFFI()->gtk_window_get_modal(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance));
		}

		/**
		 *
		 */
		public function set_default_size(int $width, int $height)
		{
			\Gtk::getFFI()->gtk_window_set_default_size(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $width, $height);
		}

		/**
		 *
		 */
		public function get_default_size() : array
		{
			$width = \Gtk::getFFI()->new("gint", FALSE);
			$height = \Gtk::getFFI()->new("gint", FALSE);

			\Gtk::getFFI()->gtk_window_get_default_size(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), \FFI::addr($width), \FFI::addr($height));

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
			// \Gtk::getFFI()->gtk_window_set_position(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $position);
		}

		/**
		 *
		 */
		public function get_position() : array
		{
			$root_x = \Gtk::getFFI()->new("gint", FALSE);
			$root_y = \Gtk::getFFI()->new("gint", FALSE);

			\Gtk::getFFI()->gtk_window_get_position(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), \FFI::addr($root_x), \FFI::addr($root_y));

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
			\Gtk::getFFI()->gtk_window_set_transient_for(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), \Gtk::getFFI()->cast("GtkWindow *", $parent->cdata_instance));
		}

		/**
		 *
		 */
		public function set_attached_to($widget)
		{
			\Gtk::getFFI()->gtk_window_set_attached_to(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), \Gtk::getFFI()->cast("GtkWidget *", $widget->cdata_instance));
		}

		/**
		 *
		 */
		public function set_destroy_with_parent(bool $setting)
		{
			\Gtk::getFFI()->gtk_window_set_destroy_with_parent(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $setting);
		}

		/**
		 *
		 */
		public function set_hide_titlebar_when_maximized(bool $setting)
		{
			\Gtk::getFFI()->gtk_window_set_hide_titlebar_when_maximized(\Gtk::getFFI()->cast("GtkWindow *", $this->cdata_instance), $setting);
		}

	}

}