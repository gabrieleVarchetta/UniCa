package it.unica.pr2.spreadsheet;

import java.util.*;

public class Spreadsheet extends ArrayList<WorkSheet>{

    public Spreadsheet() {
        super.add(new WorkSheet());
    }

    public WorkSheet getDefaultWorksheet() {
        return super.get(0);
    }
}