#include "StopWatch.h"
#include <iostream>
#include <time.h>
using namespace std;

// Constructor initializes times and lap count
StopWatch::StopWatch() {
    startTime   = 0;
    endTime     = 0;
    lastLapTime = 0;
    lapCount    = 0;
    isTicking   = false;

    // Initialize lapTimes array to 0
    for (int i = 0; i < 10; ++i) {
        lapTimes[i] = 0; // Set each lap time to 0
    }
}

// Start the stopwatch
bool StopWatch::Start() {
    if (!isTicking) {
        startTime = clock();
        lastLapTime = startTime;
        lapCount = 0;  // Reset lap count when stopwatch starts
        isTicking = true;
        return true;
    }
    return false;
}

// Record a lap time
void StopWatch::Lap() {
    if (!isTicking) return;  // Only allow laps if the stopwatch is ticking

    clock_t currentTime = clock();
    double lapDuration = double(currentTime - lastLapTime) / CLOCKS_PER_SEC;

    if (lapCount < 10) {  // Ensure we don't exceed the array size
        lapTimes[lapCount] = lapDuration; // Store the lap duration
        lapCount++;
    }
    else {
        cout << "Maximum number of laps reached!" << endl;
    }

    lastLapTime = currentTime;
}

// Check if any laps have been recorded
bool StopWatch::hasLaps() const {
    return lapCount > 0;
}

// Prof. Mark's delay function
void StopWatch::sleep(clock_t delayInMS) {
    clock_t targetTime = clock() + delayInMS;
    while (clock() < targetTime);
}

// Display all recorded laps
void StopWatch::DisplayAllLaps() const {
    cout << "Lap Times:\n";
    for (int i = 0; i < lapCount; ++i) {
        cout << "Lap " << (i + 1) << ": " << lapTimes[i] << " seconds" << endl;
    }
}

// Stop the stopwatch
bool StopWatch::Stop() {
    if (isTicking) {
        endTime = clock();
        isTicking = false;
        return true;
    }
    return false;
}

// Check if the stopwatch is ticking
bool StopWatch::IsTicking() const {
    return isTicking;
}

// Calculate and Display total elapsed time
void StopWatch::DisplayTimerInfo() const {
    double elapsedTime = GetElapsedTime();
    int minutes = int(elapsedTime) / 60;
    double seconds = elapsedTime - (minutes * 60);

    // Print to console with 4 decimal precision
    cout << "Total time: " << minutes << " minute(s), "
        << seconds << " second(s) (total of seconds: " << elapsedTime << " )" << endl;
}

// Get the elapsed time in seconds 
double StopWatch::GetElapsedTime() const {
    if (isTicking) {
        return double(clock() - startTime) / CLOCKS_PER_SEC;
    }
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}
