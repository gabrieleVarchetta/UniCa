package it.unica.pr2.autostrada;

import java.util.*;

public class Autostrada extends HashSet<Auto> {

    String nome;
    ArrayList<String> eventiCasello;

    public Autostrada(String nome) {
        this.nome = nome;
        eventiCasello = new ArrayList<>();
    }

    public ArrayList<String> casello() {

        return eventiCasello;
    }

    //Overload del metodo add di Set
    public boolean add(Auto a) {

        eventiCasello.add(a.getClass().getSimpleName() + " colore " + a.colore + " targata " + a.targa + " entra in " + nome);

        if(a.autostrada == null) {
            if(super.add(a)) {
                a.autostrada = nome;
                return true;
            }
        } else
            throw new AutoInDueAutostradeException("palle");
            
        return false;
    }

    @Override
    public boolean remove(Object o) {

        Auto a = (Auto) o;

        eventiCasello.add(a.getClass().getSimpleName() + " colore " + a.colore + " targata " + a.targa + " esce da " + nome);

        if(super.remove(a)) {
            a.autostrada = null;
            return true;
        }
        
        return false;
    }
}