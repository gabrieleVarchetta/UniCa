package classi;

import classi.classi_abstract.ElementoMultimediale;
import interfacce.Audio;

public class Canzone extends ElementoMultimediale implements Audio {
    private int durata, volume;

    public Canzone(String title, String format, int durata) {
        super(title, format, new String[]{"MP3", "MIDI", "WAV", "AAC"});
        this.durata = durata;
        volume = 0;
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
    public String esegui() {
        String res = new String();

        for(int i = 0; i < durata; i++) {
            res += getTitolo();
        }
        
        for(int i = 0; i < volume; i++) {
            res += "!";
        }

        return res;
    }

}