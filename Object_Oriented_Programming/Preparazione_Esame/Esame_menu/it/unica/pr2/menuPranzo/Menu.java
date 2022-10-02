package it.unica.pr2.menuPranzo;

import java.util.*;

public class Menu extends ArrayList<Pietanza> {

    public static Menu pranzo() {
        Menu menu = new Menu();

        menu.add(new Pietanza("maccheroni", 12));
        menu.add(new Pietanza("riso", 8));
        menu.add(new Pietanza("bistecca", 15));

        return menu;
    }
}