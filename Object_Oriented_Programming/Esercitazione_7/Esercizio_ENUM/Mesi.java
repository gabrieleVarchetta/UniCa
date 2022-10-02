public enum Mesi {
    GENNAIO(31, "Inverno"),
    FEBBRAIO(28, "Inverno"),
    MARZO(31, "Inverno/Primavera"),
    APRILE(30, "Primavera"),
    MAGGIO(31, "Priavera"),
    GIUGNO(30, "Primavera/Estate"),
    LUGLIO(31, "Estate"),
    AGOSTO(31, "Estate"),
    SETTEMBRE(30, "Estate/Autunno"),
    OTTOBRE(31, "Autunno"),
    NOVEMBRE(30, "Autunno"),
    DICEMBRE(31, "Autunno/Inverno");

    private int giorni;
    private String stagione;

    Mesi(int giorni, String stagione) {
        this.giorni = giorni;
        this.stagione = stagione;
    }

    public int getGiorni() {
        return giorni;
    }

    public String getStagione() {
        return stagione;
    }

}