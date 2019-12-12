<?php

class Cairo
{
	private static $instance;

	/**
	 * FFI Object
	 */
	protected $ffi = "";

	/**
	 * Construtor
	 */
	private function __construct()
	{
		$this->ffi = FFI::load(PHPGTK3_SOUCE_PATH . "/Cairo/cairo.h");
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
}