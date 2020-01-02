<?php

require_once("phpgtk3.php");

\Gtk::init();

class Test3
{
	public function __construct()
	{
		// Window
		$this->window = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
		$this->window->set_default_size(500,500);
		$this->window->set_title("PHP-GTK3 FFI Test3");
		$this->window->connect("destroy", [$this, "window_destroy"]);

		// Paned
		$paned = new \Gtk\Paned(\Gtk\Paned::ORIENTATION_HORIZONTAL);
		$paned->pack1(new \Gtk\Entry());
		$paned->pack2(new \Gtk\Entry());
		$paned->set_position(100);
		var_dump($paned->get_position());

		// Show all and start
		$this->window->add($paned);
		$this->window->show_all();
		\Gtk::main();
	}

	public function window_destroy()
	{
		\Gtk::main_quit();
	}

}

new Test3();