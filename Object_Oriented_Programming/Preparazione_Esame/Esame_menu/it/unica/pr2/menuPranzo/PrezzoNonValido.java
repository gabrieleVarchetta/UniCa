package it.unica.pr2.menuPranzo;

public class PrezzoNonValido extends RuntimeException {
    public String msg;

    public PrezzoNonValido(String errMsg) {
        super(errMsg);
        msg = errMsg;
    }
}