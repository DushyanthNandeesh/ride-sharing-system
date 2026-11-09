"Rider.st"
Object subclass: Rider [
    | riderID name requestedRides |

    Rider class >> id: anId name: aName [
        ^self new setId: anId name: aName
    ]

    setId: anId name: aName [
        riderID := anId.
        name := aName.
        requestedRides := OrderedCollection new
    ]

    requestRide: aRide [ requestedRides add: aRide. ^aRide ]

    totalSpent [ ^requestedRides inject: 0 into: [:sum :r | sum + r fare] ]

    viewRides [
        ('Rider #', riderID printString, ' ', name, ' - ride history:') displayNl.
        requestedRides isEmpty ifTrue: [^'   (no rides yet)' displayNl].
        requestedRides do: [:r | ('   ', r rideDetails) displayNl].
        ('   Total spent: ', (requestedRides first formatMoney: self totalSpent)) displayNl
    ]
]
