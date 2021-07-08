<?php
    function arrayExchange(&$array, $len) {
        for ( $i = 0, $j = 1; $j < $len; $i += 2, $j += 2 ) {
            $temp = $array[$i];
            
            $array[$i] = $array[$j];
            $array[$j] = $temp;
        }
    }

    $array = array(11, 13, 9, 0);
    $len = 4;

    arrayExchange($array, $len);

    print_r($array);

?>
