package it.unica.pr2.hotels;

import java.util.*;

public class Hotel extends ArrayList<Room> {

    String name, city;
    ArrayList<Room> freeRooms;
    HashMap<Room, String> bookedRooms;

    public Hotel(String name, String city) {
        this.name = name;
        this.city = city;
        freeRooms = new ArrayList<>();
        bookedRooms = new HashMap<>();
    }

    public void addRoom(Room room) {
        super.add(room);
        freeRooms.add(room);
        room.hotelOfTheRoom = this;
    }

    public int rooms() {
        return super.size();
    }

    public int freeRooms() {
        return freeRooms.size();
    }

    public int freeBeds() {
        int result = 0;

        for(Room r : freeRooms)
            result += r.bedNum;
        
        return result;
    }

    public boolean book(String name, int roomType) {
        for(Room r : freeRooms)
            if(r.roomKind == roomType) {
                freeRooms.remove(r);
                bookedRooms.put(r, name);
                return true;
            }

        return false;
    }

    public boolean isBooked(String target) {
        if(bookedRooms.containsValue(target))
            return true;
        
        return false;
    }

    public Room getBookedRoom(String target) {
        for(Map.Entry<Room, String> entry : bookedRooms.entrySet())
            if(entry.getValue().equals(target)) 
                return entry.getKey();
            
        throw new RoomNotFound("palle");
    }

}