package comparator;

import classi.Gatto;
import java.util.Comparator;

public class CodaComparator implements Comparator<Gatto> {

    @Override
    public int compare(Gatto g1, Gatto g2) {

        if(g1.getTaillength() < g2.getTaillength())
            return -1;

        if(g1.getTaillength() > g2.getTaillength())
            return 1;

        return 0;
    }
}