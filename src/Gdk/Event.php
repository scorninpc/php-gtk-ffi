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
		protected $instance = "";

		/**
		 *
		 */
		public function getInstance()
		{
			return $this->instance;
		}

		/**
		 *
		 */
		public function setInstance($instance)
		{
			$this->instance = $instance;
		}

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
				return $this->ffi->cast("GdkEventButton", $this->instance->button);
			}
			else if($name == "key") 
			{
				return $this->ffi->cast("GdkEventKey", $this->instance->button);
			}
		}
	}
}