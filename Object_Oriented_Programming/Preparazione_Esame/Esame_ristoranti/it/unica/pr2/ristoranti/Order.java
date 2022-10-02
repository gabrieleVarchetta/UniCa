package it.unica.pr2.ristoranti;

import java.util.ArrayList;

public class Order extends ArrayList<String>{

    private double totalCost;

    public Order(double totalCost, String... args) {
        this.totalCost = totalCost;
        for(String s : args)
            add(s);
    }
    
    public int people() {
        return size();
    } 

    public double cost() {
       return totalCost;
    }
}