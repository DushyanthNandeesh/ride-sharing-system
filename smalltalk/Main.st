"Main.st - Demo of the Ride Sharing System (Smalltalk)"
| rides total alice bob carol dave |

"Polymorphism: one collection holding different ride types"
rides := OrderedCollection new.
rides add: (StandardRide id: 101 from: 'Downtown' to: 'Airport' distance: 12.5).
rides add: (PremiumRide id: 102 from: 'Hotel Lobby' to: 'Convention Center' distance: 6
                amenity: 'Leather seats & water').
rides add: (SharedRide id: 103 from: 'University' to: 'Mall' distance: 8 passengers: 3).
rides add: (StandardRide id: 104 from: 'Library' to: 'Stadium' distance: 4.2).
rides add: (Ride id: 105 from: 'Park' to: 'Museum' distance: 3).

'===== Polymorphic fare and rideDetails =====' displayNl.
total := 0.
rides do: [:r |
    r rideDetails displayNl.
    total := total + r fare].
('Total fares for all rides: ', (rides first formatMoney: total)) displayNl.
'' displayNl.

alice := Driver id: 1 name: 'Alice Johnson' rating: 4.9.
bob := Driver id: 2 name: 'Bob Martinez' rating: 4.6.
carol := Rider id: 10 name: 'Carol Nguyen'.
dave := Rider id: 11 name: 'Dave Smith'.

carol requestRide: (rides at: 1). alice addRide: (rides at: 1).
carol requestRide: (rides at: 2). alice addRide: (rides at: 2).
dave requestRide: (rides at: 3). bob addRide: (rides at: 3).
dave requestRide: (rides at: 4). bob addRide: (rides at: 4).
dave requestRide: (rides at: 5). bob addRide: (rides at: 5).

'===== Drivers =====' displayNl.
alice getDriverInfo displayNl.
alice viewAssignedRides.
bob getDriverInfo displayNl.
bob viewAssignedRides.
'' displayNl.

'===== Riders =====' displayNl.
carol viewRides.
dave viewRides.
