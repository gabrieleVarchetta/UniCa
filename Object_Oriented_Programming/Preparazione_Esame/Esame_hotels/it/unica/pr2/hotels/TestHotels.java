/*
due in 90 minutes

remember to run the interpreter with -ea (enable assertions)

*/

package it.unica.pr2.hotels;
import java.util.*;

public class TestHotels {
	public static void main(String[] args) {
		
		// 18
		Hotel h1 = new Hotel("SeaView Hotel","Miami");
		assert h1 instanceof List;
		List<Room> l = h1;
		
		Room r = new Room(Room.TWIN_ROOM);
		// hint: you are free to set DOUBLE_ROOM and the others to any value as long as the code works.
		h1.addRoom(new Room(Room.DOUBLE_ROOM)); // A room may be double (matrimoniale), twin (doppia), single (singola) or suite (fino a quattro persone). 
		h1.addRoom(new Room(Room.TWIN_ROOM)); 
		h1.addRoom(new Room(Room.SINGLE_ROOM));
		h1.addRoom(new Room(Room.SUITE_ROOM));
		
		
		// this second hotel has 2 twin rooms, 2 single rooms and a double room
		Hotel h2 = new Hotel("Miramare","Cagliari");
		h2.addRoom(new Room(Room.DOUBLE_ROOM)); // A room may be double (matrimoniale), twin (doppia), single (singola) or suite (fino a quattro persone). 
		h2.addRoom(new Room(Room.TWIN_ROOM)); 
		h2.addRoom(new Room(Room.TWIN_ROOM)); 
		h2.addRoom(new Room(Room.SINGLE_ROOM));
		h2.addRoom(new Room(Room.SINGLE_ROOM));
		
		assert h1.rooms() == 4;
		assert h1.rooms() == h1.size();
		assert h1.freeRooms() == 4;
		assert h1.freeBeds() == 2+2+1+4;

		assert h2.rooms() == 5;
		assert h2.rooms() == h2.size();
		assert h2.freeRooms() == 5;
		assert h2.freeBeds() == 2+2+2+1+1;		
		
		// 22
		boolean ok = h1.book("Marco",Room.SINGLE_ROOM);
		assert ok == true;
		assert h1.freeRooms() == 3;
		assert h1.freeBeds() == 2+2+4;

		ok = h1.book("Michela",Room.SINGLE_ROOM);
		assert ok == false; // there are no free single rooms; nothing happens.
		assert h1.freeRooms() == 3;
		assert h1.freeBeds() == 2+2+4;
		
		ok = h2.book("Cesare",Room.DOUBLE_ROOM);
		assert ok == true;
		assert h2.freeRooms() == 4;
		assert h2.freeBeds() == 2+2+1+1;

		
		// 24
		assert !h1.isBooked("Michela");
		assert !h2.isBooked("Michela");
		assert h2.isBooked("Cesare");
		assert !h1.isBooked("Cesare");
		
		
		// 27
		Room roomBookedByCesare = h2.getBookedRoom("Cesare");
		assert roomBookedByCesare.hotel() == h2;
		assert roomBookedByCesare.roomNumber() == 1; // first booking on h2
		
		assert h1.getBookedRoom("Marco").roomNumber() == 3; // marco booked the single room, which is the third room in the hotel (third added to the hotel
        assert h1.getBookedRoom("Marco").hotel() == h1; // first booking on h1

		h1.book("GV",Room.SUITE_ROOM);
		assert h1.getBookedRoom("GV").roomNumber() == 4; // second booking on h1
		
		
		// 30
		try {
			Room roomOfGianluca = h2.getBookedRoom("GV");
			assert false;
		} catch(RoomNotFound e) {
			assert true; // GV did not book any room of hotel h2.
		}
		/**/
		
	}
	
	
}
