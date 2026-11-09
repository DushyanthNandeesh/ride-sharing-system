"PremiumRide.st"
Ride subclass: PremiumRide [
    | amenity |

    PremiumRide class >> id: anId from: pickup to: dropoff distance: miles amenity: aString [
        ^(self id: anId from: pickup to: dropoff distance: miles) setAmenity: aString
    ]

    setAmenity: aString [ amenity := aString ]
    amenity [ ^amenity ifNil: ['Luxury sedan'] ]

    fare [ ^5.0 + (self distance * 3.25) ]
    rideType [ ^'Premium' ]
    rideDetails [ ^super rideDetails, ' | Amenity: ', self amenity ]
]
