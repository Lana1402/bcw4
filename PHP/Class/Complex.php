<?php
    class Complex {
        private $real, $imaginary;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($real=0, $imaginary=0) {
            $this->real = $this->validate($real);
            $this->imaginary = $this->validate($imaginary);
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }
        
        public function increment(Complex $other) {
            $this->real += $other->real;
            $this->imaginary += $other->imaginary;
        }
        
        public function decrement(Complex $other) {
            $this->real -= $other->real;
            $this->imaginary -= $other->imaginary;
        }
        
        public function sum(Complex $other) {
            $tmp = $this;
        
            $tmp->real += $other->xreal;
            $tmp->imaginary += $other->imaginary;
            return $tmp;
        }
        
        public function diff(Complex $other) {
            $tmp = $this;
        
            $tmp->real-= $other->real;
            $tmp->imaginary-= $other->imaginary;
            return $tmp;
        }
        
        public function multiply(Complex $other) {
            $tmp = $this;
        
            $tmp->real *= $other->real;
            $tmp->imaginary *= $other->imaginary;
            return $tmp;
        }
        
        public function __toString() {
            return sprintf("(%g%+gi)", $this->real, $this->imaginary);
        }
    }

    function compare($real, $imaginary) {
        if ( $real == $imaginary ) {
            echo $real . " is equal to " . $imaginary . PHP_EOL;
        } else {
            echo $real . " is not equal to " . $imaginary . PHP_EOL;
        }
    }

    function isTheSameInstance($real, $imaginary) {
        if ( $real === $imaginary ) {
            echo $real . " and " . $imaginary . " is references to the same instance" . PHP_EOL;
        } else {
            echo $real . " and " . $imaginary . " is different instances" . PHP_EOL;
        }
    }

    $a = new Complex(2.3, -5);
    $b = new Complex(3, 7);
    $c = new Complex(3, 7);
    $d = $a;

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    // echo "c: " . $c . PHP_EOL;

    compare($a, $b);
    // compare($b, $c);


    isTheSameInstance($a, $b);
    // isTheSameInstance($a, $d);
    
    $a->increment($d);

    echo $a . PHP_EOL;
?>
