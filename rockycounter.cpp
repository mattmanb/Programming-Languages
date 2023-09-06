#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 
    Date of last revision: 
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  :
    */

   const string QUIT = "0";
   int Rocky_Counter = 0;
   string Increment;

   cout << "Current Rocky count: " << Rocky_Counter << '\n';
   cout << "Enter any key or word to increment rocky counter (0 to quit): ";
   cin >> Increment;
   
    while(Increment != QUIT) {
        Rocky_Counter++;
        cout << "\nCurrent Rocky count: " << Rocky_Counter << '\n';
        cout << "\nEnter any key to increment rocky counter (0 to quit): ";
        cin >> Increment;

    }

    return 0;
}
