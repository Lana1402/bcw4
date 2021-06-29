package Warriors;

import EnumID.*;
import Basic.*;
import State.*;

public class WereWolf extends Unit {
    private WarriorID warrior;
    
    public WereWolf(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.WEREWOLF;
        this.setState(new WereWolfState(this));
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }
}