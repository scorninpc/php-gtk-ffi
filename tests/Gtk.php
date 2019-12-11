<?php

namespace Gtk 
{

	use FFI;

	$gtk_ffi = FFI::cdef("
		void gtk_init(int *, char **[]);
		void gtk_main();
		void gtk_main_quit();
	", "libgtk-3.so");

	/**
	 *
	 */
	function init($argc, $argv)
	{
		global $gtk_ffi;

		$argc = FFI::new('int');
		$argv = FFI::new('char[0]');
		$pargv = FFI::addr($argv);

		$gtk_ffi->gtk_init(FFI::addr($argc), FFI::addr($pargv));
	}

	/**
	 *
	 */
	function main()
	{
		global $gtk_ffi;

		$gtk_ffi->gtk_main();
	}

	/**
	 *
	 */
	function main_quit()
	{
		global $gtk_ffi;

		$gtk_ffi->gtk_main_quit();
	}

}