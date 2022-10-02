package it.unica.pr2.bricostore;

public class RepartoNonAllargabileException extends RuntimeException {
    String myMessage;

    public RepartoNonAllargabileException(String msg) {
        super(msg);
        myMessage = msg;
    }
}