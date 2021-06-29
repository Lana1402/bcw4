package State;
import Basic.*;

public class SoldierState implements State {
    protected Unit thisUnit;

    public SoldierState(Unit unit) {
        this.thisUnit = unit;
    }

    public void printState() {
        System.out.println("\tI'm Soldier!!!");
    }

    public void changeUnit(Unit enemy) throws UnitIsDeadException {
        System.out.println("No ability!!!");
    }

    public void transformTo() throws UnitIsDeadException {
        System.out.println("No ability!!!");
    }
}
