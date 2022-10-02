package it.unica.pr2.risorseWeb;

import java.io.File;

public class RisorsaWeb extends File {

    String nome, contenuto;

    public RisorsaWeb(String nome, String contenuto) {
        super(nome);
        this.contenuto = contenuto;
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public String getContenuto() {
        return contenuto;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        
        if(this == obj) 
            return true;
            
        if(!(obj instanceof RisorsaWeb))
            return false;
        
        RisorsaWeb other = (RisorsaWeb) obj;

        return nome.equals(other.nome) && contenuto.equals(other.contenuto);
    }

    @Override
    public int hashCode() {
        return 7 * 31 + nome.hashCode() + contenuto.hashCode();
    }
}