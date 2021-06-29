#include "TextHandler.h"

TextHandler::TextHandler(const char* filename) : filename(filename) {
    this->diff = 'a' - 'A';
    this->characters = new std::set<char>();
    this->charactersStatistics = new std::map<char, int>();
    this->numbers = new std::set<char>();
    this->numbersStatistics = new std::map<char, int>();
    this->specialSymbols = new std::set<char>();
    this->specialSymbolsStatistics = new std::map<char, int>();
    this->words = new std::set<std::string>();
    this->wordsStatistics = new std::map<std::string, int>();
    this->quantitySymbols = 0;
    this->quantityWords = 0;
}

TextHandler::~TextHandler() {
    delete this->characters;
    delete this->charactersStatistics;
    delete this->numbers;
    delete this->numbersStatistics;
    delete this->specialSymbols;
    delete this->specialSymbolsStatistics;
    delete this->words;
    delete this->wordsStatistics;
}

const std::set<char>& TextHandler::getCharacters() const {
    return *(this->characters);
}

const std::map<char, int>& TextHandler::getCharactersStatistics() const {
    return *(this->charactersStatistics);
}

const std::set<char>& TextHandler::getNumbers() const {
    return *(this->numbers);
}

const std::map<char, int>& TextHandler::getNumbersStatistics() const {
    return *(this->numbersStatistics);
}

const std::set<char>& TextHandler::getSpecialSymbols() const {
    return *(this->specialSymbols);
}

const std::map<char, int>& TextHandler::getSpecialSymbolsStatistics() const {
    return *(this->specialSymbolsStatistics);
}

const std::set<std::string>& TextHandler::getWords() const {
    return *(this->words);
}

const std::map<std::string, int>& TextHandler::getWordsStatistics() const {
    return *(this->wordsStatistics);
}

long long TextHandler::getQuantitySymbols() const {
    return this->quantitySymbols;
}

long long TextHandler::getQuantityWords() const {
    return this->quantityWords;
}

void TextHandler::insert(char symbol, std::set<char>* lst) {
    lst->insert(symbol);
}

void TextHandler::insert(char symbol, std::map<char, int>* lst) {
    if ( lst->find(symbol) == lst->end() ) {
        lst->insert(std::pair<char, int>(symbol, 0));
    }
    lst->at(symbol) += 1;
}

void TextHandler::insertWord(std::string word, std::set<std::string>* lst) {
    lst->insert(word);
}

void TextHandler::insertWord(std::string word, std::map<std::string, int>* lst) {
    if ( lst->find(word) == lst->end() ) {
        lst->insert(std::pair<std::string, int>(word, 0));
    }
    lst->at(word) += 1;
}

bool TextHandler::isLetter(char symbol) {
    return ( symbol >= 'A' && symbol <= 'Z' ) || ( symbol >= 'a' && symbol <= 'z' );
}

bool TextHandler::isNumber(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool TextHandler::isSpecial(char symbol) {
    bool special = false;
    
    if ( ( symbol > ' ' && symbol < '0' ) || ( symbol > '9' && symbol < 'A' ) ) {
        special = true;
    }
    if ( ( symbol > 'Z' && symbol < 'a' ) || ( symbol > 'z' && symbol <= '~' ) ) {
        special = true;
    }
    return special;
}

bool TextHandler::isWords(std::string word) {
    bool justAword = true;
    int start = 0;
    
    if ( word[start] == '-' ) {
        justAword = false;
    }

    if ( isNumber(word[start]) ) {
        justAword = false;
    }
    return justAword;
}

void TextHandler::parseText() {
    std::ifstream file(filename);
    char symbol;
    
    for ( ; file.get(symbol) ; ) {
        if ( isLetter(symbol) ) {
            if ( symbol < 'a' ) {
                symbol += this->diff;
            }
            insert(symbol, characters);
            insert(symbol, charactersStatistics);
            quantitySymbols += 1;
        }
        if ( isNumber(symbol) ) {
            insert(symbol, numbers);
            insert(symbol, numbersStatistics);
            quantitySymbols += 1;
        }
        if ( isSpecial(symbol) ) {
            insert(symbol, specialSymbols);
            insert(symbol, specialSymbolsStatistics);
            quantitySymbols += 1;
        }
    }
    file.close();
    addWord();
}

void TextHandler::addWord() {
    std::ifstream file(filename);
    
    for ( std::string word; file >> word; ) {
        for ( int i = 0; word[i] != '\0'; i++ ) {
            if ( word[i] >= 'A' && word[i] <= 'Z' ) {
                word[i] += this->diff;
            }
        }
        if ( isWords(word) ) {
            if ( word[0] == '"') {
                auto iter = word.begin();
                word.erase(iter);
            }
            for ( int i = word.size() - 1; !isLetter(word[i]); i-- ) {
                word.pop_back();
            }
            insertWord(word, words);
            insertWord(word, wordsStatistics);
            quantityWords += 1;
        }
    }
    file.close();
}

std::ostream& operator<<(std::ostream& out, const TextHandler& handler) {
    out << "Symbols found: " << handler.getQuantitySymbols() << std::endl;
    out << "Letters statistic:" << std::endl;
    out << "Unique: " << handler.getCharacters() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getCharactersStatistics() << std::endl;
    
    out << "Numbers statistic:" << std::endl;
    out << "Unique: " << handler.getNumbers() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getNumbersStatistics() << std::endl;
    
    out << "Special symbols statistic:" << std::endl;
    out << "Unique: " << handler.getSpecialSymbols() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getSpecialSymbolsStatistics() << std::endl;
    
    out << "Words found: " << handler.getQuantityWords() << std::endl;
    out << "Words statistic:" << std::endl;
    out << "Unique: " << handler.getWords() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getWordsStatistics() << std::endl;
    
    return out;
}
