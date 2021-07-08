<?php
    function arrayShiftRight(&$array) {
        $first = array_shift($array);
        
        array_push($array, $first);
    }

    $array = array(1, 2, 3, 4);

    arrayShiftRight($array, $size);

    print_r($array);
?>
