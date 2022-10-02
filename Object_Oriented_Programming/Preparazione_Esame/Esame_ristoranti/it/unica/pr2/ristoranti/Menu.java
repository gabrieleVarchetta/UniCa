package it.unica.pr2.ristoranti;

import java.util.HashMap;
import java.util.Map;

public class Menu extends HashMap<String, Double> {

    public Menu() {
        super();
    }

    public String mostExpensive() {
        Double max = 0.0;
        String temp = new String();

        for(Map.Entry<String, Double> entry : super.entrySet()) {

            if(max < entry.getValue()) {
                max = entry.getValue();
                temp = entry.getKey();
            }
        }

        return temp;
    }
}