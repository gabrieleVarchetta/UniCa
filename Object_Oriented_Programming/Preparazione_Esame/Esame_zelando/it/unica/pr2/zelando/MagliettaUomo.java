package it.unica.pr2.zelando;

public class MagliettaUomo extends ProdottoUomo{
    private String size;

    public MagliettaUomo(String size, String description, double price) {
        super(description, price);
        this.size = size;
    }
}