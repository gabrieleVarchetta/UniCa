package it.unica.pr2.lavori;

public class Lavoratore {
    
    protected String firstName, lastName;
    protected double dailyWage;

    public Lavoratore(String firstName, String lastName, double dailyWage) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.dailyWage = dailyWage;
    }

    public double stipendioSettimanale() {
        return dailyWage * 7;
    }

    @Override
    public String toString() {
        return firstName + " " + lastName  + ": guadagna " + dailyWage;
    }

    @Override
    public boolean equals(Object o) {
        if(this == o)
            return true;
        
        if(o == null)
            return false;
        
        if(!(o instanceof Lavoratore))
            return false;
        
        Lavoratore other = (Lavoratore) o;

        if(firstName.equals(other.firstName) && lastName.equals(other.lastName) && dailyWage == other.dailyWage)
            return true;
        
        return false;
    }
}