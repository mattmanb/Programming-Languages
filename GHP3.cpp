#include <iostream>

using namespace std;

class Word_Square {
    public:

    Word_Square() { 
        /*****************************/
        /* The constructor queries   */
        /* the user for a string.    */
        /*****************************/
        cout << "Enter a sequence of characters: ";
        cin >> a;
    }

    void start_doing_cool_stuff() {
        /*****************************/
        /* This function sets up     */
        /* cool_stuff for recursion. */
        /*****************************/

        //sends 0 as the first "square_layer"
        cool_stuff(0);
        //haven't found the middle yet
        middle = false;
    }
    void cool_stuff(int square_layer) {
        /*******************************************************************/
        /* This is a recursive function. Each call prints a line, based on */
        /* the int variable "square_layer." Once the middle-most line is   */
        /* printed, the private class variable "middle" is set to true,    */
        /* which then makes future calls on the function decrement square_ */
        /* layer instead of increment. This goes until square_layer is 0.  */
        /*******************************************************************/

        int letters_printed = 0;
        //print left side of the middle characters for the line
        for(int i = 0; i < square_layer; i++) {
            cout << a[a.length() - 1 - i] << " ";
            letters_printed++;
        }
        //this prints the middle characters of the line (always executes at least once)
        while (letters_printed < get_side_length() - square_layer) {
            cout << a[a.length() - 1 - square_layer] << " ";
            letters_printed++;
        }
        //this prints the right side of the middle characters for the line
        for(int i = square_layer - 1; i >= 0; i--) {
            cout << a[a.length() - 1 - i] << " ";
            letters_printed++;
        }

        //newline
        cout << "\n";

        //if the middle hasn't been printed and this call isn't the middle print
        if(!middle && (square_layer < get_side_length() / 2)) {
            cool_stuff(square_layer + 1);
        }
        //if the square_layer is greater than 0, call cool_stuff and dec square_layer
        else if (square_layer > 0) {
            middle = true; //middle has been found, stop from incrememnting the square layer
            cool_stuff(square_layer - 1);
        }
        //end of recursion has been reached, return
        else
            return;
    }
    int get_side_length() {
        /********************************/
        /* This function is designed to */
        /* find the length of each line */
        /* in characters.               */
        /********************************/

        return 2 * a.length() - 1;

        /* EXPLANATION:
            1 2 3 4 5 6 7 8 9      =    a.length() * 2 - 1 = 5 * 2 - 1 = 9
            Y Y Y Y Y Y Y Y Y 1
            Y K K K K K K K Y 2
            Y K C C C C C K Y 3
            Y K C O O O C K Y 4
            Y K C O R O C K Y 5
            Y K C O O O C K Y 6
            Y K C C C C C K Y 7
            Y K K K K K K K Y 8
            Y Y Y Y Y Y Y Y Y 9
        */
    }

    private:
    string a; //queried for in the constructor
    bool middle; //bool value to determine of the middle line has been printed
};

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 3/29
    Date of last revision: 3/29
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : This program prints a concentric square of a string using
                           recursion.
    */

    Word_Square cool;

    cool.start_doing_cool_stuff();

    return 0;
}
