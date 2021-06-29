package Basic;

import EnumID.*;

public class Attack {
    protected Unit thisUnit;

    public Attack(Unit unit) {
        this.thisUnit = unit;
    }
    
    public void attack(Unit enemy) throws UnitIsDeadException {
        thisUnit.getHealth().ensureIsAlive();
        
        if ( thisUnit.getWarriorID() == WarriorID.VAMPIRE ) {
            enemy.getHealth().takeDamage(thisUnit.getHealth().getDamage());
            enemy.counterAttack(thisUnit);
        
            thisUnit.getHealth().addHitPoints(enemy.getHealth().getHitPoints()/5);
            System.out.println("Vampire Attack!!!");
        } else if ( thisUnit.getWarriorID() == WarriorID.ROGUE ) {
            enemy.getHealth().takeDamage(thisUnit.getHealth().getDamage());
            System.out.println("Rouge Attack!!!");
        } else {
            enemy.getHealth().takeDamage(thisUnit.getHealth().getDamage());
            enemy.counterAttack(thisUnit);
            System.out.println("Soldier Attack!!!");
        }
        
        enemy.notifyObserver();
    }
    public void counterAttack(Unit enemy) throws UnitIsDeadException {
        if ( thisUnit.getHealth().getHitPoints() == 0 ) {
            enemy.notifyObserver();
            return;
        }
        if ( thisUnit.getWarriorID() == WarriorID.VAMPIRE ) {
            enemy.getHealth().takeDamage(thisUnit.getHealth().getDamage()/2);
        
            thisUnit.getHealth().addHitPoints(enemy.getHealth().getHitPoints()/5);
        } else {
            enemy.getHealth().takeDamage(thisUnit.getHealth().getDamage()/2);
        }
    }
}
