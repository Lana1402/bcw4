<?php
    class Count {
        private static $globalQuantity = 0;
        
        public function __construct(){
            Count::$globalQuantity += 1;
        }
        
        public function __destruct() {}
        
        public static function getQuantity() {
            return Count::$globalQuantity;
        }
    }

    $q = new Count();
    $a = new Count();

    echo Count::getQuantity() . PHP_EOL;

    $z = new Count();

    echo Count::getQuantity() . PHP_EOL;
?>