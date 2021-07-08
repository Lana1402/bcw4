<?php
    function arrayScan($in, $limit) {
        $array = explode(' ', fread($in, $limit));
        return count($array);
    }

    $in = fopen("task.in", "r");
    $limit = 99;

    echo arrayScan($in, $limit) . PHP_EOL;

?>
