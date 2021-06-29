package State;
import Basic.*;
import EnumID.*;

public class VampireState implements State {
    protected Unit thisUnit;

    public VampireState(Unit unit) {
        this.thisUnit = unit;
    }

    public void printState() {
        System.out.println("\tI'm Vampire!!!");
    }

    public void changeUnit(Unit enemy) throws UnitIsDeadException {
        thisUnit.getHealth().ensureIsAlive();
        enemy.getHealth().ensureIsAlive();
        
        if ( enemy.getWarriorID() == WarriorID.VAMPIRE || enemy.getWarriorID() == WarriorID.WEREWOLF || enemy.getWarriorID() == WarriorID.WOLF || enemy.getWarriorID() == WarriorID.DEMON ) {
            System.out.println("Error!!!");
            return;
        }
        
        enemy.setState(new VampireState(enemy));
        
        enemy.setWarriorID(WarriorID.VAMPIRE);
        enemy.getHealth().setDamage(thisUnit.getHealth().getDamage());
        enemy.getHealth().setHitPoints(thisUnit.getHealth().getHitPointsLimit());
        enemy.getHealth().setHitPointsLimit(thisUnit.getHealth().getHitPointsLimit());
    }

    public void transformTo() throws UnitIsDeadException {
        System.out.println("No ability!!!");
    }
}
