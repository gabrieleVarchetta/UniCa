package it.unica.pr2.zelando;

public class Prodotto {
    private String description;
    private double price;

    public Prodotto(String description, double price) {
        this.description = description;
        this.price = price;
    }

    public String descrizione() {
        return description;
    }

    public double prezzo() {
        return price;
    }
}