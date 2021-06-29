package State;
import Basic.*;
import EnumID.*;

public class WereWolfState implements State {
    protected Unit thisUnit;

    public WereWolfState(Unit unit) {
        this.thisUnit = unit;
    }

    public void printState() {
        System.out.println("\tI'm WereWolf!!!");
    }

    public void changeUnit(Unit enemy) throws UnitIsDeadException {
        thisUnit.getHealth().ensureIsAlive();
        enemy.getHealth().ensureIsAlive();
        
        if ( enemy.getWarriorID() == WarriorID.VAMPIRE || enemy.getWarriorID() == WarriorID.WEREWOLF || enemy.getWarriorID() == WarriorID.WOLF || enemy.getWarriorID() == WarriorID.DEMON ) {
            System.out.println("Error!!!");
            return;
        }

        enemy.setState(new WereWolfState(enemy));
        
        enemy.setWarriorID(WarriorID.WEREWOLF);
        enemy.getHealth().setDamage(thisUnit.getHealth().getDamage());
        enemy.getHealth().setHitPoints(thisUnit.getHealth().getHitPointsLimit());
        enemy.getHealth().setHitPointsLimit(thisUnit.getHealth().getHitPointsLimit());
    }

    public void transformTo() throws UnitIsDeadException {
        thisUnit.getHealth().ensureIsAlive();
        
        thisUnit.setState(new WolfState(thisUnit));
        
        thisUnit.setWarriorID(WarriorID.WOLF);
        thisUnit.getHealth().setDamage(thisUnit.getHealth().getDamage()*2);
        thisUnit.getHealth().setHitPoints(thisUnit.getHealth().getHitPoints()*2);
        thisUnit.getHealth().setHitPointsLimit(thisUnit.getHealth().getHitPointsLimit()*2);
    }
}
