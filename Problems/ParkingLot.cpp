#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

/*
Requirements:

1> Large Parking Lot.
2> Multiple Entry/Exit, say 4.
3> Ticket with parking spot is assigned at entrance.
4> Parking spot should be nearest to the entrance.
5> Shouldn't allow more vehicles than capacity.
6> Should support different kinds of parking spots(Handicapped, Compact, Large, Motorcyles).
7> Parking fees based on time at exit.
8> Multiple payment modes.
9> Should be flexible enough to apply at different places.

Actors:
1> Parking Lot Itself
2> Entry/Exit Terminals
3> Exit will payment processor
4> Parking Spot
5> Ticket
6> Database

**Vehicle is not a necessary actor, vehicle parking spot is different from vehicle class

*/

/********************************************************************************/
/* Parking Spot*/
/* No enums, cause ParkingSpot should follow Open/Close principle, difficulty while adding new type of
Parking Spot*/
class ParkingSpot{
    public:
    virtual void getId() = 0;
    virtual void reserve(unsigned int) = 0;
    private:
    unsigned int id;
    bool reserved;
};

class HandicappedParkingSpot: public ParkingSpot{

};

class LargeParkingSpot: public ParkingSpot{

};

class CompactParkingSpot: public ParkingSpot{

};

class MotorcyleParkingSpot: public ParkingSpot{

};
/********************************PARKING TICKET**********************************/
class ParkingTicket{
    unsigned int id;
    unsigned int parkingSpotId;
    std::string parkingSpotType;
    time_t issueTime;
};
/***********************************TERMINALS***********************************/
class Terminal{
    unsigned int id;
};

class EntryTerminal: public Terminal{
    ParkingTicket getParkingTicket(){

    }
};

class ExitTerminal: public Terminal{

    int acceptParkingTicket(ParkingTicket){
        //return fees;
    }
};
/****************************PARKING STRATEGY************************************/
class IParkingStrategy{
    virtual ParkingSpot getParkingSpot(Terminal) = 0;
    virtual void freeParkingSpot(ParkingTicket) = 0;
};

class ParkingNearEntranceStrategy: public IParkingStrategy{

};

/************************************PAYMENT***********************************/
class IPaymentProcessor{
    virtual void process() = 0;
};

class CreditCard: public IPaymentProcessor{

};

class UPI: public IPaymentProcessor{

};
/********************************************************************************/

class ParkingLot{

    private:
    const int PARKING_FLOORS = 5;
    std::vector<ParkingSpot> parkingArea;
    std::unordered_set<ParkingSpot> availableSpots;
    std::unordered_set<ParkingSpot> reservedSpots;
};