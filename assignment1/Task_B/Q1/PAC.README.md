## PAC Chart

| Item | Description |
| :--- | :--- |
| Problem | Process hotel bookings for N guests and calculate final price and total revenue |
| Input | Number of guests as (N) |
| Input | Season for each guest (Peak / Off-Peak) |
| Input | Room type for each guest (Standard / Deluxe / Suite) |
| Input | Number of nights stayed for each guest |
| Initial Value | `hotelRevenue = 0`, `rate = 0` |
| Loop | Repeat for N guests |
| Condition 1 | If `season == Peak` -> `Standard=5000, Deluxe=8000, Suite=12000` |
| Condition 2 | If `season == Off-Peak` -> `Standard=3000, Deluxe=5000, Suite=8000` |
| Condition 3 | If `nights > 7` -> Apply 15% discount `discount = total * 0.15` |
| Condition 4 | If `nights <= 7` -> `discount = 0` |
| Formula 1 | `total = rate * nights` |
| Formula 2 | `finalPrice = total - discount` |
| Update | `hotelRevenue = hotelRevenue + finalPrice` after each guest |
| Output | Final price for each guest |
| Final Output | Total hotel revenue after processing all guests |

