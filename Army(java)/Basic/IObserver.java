package Basic;

public interface IObserver {
    public void update(Unit enemy) throws UnitIsDeadException;
}
