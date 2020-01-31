// Justin Ventura COSC220
// Used for Lab1 in COSC320
#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <iostream>

class Timer {
private:
    // keeps track of start and end of the current timer.
    clock_t start_time, end_time;
public:
    Timer();
    void start_timer();
    void end_timer();
    double get_time();
    void reset_time();
    void display_time();
};

#endif
