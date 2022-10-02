package it.unica.pr2.letters;

public class C {

    public static A d() {
        return new A();
    }

    public static int e(int arg) {
        return arg * 10;
    }

    @Override
    public int hashCode() {
        return 7 * 31;
    }

    @Override
    public boolean equals(Object o) {
        if(o == null)
            return false;
        
        if(this == o)
            return true;
        
        C other = (C) o;

        if(this.hashCode() == other.hashCode())
            return true;
        
        return false;
    }

    public static class D extends C{

 
    }
}