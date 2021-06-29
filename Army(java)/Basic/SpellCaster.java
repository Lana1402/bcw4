package Basic;

import EnumID.*;
import State.*;
import Magic.*;

public abstract class SpellCaster extends Unit {
    protected MagicPower magic;
    protected SpellBook book;

    public SpellCaster(String name, int hp, int mana, int dmg){
        super(name, hp, dmg);
        this.magic = new MagicPower(mana);
        this.book = new SpellBook();
    }

    public abstract MagicianID getMagicianID();

    public MagicPower getMagicPower() {
        return magic;
    }

    public SpellBook getSpellBook() {
        return book;
    }

    public void magicAttack(Unit enemy, String spell) throws UnitIsDeadException, MagicManaOffException {
        if ( spell == "Freeze" || spell == "HellFire" || spell == "Lightning" || spell == "AcidMist" ) {           
            book.getSpellBook().get(spell).mAttack(enemy, this);
        }
    }

    public void healHealth(Unit other, String spell) throws UnitIsDeadException, MagicManaOffException {
        if ( spell == "Heal" ) {
            book.getSpellBook().get(spell).healHealth(other, this);
        } else if ( spell == "Human" ) {
            book.getSpellBook().get(spell).backToHuman(other, this);
        } else {
            return;
        }
    }

    public void healMagic(SpellCaster other) throws UnitIsDeadException, MagicManaOffException {
        book.getSpellBook().get("ReturnMagic").healMagic(other, this);
    }

    public void printMagician() {
        this.printUnit();
        getMagicPower().printPower();
    }
}
