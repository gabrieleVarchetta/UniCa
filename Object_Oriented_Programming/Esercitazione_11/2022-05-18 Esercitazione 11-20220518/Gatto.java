public class Gatto {

    public String nome;
    public Double lunghezzaCoda;


    public Gatto(String nome, Double lunghezzaCoda) {
        this.nome = nome;
        this.lunghezzaCoda = lunghezzaCoda;
    }

    @Override
    public String toString() { 
        return this.nome; 
    }

}
