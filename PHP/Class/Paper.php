<?php
    class Paper {
        private $maxSymbols;
        private $symbols;
        private $content;
        
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
        
        public function __construct($maxSymbols=4096) {
            $this->maxSymbols = $this->validate($maxSymbols);
            $this->symbols = 0;
            $this->content = "";
        }
        
        public function __destruct() {}
        
        public function __get($name) {
            return $this->$name;
        }
        
        public function addContent($message) {
            if ( $this->symbols == $this->maxSymbols ) {
                throw new Exception ("Out of space");
            }
            
            $this->content .= substr($this->validateStr($message), 0, ($this->maxSymbols-$this->symbols));
            $this->symbols = strlen($this->content);
        }
        
        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
?>
