package it.unica.pr2.menuPranzo;

import java.lang.*;

public class Pietanza implements Comparable<Pietanza>{

    String name;
    int price;

    public Pietanza(String name, int price) {
        this.name = name;
        if(price > 0)
            this.price = price;
        else
            throw new PrezzoNonValido("il prezzo di OGNI PIETANZA non puo essere negativo");
    }

    public int prezzo() {
        return price;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        
        if(obj == null)
            return false;
        
        if(!(obj instanceof Pietanza))
            return false;

        Pietanza other = (Pietanza) obj;

        if(name.equals(other.name) && price == other.price)
            return true;
        
        return false;
    }

    @Override
    public int compareTo(Pietanza p) {

        if(price == p.price)
            return name.compareTo(p.name);
        
        return price - p.price;
    }
}