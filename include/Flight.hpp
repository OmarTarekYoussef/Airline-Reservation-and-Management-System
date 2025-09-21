#pragma once

#include <iostream>
#include <string>
#include <map>


using namespace std;

class Flight {
    public:
        enum class flightstatus {
            scheduled,
            OnTime,
            Delayed,
            Cancelled
        };

        Flight(const string& flightNumber, const string& origin, const string& destination, const string& deppartureTime,
                const string& arrivalTime, flightstatus status, int cost);
        const string& get_flight_number() const;
        const string& get_flight_boarding() const;
        const string& get_flight_destination() const;
        const string& get_flight_deppartureTime() const;
        const string& get_flight_arrivalTime() const;
        const string& get_flight_details() const;
        flightstatus get_flight_status() const;
        int get_flight_cost() const;
        void displayFlight();
        bool isFlightFull();
        bool book_seat(int seat_num);
        bool unbook_seat(int seat_num);
        
    private:
        string flightNumber;
        string origin;
        string destination;
        string deppartureTime;
        string arrivalTime;
        flightstatus status;
        int cost;
        seatMap seats;
};

class seatMap{
    public:
        seatMap() {}
        seatMap(int seatsNumber);
        bool book_seat(int seat_num);
        bool unbook_seat(int seat_num);
        int seats_cnt();
        void resetMap();
    private:
        map<int, bool> seats_availability;
};