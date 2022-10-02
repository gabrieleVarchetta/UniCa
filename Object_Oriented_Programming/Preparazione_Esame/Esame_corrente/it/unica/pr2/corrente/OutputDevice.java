package it.unica.pr2.corrente;

import java.util.HashMap;
import java.util.ArrayList;

public class OutputDevice extends Device {
    boolean isOn = false;
    ArrayList<InputDevice> inputDevices = new ArrayList<>();
    
    public OutputDevice(int watt) {
        super(watt);
    }

    public void setToOn(boolean status) {
        isOn = status;
    }

    public int wattSupportati() {
        return watt;
    }

    public void setDevices(HashMap<InputDevice, OutputDevice> map) {
        for(InputDevice i : map.keySet())
            inputDevices.add(i);
    }

    public int wattIstantanei() {
       int total = 0;

       if(isOn)
            for(InputDevice i : inputDevices)
                total += i.watt;

        return total;
    }
}