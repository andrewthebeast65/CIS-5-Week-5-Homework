## How to run
g++ -std=c++17 -o program main.cpp && ./program

## Decision table
| Score | Attendance | Result |
|-------|------------|--------|
| -3 | 90 | invalid score |
| 72 | 140 | invalid attendance |
| 72 | 90 | pass |
| 72 | 60 | warn |
| 72 | 40 | fail |
| 55 | 90 | fail |
| 59 | 90 | fail (edge: just below score floor) |
| 60 | 90 | warn (edge: exactly on score floor) |
| 69 | 90 | warn (edge: just below pass mark) |
| 70 | 90 | pass (edge: exactly on pass mark) |
| 70 | 74 | warn (edge: just below attendance mark) |
| 70 | 75 | pass (edge: exactly on attendance mark) |
| 70 | 49 | fail (edge: just below attendance floor) |
| 70 | 50 | warn (edge: exactly on attendance floor) |

## Sample run
Score 0-100? 72
Attendance percent? 90
Result: pass
