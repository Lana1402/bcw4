<?php
    class Gun {
        private $amount;
        private $capacity;
        private $isReady;
        private $model;
        private $totalShots;
        
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
        
        public function __construct($model="Beretta", $capacity=8) {
            $this->model = $this->validateStr($model);
            $this->amount = 0;
            $this->capacity = $this->validate($capacity);
            $this->totalShots = 0;
            $this->isReady = false;
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function ready() {
            return $this->isReady;
        }
        
        public function prepare() {
            $this->isReady = !$this->isReady;
        }
        
        public function reload() {
            $this->amount = $this->capacity;
        }
        
        public function shoot() {
            if (!$this->ready()) {
                throw new Exception("Not ready!!!");
            }
            
            if ( $this->amount == 0 ) {
                throw new Exception("Out of rounds");
            }
            
            echo "Bang!" . PHP_EOL;
            
            $this->amount -= 1;
            $this->totalShots += 1;
        }
        
        public function __toString() {
            return "Model - " . "'" . $this->model . "'" . 
                    "\nCapacity\t" . $this->capacity . 
                    "\nAmount\t\t" . $this->amount . 
                    "\nTotal shots\t" . $this->totalShots;
        }
    }

    // $gun = new Gun("Revolver", 6);
    $gun = new Gun();

    echo $gun . PHP_EOL;
    echo " " . PHP_EOL;

    $gun->reload();
    $gun->prepare();

    echo $gun . PHP_EOL;
    echo " " . PHP_EOL;
    
    for ( $i = 0; $i < 6; $i++ ) {
        $gun->shoot();
    }

    echo " " . PHP_EOL;

    try {
        $gun->shoot(); 
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }

    echo $gun . PHP_EOL;
?>
