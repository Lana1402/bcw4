package Basic;

public class MagicPower {
    protected int mana;
    protected int manaLimit;
    
    public MagicPower(int mana) {
        this.mana = mana;
        this.manaLimit = mana;
    }
        
    public void ensureHaveIsMana() throws MagicManaOffException {
        if ( mana == 0 ) {
            throw new MagicManaOffException();
        }
    }

    public int getMana() {
        return mana;
    }

    public int getManaLimit() {
        return manaLimit;
    }
        
    public void addMana(int newMana) throws MagicManaOffException {
        ensureHaveIsMana();
        
        if ( newMana <= (manaLimit - mana) ) {
            mana += newMana;
        } else {
            mana = manaLimit;
        }
    } 

    public void takeMana(int cost) throws MagicManaOffException {
        ensureHaveIsMana();
        
        mana -= cost;
        
        if ( mana < 0 ) {
            mana = 0;
        }
    }

    public void printPower() {
        System.out.println("Mana\t\t" + " " + mana);
        System.out.println("Mana limit\t" + " " + manaLimit);
    }
}
