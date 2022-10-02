package classi;

public class Gatto extends Animale {

    double tailLength;

    public Gatto(String name, double tailLength) {
        
        super(name);
        this.tailLength = tailLength;
    }

    public double getTaillength() {
        return tailLength;
    }
}