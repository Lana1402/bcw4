<?php
    class Identifiable {
        private static $globalId = 0;
        private $id;
        
        public function __construct() {
            $this->id = Identifiable::$globalId;
            Identifiable::$globalId += 1;
        }
        
        public function __destruct() {}
        
        public function getID() {
            return $this->id;
        }
    }

    $q = new Identifiable();
    $a = new Identifiable();
    $z = new Identifiable();

    echo "q: " . $q->getID() . PHP_EOL;
    echo "a: " . $a->getID() . PHP_EOL;
    echo "z: " . $z->getID() . PHP_EOL;
?>