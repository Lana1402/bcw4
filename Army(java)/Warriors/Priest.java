package Warriors;

import EnumID.*;
import Basic.*;

public class Priest extends SpellCaster {
    private WarriorID warrior;
    private MagicianID magician;

    public Priest(String name,  int hp, int mana, int dmg) {
        super(name, hp, mana, dmg);
        this.warrior = WarriorID.PRIEST;
        this.magician = MagicianID.CHURCH_WORKER;
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