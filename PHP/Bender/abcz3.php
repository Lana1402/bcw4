a<?php
    $a = readline();
    $b = readline();
    $c = readline();
    
    $sum = $a + $b;
    $diff = $b - $c;
    
    if ( $sum > $c ) {
        echo "alpha" . PHP_EOL;
    } else if ( $a < $diff ) {
        echo "bravo" . PHP_EOL;
    } else if ( $b % $c == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>
