<?php
    function arraySearch($array, $size, $needle) {
        $index = array_search($needle, array_slice($array, 0, $size));
        
        if ( false != $index ) {
            return $index;
        }
        
        return -1;
    }

    $array = array(11, 13, 9);
    $size = 3;
    $needle = 1;

    echo arraySearch($array, $size, $needle) . PHP_EOL;

?>
