"Driver.st - assignedRides is private; only addRide: and the query methods expose it"
Object subclass: Driver [
    | driverID name rating assignedRides |

    Driver class >> id: anId name: aName rating: aRating [
        ^self new setId: anId name: aName rating: aRating
    ]

    setId: anId name: aName rating: aRating [
        driverID := anId.
        name := aName.
        rating := aRating.
        assignedRides := OrderedCollection new
    ]

    addRide: aRide [ assignedRides add: aRide. ^aRide ]

    rideCount [ ^assignedRides size ]

    totalEarnings [
        ^assignedRides inject: 0 into: [:sum :r | sum + r fare]    "polymorphic send"
    ]

    getDriverInfo [
        ^'Driver #', driverID printString, ' ', name,
          ' | Rating: ', (Ride format: rating decimals: 1),
          ' | Rides completed: ', self rideCount printString,
          ' | Earnings: ', ((assignedRides isEmpty) ifTrue: ['$0.00']
                ifFalse: [assignedRides first formatMoney: self totalEarnings])
    ]

    viewAssignedRides [
        assignedRides do: [:r | ('   ', r rideDetails) displayNl]
    ]
]
