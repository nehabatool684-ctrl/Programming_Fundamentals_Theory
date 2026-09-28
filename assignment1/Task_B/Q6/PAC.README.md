PAC Chart

| Item | Description |
| :--- | :--- |
| Problem | Process hotel bookings for N guests and calculate final price and total hotel revenue |
| Input | Number of guests as (N) |
| Input | Season for each guest (Peak / Off-Peak) |
| Input | Room type for each guest (Standard / Deluxe / Suite) |
| Input | Number of nights stayed for each guest |
| Initial Value | `hotelRevenue = 0`, `rate = 0`, `total = 0`, `discount = 0` |
| Loop | Repeat for N guests (e.g., N=4) |
| Condition 1 | If `season == Peak` -> Standard = Rs.5000/night, Deluxe = Rs.8000/night, Suite = Rs.12000/night |
| Condition 2 | If `season == Off-Peak` -> Standard = Rs.3000/night, Deluxe = Rs.5000/night, Suite = Rs.8000/night |
| Condition 3 | If `nights > 7` -> Apply 15% long-stay discount |
| Formula | `total = rate * nights` |
| Formula | `finalPrice = total - discount` |
| Update | `hotelRevenue = hotelRevenue + finalPrice` after each guest |
| Output | Display final price for each guest |
| Final Output | Display total hotel revenue after loop ends |

 
