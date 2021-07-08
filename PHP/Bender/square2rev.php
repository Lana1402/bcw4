<?php
    $size = readline();
    
    $start = $size * $size - ($size - 1);
    
    for ( $row = 1, $end = $start; $row <= $size; $row++ ) {
        for ( $col = 1; $col < $size; $col++ ) {
            echo $end . ' ';
            $end += 1;
        }
        echo $end . PHP_EOL;
        $end = $start - $size * $row;
    }
?>
