package it.unica.pr2.pair;

public class SameTypePair<F> extends OrderedPair<F,F> {
    public SameTypePair(F first, F second) {
        super(first, second);
    }
}