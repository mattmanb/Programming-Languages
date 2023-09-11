#include <iostream>

using namespace std;

void sort(void);
void move(void);
void FindKay(void);

int n;
int* a;

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 2/22/23
    Date of last revision: 2/23/23
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : This main function sets the array size of integer array 'a',
    based on user unput, fills the array using user input, prints the array before it
    gets sorted, calls the 'sort' function, then prints the array after the sort is complete.
    */

   cout << "Enter array size: ";
   cin >> n;

   a = new int[n];

    //fill the array
    cout << "Fill the array:";
    for(int i = 0; i < n; i++) {
        cout << "\nPos " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << "Array order before sort:\n";
    for(int i = 0; i < n; i++) {
        cout << "Pos " << i+1 << ": " << a[i] << '\n';
    }

    sort();

    cout << "Array order after sort:\n";
    for(int i = 0; i < n; i++) {
        cout << "Pos " << i+1 << ": " << a[i] << '\n';
    }

    return 0;
}

int j;
void sort(void) {
    /*
    Author               : Matthew Barrington
    Date of creation     : 2/22/23
    Date of last revision: 2/23/23
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : for each integer in array 'a' not including the last index is
    compared to the next index, and if it is greater than its successor, then the 'move'
    function is called.
    */
    for(j = 0; j < n - 1; j++) {
        if(a[j] > a[j+1]) {
            move();
        }
    }
    return;
}

int temp;
int k;

void move(void) {
    /*
    Author               : Matthew Barrington
    Date of creation     : 2/22/23
    Date of last revision: 2/23/23
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : this function switches the successor interger in the array 
    into the current index, and puts the current index into position 'k', which is 
    found after calling the 'FindKay' function.
    */
    temp = a[j+1];
    a[j+1] = a[j];
    FindKay();
    a[k] = temp;

    return;
}

int sw;
void FindKay(void) {
    /*
    Author               : Matthew Barrington
    Date of creation     : 2/22/23
    Date of last revision: 2/23/23
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : FindKay is meant to find if the successor index is greater than
    any of the integers before the current index. If it is, then the successor index gets
    moved before all the values that are greater than itself until A. it gets to a value
    that is less than itself or B. it is less than all previous indexes.
    */
    k = j;
    sw = 0;
    while(k > 0 && sw == 0) {
        if(a[k - 1] > temp) {
            a[k] = a[k - 1];
            k--;
        }
        else {
            sw = 1;
        }
    }
    return;
}
