<?php

namespace Gtk
{
	/**
	 *
	 */
	class Entry extends Widget
	{
		/**
		 *
		 */
		protected $name = "GtkEntry";

		/**
		 *
		 */
		public function __construct()
		{
			parent::__construct();

			// Create the window
			$this->instance = $this->ffi->gtk_entry_new();
		}
	}
}