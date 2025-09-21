#include "../include/Flight.hpp"
#include <algorithm>

seatMap::seatMap(int seatsNumber) {
    for (int i = 1; i <= seatsNumber; i++) {
        seats_availability.emplace(i, true);
    }
}

bool seatMap::book_seat(int seat_num) {
    auto it = seats_availability.find(seat_num);
    if (it != seats_availability.end() && it->second){
        it->second = false;
        return true;
    }
    return false;
}

bool seatMap::unbook_seat(int seat_num) {
    auto it = seats_availability.find(seat_num);
    if (it != seats_availability.end()){
        it->second = true;
        return true;
    }
    return false;
}

int seatMap::seats_cnt() {
    return count_if(seats_availability.begin(), seats_availability.end(), [](const pair<int, bool>& p) { return p.second; });
}

void seatMap::resetMap() {
    for (auto& pair : seats_availability) {
        pair.second = true;
    }
}

Flight::Flight(const string& flightNumber, const string& origin, const string& destination, const string& deppartureTime,
                const string& arrivalTime, flightstatus status, int cost)
                : flightNumber(flightNumber), origin(origin), destination(destination), deppartureTime(deppartureTime), arrivalTime(arrivalTime),
                status(status), cost(cost) {} 

const string& Flight::get_flight_number() const {
    return flightNumber;
}

const string& Flight::get_flight_boarding() const {
    return origin;
}

const string& Flight::get_flight_destination() const {
    return destination;
}

const string& Flight::get_flight_deppartureTime() const {
    return deppartureTime;
}

const string& Flight::get_flight_arrivalTime() const {
    return arrivalTime;
}

const string& Flight::get_flight_details() const {
    return flightNumber + "from" + origin + "to" + destination + "," + deppartureTime + "," + arrivalTime;
}

int Flight::get_flight_cost() const {
    return cost;
}

bool Flight::unbook_seat(int seat_num) {
    return seats.unbook_seat(seat_num);
}

bool Flight::book_seat(int seat_num) {
    return seats.book_seat(seat_num);
}

bool Flight::isFlightFull() {
    return seats.seats_cnt() == 0;
}

void Flight::displayFlight() {
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Origin: " << origin << endl;
    cout << "Destination: " << destination << endl;
    cout << "Departure Time: " << deppartureTime << endl;
    cout << "Arrival Time: " << arrivalTime << endl;
    cout << "Price: $" << cost << endl;

    if(seats.seats_cnt() > 0)
    {
        cout << "Seats Available: " << seats.seats_cnt() << endl;
    }
    else
    {
        cout << "Seats Available: 0" << endl;
    }
 
}



