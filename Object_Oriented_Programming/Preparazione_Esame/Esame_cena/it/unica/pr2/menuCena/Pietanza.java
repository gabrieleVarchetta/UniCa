package it.unica.pr2.menuCena;

public class Pietanza {
    String nome;

    public Pietanza(String nome) {
        if(!nome.equals("") || nome.length() > 2)
            this.nome = nome;
        else
            throw new NomePietanzaNonValido("il nome di OGNI PIETANZA non puo' essere null ed avere almeno 2 caratteri");
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;

        if(obj == null)
            return false;
        
        if(!(obj instanceof Pietanza))
            return false;
        
        Pietanza other = (Pietanza)obj;

        if(nome.equals(other.nome))
            return true;
        
        return false;
    }

    @Override
    public int hashCode() {

        return 7 * 31 + nome.hashCode();
    }

}
