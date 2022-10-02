package it.unica.pr2.risorseWeb;

import java.util.ArrayList;
import java.util.Set;
import java.util.Comparator;

public class Ordina {

    public static ArrayList<RisorsaWeb> perCriterioUtente(Set<RisorsaWeb> set, Comparator<RisorsaWeb> comp) {
        ArrayList<RisorsaWeb> list = new ArrayList<>(set);

        list.sort(comp);

        return list;
    } 

    public static ArrayList<RisorsaWeb> perLunghezzaContenuto(Set<RisorsaWeb> set) {
        ArrayList<RisorsaWeb> list = new ArrayList<>(set);

        list.sort((e1, e2) -> e1.contenuto.length() - e2.contenuto.length());

        return list;
    }
}