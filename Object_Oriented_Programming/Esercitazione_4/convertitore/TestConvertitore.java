package convertitore;
public class TestConvertitore {
    
    public static void main(String[] args) {

        Convertitore bancaRussa = new Convertitore("Rubli", 2);
        bancaRussa.aggiungiValuta("Euro", 2.0);
        bancaRussa.aggiungiValuta("Yen", 0.9);

        Convertitore bancaEuropea = new Convertitore("Euro", 2);
        bancaEuropea.aggiungiValuta("Sterline", 1.2);
        bancaEuropea.aggiungiValuta("Rubli", 0.5);

        Convertitore bancaGiapponese = new Convertitore("Yen", 2);
        bancaGiapponese.aggiungiValuta("Rubli", 1.1);
        bancaGiapponese.aggiungiValuta("Dollari", 10.0);


        // Due test generali

        // 1. Non possiamo aggiungere una terza valuta
        assert !bancaRussa.aggiungiValuta("Dollari", 1.0);

       // 2. Valuta inattesa
        Contante attesi0Rubli = bancaRussa.converti(new Contante("Yuan", 100.0));
        assert attesi0Rubli.getValore() == 0.0;
        assert attesi0Rubli.getValuta().equals("Rubli");


        // Due test sui Rubli
        
        // 1. Cambio da Euro
        Contante attesi2Rubli = bancaRussa.converti(new Contante("Euro", 1.0));
        assert attesi2Rubli.getValore() == 2.0;
        assert attesi2Rubli.getValuta().equals("Rubli");

        // 3. Cambio da Yen
        Contante attesi0_9Rubli = bancaRussa.converti(new Contante("Yen", 1.0));
        assert attesi0_9Rubli.getValore() == 0.9;
        assert attesi0_9Rubli.getValuta().equals("Rubli");


        // Due test sugli Euro
        
        // 1. Cambio da Sterline
        Contante attesi1_2Euro = bancaEuropea.converti(new Contante("Sterline", 1.0));
        assert attesi1_2Euro.getValore() == 1.2;
        assert attesi1_2Euro.getValuta().equals("Euro");

        // 2. Cambio da Rubli
        Contante attesi0_5Euro = bancaEuropea.converti(new Contante("Rubli", 1.0));
        assert attesi0_5Euro.getValore() == 0.5;
        assert attesi0_5Euro.getValuta().equals("Euro");


        // Due test sugli Yen
        
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

        System.out.println("toString() del convertitore della banca russa:");
        System.out.println(bancaRussa.toString() + "\n");

        System.out.println("toString() del convertitore della banca europea:");
        System.out.println(bancaEuropea.toString() + "\n");

        System.out.println("toString() del convertitore della banca giapponese:");
        System.out.println(bancaGiapponese.toString() + "\n");
    }
    

}