 IPO Chart

| Input | Process | Output |
|---|---|---|
| Number of floor requests `N` | Let `currentFloor = 0` | Motion message for each request |
| Requested floor | Compare requested floor with current floor | `"Moving Up"` |
| | If requested floor > current floor | `"Moving Down"` |
| | If requested floor < current floor | `"Doors Opening"` |
| | If requested floor = current floor | Updated current floor |
| | Update `currentFloor = requestedFloor` after each stop | |
| | Repeat the process for all `N` requests times | |

