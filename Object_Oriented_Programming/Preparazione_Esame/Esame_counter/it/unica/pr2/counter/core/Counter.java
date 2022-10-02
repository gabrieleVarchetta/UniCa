package it.unica.pr2.counter.core;

import java.util.*;

public class Counter<T> extends HashSet<T> {
    private HashMap<T, Integer> map = new HashMap<>();

    public Counter() {

    }

    public Counter(List<T> list) {
        super.addAll(list);
    }

    @Override
    public boolean add(T element) {

        if(map.containsKey(element))
            map.put(element, map.get(element) + 1);
        else
            map.put(element, 1);

        return super.add(element);
    }

    @Override
    public boolean remove(Object o) {
        map.remove(o);

        return super.remove(o);
    }

    public Integer count() {
        Integer totalEl = 0;

        for(Integer i : map.values())
            totalEl += i;

        return totalEl;
    }

    public Integer count(T arg) {
        if(!map.containsKey(arg))
            return 0;

        return map.get(arg);
    }
}