package it.unica.pr2.attrezzaturaNautica;

public class DirezioneNonValidaException extends IllegalArgumentException {

    private int errValue;

    public DirezioneNonValidaException(int errValue) {
        this.errValue = errValue;
    }

    public String stampaCausa() {
        return "Direzione " + errValue + " non valida. La direzione deve essere un valore nell'intervallo [0,360]";
    }
}