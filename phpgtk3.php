<?php

// Define a path to source directory
defined("PHPGTK3_SOUCE_PATH") || define("PHPGTK3_SOUCE_PATH", dirname(__FILE__) . "/src");

// Autoload
spl_autoload_register(function($className) {

	$filename = PHPGTK3_SOUCE_PATH . "/" . implode("/", explode("\\", $className)) . ".php";
	if(!file_exists($filename)) {
		throw new Exception("Class \"" . $className . "\" not fount", 1);
	}

	require_once($filename);
});