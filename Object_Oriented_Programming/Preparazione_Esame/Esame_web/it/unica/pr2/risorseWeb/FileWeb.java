package it.unica.pr2.risorseWeb;

import java.io.*;
import java.util.Scanner;

public class FileWeb extends RisorsaWeb {

    public FileWeb(String nome, String contenuto) {
        super(nome, contenuto);
    }

    public FileWeb(String nome) {
        this(nome, readFile(nome));
    }

    public void salva() {
        
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(super.getNome()))){
            writer.write(super.getContenuto());
        } catch(IOException e) {
            e.printStackTrace();
        }
    }

    public static String readFile(String nome) {
        StringBuilder contenuto = new StringBuilder();

        try(Scanner scanner = new Scanner(new File(nome))){
            
            while(scanner.hasNextLine()) {
                contenuto.append(scanner.nextLine());

                if(scanner.hasNextLine())
                    contenuto.append("\n");
            }     
            
        }catch(IOException e) {
            e.printStackTrace();
        }

        return contenuto.toString();
    }
}