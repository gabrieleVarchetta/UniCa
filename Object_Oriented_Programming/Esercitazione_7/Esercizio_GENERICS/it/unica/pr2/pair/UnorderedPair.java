package it.unica.pr2.pair;

public class UnorderedPair extends OrderedPair<Object,Object> {
    public UnorderedPair(Object primo, Object secondo) {
        super(primo,secondo);
    }

    @Override
    public boolean equals(Object o) { 
        if(o instanceof UnorderedPair) {
            UnorderedPair otherPair = (UnorderedPair)o;
            return (getFirst().equals(otherPair.getFirst()) && getSecond().equals(otherPair.getSecond())) || (getFirst().equals(otherPair.getSecond()) && getSecond().equals(otherPair.getFirst()));
        }

        return false;
    }
}
