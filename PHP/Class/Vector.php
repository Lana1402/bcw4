<?php
    class Vector {
        private $x, $y;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($x=0, $y=0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }
        
        public function len() {
            return hypot($this->x, $this->y);
        }
        
        public function increment(Vector $other) {
            $this->x += $other->x;
            $this->y += $other->y;
        }
        
        public function decrement(Vector $other) {
            $this->x -= $other->x;
            $this->y -= $other->y;
        }
        
        public function sum(Vector $other) {
            $tmp = $this;
        
            $tmp->x += $other->x;
            $tmp->y += $other->y;
            return $tmp;
        }
        
        public function diff(Vector $other) {
            $tmp = $this;
        
            $tmp->x-= $other->x;
            $tmp->y-= $other->y;
            return $tmp;
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }

    function compare($x, $y) {
        if ( $x == $y ) {
            echo $x . " is equal to " . $y . PHP_EOL;
        } else {
            echo $x . " is not equal to " . $y . PHP_EOL;
        }
    }

    function isTheSameInstance($x, $y) {
        if ( $x === $y ) {
            echo $x . " and " . $y . " is references to the same instance" . PHP_EOL;
        } else {
            echo $x . " and " . $y . " is different instances" . PHP_EOL;
        }
    }

    $a = new Vector(2.3, 5);
    $b = new Vector(3, 7);
    $c = new Vector(3, 7);
    $d = $a->sum($c);

    // echo "a: " . $a . PHP_EOL;
    // echo "b: " . $b . PHP_EOL;
    // echo "c: " . $c . PHP_EOL;

    // compare($a, $b);
    // compare($b, $c);


    // isTheSameInstance($a, $b);
    // isTheSameInstance($a, $d);
    
    // $a->increment($d);

    echo $d . PHP_EOL;
?>
