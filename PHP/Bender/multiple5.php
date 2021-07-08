<?php
    $multiple = 5;
    $last = readline();
    
    $last -= $last % $multiple;
    
    for ( $i = 0; $i < $last; $i += $multiple ) {
        echo $i . ' ';
    }
    echo $last . PHP_EOL;
?>
