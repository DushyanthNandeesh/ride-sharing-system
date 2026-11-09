// Ride.h - Base class and derived ride types (inheritance + polymorphism)
#ifndef RIDE_H
#define RIDE_H

#include <iomanip>
#include <sstream>
#include <string>

class Ride {
private:                         // Encapsulation: state hidden from outside code
    int         rideID_;
    std::string pickupLocation_;
    std::string dropoffLocation_;
    double      distance_;       // miles
    double      fare_;           // recorded by finalizeFare()

public:
    Ride(int id, std::string pickup, std::string dropoff, double distance)
        : rideID_(id), pickupLocation_(std::move(pickup)),
          dropoffLocation_(std::move(dropoff)), distance_(distance), fare_(0.0) {}

    virtual ~Ride() = default;   // virtual destructor: safe deletion via base pointer

    // Polymorphic behavior: subclasses override these.
    virtual double      fare() const { return distance_ * 1.25; }   // basic flat rate
    virtual std::string rideType() const { return "Basic"; }

    virtual std::string rideDetails() const {
        std::ostringstream out;
        out << "Ride #" << rideID_ << " [" << rideType() << "] "
            << pickupLocation_ << " -> " << dropoffLocation_
            << " | " << distance_ << " mi | Fare: $"
            << std::fixed << std::setprecision(2) << fare();
        return out.str();
    }

    // Stores the fare using the (virtual) fare() of the real object type.
    // Not called in the constructor because virtual calls there would not
    // reach the derived class's override.
    void finalizeFare() { fare_ = fare(); }

    // Public accessors (getters only: no setters, so data stays consistent)
    int                getRideID()          const { return rideID_; }
    const std::string& getPickupLocation()  const { return pickupLocation_; }
    const std::string& getDropoffLocation() const { return dropoffLocation_; }
    double             getDistance()        const { return distance_; }
    double             getRecordedFare()    const { return fare_; }
};

class StandardRide : public Ride {
public:
    using Ride::Ride;            // inherit constructor
    double      fare() const override { return 2.00 + getDistance() * 1.50; }
    std::string rideType() const override { return "Standard"; }
};

class PremiumRide : public Ride {
    std::string amenity_;
public:
    PremiumRide(int id, std::string pickup, std::string dropoff, double distance,
                std::string amenity = "Luxury sedan")
        : Ride(id, std::move(pickup), std::move(dropoff), distance),
          amenity_(std::move(amenity)) {}
    double      fare() const override { return 5.00 + getDistance() * 3.25; }
    std::string rideType() const override { return "Premium"; }
    std::string rideDetails() const override {      // extends the base output
        return Ride::rideDetails() + " | Amenity: " + amenity_;
    }
};

class SharedRide : public Ride {
    int passengers_;
public:
    SharedRide(int id, std::string pickup, std::string dropoff, double distance,
               int passengers = 2)
        : Ride(id, std::move(pickup), std::move(dropoff), distance),
          passengers_(passengers < 1 ? 1 : passengers) {}
    // Cost is split between passengers, with a small pooling discount.
    double      fare() const override { return (1.00 + getDistance() * 1.10) / passengers_; }
    std::string rideType() const override { return "Shared"; }
    std::string rideDetails() const override {
        return Ride::rideDetails() + " | Passengers: " + std::to_string(passengers_);
    }
};

#endif
