package it.unica.pr2.ristoranti;

public class TooMuchPeopleException extends RuntimeException {
    public TooMuchPeopleException(String errMsg) {
        super(errMsg);
    }
}