package it.unica.pr2.bricostore;

import java.util.*;

public class Reparto extends HashSet<Product> {

    String name;
    static ArrayList<Reparto> altriReparti = new ArrayList<>();
    static int count;

    public Reparto(String name) {
        this.name = name;
    }

    public static Reparto falegnameria() {
        Reparto temp = new Reparto("falegnameria");

        temp.add(new Product("portone", 250.0));
        temp.add(new Product("finestra", 170.0));
        count += 2;

        return temp;
    }

    public static Reparto elettricita() {
        Reparto temp = new Reparto("elettricita");

        temp.add(new Product("presa", 10.0));
        count++;

        return temp;
    }

    public static ArrayList<Reparto> altriReparti() {
        ArrayList<Reparto> temp = new ArrayList<>();

        temp.addAll(altriReparti);

        return temp;
    }

    public static boolean addReparto(String name) {
        if(altriReparti.add(new Reparto(name)))
            return true;
        
        return false;
    }

    @Override
    public boolean add(Product p) {
        if(count >= 3)
            throw new RepartoNonAllargabileException("Reparto non modificabile");
        
        return super.add(p);
    }
}