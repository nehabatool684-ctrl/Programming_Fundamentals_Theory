## IPO Chart

| Input | Process | Output |
|---|---|---|
| Quantity `q` | Validate quantity | Error message if input is invalid |
| Price per item `p` | Validate price | Error message if input is invalid |
| Discount percentage `d` | Validate discount percentage | Error message if input is invalid |
| Tax percentage `t` | Validate tax percentage | Error message if input is invalid |
| | Calculate Subtotal: `s = q × p` | Subtotal |
| | Calculate Discounted Amount: `a = s - (s × d) / 100` | Discounted Amount |
| | Calculate Final Bill: `Final Bill = a + (a × t) / 100` | Final Bill |
| | Store calculation details | Bill document |
| | Generate bill document | Final bill displayed to customer |
| | Display final bill | |

