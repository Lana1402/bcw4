package Warriors;

import EnumID.*;
import Basic.*;

public class Rogue extends Unit {
    private WarriorID warrior;
    
    public Rogue(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.ROGUE;
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }
}
