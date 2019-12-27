<?php

define("GDK_LIB_PATH", "/usr/lib/x86_64-linux-gnu/libgtk-3.so");

/**
 *
 */
class Gdk 
{
	private static $instance;

	// Modifyers
	public const SHIFT_MASK = 1 << 0;
	public const LOCK_MASK = 1 << 1;
	public const CONTROL_MASK = 1 << 2;
	public const MOD1_MASK = 1 << 3;
	public const MOD2_MASK = 1 << 4;
	public const MOD3_MASK = 1 << 5;
	public const MOD4_MASK = 1 << 6;
	public const MOD5_MASK = 1 << 7;
	public const BUTTON1_MASK = 1 << 8;
	public const BUTTON2_MASK = 1 << 9;
	public const BUTTON3_MASK = 1 << 10;
	public const BUTTON4_MASK = 1 << 11;
	public const BUTTON5_MASK = 1 << 12;
	public const MODIFIER_RESERVED_13_MASK = 1 << 13;
	public const MODIFIER_RESERVED_14_MASK = 1 << 14;
	public const MODIFIER_RESERVED_15_MASK = 1 << 15;
	public const MODIFIER_RESERVED_16_MASK = 1 << 16;
	public const MODIFIER_RESERVED_17_MASK = 1 << 17;
	public const MODIFIER_RESERVED_18_MASK = 1 << 18;
	public const MODIFIER_RESERVED_19_MASK = 1 << 19;
	public const MODIFIER_RESERVED_20_MASK = 1 << 20;
	public const MODIFIER_RESERVED_21_MASK = 1 << 21;
	public const MODIFIER_RESERVED_22_MASK = 1 << 22;
	public const MODIFIER_RESERVED_23_MASK = 1 << 23;
	public const MODIFIER_RESERVED_24_MASK = 1 << 24;
	public const MODIFIER_RESERVED_25_MASK = 1 << 25;
	public const SUPER_MASK = 1 << 26;
	public const HYPER_MASK = 1 << 27;
	public const META_MASK = 1 << 28;
	public const MODIFIER_RESERVED_29_MASK = 1 << 29;
	public const RELEASE_MASK = 1 << 30;
	public const MODIFIER_MASK = 0x5c001fff;

	/**
	 * FFI Object
	 */
	protected $ffi = "";

	/**
	 * Invalida os metodos magicos
	 */
	private function __clone() { }
	private function __wakeup() { }

	/**
	 * Construtor
	 */
	private function __construct()
	{
		$final_header = PHPGTK3_SOUCE_PATH . "/Gdk/headers/gdk.h";
unlink($final_header);
		if(!file_exists($final_header)) {
			$data = "";

			// Create the final header
			$data .= "#define FFI_LIB \"" . GDK_LIB_PATH . "\"\n\n";

			$files = scandir(PHPGTK3_SOUCE_PATH . "/Gdk/headers");
			foreach($files as $file) {
				if(!is_dir(PHPGTK3_SOUCE_PATH . "/Gdk/headers/" . $file)) {
					$data .= file_get_contents(PHPGTK3_SOUCE_PATH . "/Gdk/headers/" . $file) . "\n\n";
				}
			}

			file_put_contents($final_header, $data);
			
		}
		$this->ffi = \FFI::load($final_header);
	}

	/**
	 * Singleton
	 */
	public static function getInstance()
	{
		if(self::$instance === NULL) {
			self::$instance = new self;
		}
		return self::$instance;
	}

	/**
	 *
	 */
	public static function getFFI()
	{
		$instance = self::getInstance();

		return $instance->ffi;
	}
}