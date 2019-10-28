<?php


require_once("Gtk.php");
require_once("GtkWindow.php");

\Gtk\init($argc, $argv);

$window = new \Gtk\GtkWindow(\Gtk\GtkWindow::TOPLEVEL);
$window->show_all();
$window->connect("delete-event", function($a=NULL) {
	var_dump($a);

	$a->show_all();

	//\Gtk\main_quit();
	return true;
});

\Gtk\main();