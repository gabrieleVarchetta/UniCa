public class Main {
    public static void main(String[] args) {
        Persona pippo = new Persona("Pippo", "Inzaghi", 46);
        Studente paolo = new Studente("Paolo", "Maldini", 21, "porcoiddio");
        Persona p = new Studente("Gab", "Var", 20, "siracarognawaka");

        System.out.println(pippo.getAnagrafica());
        
        System.out.println(paolo.getAnagrafica("PAOLOMALDINI"));

        System.out.println(p.getAnagrafica());
        System.out.println(p);

    }
}
