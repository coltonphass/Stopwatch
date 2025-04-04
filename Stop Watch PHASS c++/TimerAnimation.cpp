#include "TimerAnimation.h"
using namespace std;

TimerAnimation::TimerAnimation() {
    progressCounter = 0; 
    progressStriker = 0;
}

void TimerAnimation::StartAnimation() {
    // Progress bar animation logic
    if (progressStriker % 2 == 0)
        cout << ".";
    else
        cout << " ";

    progressCounter++;
    if (progressCounter == 80) {
        progressCounter = 1;
        progressStriker++;
        _putch(13);  // Carriage return
    }
}

void TimerAnimation::Reset() {
    progressCounter = 1;
    progressStriker = 0;
}
