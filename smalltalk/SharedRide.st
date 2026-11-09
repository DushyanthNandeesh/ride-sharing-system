"SharedRide.st"
Ride subclass: SharedRide [
    | passengers |

    SharedRide class >> id: anId from: pickup to: dropoff distance: miles passengers: n [
        ^(self id: anId from: pickup to: dropoff distance: miles) setPassengers: n
    ]

    setPassengers: n [ passengers := n < 1 ifTrue: [1] ifFalse: [n] ]
    passengers [ ^passengers ifNil: [2] ]

    "Cost is split between passengers, with a small pooling discount."
    fare [ ^(1.0 + (self distance * 1.1)) / self passengers ]
    rideType [ ^'Shared' ]
    rideDetails [ ^super rideDetails, ' | Passengers: ', self passengers printString ]
]
