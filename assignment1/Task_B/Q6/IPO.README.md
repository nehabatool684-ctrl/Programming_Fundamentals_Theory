IPO Chart

| Item | Description |
| :--- | :--- |
| Input | N (Number of guests) |
| Input | season (Peak / Off-Peak) |
| Input | roomType (Standard / Deluxe / Suite) |
| Input | nights (Number of nights) |
| Processing | 1. Initialize `hotelRevenue = 0` |
| Processing | 2. Start loop `i=1 to N` |
| Processing | 3. Determine `rate` using nested if: <br> `IF Peak -> 5000/8000/12000 ELSE Off-Peak -> 3000/5000/8000` |
| Processing | 4. Calculate `total = rate * nights` |
| Processing | 5. Check `IF nights > 7 THEN discount = total*0.15 ELSE discount=0` |
| Processing | 6. Calculate `finalPrice = total - discount` |
| Processing | 7. Accumulate `hotelRevenue += finalPrice` |
| Processing | 8. Repeat loop until N guests processed |
| Output | Final price of each guest (`finalPrice`) |
| Output | Total revenue of hotel (`hotelRevenue`) |
