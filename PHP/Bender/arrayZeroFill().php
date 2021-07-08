<?php
    function arrayZeroFill(&$array, $size) {
        $array = array_fill(0, $size, 0);
    }

    $array = array();
    $size = 10;

    arrayZeroFill($array, $size);

    print_r($array);
?>
