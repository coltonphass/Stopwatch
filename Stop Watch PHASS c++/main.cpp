#pragma warning(disable:6031)

#include <iostream>
#include <conio.h>
#include "StopWatch.h"
#include "TimerAnimation.h"

using namespace std;

int main() {
    StopWatch myTimer;
    TimerAnimation animation;

    bool isValidInput = false;  // Flag to track valid input

    // Loop to ensure valid input for starting the stopwatch
    while (!isValidInput) {
        cout << "Press the space bar to start the stopwatch..." << endl;
        char input = _getch();  // Wait for key press

        if (input == ' ') {
            isValidInput = true;
            myTimer.Start();  // Start the timer
            cout << "The stopwatch has been started. Press Enter to record a lap or Space to stop the timer..." << endl;

            while (myTimer.IsTicking()) {
                animation.StartAnimation();  // Update the animation

                if (_kbhit()) {
                    input = _getch();  // Read key press

                    if (input == '\r') {
                        myTimer.Lap();  // Record lap

                        if (myTimer.hasLaps()) {
                            system("cls");  // Clear console
                            myTimer.DisplayAllLaps();  // Show laps
                        }

                        cout << "Press Enter to record another lap or Space to stop." << endl;
                    }
                    else if (input == ' ') {  // Space key (stop timer)
                        system("cls");  // Clear console
                        myTimer.Stop();  // Stop the timer

                        if (myTimer.hasLaps()) {
                            myTimer.DisplayAllLaps();
                        }
                        else {
                            cout << "No laps recorded." << endl;
                        }

                        myTimer.DisplayTimerInfo();  // Display total time
                        cout << "Stopwatch stopped!" << endl;
                        return 0;  // Exit program
                    }
                    else {
                        system("cls");
                        cout << "Invalid input! Press Enter to record a lap or Space to stop." << endl;
                    }
                }

                myTimer.sleep(10);  // Wait 10ms
            }
        }
        else {
            system("cls");
            cout << "Invalid input! Please press the space bar to begin." << endl;
        }
    }

    cout << "Press any key to exit..." << endl;
    _getch();  // Wait for user input before exiting
    return 0;
}
