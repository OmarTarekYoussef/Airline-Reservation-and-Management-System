#pragma once

#include "../include/Flight.hpp"
#include "../include/Users.hpp"
#include <iostream>
#include <string>
#include <memory>


using namespace std;

class Reservation{
    public:
        Reservation(int seatNum, const shared_ptr<Passenger>& p, const shared_ptr<Flight>& f, const string& method, const string& details, int amount);
        int getReservationID() const;
        int getCost() const;
        string getReservationString() const;
        void modifyBooking(int seat_num);
        void confirmReservation();
        void checkingReservation();
        void cancelReservation();
        void displayReservation();

    private:
        static int reservationCount;
        int reservationID;
        int seatNum;
        shared_ptr<Flight> flight;
        shared_ptr<Passenger> passenger;

        struct Payment
        {
            string method;
            string details;
            int amount;
            Payment(const string& m, const string& d, int a);
        } payment;
};