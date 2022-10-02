package it.unica.pr2.hotels;

public class Room {

    int bedNum, roomKind, roomNumber;
    Hotel hotelOfTheRoom;
    static final int DOUBLE_ROOM = 1, TWIN_ROOM = 2, SINGLE_ROOM = 3, SUITE_ROOM = 4;

    public Room(int roomType) {
        switch(roomType) {
            case 1:
                    bedNum = 2;
                    roomKind = 1;
                    roomNumber = 1;
            break;

            case 2:
                    bedNum = 2;
                    roomKind = 2;
                    roomNumber = 2;
            break;

            case 3:
                    bedNum = 1;
                    roomKind = 3;
                    roomNumber = 3;
            break;

            case 4:
                bedNum = 4;
                roomKind = 4;
                roomNumber = 4;
            break;
        }
    }

    public int roomNumber() {
        return roomNumber;
    }

    public Hotel hotel() {
        return hotelOfTheRoom;
    }
}