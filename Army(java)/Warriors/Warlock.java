package Warriors;

import EnumID.*;
import Basic.*;

public class Warlock extends SpellCaster {
    private int demonCost;
    private WarriorID warrior;
    private MagicianID magician;
    public Demon demon;

    public Warlock(String name,  int hp, int mana, int dmg) {
        super(name, hp, mana, dmg);
        this.demonCost = 50;
        this.warrior = WarriorID.WARLOCK;
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

    public void summonDemon() throws MagicManaOffException  {
        this.getMagicPower().ensureHaveIsMana();
        
        if ( this.getMagicPower().getMana() < demonCost ) {
            System.out.println("Not enough mana!");
            return;
        }
        this.demon = new Demon("Demon", 150, 50);
            
        this.getMagicPower().takeMana(demonCost);
    }
}
