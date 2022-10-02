package convertitore;
public class Convertitore {
    private String valutaLocale;
    private int nValuteEstere;
    private int valuteEstereAttuali = 0;
    private Contante[] valuteEstere;

    Convertitore(String valutaLocale, int nValuteEstere) {
        this.valutaLocale = valutaLocale;
        this.nValuteEstere = nValuteEstere;
        valuteEstere = new Contante[this.nValuteEstere];
    }

    public boolean aggiungiValuta(String valuta, double tassoDiCambio) {
        if(valuteEstereAttuali < nValuteEstere) {
            valuteEstere[valuteEstereAttuali] = new Contante(valuta, tassoDiCambio);
            valuteEstereAttuali++;

            return true;
        }
        else
            return false;
    }

    public Contante converti(Contante contante) {
        String valutaDaCercare = contante.getValuta();

        for(int i = 0; i < valuteEstere.length; i++) {
            if(valutaDaCercare.equals(valuteEstere[i].getValuta()))
                return new Contante(valutaLocale, contante.getValore() * valuteEstere[i].getValore());
        }

        return new Contante(valutaLocale, 0);
    }
}
