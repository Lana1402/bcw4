<?php
    $divisible = readline();
    $divisor = readline();
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    
    $multiple = $divisible - ($divisible % $divisor);
    
    if ( $multiple < $divisible ) {
        $multiple += $divisor;
    }
    echo $multiple . PHP_EOL;
?>
