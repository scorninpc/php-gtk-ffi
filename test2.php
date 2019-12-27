<?php

$ffi = FFI::load("src/Gtk/gtk.h");

$argc = FFI::new('int');
$argv = FFI::new('char[0]');
$ffi->gtk_init(\FFI::addr($argc), \FFI::addr(FFI::addr($argv)));

$window = $ffi->gtk_window_new(0);

//
$lookup = $ffi->g_signal_lookup ("button-press-event", G_OBJECT_TYPE($window));
$signal_info = \FFI::addr($ffi->new("GSignalQuery"));
$ffi->g_signal_query($lookup, $signal_info);
$closure = $ffi->g_cclosure_new_swap(function() use ($ffi) {

	$event = func_get_arg(1);
	var_dump($event->button->button);

}, NULL, NULL);
$ffi->g_signal_connect_closure($ffi->cast("gpointer", $window), "button-press-event", $closure, TRUE);


//
$ffi->gtk_widget_show_all($window);


$ffi->gtk_main();

function G_OBJECT_TYPE($a)
{
	global $ffi;

	$g_class = $ffi->cast("GTypeInstance *", $a)->g_class;
	$g_type = $ffi->cast("GTypeClass *", $g_class)->g_type;

	return $g_type;
}