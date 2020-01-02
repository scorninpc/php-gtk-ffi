<?php

namespace Gdk
{
	/**
	 *
	 */
	class Pixbuf
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

		/**
		 *
		 */
		static public function new_from_file($path)
		{
			$pixbuf = \Gtk::getFFI()->gdk_pixbuf_new_from_file($path, NULL);

			$object = new \Gdk\Pixbuf();
			$object->cdata_instance = $pixbuf;

			return $object;
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