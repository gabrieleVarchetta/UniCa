package classi;

public class Persona implements Comparable<Persona>{

    private String firstName, lastName;
    private int birthYear;

    public Persona (String firstName, String lastName, int birthYear) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.birthYear = birthYear;
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
        if (!(obj instanceof Persona)) 
            return false;

        // Se siamo qui, sappiamo che obj è una Persona e possiamo fare il cast
        Persona other = (Persona) obj;

        if(birthYear == other.birthYear)
            return true;

        return false;  
    }

    @Override
    public int compareTo(Persona p) {

        // vogliamo un ordinamento per età,
        // ma *decrescente*, quindi come primo addendo mettiamo l'età di p
        return p.birthYear - birthYear;
    }

    @Override
    public String toString() {
        return firstName;
    }
}