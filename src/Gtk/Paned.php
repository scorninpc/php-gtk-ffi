<?php

namespace Gtk
{
	/**
	 *
	 */
	class paned extends Container
	{

		/**
		 *
		 */
		protected $name = "GtkPaned";

		/**
		 * GtkOrientation
		 */
		const ORIENTATION_HORIZONTAL = 0;
		const ORIENTATION_VERTICAL = 1;

		/**
		 *
		 */
		public function __construct(int $orientation)
		{
			parent::__construct();

			// Create the window
			$this->cdata_instance = $this->ffi->gtk_paned_new($orientation);
		}

		/**
		 *
		 */
		public function __call($name, $value)
		{
			$function_name = "gtk_paned_" . $name;
		
			try {
				if(count($value) == 0)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkPaned *", $this->cdata_instance));
				}
				else if(count($value) == 1)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkPaned *", $this->cdata_instance), $value[0]);
				}
				else if(count($value) == 2)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkPaned *", $this->cdata_instance), $value[0], $value[1]);
				}
				else if(count($value) == 3)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkPaned *", $this->cdata_instance), $value[0], $value[1], $value[2]);
				}
				else if(count($value) == 4)	 {
					$return = $this->ffi->$function_name($this->ffi->cast("GtkPaned *", $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
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
		public function add1(\Gtk\Widget $child)
		{
			$this->ffi->gtk_paned_add1($this->ffi->cast("GtkPaned *", $this->cdata_instance), $child->cdata_instance);
		}

		/**
		 *
		 */
		public function add2(\Gtk\Widget $child)
		{
			$this->ffi->gtk_paned_add1($this->ffi->cast("GtkPaned *", $this->cdata_instance), $child->cdata_instance);
		}

		/**
		 *
		 */
		public function pack1(\Gtk\Widget $child, bool $resize=FALSE, bool $shrink=FALSE)
		{
			$this->ffi->gtk_paned_pack1($this->ffi->cast("GtkPaned *", $this->cdata_instance), $child->cdata_instance, $resize, $shrink);
		}

		/**
		 *
		 */
		public function pack2(\Gtk\Widget $child, bool $resize=FALSE, bool $shrink=FALSE)
		{
			$this->ffi->gtk_paned_pack2($this->ffi->cast("GtkPaned *", $this->cdata_instance), $child->cdata_instance, $resize, $shrink);
		}

		/**
		 *
		 */
		public function get_child1()
		{
			$object = $this->ffi->gtk_paned_get_child1($this->ffi->cast("GtkPaned *", $this->cdata_instance));
			return $this->PHPGTK_OBJECT($object);
		}

		/**
		 *
		 */
		public function get_child2()
		{
			$object = $this->ffi->gtk_paned_get_child2($this->ffi->cast("GtkPaned *", $this->cdata_instance));
			return $this->PHPGTK_OBJECT($object);
		}
	}
}