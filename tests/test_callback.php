<?php

class callback 
{
	public function funcA()
	{
		echo "\nOK\n";
	}

	public function __construct()
	{
		call_user_func_array(unserialize(serialize([$this, "funcA"])), []);
	}
}

new callback();