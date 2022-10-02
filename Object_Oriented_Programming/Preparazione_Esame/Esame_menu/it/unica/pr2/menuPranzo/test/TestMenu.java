/*
* Due in 50 minutes
* Remember to activate enable assertions: -ea
* Submit as Cognome_Nome_Matricola.zip
*
* */


package it.unica.pr2.menuPranzo.test;

import java.util.*;

import it.unica.pr2.menuPranzo.*; // all your work goes here

public class TestMenu {
    public static void main(String[] args) {

        // 18
        it.unica.pr2.menuPranzo.Menu menuPranzo = Menu.pranzo();
        assert menuPranzo instanceof java.util.List;


        int count = 0;
        for(Pietanza p : menuPranzo) {
            count++;
        }

        // 21
        assert count == 3;

        // 24
        Pietanza a = new Primo("maccheroni", 12); // costo 12 euro
        Pietanza b = new Secondo("bistecca", 15); // costo 15 euro

        assert menuPranzo.get(0).equals(a);
        assert menuPranzo.get(2).equals(b);
        assert menuPranzo.contains(new Primo("riso", 8));

        assert !menuPranzo.get(0).equals(b);
        assert !menuPranzo.get(0).equals(new Primo("maccheroni", 14));

        // 27
        Collections.sort(menuPranzo); // sort by price and then name
        assert menuPranzo.get(0).prezzo() == 8;
        assert menuPranzo.get(1).equals(a);
        assert menuPranzo.get(2).equals(b);

        // 30
        try {
            Pietanza minestra = new Primo("minestra", -5);
            assert false;
            menuPranzo.add(minestra);
        } catch(PrezzoNonValido e) {
            assert true;
            assert e.msg.equals("il prezzo di OGNI PIETANZA non puo essere negativo");
        }
        /**/


    }
}
