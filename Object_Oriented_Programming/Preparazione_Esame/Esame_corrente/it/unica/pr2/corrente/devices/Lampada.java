package it.unica.pr2.corrente.devices;

import it.unica.pr2.corrente.InputDevice;

public class Lampada extends InputDevice {

    int wattConsumati;

    public Lampada(int wattConsumati) {
        super(wattConsumati);
        this.wattConsumati = wattConsumati;
    }
}