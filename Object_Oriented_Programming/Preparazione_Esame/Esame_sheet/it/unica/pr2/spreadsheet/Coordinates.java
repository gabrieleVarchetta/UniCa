package it.unica.pr2.spreadsheet;

public class Coordinates {
    String coordinate;

    public Coordinates(String coordinate) {
        this.coordinate = coordinate;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        
        if(obj == null)
            return false;

        if(!(obj instanceof Coordinates))
            return false;
        
        Coordinates other = (Coordinates) obj;

        if(coordinate.equals(other.coordinate))
            return true;

        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;

        hash = hash * 31 + coordinate.hashCode();

        return hash;
    }
}