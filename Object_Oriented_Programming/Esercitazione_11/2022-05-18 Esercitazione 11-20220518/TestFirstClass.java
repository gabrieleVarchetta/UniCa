
public class TestFirstClass {

    public static void main(String[] args) {
        int[] mieiValori = { 17, 21, 5, 78, 123, 960, 200 };
        java.util.function.IntPredicate miaLambda = i -> i % 5 == 0;

        stampaConCriterio(mieiValori, miaLambda);
    }


    static void stampaConCriterio(int[] valori, java.util.function.IntPredicate criterio) {
        for (int valoreCorrente : valori) {
            if (criterio.test(valoreCorrente)) {
                System.out.println(valoreCorrente);
            }
        }
    }

}
