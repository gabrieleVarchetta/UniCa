package it.unica.pr2.menuCena;

import java.util.*;

public class MenuCena extends Menu { 
    static MenuCena menu = new MenuCena();

    public MenuCena() {
        super.put(new Pietanza("maccheroni"), Integer.valueOf(12));
        super.put(new Pietanza("bistecca"), Integer.valueOf(15));
        super.put(new Pietanza("riso"), Integer.valueOf(8));
    }
}
