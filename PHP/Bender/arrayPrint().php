<?php
    function arrayPrint($out, $array, $size) {
        $last = $size - 1;
        
        for ( $i = 0; $i < $last; $i++ ) {
            fprintf($out, $array[$i] . ' ');
        }
        fprintf($out, $array[$last] . PHP_EOL);
    }

    $out = fopen("task.out", 'w');

    $array = array(1, 2, 3, 4, 9);
    $size = 5;

    arrayPrint($out, $array, $size);

    fclose($out);

?>
