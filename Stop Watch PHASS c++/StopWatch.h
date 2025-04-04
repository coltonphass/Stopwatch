#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <iostream>
using namespace std;

class StopWatch {
private:
    clock_t startTime;
    clock_t lastLapTime;
    clock_t endTime;
    double lapTimes[10];  // Fixed-size array for storing lap times
    int lapCount;
    bool isTicking;       // Boolean to track stopwatch state

public:
    StopWatch();
    void sleep(clock_t delayInMS);   // Prof. Mark's delay function
    bool Start();                    // Start the stopwatch
    bool Stop();                     // Stop the stopwatch
    void Lap();                         // Record a lap time
    bool IsTicking() const;
    void DisplayTimerInfo() const;   // Display the total elapsed time
    void DisplayAllLaps() const;     // Display all recorded lap times
    double GetElapsedTime() const;   // Get the elapsed time in seconds
    bool hasLaps() const;            // Check if any laps are recorded
};

#endif
