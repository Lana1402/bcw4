<?php
    function arrayCopy(&$destination, $source, $size) {
        $destination = array_slice($source, 0, $size);
    }

    $destination = array();
    $source = array(1, 4, 6, 11);
    $size = 3;

    arrayCopy($destination, $source, $size);

    print_r($destination);
?>
