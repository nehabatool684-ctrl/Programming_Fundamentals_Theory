PAC Chart

| Item | Description |
|---|---|
| Problem | Manage vehicle entry, parking eligibility, zone assignment, capacity, and parking summary |
| Input | Number of expected vehicles `N` |
| Input | Vehicle type: `C` = Car, `B` = Bike, `V` = Van |
| Input | User category: `F` = Faculty, `S` = Student, `G` = Visitor/Guest |
| Input | Parking permit: `Y` = Valid, `N` = Invalid |
| Input | Emergency vehicle status: `Y` or `N` when permit is invalid |
| Zone A | Faculty zone with maximum capacity of 20 vehicles/spaces |
| Zone B | Student zone with maximum capacity of 40 vehicles/spaces |
| Zone C | Visitor zone with maximum capacity of 15 spaces |
| Initialization | Set occupied spaces of all zones to 0 |
| Initialization | Set accepted, rejected, car, bike, and van counters to 0 |
| Validation | Reject and re-enter invalid vehicle type |
| Validation | Reject and re-enter invalid user category |
| Validation | Reject and re-enter invalid permit value |
| Validation | Ask for emergency status when permit is invalid |
| Faculty Rule | Faculty with valid permit may use Zone A |
| Student Rule | Students with valid permit may use Zone B |
| Visitor Rule | Visitors with valid permit may use Zone C |
| Faculty Van Rule | Faculty van may use Zone A only if sufficient space is available |
| Student Van Rule | Student van uses Zone B if available; otherwise redirect to Zone C if space is available |
| Visitor Car/Bike Rule | Visitor car or bike with valid permit may use Zone C |
| Visitor Van Rule | Visitor van requires at least 2 available spaces in Zone C |
| Bike Rule | Student bike with valid permit uses Zone B |
| Bike Rule | Faculty bike with valid permit uses Zone A |
| Emergency Rule | Emergency vehicle may enter regardless of permit status and is assigned according to user category |
| Invalid Permit | Non-emergency vehicle without a valid permit is rejected |
| Capacity Rule | Check sufficient capacity before assigning a vehicle |
| Space Usage | Car and bike consume 1 space |
| Space Usage | Van assigned to Zone C consumes 2 spaces |
| Alternative Zone | Apply alternative-zone rules when the preferred zone has insufficient space |
| Rejection | Reject vehicle if there is no suitable zone or available capacity |
| Update | Increase occupied capacity after successful parking |
| Update | Increase accepted counter for successful vehicles |
| Update | Increase rejected counter for rejected vehicles |
| Update | Increase car, bike, or van counter according to successfully parked vehicle |
| Loop | Process vehicles one at a time until all `N` vehicles are processed |
| Nested Loop | Repeatedly validate input until valid information is entered |
| Output | Assigned zone and remaining capacity for accepted vehicles |
| Output | Rejection reason for rejected vehicles |
| Summary | Display total vehicles processed |
| Summary | Display total accepted and rejected vehicles |
| Summary | Display successfully parked cars, bikes, and vans |
| Summary | Display final occupancy and remaining capacity of Zones A, B, and C |
| Summary | Display zone with the highest occupancy |
| Summary | Indicate whether the entire campus parking facility is full |
