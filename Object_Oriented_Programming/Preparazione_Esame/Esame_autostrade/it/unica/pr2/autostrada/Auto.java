package it.unica.pr2.autostrada;

public class Auto extends Mezzo {

    String autostrada;

    public Auto(String colore, String targa) {
        super(colore, targa);
        autostrada = null;
    }

    public String targa() {
        return super.targa;
    }
}