/*
 * consegna in 60 minuti
 *
 * due in 60 minutes
 * remeber to enable assertion using: -ea (or -enableassertions)
 *
 */

package it.unica.pr2.spreadsheet;

import java.util.*; //Map

public class TestSheet {

    public static void main(String[] args) {

        // 19
        Spreadsheet spreadsheet = new SimpleSpreadsheet();
        List<WorkSheet> list = spreadsheet;

        assert (list.get(0) instanceof Map);
        assert spreadsheet.size() == 1;

        
        // NOTE:
        // list.get(0) must be an instance of Map<Coordinates,Object>
        spreadsheet.get(0).put(new Coordinates("A1"), Integer.valueOf(5));

        // 24
        // NOTE: only Coordinates should be changed
        assert spreadsheet.get(0).get(new Coordinates("A1")).equals(5);

        // 28
        Object o = new Reference(spreadsheet.get(0),new Coordinates("A1"));
        spreadsheet.get(0).put(new Coordinates("B2"), o);

        Coordinates b1 = new Coordinates("B1");
        Coordinates b2 = new Coordinates("B2");

        // note: default worksheet is the first
        assert spreadsheet.getDefaultWorksheet().get(b1) == null;
        assert spreadsheet.getDefaultWorksheet().get(b2) == o;
        assert spreadsheet.getDefaultWorksheet().getValue(b2).equals(5);

        //DA FINIRE
        // 30
        spreadsheet.get(0).put(new Coordinates("A1"), Integer.valueOf(6));
        assert spreadsheet.getDefaultWorksheet().getValue(b2) == 6;


        /**/
    }

}
