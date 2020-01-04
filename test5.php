<?php

require_once("phpgtk3.php");

\Gtk::init();

// Window
$window = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
$window->connect("destroy", ["Gtk", "main_quit"]);

$entry = new \Gtk\Entry();
$window->add($entry);

// Show all and start
$window->show_all();

	$window->set_title("OK");
	var_dump($window->get_title());

	$window->set_resizable(TRUE);
	var_dump($window->get_resizable());

	$window->set_modal(FALSE);
	var_dump($window->get_modal());

	$window->set_default_size(200, 100);

	$window->set_position(\Gtk\Window::POS_MOUSE);
	var_dump($window->get_position());

	var_dump($window->activate_focus());


// Accel
$accel = new \Gtk\Accel\Group();
$window->add_accel_group($accel);
$entry->add_accelerator("activate", $accel, 0xFFBE, \Gdk\Accel\Modifier\Type::SHIFT_MASK, 0); // (SHIFT + F1)
$entry->connect("activate", function($widget) {
	echo "OK\n";
});

$window->show_all();
// Loop
\Gtk::main();