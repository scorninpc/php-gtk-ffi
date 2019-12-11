<?php

require_once("phpgtk3.php");

function debug($var, $tag="")
{
	echo "\n--------\n";
	echo (strlen($tag) > 0) ? ($tag . "\n") : ("");
	var_dump($var);
	echo "\n--------\n";
}

\Gtk::init();

// Window
$window = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
$window->set_title("PHP-GTK3 FFI");
$window->set_resizable(FALSE);
debug($window->get_resizable(), "get_resizable");
$window->set_modal(TRUE);
debug($window->get_modal(), "get_modal");
$window->set_default_size(500, 500);
debug($window->get_default_size(), "get_default_size");


$window->show_all();

\Gtk::main();