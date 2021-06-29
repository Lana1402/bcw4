import Basic.*;
import State.*;
import Warriors.*;
import Magic.Spell;
import Warriors.*;

public class UnitMain {
    public static void main(String[] args) throws UnitIsDeadException, MagicManaOffException  {
        Vampire barbarian = new Vampire("Barbarian", 200, 20);
        WereWolf knight = new WereWolf("Knight", 180, 30);
        Wizard wiz = new Wizard("Wiz", 60, 100, 25);
        Warlock war = new Warlock("War", 60, 300, 10);
        Necromancer nec = new Necromancer("Nec", 100, 300, 15);

        //Spell - ["Freeze", "HellFire", "Lightning", "AcidMist", "Human", "Heal"]
        
        // barbarian.printUnit();
        // System.out.print("\n");
        // knight.printUnit();
        // System.out.print("\n");
        // wiz.printMagician();
        nec.printMagician();
        // System.out.print("\n");

        // barbarian.transform(knight);
        // knight.swichTo();
        // barbarian.attack(wiz);
        wiz.magicAttack(nec, "HellFire");
        nec.magicAttack(war, "HellFire");
        nec.magicAttack(wiz, "HellFire");
        // nec.magicAttack(wiz, "HellFire");
        barbarian.attack(wiz);
        barbarian.attack(war);
        // wiz.magicAttack(barbarian, "HellFire");
        // System.out.print("\n");
        // war.summonDemon();

        // knight.printUnit();
        // System.out.print("\n");
        // barbarian.printUnit();

         // wiz.healHealth(barbarian, "Human");

        // for ( int i = 0; i < 7; i++ ) {
        //     knight.attack(barbarian);
        //     System.out.println("Attack");
        //     System.out.print("\n");
        // }
        
        // try {
        //     knight.attack(barbarian);
        // } catch (UnitIsDeadException e) {
        //     System.out.println("Unit Is Dead");
        //     System.out.print("\n");
        // }
        
        // barbarian.printUnit();
        // System.out.print("\n");
        wiz.printMagician();
        // war.demon.printUnit();
        // war.printMagician();
        System.out.print("\n");
        nec.printMagician();
        // knight.printUnit();
        // System.out.print("\n");
    }
}
