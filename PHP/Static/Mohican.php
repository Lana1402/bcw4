<?php
    class Mohican {
        private $name;
        static private $mohican = null;
        static private $list = array();
        
        private function validateStr($str) {
            if ( is_string($str) ) {
                return $str;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($name) {
            $this->name = $this->validateStr($name);
            array_push(Mohican::$list, $this);
            Mohican::$mohican = end(Mohican::$list);
        }
        
        public function __destruct() {}
        
        public function destruct() {
            foreach ( Mohican::$list as $key => $item ) {
                if ( $item == $this ) {
                    unset(Mohican::$list[$key]);
                }
            }
            Mohican::$mohican = end(Mohican::$list);
        }
        
        public function getName() {
            return $this->name;
        }
        
        static public function getLastMohican() {
            return Mohican::$mohican;
        }
        
        public function __toString() {
            return "Name - " . "'" . $this->name . "'";
        }
    }

    $q = new Mohican("Lana");
    $a = new Mohican("Roma");
    $z = new Mohican("Vova");

    // $q->destruct();
    $a->destruct();
    // $z->destruct();

    echo Mohican::getLastMohican() . PHP_EOL;
?>