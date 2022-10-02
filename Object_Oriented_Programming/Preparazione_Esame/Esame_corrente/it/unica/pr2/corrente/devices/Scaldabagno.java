package it.unica.pr2.corrente.devices;

import it.unica.pr2.corrente.InputDevice;

public class Scaldabagno extends InputDevice {

    int wattConsumati;

    public Scaldabagno(int wattConsumati) {
        super(wattConsumati);
        this.wattConsumati = wattConsumati;
    }
}