package classi.classi_abstract;

import eccezioni.*;
import java.util.Arrays;

public abstract class ElementoMultimediale {
    private String title;
    private String format;
    private final String[] validFormats;

    public ElementoMultimediale(String title, String format, String[] validFormats) {
        this.title = title;
        this.format = format;
        this.validFormats = validFormats;

        if(!Arrays.asList(this.validFormats).contains(this.format))
            throw new FormatoNonSupportato("Formato non valido.");
    }

    public String getTitolo() {
        return title;
    }

    public String getFormat() {
        return format;
    }

    public abstract String esegui();
}
