package convertitore_abstract;

import convertitore.Contante;

public class ConvertitoreGiapponese extends Convertitore{
    
    ConvertitoreGiapponese(int nValuteEstere) {
        super("Yen", nValuteEstere);
    }

    @Override
    public boolean autorizzaCambio(Contante contante) {
        return true;
    }
}
