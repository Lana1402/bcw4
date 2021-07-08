<?php
    $last = readline();
    
    if ( $last % 2 != 0 ) {
        $last -= 1;
    }
    
    for ( $i = 0; $i < $last; $i += 2 ) {
        echo $i . ' ';
    }
    echo $last . PHP_EOL;
?>
