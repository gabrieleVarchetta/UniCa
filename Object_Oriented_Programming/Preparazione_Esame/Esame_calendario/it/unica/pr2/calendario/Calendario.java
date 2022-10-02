package it.unica.pr2.calendario;

import java.util.*;

public class Calendario extends HashSet<Appuntamento>{

    public Set<Appuntamento> ricerca(String target) {
        Calendario calendario = new Calendario();

        for(Appuntamento a : this)
            if(a.date.contains(target))
                calendario.add(a);

        return calendario;
    }

    @Override
    public boolean contains(Object o) {
        Appuntamento target = (Appuntamento) o;

        for(Appuntamento a : this)
            if(a.date.equals(target.date) && a.note.equals(target.note))
                return true;
        
        return false;
    }
}