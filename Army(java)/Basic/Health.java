package Basic;

public class Health {
    protected int damage;
    protected int hitPoints;
    protected int hitPointsLimit;

    public Health(int hp, int dmg) {
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.damage = dmg;
    }
        
    public void ensureIsAlive() throws UnitIsDeadException {
        if ( hitPoints == 0 ) {
            throw new UnitIsDeadException();
        }
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int dmg) {
        damage = dmg;
    }

    public int getHitPoints() {
        return hitPoints;
    }

    public void setHitPoints(int hp) {
        hitPoints = hp;
    }

    public int getHitPointsLimit() {
        return hitPointsLimit;
    }

    public void setHitPointsLimit(int hp) {
        hitPointsLimit = hp;
    }

    public void addHitPoints(int hp) throws UnitIsDeadException {
        ensureIsAlive();
        
        if ( hp <= (hitPointsLimit - hitPoints) ) {
            hitPoints += hp;
        } else {
            hitPoints = hitPointsLimit;
        }
    }

    public void takeDamage(int dmg) throws UnitIsDeadException {
        ensureIsAlive();
        
        hitPoints -= dmg;
        
        if ( hitPoints < 0 ) {
            hitPoints = 0;
        }
    }
    
    public void printHealth() {
        System.out.println("Dagame\t\t" + " " + damage);
        System.out.println("Hit points\t" + " " + hitPoints);
        System.out.println("Hit points limit " + hitPointsLimit);
    }
}
