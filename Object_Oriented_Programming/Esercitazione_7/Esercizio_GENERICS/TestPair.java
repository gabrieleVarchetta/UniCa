import it.unica.pr2.pair.*;

import static java.lang.System.out;

public class TestPair {
    public static void main(String[] args) {

        ////// PRIMO STEP: IMPLEMENTAZIONE \\\\\\
        Pair<String, Boolean> myPair = new OrderedPair<>(new String("bello"), true);
        Pair<String, Boolean> myPair2 = new OrderedPair<>("insignificante", false);
        Pair<String, String> myPair3 = new OrderedPair<>("ciao", "hello");
        OrderedPair<String, Boolean> myPair4 = new OrderedPair<String, Boolean>("bello", true);

        assert myPair.getFirst().equals(new String("be"+"l"+"lo"));
        assert myPair.getSecond() == true;

        assert !myPair.getSecond().equals(myPair2.getSecond());

        assert myPair.getFirst().equals(myPair4.getFirst());
        assert myPair.getSecond().equals(myPair4.getSecond());

        ////// SECONDO STEP: SameTypePair \\\\\\
        SameTypePair<String> pairS = new SameTypePair<String>("ciao","hello");
        Pair<String,String> samePair = new SameTypePair<>("ciao","hello");

        ////// TERZO STEP: UnorderedPair \\\\\\
        UnorderedPair c1 = new UnorderedPair("ciao",20);
        UnorderedPair c2 = new UnorderedPair("ciao",20);
        UnorderedPair c3 = new UnorderedPair(20,"ciao");
        UnorderedPair c4 = new UnorderedPair(20,20);

        assert c1.equals(c2);
        assert c1.equals(c3);
        assert !c1.equals(c4);
        
        out.println("Se stai leggendo questo messaggio, il tuo codice ha soddisfatto tutti gli assert.");
    }

}
