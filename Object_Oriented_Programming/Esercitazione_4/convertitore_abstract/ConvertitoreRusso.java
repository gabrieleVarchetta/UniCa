package convertitore_abstract;

import convertitore.Contante;

public class ConvertitoreRusso extends Convertitore{
    
    ConvertitoreRusso(int nValuteEstere) {
        super("Rubli", nValuteEstere);
    }

    @Override
    public boolean autorizzaCambio(Contante contante) {
        if(contante.getValore() > 20)
            return true;
        else
            return false;
    }
}
