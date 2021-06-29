package Basic;

import EnumID.*;
import State.*;

public abstract class Unit {
    private String name;
    protected Health uHealth;
    protected Attack uAttack;
    protected State uState;
    protected IObserver observer;

    public Unit(String name, int hp, int dmg) {
        this.uHealth =  new Health(hp, dmg);
        this.uAttack = new Attack(this);
        this.name = name;
        this.uState = new SoldierState(this);
        this.observer = null;
    }

    public abstract WarriorID getWarriorID();
    public abstract void setWarriorID(WarriorID newID);

    public String getName() {
        return name;
    }

    public Health getHealth() {
        return uHealth;
    }

    public State getState() {
        return uState;
    }

    public Attack getAttack() {
        return uAttack;
    }

    public void setState(State state) {
        uState = state;
    }

    public void attach(IObserver newObserver) {
        System.out.println("attach");
        observer = newObserver;
    }

    public void detach() {
        observer = null;
    }

    public void notifyObserver() throws UnitIsDeadException {
        if ( observer != null ) {
            observer.update(this);
        }
    }
    
    public void transform(Unit enemy) throws UnitIsDeadException {
        uState.changeUnit(enemy);
    }

    public void swichTo() throws UnitIsDeadException {
        uState.transformTo();
    }
    
    public void attack(Unit enemy) throws UnitIsDeadException  {
        uAttack.attack(enemy);
    }

    public void counterAttack(Unit enemy) throws UnitIsDeadException  {
        uAttack.counterAttack(enemy);
    }

    public void printUnit() {
        System.out.println("Name \t" + " " + name);
        getState().printState();
        getHealth().printHealth();
    }
}
