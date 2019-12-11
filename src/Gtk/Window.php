<?php

namespace Gtk
{
	/**
	 *
	 */
	class Window extends Widget
	{
		
		/**
		 * Gtk Instance
		 */
		protected $instance = "";

		/**
		 * GtkWindowType
		 */
		const TOPLEVEL = 0;
		const POPUP = 1;

		/**
		 * GtkWindowPosition
		 */
		const NONE = 0;
		const CENTER = 1;
		const MOUSE = 2;
		const CENTER_ALWAYS = 3;
		const CENTER_ON_PARENT = 4;

		/**
		 *
		 */
		public function __construct(int $GtkWindowType=self::TOPLEVEL)
		{
			parent::__construct();

			// Create the window
			$this->instance = \Gtk::getFFI()->gtk_window_new($GtkWindowType);
		}

		/**
		 *
		 */
		public function set_title(string $title)
		{
			\Gtk::getFFI()->gtk_window_set_title(\Gtk::getFFI()->cast("GtkWindow *", $this->instance), $title);
		}

		/**
		 *
		 */
		public function set_resizable(bool $resizable)
		{
			\Gtk::getFFI()->gtk_window_set_resizable(\Gtk::getFFI()->cast("GtkWindow *", $this->instance), $resizable);
		}

		/**
		 *
		 */
		public function get_resizable() : bool
		{
			return \Gtk::getFFI()->gtk_window_get_resizable(\Gtk::getFFI()->cast("GtkWindow *", $this->instance));
		}

		/**
		 *
		 */
		public function set_modal(bool $modal)
		{
			\Gtk::getFFI()->gtk_window_set_modal(\Gtk::getFFI()->cast("GtkWindow *", $this->instance), $modal);
		}

		/**
		 *
		 */
		public function get_modal() : bool
		{
			return \Gtk::getFFI()->gtk_window_get_modal(\Gtk::getFFI()->cast("GtkWindow *", $this->instance));
		}

		/**
		 *
		 */
		public function set_default_size(int $width, int $height)
		{
			\Gtk::getFFI()->gtk_window_set_default_size(\Gtk::getFFI()->cast("GtkWindow *", $this->instance), $width, $height);
		}

		/**
		 *
		 */
		public function get_default_size() : array
		{
			$width = \FFI::addr(\Gtk::getFFI()->new('gint', FALSE));
			$height = \FFI::addr(\Gtk::getFFI()->new('gint', FALSE));

			\Gtk::getFFI()->gtk_window_get_default_size(\Gtk::getFFI()->cast("GtkWindow *", $this->instance), $width, $height);

			return [
				$width[0], 
				$height[0],
				'width' => $width[0],
				'height' => $height[0],
			];
		}

	}

}