package it.unica.pr2.attrezzaturaNautica;

public class Timone extends AttrezzaturaNautica{
    private int direction;

    // static così sono uniche per tutti gli oggetti di tipo Timone
    public static int direzioniCambiate = 0, totaleTimoni = 0;

    public Timone(int direction) {
        this.direction = direction;
        totaleTimoni++;
    }

    public int getDirection() {
        return direction;
    }

    public void imposta(int direction) {
        if(direction < 0 || direction > 360)
            throw new DirezioneNonValidaException(direction);

        this.direction = direction;
        direzioniCambiate++;
    }

    @Override
    public boolean equals(Object obj) {
       // Vincolo della riflessività
        if (this == obj) return true;

        // Vincolo su null
        if (obj == null) return false;

        // L'altro oggetto deve essere di classe Timone o di una sua sottoclasse
        if (!(obj instanceof Timone)) return false;

        // Se siamo qui, sappiamo che obj è un RisorsaWeb e possiamo fare il cast
        Timone other = (Timone) obj;

        if(getDirection() == other.getDirection())
            return true;

        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;

        hash = 31 * hash + direction;

        return hash;
    }

    @Override
    public String toString() {

        String app = "";

        switch(getDirection()) {
            case 0: app = " NORD";
                break;
            
            case 90: app = " EST";
                break;
            
            case 180: app = " SUD";
                break;
            
            case 270: app = " OVEST";
                break;
        }

        return direction + app;
    }
}