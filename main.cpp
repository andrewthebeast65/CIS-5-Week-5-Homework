// Andrew Savio
// CIS 5 - Week 5 - Homework 5: Rule engine lite
// Two inputs (score, attendance) -> exactly one of: invalid, pass, fail, warn.

#include <iostream>
using namespace std;

int main() {
    int score;
    int attendance;

    cout << "Score 0-100? ";
    cin >> score;

    cout << "Attendance percent? ";
    cin >> attendance;

    bool scoreInvalid = score < 0 || score > 100;
    bool attendanceInvalid = attendance < 0 || attendance > 100;

    // Pass is && and not ||: you have to clear BOTH bars. With ||, a 100 score
    // with 0 attendance would pass.
    // Thresholds are >= and not >: 70 and 75 are the stated passing marks, so
    // landing exactly on one counts.
    bool passes = score >= 70 && attendance >= 75;

    // Fail is ||: dropping under EITHER floor is enough to fail on its own.
    bool fails = score < 60 || attendance < 50;

    // Edge values (just below, exactly on, just above):
    //   score range low:        -1, 0, 1
    //   score range high:       99, 100, 101
    //   attendance range low:   -1, 0, 1
    //   attendance range high:  99, 100, 101
    //   score fail floor:       59, 60, 61
    //   score pass mark:        69, 70, 71
    //   attendance fail floor:  49, 50, 51
    //   attendance pass mark:   74, 75, 76

    // The invalid branches come first: otherwise a score of -3 would match
    // "score < 60" and print "fail" for a number that makes no sense.
    if (scoreInvalid) {
        cout << "Result: invalid score" << endl;
    } else if (attendanceInvalid) {
        cout << "Result: invalid attendance" << endl;
    } else if (passes) {
        cout << "Result: pass" << endl;
    } else if (fails) {
        cout << "Result: fail - score under 60 or attendance under 50" << endl;
    } else {
        cout << "Result: warn - borderline score or attendance" << endl;
    }

    return 0;
}
