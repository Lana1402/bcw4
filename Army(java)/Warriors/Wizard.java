package Warriors;

import EnumID.*;
import Basic.*;

public class Wizard extends SpellCaster {
    private WarriorID warrior;
    private MagicianID magician;

    public Wizard(String name,  int hp, int mana, int dmg) {
        super(name, hp, mana, dmg);
        this.warrior = WarriorID.WIZARD;
        this.magician = MagicianID.SORCERER;
    }

    public WarriorID getWarriorID() {
        return warrior;
    }

    public void setWarriorID(WarriorID newID) {
        warrior = newID;
    }

    public MagicianID getMagicianID() {
        return magician;
    }
}
