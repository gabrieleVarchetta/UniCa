package it.unica.pr2.ristoranti;

import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

public class Ristorante {
    private String name;
    private int seatsNum;
    private Menu menu;
    private static int numeroRistoranti = 0;
    private static int totalePosti = 0;
    private int freeSeats;

    public Ristorante(String name, int seatsNum, Menu menu) {
        this.name = name;
        this.seatsNum = seatsNum;
        this.menu = menu;
        numeroRistoranti++;
        totalePosti += seatsNum;
        freeSeats = seatsNum;
    }

    public static int numeroRistoranti() {
        return numeroRistoranti;
    }

    public static int totalePosti() {
        return totalePosti;
    }

    public int posti() {
        return seatsNum;
    }

    public Menu menu() {
        return menu;
    }

    public String mostExpensive() {
        Double max = 0.0;
        String temp = new String();

        for(Map.Entry<String, Double> entry : menu.entrySet()) {

            if(max < entry.getValue()) {
                max = entry.getValue();
                temp = entry.getKey();
            }
        }

        return temp;
    }

    public boolean isInTheMenu(String param) {
        return menu.containsKey(param);
    }

    public Order order(String... args) {
        double cost = 0.0;

        freeSeats -= args.length;

        if(freeSeats < 0)
            throw new TooMuchPeopleException("posti esauriti");
        
        for(String s : args) 
            cost += menu.get(s);
        
        return new Order(cost, args);
    }
}