package it.unica.pr2.carrello;

public class PrezzoSconosciutoException extends RuntimeException {

    public PrezzoSconosciutoException(String errMsg) {
        super(errMsg);
    }
}