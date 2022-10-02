package it.unica.pr2.risorseWeb;

import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class RisorsaWeb extends java.io.File {
    private String content;

    public RisorsaWeb(String name, String content) {
        super(name);
        this.content = content;
    }

    public RisorsaWeb(String name) {
        super(name);
        this.content = caricaContenuto();
    }


    public String getNome() {
        return super.getName();
    }

    public String getContenuto() {
        return content;
    }

    public void salva() {

        // try-with-resources
        // java.io.FileWriter ha un costruttore che prende un oggetto File
        try(FileWriter myWriter = new FileWriter(this)) {

            myWriter.write(this.content);

        } catch(IOException e) {

            // Metodo di java.lang.Throwable utile per capire il problema
            e.printStackTrace();
        }
    }


    /*
       Questo metodo ricalca quasi del tutto quanto avete visto a lezione
       di teoria nella settimana 5 (eccezioni e file)
    */
    protected String caricaContenuto() {

        /*
           java.lang.StringBuilder è una classe che permette di costruire
           efficientemente delle stringhe in maniera incrementale
        */
        StringBuilder righeLette = new StringBuilder();

        // try-with-resources
        try (Scanner myReader = new Scanner(this)) {

            // java.util.Scanner è sostanzialmente un Iterator
            while (myReader.hasNextLine()) {

                // Inseriamo newline prima di ogni riga eccetto la prima
                if (righeLette.length() > 0) { righeLette.append("\n"); }

                righeLette.append(myReader.nextLine());
            }
        } catch (FileNotFoundException e) {

            e.printStackTrace();
        }

        return righeLette.toString();
    }

    @Override
    public boolean equals(Object obj) {

        // Vincolo della riflessività
        if (this == obj) return true;

        // Vincolo su null
        if (obj == null) return false;

        // L'altro oggetto deve essere di classe RisorsaWeb o di una sua sottoclasse
        if (!(obj instanceof RisorsaWeb)) return false;

        // Se siamo qui, sappiamo che obj è un RisorsaWeb e possiamo fare il cast
        RisorsaWeb other = (RisorsaWeb) obj;

        if(this.getNome().equals(other.getNome()) && this.getContenuto().equals(other.getContenuto()))
            return true;

        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;

        // String fornisce una sua implementazione di hashCode(), possiamo quindi usarla
        // sommando gli hashCode del nome e del contenuto, assicurando così che oggetti
        // diversi con gli stessi valori abbiano lo stesso hashCode, e vengano quindi visti
        // come lo stesso oggetto all'interno dell'HashSet
        hash = hash * 31 + getNome().hashCode() + getContenuto().hashCode();

        return hash;
    }
}