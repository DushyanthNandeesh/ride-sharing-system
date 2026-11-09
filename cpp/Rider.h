// Rider.h
#ifndef RIDER_H
#define RIDER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Ride.h"

class Rider {
private:
    int         riderID_;
    std::string name_;
    std::vector<std::shared_ptr<Ride>> requestedRides_;

public:
    Rider(int id, std::string name) : riderID_(id), name_(std::move(name)) {}

    void requestRide(std::shared_ptr<Ride> ride) {
        if (ride) requestedRides_.push_back(std::move(ride));
    }

    double totalSpent() const {
        double total = 0;
        for (const auto& r : requestedRides_) total += r->fare();
        return total;
    }

    void viewRides() const {
        std::cout << "Rider #" << riderID_ << " " << name_ << " - ride history:\n";
        if (requestedRides_.empty()) { std::cout << "   (no rides yet)\n"; return; }
        for (const auto& r : requestedRides_) std::cout << "   " << r->rideDetails() << "\n";
        std::cout << "   Total spent: $" << std::fixed << std::setprecision(2)
                  << totalSpent() << "\n";
    }
};

#endif
