package it.unica.pr2.zelando;

import java.util.*;

public class Carrello extends ArrayList<Prodotto>{

    public Carrello(Prodotto[] prodotti) {
        for(Prodotto p : prodotti)
            super.add(p);
    }

    public double costo() {
        double cost = 0.0;

        for(Object p : super.toArray()) {
            Prodotto temp = (Prodotto) p;
            cost += temp.prezzo();
        }
        
        return cost;
    }

    public int nProdotti() {
        return super.size();
    }

    public int nProdottiUomo() {
        int prodottiUomo = 0;

        for(Object p : super.toArray()) {
            Prodotto temp = (Prodotto) p;

            if(temp instanceof ProdottoUomo)
                prodottiUomo++;
        }

        return prodottiUomo;
    }

    public int nProdottiDonna() {
        int prodottiDonna = 0;

        for(Object p : super.toArray()) {
            Prodotto temp = (Prodotto) p;

            if(temp instanceof ProdottoDonna)
                prodottiDonna++;
        }

        return prodottiDonna;
    }

    public ArrayList<ProdottoDonna> prodottiDonna() {
        ArrayList<ProdottoDonna> prodottiDonna = new ArrayList<>();

        for(Object p : super.toArray()) {
            Prodotto temp = (Prodotto) p;

            if(temp instanceof ProdottoDonna) {
                ProdottoDonna app = (ProdottoDonna) temp;
                prodottiDonna.add(app);
            }
        }

        return prodottiDonna;
    }

    public static Carrello fromList(List<? extends Prodotto> list) {
        Carrello newChart = new Carrello(new Prodotto[]{});

        newChart.addAll(list);

        return newChart;
    }

    public Carrello nProdotti(String query) {
        Carrello result = new Carrello(new Prodotto[]{});

        for(Prodotto p : this) {
            if(match(p.descrizione(),query)) {
                result.add(p);
            }
        }
        
        return result;
    }
   
    private boolean match(String descrizione, String query) {
        for(String q : query.split(" ")) {
            if (!descrizione.contains(q)) {
                return false; 
            }
        }
        
        return true;
    }
}