import java.util.Arrays;

public class TestLambda {

    public static void main(String[] args) {
        Gatto[] gatti = new Gatto[3];
        gatti[0] = new Gatto("Romeo", 30.5);
        gatti[1] = new Gatto("Duchessa", 28.0);
        gatti[2] = new Gatto("Matisse", 20.3);

        System.out.println("I gatti prima dell'ordinamento:");
        System.out.println(Arrays.toString(gatti));

        System.out.println("\nI gatti ordinati per nome:");
        Arrays.sort(gatti, (Gatto g1, Gatto g2) -> {return g1.nome.compareTo(g2.nome);});
        
        System.out.println(Arrays.toString(gatti));

        System.out.println("\nI gatti ordinati per lunghezza della coda:");
        Arrays.sort(gatti, (Gatto g1, Gatto g2) -> {
            if(g1.lunghezzaCoda > g2.lunghezzaCoda)
                return 1;
            
            if(g1.lunghezzaCoda < g2.lunghezzaCoda)
                return -1;
            
            return 0;
        });
        System.out.println(Arrays.toString(gatti));
    }

}
