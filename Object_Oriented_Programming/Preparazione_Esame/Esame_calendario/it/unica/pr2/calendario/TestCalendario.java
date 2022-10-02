/* 
 
 - due in 60 minutes 
 - remember to use -ea to check assertions 
 - submit as COGNOME_NOME_MATRICOLA.zip 
 
*/ 
package it.unica.pr2.calendario; 
 
import java.util.*; 
 
public class TestCalendario { 
 
    public static void main(String[] args) { 
 
        //18 
        Calendario calendario = new Calendario(); 
        Set<Appuntamento> calendarioSet = calendario; 
 
        assert calendarioSet.size() == 0; 
        calendario.add(new Allarme("2014-12-31", "capodanno!")); 
        calendario.add(new Allarme("2015-02-03", "esame pr2")); 
        calendario.add(new Allarme("2014-12-24", "comprare regali")); 
        calendario.add(new Allarme("2014-12-31", "comprare torta")); 
        assert calendarioSet.size() == 4; 
 
        // 21 
        Set<Appuntamento> appuntamenti31Dicembre = calendario.ricerca("2014-12-31"); 
        assert appuntamenti31Dicembre.size() == 2; 
 
 
        // 23 
        assert calendario.ricerca("2014-12").size() == 3; // appuntamenti Dicembre 2014 
 
 
        // 26 [hint: implementare 2 metodi!] 
        assert calendario.contains(new Allarme("2015-02-03", "esame pr2")); 
        assert !calendario.contains(new Allarme("2015-01-04", "fiori")); 
        assert !appuntamenti31Dicembre.contains(new Allarme("2014-12-24", "comprare regali")); 
 
 
        // 27 
        assert appuntamenti31Dicembre instanceof Calendario; 
 
        // 30 
        // si ordina per data (decrescente) e, secondariamente, per descrizione (crescente) 

        List<Appuntamento> appuntamentiInOrdine = calendario 
                .stream() 
                .sorted() 
                .collect(java.util.stream.Collectors.toList()); 

        assert appuntamentiInOrdine.get(0).equals(new Allarme("2015-02-03", "esame pr2")); 
        assert appuntamentiInOrdine.get(1).equals(new Allarme("2014-12-31", "capodanno!")); 
        assert appuntamentiInOrdine.get(2).equals(new Allarme("2014-12-31", "comprare torta")); 
        assert appuntamentiInOrdine.get(3).equals(new Allarme("2014-12-24", "comprare regali")); 
 
        /**/ 
    } 
 
}
