package it.unica.pr2.pair;

public class OrderedPair<F,S> implements Pair<F,S> {
    private F firstElement;
    private S secondElement;

    public OrderedPair(F firstElement, S secondElement) {
        this.firstElement = firstElement;
        this.secondElement = secondElement;
    }

    @Override
    public F getFirst() {
        return firstElement;
    }

    @Override 
    public S getSecond() {
        return secondElement;
    }
}