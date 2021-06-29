#include "Unit.hpp"
#include "IObserver.hpp"

Unit::Unit(const std::string& name,  int hp, int dmg, State* state) 
    : name(name), uHealth(new Health(hp, dmg)), uAttack(new Attack(this))
    , uState(nullptr), observer(nullptr) {
    this->transitionTo(state);
}

Unit::~Unit(){
    delete this->uHealth;
    delete this->uAttack;
    delete this->uState;
}

const std::string& Unit::getName() const {
    return this->name;
}

Health& Unit::getHealth() const {
    return *(this->uHealth);
}

State& Unit::getState() const {
    return *(this->uState);
}

Attack& Unit::getAttack() const {
    return *(this->uAttack);
}

void Unit::transitionTo(State* state) {
    std::cout << getName() << " - transition to " << typeid(*state).name() << std::endl;
    if (this->uState != nullptr) {
        delete this->uState;
    }
    this->uState = state;
    this->uState->setContext(this);
}

void Unit::attach(IObserver* observer) {
    std::cout << "attach" << std::endl;
    this->observer = observer;
}

void Unit::detach() {
    this->observer = nullptr;
}

void Unit::notify() {
    if ( this->observer != nullptr ) {
        this->observer->update(this);
    }
}

void Unit::transform(Unit* enemy) {
    this->uState->changeUnit(enemy);
}

void Unit::swichTo() {
    this->uState->transformTo();
}

void Unit::attack(Unit* enemy) {
    this->uAttack->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->uAttack->counterAttack(enemy);
}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " - " << typeid(unit.getState()).name() << std::endl;
    out << unit.getHealth();

    return out;
}
