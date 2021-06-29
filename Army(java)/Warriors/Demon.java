package Warriors;

import EnumID.*;
import Basic.*;
import State.*;

public class Demon extends Soldier {
    private WarriorID warrior;

    public Demon(String name, int hp, int dmg) {
        super(name, hp, dmg);
        this.warrior = WarriorID.DEMON;
    }

    public WarriorID getWarriorID() {
        return warrior;
    }
}
