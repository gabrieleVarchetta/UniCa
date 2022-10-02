public class TestMesi {
    public static void main(String[] args) {
        for(Mesi m : Mesi.values()) {
            System.out.println("A " + m.toString().substring(0,1) + m.toString().substring(1).toLowerCase() + " ci sono " + m.getGiorni() + " giorni ed è " + m.getStagione());
        }
    }
}