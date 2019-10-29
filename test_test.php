<?php

$ffi = FFI::cdef("
	
	struct test 
	{
		char *field_string;
	};
	
", "libc.so.6");


// Create
$test = $ffi->new("struct test");


$p = FFI::new("char[2]");
$p[0] = "M";
$p[1] = "Y";
var_dump($p);
echo "\n-----\n";


// 
$p = FFI::new("struct test { const char field_string[5]; }");
FFI::memcpy($p, "ABCDE", 5);

echo "\n-----\n";
var_dump($p);


// 
$p = FFI::new("char");
$pointer = FFI::addr($p);
FFI::memset($pointer, ord("A"), FFI::sizeof($p) * 5);
FFI::memcpy($pointer, "ABCDE", FFI::sizeof($p) * 5);

echo "\n-----\n";
var_dump($p);
echo "\n-----\n";
var_dump($pointer);
echo "\n-----\n";




// Dump all 
// var_dump($test);
