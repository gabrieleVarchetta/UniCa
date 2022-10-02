/*
	ATTENZIONE:

	usare javac -Xlint:unchecked  per accertarsi che non ci siano problemi coi tipi generici
	usare java -ea  per verificare le assert
 */
package it.unica.pr2.testspesa;

import it.unica.pr2.carrello.*;
import java.util.*;

public class TestSpesa {

    public static void main(String[] args) {

        // 18
        Carrello carrello = new Carrello();
        Map<Prodotto, Double> m = carrello; // prodotto, quantita'
        Prodotto mela = new Prodotto("mela", 5.0); // 5 euro al kg
        Prodotto pera = new Prodotto("pera", 4.5);

        assert carrello.size() == 0;
        assert Prodotto.nProdotti() == 2;
        assert pera.prezzo() == 4.5;

        // 23
        carrello.aggiungi(mela, 2.0); // 2kg di mele
        m.put(pera, 1.5); // 1.5kg di pere

        assert carrello.costo() == 5.0 * 2.0 + 4.5 * 1.5;
        assert carrello.size() == 2;

        // 25
        Prodotto rucola = new Prodotto("rucola");
        try {
            carrello.aggiungi(rucola, 2.0);
            assert false;
        } catch (PrezzoSconosciutoException e) {
            assert true;
        }

        // 28
        Set<Prodotto> economici = Prodotto.costaMenoDi(4.7);
        assert economici.size() == 1;
        assert economici.toArray()[0].equals(pera);

        // 30
        carrello.salvaSuFile("carrello.txt");
        /* Contenuto carrello.txt:
		2.0 mela 5.0
		1.5 pera 4.5
         */

    }
}
