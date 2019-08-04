<?php


require_once("Gtk.php");
require_once("GtkWindow.php");

\Gtk\init($argc, $argv);

$window = new \Gtk\GtkWindow(\Gtk\GtkWindow::TOPLEVEL);
$window->show_all();
$window->connect("destroy", function($a=NULL) {
	var_dump($a);

	\Gtk\main_quit();
});

\Gtk\main();