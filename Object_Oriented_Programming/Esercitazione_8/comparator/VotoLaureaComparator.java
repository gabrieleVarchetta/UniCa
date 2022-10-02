package comparator;

import classi.Studente;
import java.util.Comparator;

public class VotoLaureaComparator implements Comparator<Studente> {

    @Override
    public int compare(Studente s1, Studente s2) {

        if(s1.getGrade() < s2.getGrade()) 
            return -1;

        if(s1.getGrade() > s2.getGrade())
            return 1;
        
        return 0;
    }
}