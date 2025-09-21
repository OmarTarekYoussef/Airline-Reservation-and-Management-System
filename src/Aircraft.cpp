#include "../include/Aircraft.hpp"

Aircraft::Aircraft(const string& model, int numPassengers, bool available)
                : model(model), numPassengers(numPassengers), available(available) {}

const string& Aircraft::get_model() const {
    return model;
}

int Aircraft::get_numSeats() const {
    return numPassengers;
}

const string Aircraft::get_aircraft_string() const {
    return model + "," + to_string(numPassengers);
}

bool Aircraft::isAvailable() {
    return available;
}

void Aircraft::displayAircraft() {
    cout << "Aircraft Model: " << model << endl;
    cout << "Number of Passengers: " << numPassengers << endl;
}