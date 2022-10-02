package it.unica.pr2.calendario;

public class Appuntamento implements Comparable<Appuntamento>{
    String date, note;

    public Appuntamento(String date, String note) {
        this.date = date;
        this.note = note;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        
        if(obj == null) 
            return false;

        if(!(obj instanceof Appuntamento))
            return false;
        
        Appuntamento other = (Appuntamento)obj;

        if(date.equals(other.date) && note.equals(other.note))
            return true;

        return false;
    }

    @Override
    public int compareTo(Appuntamento app) {
        if(app.date.compareTo(date) == 0)   
            return note.compareTo(app.note);
        
        return app.date.compareTo(date);
    }
}