<?php
    $max = readline();;
    $divisor = readline();
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    $max -= $max % $divisor;
    
    for ( $i = 0; $i < $max; $i += $divisor ) {
        echo $i . ' ';
    }
    echo $max . PHP_EOL;
?>
