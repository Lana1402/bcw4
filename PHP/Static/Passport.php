<?php
    class Passport {
        private $name;
        private $lastName;
        private $day;
        private $month;
        private $year;
        
        private static $firtsLetter = 'A';
        private static $secondLetter = 'A';
        private static $number = -1;
        
        private function validate($value) {
            if ( !is_numeric($value) ) {
                throw new Exception("Invalid param");
            }
            return $value;
        }
        
        private function validateStr($str) {
            if ( !is_string($str) ) {
                throw new Exception("Invalid param");
            }
            return $str;
        }
        
        private function validateDate($day, $month, $year) {
            $this->validate($day);
            $this->validate($month);
            $this->validate($year);
            
            if ( $day <= 0 || $month <= 0 || $year <= 0 || $month > 12 ) {
                throw new Exception ("Invalid Date");
            }
            if ( $month == 4 || $month == 6 || $month == 9 || $month == 11 ) {
                if ( $day > 30 ) {
                    throw new Exception ("Invalid Date");
                } else if ( $day > 31 ) {
                    throw new Exception ("Invalid Date");
                }
            }
            if ( ($year % 4 == 0 && $year % 100 != 0) || $year % 400 == 0 ) {
                if ( $month == 2 && $day > 29 ) {
                    throw new Exception ("Invalid Date");
                }
            } else if ( $month == 2 ) {
                if ( $day > 28 ) {
                    throw new Exception ("Invalid Date");
                }
            }
        }
        
        private function correctSeries() {
            if ( Passport::$firtsLetter == 'Z' && Passport::$secondLetter == 'Z' && Passport::$number >= 999999 ) {
                throw new Exception ("Is Done");
            }
            if ( Passport::$number >= 999999 ) {
                Passport::$secondLetter = chr(ord(Passport::$secondLetter) + 1);
                Passport::$number = -1;
            }
            if ( Passport::$secondLetter >= 'Z' ) {
                Passport::$firtsLetter = chr(ord(Passport::$firtsLetter) + 1);
                Passport::$secondLetter = 'A';
                Passport::$number = -1;
            }
        }
        
        private static function validateSeries($firtsLetter, $secondLetter) {
            if ( !ctype_alpha($firtsLetter) || !ctype_alpha($secondLetter) ) {
                throw new Exception ("Invalid Series");
            }
            
            if ( !ctype_upper($firtsLetter) || !ctype_upper($secondLetter) ) {
                throw new Exception ("Invalid Series");
            }
        }
        
        private static function validateNumber($number) {
            Passport::validate($number);
            
            if ( $number < 0 || $number > 999999 ) {
                throw new Exception ("Invalid Number");
            }
        }
        
        public function __construct($name, $lastName, $day, $month, $year) {
            $this->validateDate($day, $month, $year);
            $this->correctSeries();
            
            $this->name = $this->validateStr($name);
            $this->lastName = $this->validateStr($lastName);
            $this->day = $day;
            $this->month = $month;
            $this->year = $year;
            Passport::$number += 1;
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public static function getFirtLetter() {
            return Passport::$firtsLetter;
        }
        
        public static function getSecondLetter() {
            return Passport::$secondLetter;
        }
        
        public static function getNumber() {
            return Passport::$number;
        }
        
        public static function setSeries($firtsLetter, $secondLetter, $number = 0) {
            Passport::validateSeries($firtsLetter, $secondLetter);
            Passport::validateNumber($number);
            
            Passport::$firtsLetter = $firtsLetter;
            Passport::$secondLetter = $secondLetter;
            Passport::$number = $number;
        }
        
        public function __toString() {
            return sprintf("%s%s %'.06d \nName: %s %s \nDate of birth: %d.%'.02d.%d", 
                    Passport::getFirtLetter(), Passport::getSecondLetter(), Passport::getNumber(), 
                    $this->name, $this->lastName, $this->day, $this->month, $this->year);
        }
    }

    $q = new Passport("Lana", "Patuk", 29, 6, 1992);

    echo $q . PHP_EOL;

    // Passport::setSeries('Z', 'Z', 999999);

    echo $q . PHP_EOL;

    $z = new Passport("Roma", "Grach", 15, 7, 1995);

    echo $z . PHP_EOL;

    $r = new Passport("Vova", "Zasuha", 13, 2, 1990);

    echo $r . PHP_EOL;

    $t = new Passport("Andrey", "Kuznecov", 15, 10, 1989);

    Passport::setSeries('D', 'Z', 1000000);

    echo $t . PHP_EOL;

