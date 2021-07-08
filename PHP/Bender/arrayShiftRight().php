<?php
    function arrayShiftRight(&$array) {
        $last = array_pop($array);
        
        array_unshift($array, $last);
    }

    $array = array(1, 2, 3, 4);

    arrayShiftRight($array, $size);

    print_r($array);

?>