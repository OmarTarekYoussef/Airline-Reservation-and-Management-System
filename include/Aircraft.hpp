#pragma once

#include <iostream>
#include <string>


using namespace std;

class Aircraft {
    public:
        Aircraft(const string& model, int numPassengers, bool available);
        const string& get_model() const;
        const string get_aircraft_string() const;
        int get_numSeats() const;
        bool isAvailable();
        void displayAircraft();

    private:
        string model;
        int numPassengers;
        bool available;

};