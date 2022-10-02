package it.unica.pr2.autostrada;

import java.util.*;

public class TestAutostrada {

    public static void main(String[] args) {

	// 18
	Mezzo m1 = new Berlina("verde","XY123WZ"); // colore, targa
	Mezzo m2 = new Moto("giallo","AB456FG");
	Mezzo m3 = new StationWagon("verde","ZQ987PO");

	assert m1 instanceof Auto;
	assert !(m2 instanceof Auto);
	assert m3 instanceof Auto;

	Autostrada autostrada1 = new Autostrada("A17"); // nome autostrada; inoltre: solo le auto sono ammesse in autostrada
	Autostrada autostrada2 = new Autostrada("A32");

	assert autostrada1 instanceof Set;
	autostrada1.add((Auto)m1);
	autostrada1.add((Auto)m3);


	assert autostrada1.size() == 2;
	assert autostrada1.contains(m1);
	assert !autostrada1.contains(m2);
	assert autostrada1.contains(m3);
	assert autostrada2.size() == 0;

	// 21
	Mezzo a4 = new Berlina("rosso","XY123WZ");
	assert m1.equals(new Berlina("verde","XY123WZ"));
	assert !m2.equals(a4);

	assert m1.hashCode() == new Berlina("verde","XY123WZ").hashCode();
	assert m1.hashCode() != a4.hashCode();

	// 24

	List<String> targhe = new ArrayList<>();
	for(Auto a : autostrada1) {
		targhe.add(a.targa());
	}

	// 27 

	List<String> eventi = autostrada1.casello();
	assert eventi.size() == 2;

	// hint: A) instanceof oppure B) Object.getClass() and getSimpleName()
	assert eventi.get(0).equals("Berlina colore verde targata XY123WZ entra in A17");
	assert eventi.get(1).equals("StationWagon colore verde targata ZQ987PO entra in A17");
    //non ho voglia di fare questo. è troppo stupido
	autostrada1.remove(m3); // esce dall'autostrada1
    eventi = autostrada1.casello();
	assert eventi.size() == 3;
	assert eventi.get(2).equals("StationWagon colore verde targata ZQ987PO esce da A17");

	// 30

	assert autostrada2.add((Auto)m3); // entra in autostrada2

	try {
		assert autostrada2.add((Auto)m1);
		assert false;
	} catch(AutoInDueAutostradeException e) {
		assert true;
	} 
     /***/   
    }

}
