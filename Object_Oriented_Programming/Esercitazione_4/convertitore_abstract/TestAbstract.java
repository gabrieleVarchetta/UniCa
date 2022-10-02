package convertitore_abstract;
import convertitore.Contante;

public class TestAbstract {
    
    public static void main(String[] args) {

        ConvertitoreRusso bancaRussa = new ConvertitoreRusso(2);
        bancaRussa.aggiungiValuta("Euro", 2.0);
        bancaRussa.aggiungiValuta("Yen", 0.9);

        ConvertitoreEuropeo bancaEuropea = new ConvertitoreEuropeo(2);
        bancaEuropea.aggiungiValuta("Sterline", 1.2);
        bancaEuropea.aggiungiValuta("Rubli", 0.5);

        ConvertitoreGiapponese bancaGiapponese = new ConvertitoreGiapponese(2);
        bancaGiapponese.aggiungiValuta("Rubli", 1.1);
        bancaGiapponese.aggiungiValuta("Dollari", 10.0);


        // Due test generali

        // 1. Non possiamo aggiungere una terza valuta
        assert !bancaRussa.aggiungiValuta("Dollari", 1.0);

        
        // 2. Valuta inattesa
        Contante attesi0Rubli = bancaRussa.converti(new Contante("Yuan", 100.0));
        assert attesi0Rubli.getValore() == 0.0;
        assert attesi0Rubli.getValuta().equals("Rubli");

        // 3 test sui Rubli

        // 1. Si possono ottenere Rubli solo se si paga più di 20 unità
        attesi0Rubli = bancaRussa.converti(new Contante("Euro", 20.0));
        assert attesi0Rubli.getValore() == 0.0;
        assert attesi0Rubli.getValuta().equals("Rubli");

        // 2. Più di 20 unità sono accettate
        Contante attesi42Rubli = bancaRussa.converti(new Contante("Euro", 21.0));
        assert attesi42Rubli.getValore() == 42.0;
        assert attesi42Rubli.getValuta().equals("Rubli");

        // 3. Cambio da Yen
        Contante attesi27Rubli = bancaRussa.converti(new Contante("Yen", 30.0));
        assert attesi27Rubli.getValore() == 27.0;
        assert attesi27Rubli.getValuta().equals("Rubli");

        // 3 test sugli Euro
        
        // 1. Cambio da Sterline
        Contante attesi1_2Euro = bancaEuropea.converti(new Contante("Sterline", 1.0));
        assert attesi1_2Euro.getValore() == 1.2;
        assert attesi1_2Euro.getValuta().equals("Euro");

        // 2. Cambio da Rubli in assenza di sanzioni
        Contante attesi0_5Euro = bancaEuropea.converti(new Contante("Rubli", 1.0));
        assert attesi0_5Euro.getValore() == 0.5;
        assert attesi0_5Euro.getValuta().equals("Euro");

        // 3. Cambio da Rubli in presenza di sanzioni
        bancaEuropea.applicaSanzioni();
        Contante attesi0Euro = bancaEuropea.converti(new Contante("Rubli", 1.0));
        assert attesi0Euro.getValore() == 0.0;
        assert attesi0Euro.getValuta().equals("Euro");


        // 2 test sugli Yen
        
        // 1. Cambio da Rubli
        Contante attesi1_1Yen = bancaGiapponese.converti(new Contante("Rubli", 1.0));
        assert attesi1_1Yen.getValore() == 1.1;
        assert attesi1_1Yen.getValuta().equals("Yen");
        
        // 2. Cambio da Dollari
        Contante attesi10Yen = bancaGiapponese.converti(new Contante("Dollari", 1.0));
        assert attesi10Yen.getValore() == 10;
        assert attesi10Yen.getValuta().equals("Yen");


        System.out.println("\nSe stai leggendo questo messaggio, il tuo codice ha soddisfatto tutti gli assert.");


        // Test degli Override di Object.toString()
        System.out.println("\nOra testiamo i metodi toString()...\n");

        System.out.println("toString() di ConvertitoreRusso:");
        System.out.println(bancaRussa.toString() + "\n");

        System.out.println("toString() di ConvertitoreEuropeo:");
        System.out.println(bancaEuropea.toString() + "\n");

        System.out.println("toString() di ConvertitoreGiapponese:");
        System.out.println(bancaGiapponese.toString() + "\n");
    }
    

}