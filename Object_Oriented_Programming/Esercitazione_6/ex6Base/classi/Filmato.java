package classi;

import classi.classi_abstract.ElementoMultimediale;
import interfacce.*;

public class Filmato extends ElementoMultimediale implements Audio, Immagine {
    int durata, volume, brightness;

    public Filmato(String title, String format, int durata) {
        super(title, format, new String[]{"MP4", "WEBM", "AVI", "FLV"});
        this.durata = durata;
    }

    public int getDurata() {
        return durata;
    }

    public int getVolume() {
        return volume;
    }

    @Override
    public void louder() {
        if(volume < maxVolume)
            volume++;
        else
            System.out.println("Volume al massimo");
    }

    @Override
	public void weaker() {
        if(volume > 0)
            volume--;
        else
            System.out.println("Volume al minimo");
    }
    
    @Override
    public void brighter() {
        if(brightness < maxLuminosita)
            brightness++;
        else
            System.out.println("Luminosità al massimo");
    }

    @Override
	public void darker() {
        if(brightness > 0)
            brightness--;
        else
            System.out.println("Luminosità al minimo");
    }

    @Override
    public String esegui() {
        String res = new String();

        for(int i = 0; i < durata; i++) {
            res += getTitolo();
        }
        
        for(int i = 0; i < volume; i++) {
            res += "!";
        }

        for(int i = 0; i < volume; i++) {
            res += "*";
        }

        return res;
    }
}