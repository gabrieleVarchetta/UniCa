package it.unica.pr2.menuCena;

public class NomePietanzaNonValido extends RuntimeException {
    String msg;

    public NomePietanzaNonValido(String errMsg) {
        super(errMsg);
        msg = errMsg;
    }   
}