PAC Chart

| Item | Description |
|---|---|
| Problem | Process 5 subject marks for each student and classify the student |
| Input | N students and 5 marks for each student |
| Processing | Calculate total and average |
| Loop 1 | Repeat for N students |
| Loop 2 | Repeat 5 times for each student's subjects |
| Condition 1 | If mark < 33, subject deficiency = true |
| Condition 2 | If average >= 80, result = Distinction |
| Condition 3 | If average >= 60 and < 80, result = Pass |
| Condition 4 | If average < 60, result = Fail |
| Override | If any mark < 33, result = Fail — Subject Deficiency |
| Output | Total, average, and final result |
