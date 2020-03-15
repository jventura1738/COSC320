// Justin Ventura COSC220
// Used for Lab-3 in COSC320
#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <iostream>

class Timer {
private:
    // Vars keep track of start and end of the current timer.
    clock_t start_time, end_time;
public:
    // Constructor defines a timer.
    Timer();
    // Calling begins timing.
    void start_timer();
    // Calling stops the timer.
    void end_timer();
    // Returns the current time on the stopwatch.
    double get_time();
    // Resets timing to 0.
    void reset_time();
    // Returns the current time on the stopwatch.
    void display_time();
};

#endif
