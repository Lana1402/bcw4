<?php
    function arrayReverse(&$array, $size) {
    for ( $i = 0, $j = $size - 1; $i < $j; $i++, $j-- ) {
        $tmp = $array[$i];
        
        $array[$i] = $array[$j];
        $array[$j] = $tmp;
    }
}

    $array = array(11, 13, 9, 0);
    $size = 4;

    arrayReverse($array, $size);

    print_r($array);

?>
