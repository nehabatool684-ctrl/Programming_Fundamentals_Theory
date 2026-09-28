## PAC Chart

| Item | Description |
|---|---|
| Problem | Process elevator floor requests and determine the elevator's motion |
| Input | Number of floor requests as (N) |
| Input | Requested floor for each request |
| Initial Value | `currentFloor = 0` |
| Loop | Repeat for N floor requests |
| Condition 1 | If `requestedFloor > currentFloor` → Display "Moving Up" |
| Condition 2 | If `requestedFloor < currentFloor` → Display "Moving Down" |
| Condition 3 | If `requestedFloor = currentFloor` → Display "Doors Opening" |
| Update | `currentFloor = requestedFloor` after each stop |
| Output | Movement message for each floor request |
| Final Output | Current floor after processing each request |
