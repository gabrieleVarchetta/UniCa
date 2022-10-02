/*
 * consegna in 60 minuti (1h)
 *
 * due in 60 minutes
 * remeber to enable assertion using: -ea (or -enableassertions)
 *
 */

package it.unica.pr2.bricostore;

import java.util.*;

public class TestBrico {
    public static void main(String[] args) {
        // 19
        Reparto r1 = Reparto.falegnameria();
        Reparto r2 = Reparto.elettricita();

        assert r1 instanceof Set;

        // 24
        assert r1.size() == 2; // there are 2 kind of products in falegnameria
        assert r2.size() == 1; // there are 1 kind of products in elettricita

        assert r1.contains(new Product("portone", 250.00)); // Product name and price
                                                                        // HINTS: consider hashcode and equals
        assert r1.contains(new Product("finestra", 170.00));

        assert r2.contains(new Product("presa",10.0));

        assert r2.iterator().next().equals(new Product("presa",10.0));
        assert !r2.iterator().next().equals(new Product("presa",200.0));
        assert !r2.iterator().next().equals(new Product("spina",10.0));

        assert r2 instanceof HashSet;
        // 28

        List<Reparto> rList = Reparto.altriReparti();
        assert rList.size() == 0;
        Reparto.addReparto("idraulica");

        List<Reparto> rList2 = Reparto.altriReparti();
        assert rList2.size() == 1;
        assert rList.size() == 0;

        // 30
        try {
            r1.add(new Product("sedia", 5.0));
            assert false;
        } catch(RepartoNonAllargabileException e) {
            assert true;
            assert e.myMessage.equals("Reparto non modificabile");
        }
        /**/
    }
}

