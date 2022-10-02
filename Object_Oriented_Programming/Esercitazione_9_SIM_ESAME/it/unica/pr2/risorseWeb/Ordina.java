package it.unica.pr2.risorseWeb;

import java.util.List;
import java.util.Set;
import java.util.Comparator;
import java.util.ArrayList;

public class Ordina {

    public static List<RisorsaWeb> perCriterioUtente(Set<RisorsaWeb> s, Comparator<RisorsaWeb> criterio) {

        List<RisorsaWeb> list = new ArrayList<>(s);

        list.sort(criterio);

        return list;
    }

    public static List<RisorsaWeb> perLunghezzaContenuto(Set<RisorsaWeb> s) {

        List<RisorsaWeb> list = new ArrayList<>(s);

        list.sort(new Comparator<RisorsaWeb>() {
            public int compare(RisorsaWeb a, RisorsaWeb b) {
                return a.getContenuto().length() - b.getContenuto().length();
            }
        });

        return list;
    }
}