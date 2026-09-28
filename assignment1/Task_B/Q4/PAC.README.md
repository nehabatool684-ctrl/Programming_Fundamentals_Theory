 PAC Chart

| Item | Description |
|---|---|
| Problem | Calculate and display the final shopping bill after discount and tax calculations |
| Input | Quantity `q` |
| Input | Price per item `p` |
| Input | Discount percentage `d` |
| Input | Tax percentage `t` |
| Validation | Check that all entered values are valid |
| Invalid Input | Display an appropriate error message and terminate the calculation |
| Subtotal | `s = q × p` |
| Discounted Amount | `a = s - (s × d) / 100` |
| Final Bill | `Final Bill = a + (a × t) / 100` |
| Storage | Store the calculation details |
| Document | Create a bill document |
| Output | Display the final bill to the customer |
| End | Stop the program after displaying the bill |
