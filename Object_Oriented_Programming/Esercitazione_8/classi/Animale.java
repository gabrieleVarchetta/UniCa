package classi;

public class Animale implements Comparable<Animale>{

    String name;

    public Animale(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {

        // Vincolo della riflessività
        if (this == obj) 
            return true;

        // Vincolo su null
        if (obj == null) 
            return false;

        // L'altro oggetto deve essere di classe Persona o di una sua sottoclasse
        if (!(obj instanceof Animale)) 
            return false;

        Animale other = (Animale) obj;

        if(this.name != null )
            if(name.equals(other.name))
                return true;

        return false;
    }

    @Override 
    public String toString() {

        return name;
    }

    @Override
    public int compareTo(Animale a) {

        // vogliamo un ordinamento alfabetico basato sui nomi,
        // ma *decrescente*, quindi invochiamo il compareTo() di a

        return a.name.compareTo(name);
    }
}