package Magic;

import Basic.Unit;
import Basic.*;
import State.*;
import EnumID.*;

public class Spell {
    protected int manaCost;
    protected int mana;
    protected int hitPoints;

    public Spell(int cost, int mana, int hp) {
        this.manaCost = cost;
        this.mana = mana;
        this.hitPoints = hp;
    }

    public void mAttack(Unit enemy, SpellCaster magician) throws UnitIsDeadException, MagicManaOffException {
        magician.getHealth().ensureIsAlive();
        magician.getMagicPower().ensureHaveIsMana();
        enemy.getHealth().ensureIsAlive();
        
        if ( magician.getMagicPower().getMana() < manaCost) {
            System.out.println("Not enough mana!");
            return;
        }
        
        if ( enemy.getWarriorID() == WarriorID.BERSERKER ) {
            System.out.println("Magic is powerless!");
            return;
        }
        
        if ( magician.getMagicianID() == MagicianID.SORCERER ) {
            enemy.getHealth().takeDamage(hitPoints);
        }
        
        if ( magician.getMagicianID() == MagicianID.HEALING ) {
            enemy.getHealth().takeDamage(hitPoints/2);
        }
        
        if ( magician.getMagicianID() == MagicianID.CHURCH_WORKER ) {
            if ( enemy.getWarriorID() == WarriorID.VAMPIRE || enemy.getWarriorID() == WarriorID.NECROMANCER ) {
                enemy.getHealth().takeDamage(hitPoints);
            } else {
                enemy.getHealth().takeDamage(hitPoints/2);
            }
        }
        
        magician.getMagicPower().takeMana(manaCost);
        
        enemy.notifyObserver();
    }

    public void healHealth(Unit other, SpellCaster magician) throws UnitIsDeadException, MagicManaOffException {
        magician.getHealth().ensureIsAlive();
        
        if ( magician.getMagicPower().getMana() < manaCost) {
            System.out.println("Not enough mana!");
            return;
        }
        
        if ( other.getWarriorID() == WarriorID.BERSERKER || other.getWarriorID() == WarriorID.DEMON ) {
            System.out.println("Magic is powerless!");
            return;
        }
        
        if ( magician.getMagicianID() == MagicianID.HEALING || magician.getMagicianID() == MagicianID.CHURCH_WORKER ) {
            other.getHealth().addHitPoints(hitPoints);
        } else {
            other.getHealth().addHitPoints(hitPoints/2);
        }
        
        magician.getMagicPower().takeMana(manaCost);
    }

    public void healMagic(SpellCaster other, SpellCaster magician) throws UnitIsDeadException, MagicManaOffException {
        magician.getHealth().ensureIsAlive();
        other.getHealth().ensureIsAlive();
        
        if ( magician.getMagicPower().getMana() < manaCost) {
            System.out.println("Not enough mana!");
            return;
        }
        
        if ( magician.getMagicianID() == MagicianID.HEALING || magician.getMagicianID() == MagicianID.CHURCH_WORKER ) {
            other.getMagicPower().addMana(mana);
        } else {
            other.getMagicPower().addMana(mana/2);
        }
        
        magician.getMagicPower().takeMana(manaCost);
    }

    public void backToHuman(Unit enemy, SpellCaster magician) throws UnitIsDeadException, MagicManaOffException {
        magician.getHealth().ensureIsAlive();
        magician.getMagicPower().ensureHaveIsMana();
        enemy.getHealth().ensureIsAlive();
        
        if ( magician.getMagicPower().getMana() < manaCost) {
            System.out.println("Not enough mana!");
            return;
        }
        
        if ( enemy.getWarriorID() == WarriorID.VAMPIRE || enemy.getWarriorID() == WarriorID.WEREWOLF || enemy.getWarriorID() == WarriorID.WOLF ) {
            enemy.setState(new SoldierState(enemy));
        }
        magician.getMagicPower().takeMana(manaCost);
    }
}
