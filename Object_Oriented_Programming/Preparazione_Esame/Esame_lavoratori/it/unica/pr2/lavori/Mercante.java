package it.unica.pr2.lavori;

public class Mercante extends Lavoratore {

    private String sedeMercato;
    private int numOfProducts;
    private int selledProduct;

    public Mercante(String firstName, String lastName, double dailyWage, String sedeMercato, int numOfProducts) {
        super(firstName, lastName, dailyWage);
        this.sedeMercato = sedeMercato;
        this.numOfProducts = numOfProducts;
        selledProduct = 0;
    }

    public int merciVendute() {
        return selledProduct;
    }

    public void vendiFragole(int arg) {
        selledProduct += arg;

        if(selledProduct > numOfProducts)
            throw new TroppiProdottiVendutiException("palle");
    }

    public void vendiAsparagi(int arg) {
        selledProduct += arg;

         if(selledProduct > numOfProducts)
            throw new TroppiProdottiVendutiException("palle");
    }

    @Override
    public String toString() {
        return firstName + " " + lastName  + ": guadagna " + dailyWage + " nel mercato di " + sedeMercato + ", ha " + numOfProducts + " prodotti";
    }
}