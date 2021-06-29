package Warriors;

import EnumID.*;
import Basic.*;

public class Soldier extends Unit {
    private WarriorID warrior;
    
    public Soldier(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.SOLDIER;
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }
}
