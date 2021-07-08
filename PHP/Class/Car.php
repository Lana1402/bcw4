<?php
    include 'Point.php';
    
    class Car {
        private $fuelAmount;
        private $fuelCapacity;
        private $fuelConsumption;
        private $location;
        private $model;
        
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
        
        public function __construct($fuelCapacity=60, $fuelConsumption=0.6, $location=null, $model="Audi") {
            $this->fuelAmount = 0;
            $this->fuelCapacity = $this->validate($fuelCapacity);
            $this->fuelConsumption = $this->validate($fuelConsumption);
            if ( $location === null ) {
                $this->location  = new Point(0, 0);
            } else {
                $this->location = $location;
            }
            $this->model = $this->validateStr($model);
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function driveP(Point $destination) {
            $this->fuelAmount += $destination->distance($this->location) * $this->fuelConsumption;
            
            if ( $this->fuelAmount > $this->fuelCapacity ) {
                throw new Exception("Out of fuel");
            }
            
            $this->fuelCapacity -= $this->fuelAmount;
            $this->location = $destination;
        }
        
        public function drive($x, $y) {
            $destination = new Point($this->validate($x), $this->validate($y));
            
            $this->fuelAmount += $destination->distance($this->location) * $this->fuelConsumption;
            
            if ( $this->fuelAmount > $this->fuelCapacity ) {
                throw new Exception("Out of fuel!!!");
            }
            
            $this->fuelCapacity -= $this->fuelAmount;
            $this->location = $destination;
        }
        
        public function refill($fuel) {
            if ( $fuel > $this->fuelAmount ) {
                throw new Exception("To much fuel!!!");
            }
            
            $this->fuelCapacity += $fuel;
        }
        
        public function __toString() {
            return "Model - " . "'" . $this->model . "'" . 
                    "\nLocation\t" . $this->location . 
                    "\nFuel Amount\t " . $this->fuelAmount . 
                    "\nFuel Capacity\t " . $this->fuelCapacity . 
                    "\nFuel Consumption " . $this->fuelConsumption;
        }
    }

    $car1 = new Car();
    $car2 = new Car(12, 0.7, new Point(4, 2), "Volkswagen");

    echo $car1 . PHP_EOL;
    echo " " . PHP_EOL;
    echo $car2 . PHP_EOL;

    $car1->driveP(new Point(4, 4));
    $car2->drive(2, 6);

    echo " " . PHP_EOL;
    echo $car1 . PHP_EOL;
    echo " " . PHP_EOL;
    echo $car2 . PHP_EOL;
    echo " " . PHP_EOL;

    try {
        $car2->drive(20, 6);
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }

    echo " " . PHP_EOL;

    try {
        $car1->refill(5);
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
?>
