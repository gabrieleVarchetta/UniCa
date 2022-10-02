package it.unica.pr2.corrente;

public class Device {
    int watt;

    public Device(int watt) {
        this.watt = watt;
    }

    public boolean isInput() {
        return this instanceof InputDevice ? true : false;
    }

    public boolean isOutput() {
        return this instanceof OutputDevice ? true : false;
    }
}