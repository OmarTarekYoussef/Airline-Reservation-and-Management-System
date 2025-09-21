#include "../include/Users.hpp"


User::User(const string& name, const string& id, accessLevel access_Level)
            : name(name), id(id), access_Level(access_Level) {}

const string& User::get_name() const {
    return name;
}

const string& User::get_id() const {
    return id;
}

/* Administrator */
Administrator::Administrator(const string& name, const string& id)
            : User(name, id, User::accessLevel::Administrator) {}

bool Administrator::checkAccessLevel(accessLevel level) const {
    if (level == accessLevel::Administrator){
        return true;
    }
    else{
        return false;
    }
}

void Administrator::displayUser() const {
    cout << "User Name: " << get_name() << "is an Administrator" << endl;
    cout << "ID: " << get_id() << endl;
}

/* BookingAgent */
BookingAgent::BookingAgent(const string& name, const string& id)
            : User(name, id, User::accessLevel::BookingAgent) {}

bool BookingAgent::checkAccessLevel(accessLevel level) const {
    if (level == accessLevel::BookingAgent){
        return true;
    }
    else{
        return false;
    }
}

void BookingAgent::displayUser() const {
    cout << "User Name: " << get_name() << "is an BookingAgent" << endl;
    cout << "ID: " << get_id() << endl;
}

/* Passenger */
Passenger::Passenger(const string& name, const string& id)
            : User(name, id, User::accessLevel::Passenger) {}

bool Passenger::checkAccessLevel(accessLevel level) const {
    if (level == accessLevel::Passenger){
        return true;
    }
    else{
        return false;
    }
}

void Passenger::displayUser() const {
    cout << "User Name: " << get_name() << "is an Passenger" << endl;
    cout << "ID: " << get_id() << endl;
}

/* CrewMember */
CrewMember::CrewMember(const string& name, const string& id, Role role)
            : User(name, id, User::accessLevel::None), role(role) {}

bool CrewMember::checkAccessLevel(accessLevel level) const {
    return false;
}

CrewMember::Role CrewMember::get_role() const {
    return (role == Role::Pilot) ? Role::Pilot : Role::Attendant;
}

void CrewMember::displayUser() const {
    if(role == Role::Pilot)
    {
        cout << "User Name: " << get_name() << "is a Pilot" << endl;
        cout << "ID: " << get_id() << endl;
    }
    else
    {
        cout << "User Name: " << get_name() << "is an Attendant" << endl;
        cout << "ID: " << get_id() << endl;
    }
}