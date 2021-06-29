package State;

import Basic.*;

public interface State {
    public void printState();
    public void changeUnit(Unit enemy) throws UnitIsDeadException;
    public void transformTo() throws UnitIsDeadException;
}
