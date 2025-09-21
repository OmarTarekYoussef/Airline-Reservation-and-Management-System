#pragma once

#include <iostream>
#include <string>


using namespace std;

class User {
    public:
        enum class accessLevel {
            Administrator,
            BookingAgent,
            Passenger,
            None
        };

        User(const string& name, const string& id, accessLevel access_Level);
        virtual void displayUser() const;
        virtual bool checkAccessLevel(accessLevel level) const;
        const string& get_name() const;
        const string& get_id() const;

    private:
        string name;
        string id;
        accessLevel access_Level;
};


class Administrator : public User {
    public:
        Administrator(const string& name, const string& id);
        bool checkAccessLevel(accessLevel level) const;
        void displayUser() const override;
};


class BookingAgent : public User {
    public:
        BookingAgent(const string& name, const string& id);
        bool checkAccessLevel(accessLevel level) const;
        void displayUser() const override;
};


class Passenger : public User {
    public:
        Passenger(const string& name, const string& id);
        bool checkAccessLevel(accessLevel level) const;
        void displayUser() const override;
};


class CrewMember : public User {
    public:
        enum class Role {
            Pilot,
            Attendant
        };

        CrewMember(const string& name, const string& id, Role role);
        bool checkAccessLevel(accessLevel level) const;
        Role get_role() const;
        void displayUser() const override;

    private:
        Role role;
};