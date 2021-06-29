package Warriors;

import EnumID.*;
import Basic.*;
import State.*;

public class Berserker extends Unit {
    private WarriorID warrior;
    
    public Berserker(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.BERSERKER;
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }
}
