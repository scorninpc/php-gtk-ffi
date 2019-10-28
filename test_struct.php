<?php

$ffi = FFI::cdef("
	
	struct test 
	{
		int field_int;
		char field_char;
		char *field_string;
	};
	
", "libc.so.6");


// Create
$test = $ffi->new("struct test");

// Populate int
$test->field_int = 59;

// Populate char
$test->field_char = "A";

// Populate string
// $test->c_data->field_string[0] = 'M';

$p = FFI::new("char[2]");
// $string = "MY";
$p[0] = 'M';
$p[1] = 'Y';

$pointer = FFI::addr($test->field_string);
FFI::memset($pointer, 0, FFI::sizeof(FFI::new("char *")) * 2 );


// test 1
// $test->field_string = FFI::cast("char", "My String");

// $pointer = FFI::addr($test->field_string);
// FFI::memset($pointer, 0, strlen("My String") * FFI::sizeof(FFI::new("const char *")));
// FFI::memcpy($pointer, "My String");
// var_dump($pointer);


// $string = FFI::new("char[3]");
// $string->c_data[0] = "1";
// $string->c_data[1] = "2";
// $string->c_data[2] = "3";
// var_dump($string);







// test 2
// FFI::memset($test->field_string, 0, strlen("My String") * FFI::sizeof($test->field_string));
// FFI::memcpy($test->field_string, "My String", strlen("My String"));

// Dump all 
var_dump($test);

// Dump single field
var_dump($test->field_int);
var_dump($test->field_char);
var_dump($test->field_string);