package it.unica.pr2.hotels;

public class RoomNotFound extends RuntimeException {
    public RoomNotFound(String errMsg) {
        super(errMsg);
    }
}