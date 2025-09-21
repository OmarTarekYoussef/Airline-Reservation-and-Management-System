#include "../include/Reservation.hpp"
int Reservation::reservationCount = 0;

Reservation::Reservation(int seatNum, const shared_ptr<Passenger>& p, const shared_ptr<Flight>& f, const string& method, const string& details, int amount)
    : seatNum(seatNum), passenger(p), flight(f), payment(method, details, amount)
{
    reservationID = ++reservationCount;
}

Reservation::Payment::Payment(const string& m, const string& d, int a)
                : method(m), details(d), amount(a){}

int Reservation::getReservationID() const
{
    return reservationID;
}

int Reservation::getCost() const
{
    return payment.amount;
}

string Reservation::getReservationString() const
{
    return to_string(reservationID) + "," + passenger->get_id() + "," + flight->get_flight_number() + "," +
            to_string(seatNum) + "," + payment.method + "," + payment.details + "," + to_string(payment.amount) + "\n";
}

void Reservation::modifyBooking(int seat_num)
{
    if (!flight->book_seat(seat_num))
        throw std::runtime_error("Seat is not available");
    seatNum = seat_num;
}

void Reservation::confirmReservation()
{
    cout << "\nBooking successful!\n";
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Flight: " << flight->get_flight_details() << endl;
    cout << "Seat: " << seatNum << endl;
    cout << "Total Cost: " << payment.amount << endl;
    cout << "Payment Method: " << payment.method << endl;
}

void Reservation::checkingReservation()
{
    cout<<"Reservation ID: "<<reservationID<<endl;
    cout<<"Passenger: "<<passenger->get_name()<<endl;
    cout<<"Flight: "<<flight->get_flight_details()<<endl;
    cout<<"Departure: "<<flight->get_flight_deppartureTime()<<endl;
    cout<<"Seat: "<<seatNum<<endl;
    cout<<"Boarding Time: "<<flight->get_flight_boarding()<<endl;
}

void Reservation::cancelReservation()
{
    cout<<"Reservation ID: "<<reservationID;
    cout<<" is canceled\n";
    cout << "Total Cost: " << payment.amount << " is refunded through ";
    cout << "Payment Method: " << payment.method << endl;
}

void Reservation::displayReservation()
{
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Flight: " << flight->get_flight_details() << endl;
    cout << "Seat: " << seatNum << endl;
    cout << "Total Cost: " << payment.amount << endl;
    cout << "Payment Method: " << payment.method << endl;
};


