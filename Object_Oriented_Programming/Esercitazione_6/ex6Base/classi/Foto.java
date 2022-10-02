package classi;

import classi.classi_abstract.ElementoMultimediale;
import interfacce.Immagine;

public class Foto extends ElementoMultimediale implements Immagine {
    private int brightness;

    public Foto (String title, String format) {
        super(title, format, new String[]{"JPG", "PNG", "JPEG", "TIFF"});
        brightness = 0;
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
        String res = getTitolo();

        for(int i = 0; i < brightness; i++) {
            res += "*";
        }

        return res;
    }

}
