//2021-09-10 prova pratica
/*

	enable assertions check using: java -ea ...

	there must be no warnings when compiling/running.

	

	Due in 100 min

*/

package it.unica.pr2.test;



import it.unica.pr2.ristoranti.*; // classes or interfaces must be placed here

import java.util.Map;

public class TestRistoranti {


    public static void main(String[] args) {



        // 18

        Menu pizzas = new Menu();

        pizzas.put("margherita",5.0); // food, price in euros

        pizzas.put("frutti di mare",8.5);

        pizzas.put("capricciosa",6.0);



        assert pizzas.size() == 3;



        it.unica.pr2.ristoranti.Menu italianFood = new Menu();

        italianFood.put("spaghetti al ragu bolognese",5.5);

        italianFood.put("trofie alla genovese",6.5);



        assert italianFood instanceof java.util.Map;

        Double d = italianFood.get("spaghetti al ragu bolognese");

        assert d == 5.5;




        Ristorante smallRestaurant = new Ristorante("Pizzeria bella Italia", 12, pizzas); // name, number of seats, menu of the restaurant

        Ristorante restaurant = new Ristorante("Da Ciro", 50, italianFood);

        Ristorante bigOne = new Ristorante("Ristorante Sala", 80, italianFood);

        assert Ristorante.numeroRistoranti() == 3;

        assert smallRestaurant.posti() == 12;



        assert smallRestaurant instanceof it.unica.pr2.ristoranti.Ristorante;

        

        // 21

        assert Ristorante.totalePosti() == 12+50+80;



        assert smallRestaurant.menu() == pizzas;



        assert italianFood.mostExpensive().equals("trofie alla genovese");
        

        // 24

        assert smallRestaurant.mostExpensive().equals("frutti di mare");

        assert smallRestaurant.isInTheMenu("frutti di mare");

        assert !smallRestaurant.isInTheMenu("spaghetti al ragu bolognese");


        // 27



        // ordina 4 pizze

        Order myOrder = smallRestaurant.order("frutti di mare","frutti di mare",

        "margherita", "capricciosa"); // hint: use varargs (String... cibi)

        assert myOrder.people() == 4; // one people per food and viceversa

        assert myOrder.cost() == 8.5 + 8.5 + 5.0 + 6.0; // 

        

        // 30

        Order anotherOrder = smallRestaurant.order("margherita", "capricciosa", "margherita"); // hint: use varargs (String... cibi)

        assert anotherOrder.people() == 3;

        assert myOrder.people() == 4; // one people per food and viceversa



        Order thirdOrder = smallRestaurant.order("margherita", "capricciosa", "margherita","margherita");



        // now we have 11 food/people being served

        // smallRestaurant accepts a total of 12 people (see constructor)



        try {

                Order fourthOrder = smallRestaurant.order("margherita", "capricciosa");

                assert false;

        } catch(TooMuchPeopleException e) {

                // the restaurant does not accept the order because there are too many people being served

                assert true;

        }



        /**/
        
    }

    

}