package it.unica.pr2.corrente.devices;

import it.unica.pr2.corrente.OutputDevice;

public class PresaElettrica extends OutputDevice {

    int wattForniti;

    public PresaElettrica(int wattForniti) {
        super(wattForniti);
        this.wattForniti = wattForniti;
    }
}