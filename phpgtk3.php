<?php

// Define a path to source directory
defined("PHPGTK3_SOURCE_PATH") || define("PHPGTK3_SOURCE_PATH", dirname(__FILE__) . "/src");

// General config
define("PHPGTK3_RECOMPILE_HEADERS", TRUE);

// Autoload
spl_autoload_register(function($className) {

	$filename = PHPGTK3_SOURCE_PATH . "/" . implode("/", explode("\\", $className)) . ".php";
	if(!file_exists($filename)) {
		throw new Exception("Class \"" . $className . "\" not fount", 1);
	}

	require_once($filename);
});

class PHPGTK3
{
	/**
	 * Convert PHP string into char *
	 */
	static public function char_p(string $string)
	{
		$char = \FFI::new("char[" . strlen($string) . "]");

		\FFI::memcpy($char, $string, strlen($string));

		return \FFI::cast("char *", $char);
	}
}