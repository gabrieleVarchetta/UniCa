package it.unica.pr2.bricostore;

import java.util.*;

public class Product {
    String name;
    double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;

        if(obj == null)
            return false;

        if(!(obj instanceof Product))
            return false;

        Product other = (Product)obj;

        if(name.equals(other.name) && price == other.price)
            return true;
        
        return false;
    }

    @Override
    public int hashCode() {
        return 7*31 + name.hashCode() + Double.valueOf(price).hashCode();
    }
}