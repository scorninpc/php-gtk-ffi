<?php

namespace Gdk
{
	/**
	 *
	 */
	class Event
	{
		/**
		 * FFI Instance
		 */
		protected $ffi = "";

		/**
		 * Gtk Instance
		 */
		public $cdata_instance = "";

		/**
		 *
		 */
		public function __construct()
		{
			
			// Get instance of FFI
			$this->ffi = \Gtk::getFFI();
		}

		public function __get($name)
		{
			if($name == "button") 
			{
				return $this->ffi->cast("GdkEventButton", $this->cdata_instance->button);
			}
			else if($name == "key") 
			{
				return $this->ffi->cast("GdkEventKey", $this->cdata_instance->button);
			}
		}
	}
}