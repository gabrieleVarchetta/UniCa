package it.unica.pr2.zelando;

public class ScarpaDonna extends ProdottoDonna{
    private int size;

    public ScarpaDonna(int size, String description, double price) {
        super(description, price);
        this.size = size;
    }
}