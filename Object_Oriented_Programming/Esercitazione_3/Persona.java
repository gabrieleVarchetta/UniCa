public class Persona {
    private String name, surname;
    private int age;

    Persona(String name, String surname, int age) {
        this.name = name;
        this.surname = surname;
        this.age = age;
    }

    Persona(String name, String surname) {
        this(name, surname, 0);
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }

    public String getAnagrafica() {
        return "Nome: " + name + "; Cognome: " + surname + "; Età: " + age + ";";
    }
}