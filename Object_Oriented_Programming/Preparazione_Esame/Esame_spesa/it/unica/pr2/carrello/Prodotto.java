package it.unica.pr2.carrello;

import java.util.*;

public class Prodotto {
    
    private String product;
    private Double price;
    private static int productsNum = 0;
    private static ArrayList<Prodotto> productsList = new ArrayList<>();

    public Prodotto(String product) {
        this(product, null);
    }

    public Prodotto(String product, Double price) {
        this.product = product;
        this.price = price;
        productsNum++;

        if(price != null)
            productsList.add(this);
    }

    public static int nProdotti() {
        return productsNum;
    } 

    public static HashSet<Prodotto> costaMenoDi(Double target) {
        HashSet<Prodotto> set = new HashSet<>();

        for(Prodotto p : productsList) 
            if(p.prezzo() < target)
                set.add(p);

        return set;
    }

    public Double prezzo() {
        return price;
    }

    public String product() {
        return product;
    }
}