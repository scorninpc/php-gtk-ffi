<?php

define("GTK_LIB_PATH", "/usr/lib/x86_64-linux-gnu/libgtk-3.so");

/**
 *
 */
class Gtk 
{
	private static $instance;

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
		$final_header = PHPGTK3_SOURCE_PATH . "/Gtk/gtk.h";

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

	/**
	 *
	 */
	public static function init(int $argc=0, array $argv=[])
	{
		$instance = self::getInstance();

		$argc = FFI::new('int');
		$argv = FFI::new('char[0]');
		$pargv = FFI::addr($argv);

		$instance->ffi->gtk_init(\FFI::addr($argc), \FFI::addr($pargv));
	}

	/**
	 *
	 */
	public static function main()
	{
		$instance = self::getInstance();

		$instance->ffi->gtk_main();
	}

	/**
	 *
	 */
	public static function main_quit()
	{
		$instance = self::getInstance();

		$instance->ffi->gtk_main_quit();
	}
}