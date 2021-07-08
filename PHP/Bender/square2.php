<?php
    $size = readline();
    
    for ( $row = 1, $next = 1; $row <= $size; $row++, $next++ ) {
        for ( $col = 1; $col < $size; $col++ ) {
            echo $next . ' ';
            $next += 1;
        }
        echo $next . PHP_EOL;
    }
?>
