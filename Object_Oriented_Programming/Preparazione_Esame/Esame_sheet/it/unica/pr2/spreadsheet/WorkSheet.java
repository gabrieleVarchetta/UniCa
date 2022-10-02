package it.unica.pr2.spreadsheet;

import java.util.*;

public class WorkSheet extends HashMap<Coordinates, Object>{

    public Integer getValue(Coordinates c) {
        
        Object obj = super.get(c);
        
        if(obj instanceof Reference) {
            Reference ref = (Reference)obj;

            obj = ref.worksheet.get(ref.coordinate);
        }
        
        return (Integer) obj;
    }
}