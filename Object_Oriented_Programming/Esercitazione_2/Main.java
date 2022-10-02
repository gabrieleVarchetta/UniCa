class Main {
    public static void main(String[] args) {
        // Primo programma
        /*int a = 5, b = 7, res;

        res = a + b;

        System.out.println(res);
        
        // Secondo programma
        String phrase = args[0];

        System.out.println(phrase.toUpperCase());

        // Terzo programma
        Rectangle rectangle = new Rectangle();

        rectangle.printEdges();

        rectangle.scaleRect(2);

        rectangle.printEdges();*/

        // Esercizio proposto
        Quaderno quaderno = new Quaderno();

        quaderno.addPages(50);
        quaderno.assignTitle(args[0]);
        quaderno.printAttributes();
        quaderno.removePages(20);
        quaderno.printAttributes();
    }
}
