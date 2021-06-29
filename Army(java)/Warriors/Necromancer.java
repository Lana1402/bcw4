package Warriors;

import EnumID.*;
import Basic.*;
import Magic.*;

public class Necromancer extends SpellCaster implements IObserver {
    private WarriorID warrior;
    private MagicianID magician;
    
    public Necromancer(String name,  int hp, int mana, int dmg) {
        super(name, hp, mana, dmg);
        this.warrior = WarriorID.NECROMANCER;
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
        
    public void update(Unit enemy) throws UnitIsDeadException {
        if ( enemy.getHealth().getHitPoints() == 0 ) {
            this.getHealth().addHitPoints(enemy.getHealth().getHitPointsLimit()/5);
            enemy.detach();
        }
    }

    public void attack(Unit enemy) throws UnitIsDeadException  {
        this.getAttack().attack(enemy);
        enemy.attach(this);
    }

    public void counterAttack(Unit enemy) throws UnitIsDeadException  {
        this.getAttack().counterAttack(enemy);
        enemy.attach(this);
    }

    public void magicAttack(Unit enemy, String spell) throws UnitIsDeadException, MagicManaOffException {
        if ( spell == "Freeze" || spell == "HellFire" || spell == "Lightning" || spell == "AcidMist" ) {
            book.getSpellBook().get(spell).mAttack(enemy, this);
        }
        enemy.attach(this);
    }
    
}