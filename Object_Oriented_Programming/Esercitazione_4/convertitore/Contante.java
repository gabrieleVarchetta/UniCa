package convertitore;
public class Contante {
    private String valuta;
    private double valore;

    public Contante(String valuta, double tassoDiCambio) {
        this.valuta = valuta;
        this.valore = tassoDiCambio;
    }

    public String getValuta() {
        return valuta;
    }

    public double getValore() {
        return valore;
    }
}
