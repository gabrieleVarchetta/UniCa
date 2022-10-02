/*
 * Due in 60 minutes
 * Remember to activate enable assertions: -ea
 * Submit as Cognome_Nome_Matricola.zip
 *
 * */


package it.unica.pr2.menuCena;

import java.util.*;


public class TestMenuCena {
    public static void main(String[] args) {

        // 19
        MenuCena menuCena = MenuCena.menu;
        assert menuCena instanceof java.util.HashMap;

        it.unica.pr2.menuCena.Menu menu = menuCena;

        // 22 hint: do not override methods

        Set<Pietanza> pietanze = menuCena.keySet();
        assert pietanze.size() == 3;

        // 25  hint: do not override contains;  implement 2 methods
        assert menuCena.containsKey(new Primo("maccheroni"));
        assert menuCena.containsKey(new Secondo("bistecca"));
        assert menuCena.containsKey(new Primo("riso"));


        // 27
        assert menuCena.get(new Object()) == null;
        Integer quindici = Integer.valueOf(15);
        assert quindici.equals(menuCena.get(new Secondo("bistecca")));
        assert menuCena.get(new Primo("maccheroni")).equals(12);
        
        // 30
        try {
            Pietanza piattoVuoto = new Primo("");
            assert false;
        } catch(NomePietanzaNonValido e) {
            assert true;
            assert e.msg.equals("il nome di OGNI PIETANZA non puo' essere null ed avere almeno 2 caratteri");
        }
        /**/

    }
}
