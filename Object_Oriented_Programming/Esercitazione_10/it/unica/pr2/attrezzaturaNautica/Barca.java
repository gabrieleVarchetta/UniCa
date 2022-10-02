package it.unica.pr2.attrezzaturaNautica;

import java.util.HashSet;

public class Barca extends HashSet<AttrezzaturaNautica> {

    private Timone timone;

    public void setTimone(Timone timone) {

        if(this.timone != null)
            clear();
            
        this.timone = timone;

        add(this.timone);
    }

    public int direzioneAttuale() {
        if(timone != null)
            return timone.getDirection();
        
        return 0;
    }
}