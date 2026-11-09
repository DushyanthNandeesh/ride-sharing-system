# Ride Sharing System (Smalltalk and C++)

An object-oriented ride sharing system implemented twice to demonstrate
encapsulation, inheritance, and polymorphism.

## Classes
- `Ride` - base class (rideID, pickup, dropoff, distance, fare, rideDetails)
- `StandardRide`, `PremiumRide`, `SharedRide` - override `fare()` (and `rideDetails()` where extended)
- `Driver` - private list of assigned rides, `addRide`, `getDriverInfo`
- `Rider` - private list of requested rides, `requestRide`, `viewRides`

## Run the C++ version
```
cd cpp
g++ -std=c++17 -Wall -Wextra -o ride_demo main.cpp
./ride_demo
```

## Run the Smalltalk version (GNU Smalltalk 3.2+)
```
cd smalltalk
gst Ride.st StandardRide.st PremiumRide.st SharedRide.st Driver.st Rider.st Main.st
```
