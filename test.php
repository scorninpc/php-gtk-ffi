<?php

require_once("phpgtk3.php");

function debug($var, $tag="")
{
	return 1;

	echo "\n--------\n";
	echo (strlen($tag) > 0) ? ($tag . "\n") : ("");
	var_dump($var);
	echo "\n--------\n";
}

// 
\Gtk::init();

// Window 1
$window = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
$window->set_title("PHP-GTK3 FFI");
$window->set_modal(TRUE);
debug($window->get_modal(), "get_modal");
$window->set_default_size(500, 500);
debug($window->get_default_size(), "get_default_size");
$window->set_position(\Gtk\Window::POS_CENTER);
debug($window->get_position(), "get_position");
$window->set_hide_titlebar_when_maximized(TRUE);

$window->show_all();

// 
$window2 = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
$window2->set_transient_for($window);
$window2->set_resizable(FALSE);
debug($window2->get_resizable(), "get_resizable");
$window2->set_position(\Gtk\Window::POS_CENTER_ON_PARENT);
$window2->set_modal(TRUE);
$window2->show_all();

// 
\Gtk::main();