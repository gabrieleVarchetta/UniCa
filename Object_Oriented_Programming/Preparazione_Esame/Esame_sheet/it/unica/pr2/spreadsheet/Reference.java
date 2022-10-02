package it.unica.pr2.spreadsheet;

public class Reference {

    WorkSheet worksheet;
    Coordinates coordinate;

    public Reference(WorkSheet worksheet, Coordinates coordinate) {
        this.worksheet = worksheet;
        this.coordinate = coordinate;
    }
}