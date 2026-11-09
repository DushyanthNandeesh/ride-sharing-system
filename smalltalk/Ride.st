"Ride.st - Base class (GNU Smalltalk syntax)"
Object subclass: Ride [
    "Encapsulation: instance variables are private to the object in Smalltalk.
     They can only be reached through the methods defined below."
    | rideID pickupLocation dropoffLocation distance |

    Ride class >> id: anId from: pickup to: dropoff distance: miles [
        ^self new setId: anId from: pickup to: dropoff distance: miles
    ]

    "Prints a number with a fixed count of decimals using integer math only.
     (Some GNU Smalltalk builds crash when printing Floats such as 4.2.)"
    Ride class >> format: aNumber decimals: n [
        | scale scaled |
        scale := 10 raisedTo: n.
        scaled := (aNumber * scale) rounded.
        ^(scaled // scale) printString, '.', (scaled \\ scale printPaddedWith: $0 to: n)
    ]

    "Prints 12.5 as 12.5, 6 as 6, and 4.2 as 4.2."
    Ride class >> formatNumber: aNumber [
        | s |
        aNumber = aNumber truncated ifTrue: [^aNumber truncated printString].
        s := self format: aNumber decimals: 2.
        s last = $0 ifTrue: [s := s copyFrom: 1 to: s size - 1].
        ^s
    ]

    setId: anId from: pickup to: dropoff distance: miles [
        rideID := anId.
        pickupLocation := pickup.
        dropoffLocation := dropoff.
        distance := miles
    ]

    rideID [ ^rideID ]
    pickupLocation [ ^pickupLocation ]
    dropoffLocation [ ^dropoffLocation ]
    distance [ ^distance ]

    "Polymorphic protocol: subclasses override fare and rideType."
    fare [ ^distance * 1.25 ]
    rideType [ ^'Basic' ]

    formatMoney: amount [ ^'$', (Ride format: amount decimals: 2) ]

    rideDetails [
        ^'Ride #', rideID printString, ' [', self rideType, '] ',
          pickupLocation, ' -> ', dropoffLocation,
          ' | ', (Ride formatNumber: distance), ' mi | Fare: ', (self formatMoney: self fare)
    ]
]
