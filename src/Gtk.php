<?php

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
		$this->ffi = FFI::load(PHPGTK3_SOUCE_PATH . "/Gtk/gtk.h");
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
	static function init(int $argc=0, array $argv=[])
	{
		$instance = self::getInstance();

		$argc = FFI::new('int');
		$argv = FFI::new('char[0]');
		$pargv = FFI::addr($argv);
		Gtk::getFFI()->gtk_init(FFI::addr($argc), FFI::addr($pargv));
	}

	/**
	 *
	 */
	static function main()
	{
		$instance = self::getInstance();

		Gtk::getFFI()->gtk_main();
	}

	/**
	 *
	 */
	static function main_quit()
	{
		$instance = self::getInstance();

		Gtk::getFFI()->main_quit();
	}
}