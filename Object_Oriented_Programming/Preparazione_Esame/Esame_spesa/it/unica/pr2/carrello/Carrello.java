package it.unica.pr2.carrello;

import java.util.*;
import java.io.*;

public class Carrello extends HashMap<Prodotto, Double> {

    public void aggiungi(Prodotto product, Double kg) {

        if(product.prezzo() != null)
            super.put(product, kg);
        else
            throw new PrezzoSconosciutoException("palle");
    }

    public Double costo() {
        Double cost = 0.0;

        for(Prodotto p : super.keySet()) {
            cost += p.prezzo() * super.get(p);
        }
        
        return cost;
    }

    @Override
    public String toString() {
        String result = new String();

        for(Prodotto p : super.keySet()) {
            result += super.get(p) + " " + p.product() + " " + p.prezzo() + "\n";
        }

        return result;
    }

    public void salvaSuFile(String name){

        try(PrintWriter out = new PrintWriter(name)){
            out.print(this.toString());

        } catch(FileNotFoundException e) {
            System.out.println("Sei sveglio");
        }
    }
}