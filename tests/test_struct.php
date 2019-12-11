<?php

/**
 *  I dont know how to do dinamic char size. So, struct can be created with this way
 */

// string to write struct
$mystring = "My String!";

// Create
$test = FFI::new("
		struct test {
			int field_int; 
			char field_char; 
			const char field_string[" . strlen($mystring) . "]; 
			float field_float; 
		}
	");

// Populate int
$test->field_int = 59;

// Populate char
$test->field_char = "A";

// Populate string
FFI::memcpy($test->field_string, $mystring, strlen($mystring));

// Populate float
$test->field_float = 42.3;

// Dump all 
var_dump($test);

// Dump single field
var_dump($test->field_int);
var_dump($test->field_char);
var_dump(FFI::string($test->field_string));
var_dump($test->field_float);