package it.unica.pr2.zelando;

public class Gonna extends ProdottoDonna{
    private String size;

    public Gonna(String size, String description, double price) {
        super(description, price);
        this.size = size;
    }
}