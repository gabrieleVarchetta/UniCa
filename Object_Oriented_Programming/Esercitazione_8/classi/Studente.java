package classi;

public class Studente extends Persona {

    private String university;
    int grade;

    public Studente (String firstName, String lastName, int birthYear, String university, int grade) {
        super(firstName, lastName, birthYear);
        this.university = university;
        this.grade = grade;
    }

    public int getGrade() {
        return grade;
    }
}