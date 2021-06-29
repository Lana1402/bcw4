package Magic;

import java.util.*;

public class SpellBook {
    protected Map<String, Spell> spellBook;

    public SpellBook() {
        this.spellBook = new HashMap<>();
        
        this.spellBook.put("Freeze", new Spell(15, 0, 20));
        this.spellBook.put("HellFire", new Spell(30, 0, 55));
        this.spellBook.put("Lightning", new Spell(25, 0, 40));
        this.spellBook.put("AcidMist", new Spell(20, 0, 30));
        this.spellBook.put("Human", new Spell(80, 0, 0));
        this.spellBook.put("Heal", new Spell(20, 0, 60));
        this.spellBook.put("ReturnMagic", new Spell(40, 70, 0));
    }
    
    public Map<String, Spell> getSpellBook() {
        return spellBook;
    }
}
