<?php
    $limit = readline();
    
    for ( $row = 1; $row <= $limit; $row++ ) {
        for ( $col = 1; $col < $limit; $col++ ) {
            echo $col . ' ';
        }
        echo $limit . PHP_EOL;
    }
?>
