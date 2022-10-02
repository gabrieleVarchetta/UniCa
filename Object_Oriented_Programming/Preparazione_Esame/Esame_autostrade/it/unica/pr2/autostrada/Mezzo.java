package it.unica.pr2.autostrada;

public class Mezzo {
    String colore, targa;

    public Mezzo(String colore, String targa) {
        this.colore = colore;
        this.targa = targa;
    }

    @Override
    public boolean equals(Object o) {
        if(o == null)
            return false;
        
        if(this == o)
            return true;
        
        if(!(o instanceof Mezzo))
            return false;
        
        Mezzo other = (Mezzo) o;

        if(colore.equals(other.colore) && targa.equals(other.targa))
            return true;
        
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;

        hash = hash * 31 + colore.hashCode() + targa.hashCode();
        
        return hash;
    }
}