package State;
import Basic.*;
import EnumID.*;

public class WolfState implements State {
    protected Unit thisUnit;

    public WolfState(Unit unit) {
        this.thisUnit = unit;
    }

    public void printState() {
        System.out.println("\tI'm Wolf!!!");
    }

    public void changeUnit(Unit enemy) throws UnitIsDeadException {
        System.out.println("No ability!!!");
    }

    public void transformTo() throws UnitIsDeadException {
        thisUnit.getHealth().ensureIsAlive();
        
        thisUnit.setState(new WereWolfState(thisUnit));
        
        thisUnit.setWarriorID(WarriorID.WEREWOLF);
        thisUnit.getHealth().setDamage(thisUnit.getHealth().getDamage()/2);
        thisUnit.getHealth().setHitPoints(thisUnit.getHealth().getHitPoints()/2);
        thisUnit.getHealth().setHitPointsLimit(thisUnit.getHealth().getHitPointsLimit()/2);
    }
}
