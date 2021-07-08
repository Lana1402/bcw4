<?php
    include 'Paper.php';

    class Pen {
        private $inkAmount;
        private $inkCapacity;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        private function validateStr($str) {
            if ( is_string($str) ) {
                return $str;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($inkCapacity=4096) {
            $this->inkCapacity = $this->validate($inkCapacity);
            $this->inkAmount = $this->validate($inkCapacity);
        }

        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function write(Paper $paper, $message) {
            if ( $this->inkAmount == 0 ) {
                throw new Exception ("Out of ink");
            }
            
            $paper->addContent(substr($this->validateStr($message), 0, $this->inkAmount));
            
            $this->inkAmount -= strLen($message);
            
            if ( $this->inkAmount < 0 ) {
                $this->inkAmount = 0;
            }
        }
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }

    $pen = new Pen(0);
    $pen2 = new Pen(20);
    $paper = new Paper(30);

    try {
        $pen->write($paper, "Hello, world!");
    } catch ( Exception $e ) {
        echo $e->getMessage() . PHP_EOL;
    }

    $pen2->write($paper, " Hello, world!");
    $paper->show();

    echo $pen2->inkAmount . PHP_EOL;
?>
