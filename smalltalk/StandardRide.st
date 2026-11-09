"StandardRide.st"
Ride subclass: StandardRide [
    fare [ ^2.0 + (self distance * 1.5) ]
    rideType [ ^'Standard' ]
]
