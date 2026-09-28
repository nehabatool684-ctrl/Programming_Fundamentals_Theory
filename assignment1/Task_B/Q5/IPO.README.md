IPO Chart

| Input | Process | Output |
|---|---|---|
| Number of expected vehicles `N` | Let Zone A capacity = 20, Zone B capacity = 40, Zone C capacity = 15 | Allotted zone for each accepted vehicle |
| Vehicle type: C, B, or V | Validate vehicle type | Remaining capacity of assigned zone |
| User category: F, S, or G | Validate user category | Reason for rejected vehicles |
| Parking permit: Y or N | Validate permit value | Total vehicles processed |
| Emergency vehicle: Y or N when permit is invalid | Validate emergency status | Total accepted vehicles |
| | Process each vehicle using iteration | Total rejected vehicles |
| | Determine eligibility using nested conditions | Successfully parked cars |
| | Check available capacity in the appropriate zone | Successfully parked bikes |
| | Apply alternative-zone rules when needed | Successfully parked vans |
| | Assign parking zone if eligible and space is available | Final occupancy of Zone A, B, and C |
| | Van in Zone C consumes 2 spaces | Remaining capacity of Zone A, B, and C |
| | Car/Bike consumes 1 space | Zone with highest occupancy |
| | Update zone occupancy and vehicle counters | Whether entire campus parking is full |
| | Repeat until all N vehicles are processed | Parking summary |

