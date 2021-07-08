<?php
    class Unit {
        private $dagame;
        private $hitPoints;
        private $hitPointsLimit;
        private $name;
        
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
        
        private function ensureIsAlive() {
            if ( $this->hitPoints == 0 ) {
                throw new Exception("Unit Is Dead");
            }
        }
        
        public function __construct($name, $hp, $dgm) {
            $this->name = $this->validateStr($name);
            $this->hitPoints = $this->validate($hp);
            $this->hitPointsLimit = $this->validate($hp);
            $this->dagame = $this->validate($dgm);
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function addHitPoints($hp) {
            $this->ensureIsAlive();
            
            if ( $this->hp <= ($this->hitPointsLimit - $this->hitPoints) ) {
                $this->hitPoints += $hp;
            }
        }
        
        public function takeDagame($dgm) {
            $this->ensureIsAlive();
            
            $this->hitPoints -= $dgm;
            
            if ( $this->hitPoints < 0 ) {
                $this->hitPoints = 0;
            }
        }
        
        public function attack(Unit $enemy) {
            $this->ensureIsAlive();   
            $enemy->takeDagame($this->dagame);
            $enemy->counterAttack($this);
        }
        
        public function counterAttack(Unit $enemy) {
            $enemy->ensureIsAlive();
            $enemy->takeDagame($this->dagame/2);
        }
        
        public function __toString() {
            return "Name - " . "'" . $this->name . "'" . 
                    "\nDagame\t\t " . $this->dagame . 
                    "\nHit points\t " . $this->hitPoints . 
                    "\nHit points limit " . $this->hitPointsLimit;
        }
    }

    $barbarian = new Unit("Barbarian", 0, 20);
    $knight = new Unit("Knight", 40, 30);

    echo $barbarian . PHP_EOL;
    echo " " . PHP_EOL;
    echo $knight . PHP_EOL;
    echo " " . PHP_EOL;

    try {
        $barbarian->attack($knight);
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }

    echo " " . PHP_EOL;

    echo $barbarian . PHP_EOL;
    echo " " . PHP_EOL;
    echo $knight . PHP_EOL;
    // echo " " . PHP_EOL;

?>
