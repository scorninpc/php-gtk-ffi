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

		public const ICON_PRIMARY = 0;
		public const ICON_SECONDARY = 1;

		/**
		 *
		 */
		public function __construct()
		{
			parent::__construct();

			// Create the window
			$this->cdata_instance = $this->ffi->gtk_entry_new();
		}

		/**
		 *
		 */
		public function __call($name, $value)
		{
			$function_name = "gtk_entry_" . $name;
		
			if(count($value) == 0)	 {
				$return = $this->ffi->$function_name($this->ffi->cast("GtkEntry *", $this->cdata_instance));
			}
			else if(count($value) == 1)	 {
				$return = $this->ffi->$function_name($this->ffi->cast("GtkEntry *", $this->cdata_instance), $value[0]);
			}
			else if(count($value) == 2)	 {
				$return = $this->ffi->$function_name($this->ffi->cast("GtkEntry *", $this->cdata_instance), $value[0], $value[1]);
			}
			else if(count($value) == 3)	 {
				$return = $this->ffi->$function_name($this->ffi->cast("GtkEntry *", $this->cdata_instance), $value[0], $value[1], $value[2]);
			}
			else if(count($value) == 4)	 {
				$return = $this->ffi->$function_name($this->ffi->cast("GtkEntry *", $this->cdata_instance), $value[0], $value[1], $value[2], $value[3]);
			}

			return $return;
		}

		/**
		 *
		 */
		public function set_visibility1(bool $visible)
		{
			$this->ffi->gtk_entry_set_visibility($this->ffi->cast("GtkEntry *", $this->cdata_instance), $visible);
		}

		/**
		 *
		 */
		public function get_visibility1() : bool
		{
			return $this->ffi->gtk_entry_get_visibility($this->ffi->cast("GtkEntry *", $this->cdata_instance));
		}

		/**
		 *
		 */
		public function set_icon_from_pixbuf($icon_pos=0, $pixbuf)
		{
			$this->ffi->gtk_entry_set_icon_from_pixbuf($this->ffi->cast("GtkEntry *", $this->cdata_instance), $icon_pos, $pixbuf->cdata_instance);
		}

		/**
		 *
		 */
		public function get_icon_pixbuf($icon_pos=0)
		{
			$object = $this->ffi->gtk_entry_get_icon_pixbuf($this->ffi->cast("GtkEntry *", $this->cdata_instance), $icon_pos);

			$this->parse_variable($object);

			return $object;
		}
	}
}