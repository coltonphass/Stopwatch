#ifndef TIMERANIMATION_H
#define TIMERANIMATION_H

#include <iostream>
#include <conio.h>

class TimerAnimation {
private:
    int progressCounter;
    int progressStriker;

public:
    TimerAnimation();  // Constructor declaration

    void StartAnimation();  // Method to start the animation
    void Reset();           // Method to reset the animation
};

#endif
