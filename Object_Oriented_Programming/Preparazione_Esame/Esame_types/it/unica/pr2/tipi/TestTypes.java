/*
	ATTENZIONE:

	usare javac -Werror -Xlint:unchecked  per accertarsi che non ci siano problemi coi tipi generici
	usare java -ea  per verificare le assert
*/
		

/* due in 45 min including questions */

package it.unica.pr2.tipi;

import it.unica.pr2.letters.*; // all work must be placed here
import java.util.stream.IntStream;

public class TestTypes {

    public static void main(String[] args) {

        // 18
        A b = C.d();
        D d = b;

        // 22
        System.out.println(d.hashCode()+"");
        System.out.println(C.d().hashCode()+"");
        
        assert d != C.d() && d.hashCode() == C.d().hashCode();
       
        // also equals accordingly / equals deve essere implementato di conseguenza nel modo corretto

        // 24
        for (C c : d) {
        };


        // 27
        C c = new C.D();

        // 30
       assert IntStream.range(0, 100).limit(3).map(C::e).sum() == 0 + 10 + 20;
/**/
    }

}
