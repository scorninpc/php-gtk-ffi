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
		// $this->window->maximize();
		$this->window->set_title("PHP-GTK3 FFI Test3");
		$this->window->connect("destroy", [$this, "window_destroy"]);

		// Paned
		$paned = new \Gtk\Paned(\Gtk\Paned::ORIENTATION_HORIZONTAL);
		$paned->pack1($entry = new \Gtk\Entry());
		$paned->pack2(new \Gtk\Entry());
		$paned->set_position(100);

		// Pixbuf
		$pixbuf = \Gdk\Pixbuf::new_from_file("/home/scorninpc/Desktop/Bruno/BUILD_PHP_GTK/php-gtk3/logo.png");
		$entry->set_icon_from_pixbuf(0, $pixbuf);


		// Debug return variables test
		echo "\narray\n";
		$this->window->get_children();

		echo "\nobject\n";
		$paned->get_child1();
		
		echo "\ninteger\n";
		$paned->get_position();

		echo "\nGdkPixbuf\n";
		$entry->get_icon_pixbuf(0);



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