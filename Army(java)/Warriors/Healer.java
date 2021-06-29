package Warriors;

import EnumID.*;
import Basic.*;

public class Healer extends SpellCaster {
    private WarriorID warrior;
    private MagicianID magician;

    public Healer(String name,  int hp, int mana, int dmg) {
        super(name, hp, mana, dmg);
        this.warrior = WarriorID.HEALER;
        this.magician = MagicianID.HEALING;
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