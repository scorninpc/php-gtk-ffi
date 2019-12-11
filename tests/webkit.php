<?php

$webkit_ffi = FFI::load("webkit.h");
$gtk_ffi = FFI::load("gtk.h");

//
$argc = FFI::new('int');
$argv = FFI::new('char[0]');
$pargv = FFI::addr($argv);
$gtk_ffi->gtk_init(FFI::addr($argc), FFI::addr($pargv));

//
$window = $gtk_ffi->gtk_window_new(0);


//
$webview = $webkit_ffi->webkit_web_view_new();
$gtk_ffi->gtk_container_add($gtk_ffi->cast("GtkContainer *", $window), $gtk_ffi->cast("GtkWidget *", $webview));

// 
$gtk_ffi->gtk_widget_show_all($window);

$webkit_ffi->webkit_web_view_load_uri($webview, "http://twitter.com");

// 
$gtk_ffi->gtk_main();