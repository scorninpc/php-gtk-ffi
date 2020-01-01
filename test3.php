<?php

require_once("phpgtk3.php");

\Gtk::init();

class Test3
{
	public function __construct()
	{
		// Window 1
		$this->window = new \Gtk\Window(\Gtk\Window::TOPLEVEL);
		$this->window->set_title("PHP-GTK3 FFI Test3");
		$this->window->connect("destroy", [$this, "window_destroy"]);

		$box = new \Gtk\Box(\Gtk\Box::ORIENTATION_VERTICAL, 10);

		$box->pack_start(new \Gtk\Entry(), FALSE, FALSE, 5);

		$this->window->add($box);
		$this->window->show_all();


		\Gtk::main();
	}

	public function window_destroy()
	{
		\Gtk::main_quit();
	}

}

new Test3();