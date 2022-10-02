package convertitore_abstract;

import convertitore.Contante;

public class ConvertitoreEuropeo extends Convertitore{
    private boolean isRussiaSanzionata = false;

    ConvertitoreEuropeo(int nValuteEstere) {
        super("Euro", nValuteEstere);
    }

    @Override
    public boolean autorizzaCambio(Contante contante) {
        if(contante.getValuta().equals("Rubli") && !isRussiaSanzionata)
            return true;
        else if(contante.getValuta().equals("Rubli") && isRussiaSanzionata)
            return false;
        else
            return true;
    }

    public void applicaSanzioni() {
        isRussiaSanzionata = true;
    }
}
