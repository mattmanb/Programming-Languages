#include <iostream>

using namespace std;
int intdiv(void);

int N, D, Q, R;

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 1/26/23
    Date of last revision: 2/6/23
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : Reads global variables N and D, calls the intdiv function, and prints the
                           results after intdiv is called.
    */

   cout << "Enter the numerator: ";
   cin >> N;
   cout <<"Enter the denominator: ";
   cin >> D; 

   //N before its changed
   cout << "N: " << N;

   intdiv();

   cout<<"\nD: " << D;
   cout<<"\nQ: " << Q;
   cout<<"\nR: " << R << "\n";


    return 0;
}

int intdiv(void) {
    /*
    Author               : Matthew Barrington
    Date of creation     : 1/26/23
    Date of last revision: 2/6/23
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : Divides the global variables N and D, stores the quotient
                           in Q, and the remainder in R.
    */

   Q = 0;

   while(N >= D){
    N = N - D;
    Q += 1;
   }
   
   R = N;
   
   return 0;
}
