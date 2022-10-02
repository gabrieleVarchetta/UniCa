package it.unica.pr2.corrente;

import java.util.HashMap;

public class InputDevice extends Device {

    HashMap<InputDevice, OutputDevice> map = new HashMap<>();
    static int totalWAtt;

    public InputDevice(int watt) {
        super(watt);
    }

    public boolean isOn() {
        if(map.containsKey(this))
            return map.get(this).isOn;
        
        return false;
    }

    public void connectTo(OutputDevice output) {
        totalWAtt += this.watt;

        if(output.isOn)
            if(totalWAtt > output.watt) {
                output.setToOn(false);
                throw new SaltataLaCorrente("palle");
            }

        map.put(this, output);
        output.setDevices(map);
    }
}