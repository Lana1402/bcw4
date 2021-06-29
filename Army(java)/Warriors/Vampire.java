package Warriors;

import EnumID.*;
import Basic.*;
import State.*;

public class Vampire extends Unit {
    private WarriorID warrior;
    
    public Vampire(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.VAMPIRE;
        this.setState(new VampireState(this));
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }
}
