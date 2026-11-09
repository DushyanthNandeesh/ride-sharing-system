// Driver.h - Driver keeps its ride list private (encapsulation)
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Ride.h"

class Driver {
private:
    int         driverID_;
    std::string name_;
    double      rating_;
    std::vector<std::shared_ptr<Ride>> assignedRides_;   // not directly reachable

public:
    Driver(int id, std::string name, double rating)
        : driverID_(id), name_(std::move(name)), rating_(rating) {}

    void addRide(std::shared_ptr<Ride> ride) {
        if (ride) assignedRides_.push_back(std::move(ride));
    }

    double totalEarnings() const {
        double total = 0;
        for (const auto& r : assignedRides_) total += r->fare();   // polymorphic call
        return total;
    }

    std::size_t rideCount() const { return assignedRides_.size(); }

    std::string getDriverInfo() const {
        std::ostringstream out;
        out << "Driver #" << driverID_ << " " << name_ << " | Rating: "
            << std::fixed << std::setprecision(1) << rating_
            << " | Rides completed: " << assignedRides_.size()
            << " | Earnings: $" << std::setprecision(2) << totalEarnings();
        return out.str();
    }

    void viewAssignedRides() const {
        for (const auto& r : assignedRides_) std::cout << "   " << r->rideDetails() << "\n";
    }
};

#endif
