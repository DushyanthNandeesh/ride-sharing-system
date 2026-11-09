// main.cpp - Demo of the Ride Sharing System (C++)
#include <iostream>
#include <memory>
#include <vector>
#include "Ride.h"
#include "Driver.h"
#include "Rider.h"

int main() {
    // Polymorphism: one container, many ride types, accessed via base pointers
    std::vector<std::shared_ptr<Ride>> rides;
    rides.push_back(std::make_shared<StandardRide>(101, "Downtown", "Airport", 12.5));
    rides.push_back(std::make_shared<PremiumRide>(102, "Hotel Lobby", "Convention Center", 6.0, "Leather seats & water"));
    rides.push_back(std::make_shared<SharedRide>(103, "University", "Mall", 8.0, 3));
    rides.push_back(std::make_shared<StandardRide>(104, "Library", "Stadium", 4.2));
    rides.push_back(std::make_shared<Ride>(105, "Park", "Museum", 3.0));   // base-class object

    for (auto& r : rides) r->finalizeFare();

    std::cout << "===== Polymorphic fare() and rideDetails() =====\n";
    double total = 0;
    for (const auto& r : rides) {
        std::cout << r->rideDetails() << "\n";
        total += r->fare();
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Total fares for all rides: $" << total << "\n\n";

    // Drivers and riders
    Driver alice(1, "Alice Johnson", 4.9), bob(2, "Bob Martinez", 4.6);
    Rider  carol(10, "Carol Nguyen"),      dave(11, "Dave Smith");

    // Carol: rides 101 and 102; Dave: 103, 104, 105
    carol.requestRide(rides[0]); alice.addRide(rides[0]);
    carol.requestRide(rides[1]); alice.addRide(rides[1]);
    dave.requestRide(rides[2]);  bob.addRide(rides[2]);
    dave.requestRide(rides[3]);  bob.addRide(rides[3]);
    dave.requestRide(rides[4]);  bob.addRide(rides[4]);

    std::cout << "===== Drivers =====\n";
    std::cout << alice.getDriverInfo() << "\n";
    alice.viewAssignedRides();
    std::cout << bob.getDriverInfo() << "\n";
    bob.viewAssignedRides();

    std::cout << "\n===== Riders =====\n";
    carol.viewRides();
    dave.viewRides();

    // Encapsulation check: the following would NOT compile (private member):
    // alice.assignedRides_.clear();
    return 0;
}
