public class Studente extends Persona {
    private String matricola;

    Studente(String name, String surname, int age, String matricola) {
        super(name, surname, age);
        this.matricola = matricola;
    }
    
    public String getAnagrafica(String password) {
        boolean flag;
        flag = password.equals(this.getName().toUpperCase() + this.getSurname().toUpperCase()) ? true : false;

        if(flag)
            return "Password corretta, la matricola verrà visualizzata \n" + super.getAnagrafica() + " Matricola: " + matricola + ";";
        else
            return "Password sbagliata, la matricola verrà nascosta \n" + super.getAnagrafica() + " Matricola: ********* ;";
    }
}
