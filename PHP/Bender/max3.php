<?php
    $x = readline();
    $y = readline();
    $z = readline();
    
    if ( $x > $y ) {
        $max = $x;
    } else {
        $max = $y;
    }
    
    if ( $max < $z ) {
        $max = $z;
    }
    echo $max . PHP_EOL;
?>
