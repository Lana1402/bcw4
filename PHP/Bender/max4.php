a<?php
    $first = readline();
    $second = readline();
    $third = readline();
    $fourth = readline();
    $max = $first;
    
    if ( $max < $second ) {
        $max = $second;
    }
    if ( $max < $third ) {
        $max = $third;
    }
    if ( $max < $fourth ) {
        $max = $fourth;
    }
    echo $max . PHP_EOL;
?>
