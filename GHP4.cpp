#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm> 

using namespace std;

class Word {
    public:
    //Default Constructor
    Word() {this -> Count = 0;}
    //Arg Constructor
    Word(string w) {
        SetWord(w);
    }
    ////////////////////////////////////////////////////////
    //Purpose: Returns the number of occurances for a Word//
    ////////////////////////////////////////////////////////
    int GetCount() {
        return this -> Count;
    }
    /////////////////////////////////
    //Purpose: Returns Word_Content//
    /////////////////////////////////
    string GetWord() {
        return Word_Content;
    }
    ///////////////////////////////////////////////
    //Purpose: Increments the Count of the obejct//
    ///////////////////////////////////////////////
    void IncCount() {
        this->Count++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    //Purpose: Sets the Word_Content of the object, makes it uppercase, and increments Count//
    //////////////////////////////////////////////////////////////////////////////////////////
    void SetWord(string w) {
        this->Count = 0;
        Word_Content = w;
        for(int i = 0; i < Word_Content.length(); i++) {
            toupper(Word_Content[i]);
        }
        IncCount();
    } 
    ////////////////////////////////////////
    //Purpose: Displays the word and Count//
    ////////////////////////////////////////
    void display() {
        cout << Word_Content << ": " << this->Count << "\n";
    }
    private:
    string Word_Content;
    int Count;
};

//Prototypes
bool CompareWords(Word A, Word B);

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 4/9
    Date of last revision: 4/9
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : This program will read a file's words. The words will be sorted
                           into two lists: one list containing words that start with 'd'
                           or 'D', and another with all other words. The words then get sorted
                           alphabetically, and displayed onto the screen along with the number
                           of occurances.
    */

    //local variables
    string File_Name; //name of the file
    string Current_Word; //placeholder of the current word being read in from the file
    vector<Word> D_Words; //'D words', vector of 'Word' objects
    int D_Count = 0; //Keeps track of how many unique words have been added to D_Words
    vector <Word> O_Words; //'Other words', vector of 'Word' objects
    int O_Count = 0; //Keeps track of how many unique words have been added to O_Words
    bool Found; //keeps track of if a reoccuring word appears

    /***   Main program   ***/
    //instantiate file input stream
    ifstream fileIn;

    //query the user for a file
    cout << "Enter a file name: ";
    cin >> File_Name;

    //Opens the file
    fileIn.open(File_Name.data());

    //Make sure the file is open
    assert(fileIn.is_open());

    //while words are being read in
    while(fileIn >> Current_Word) {
        //makes current word uppercase for comparison later
        for(int i = 0; i < Current_Word.length(); i++) {
            Current_Word[i] = toupper(Current_Word[i]);
        }
        //Initialize Found to false for each word
        Found = false;
        //if the word starts with 'D' or 'd'
        if(Current_Word[0] == 'D') {
            //check to see if the word has already occurred
            for(int i = 0; i < D_Count; i++) {
                //if the word has occured
                if(Current_Word == D_Words[i].GetWord()) {
                    //Increase the count of that word
                    D_Words[i].IncCount();
                    //Set found to true
                    Found = true;
                    break;
                }
            }
            //if the word hasn't occured
            if(!Found) {
                Word w(Current_Word);
                //set the next D_Word in the array to the Current_Word
                D_Words.push_back(w);
                //increase D_Count
                D_Count++;
            }
        }
        //if the word doesn't start with 'D' or 'd'
        else {
            //check to see if the word has already occurred
            for(int i = 0; i < O_Count; i++) {
                //if the word has occured
                if(Current_Word == O_Words[i].GetWord()) {
                    //Increase the count of that word
                    O_Words[i].IncCount();
                    //Set found to true
                    Found = true;
                    break;
                }
            }
            //if the word hasn't occured
            if(!Found) {
                Word w(Current_Word);
                //set the next O_Word in the array to the Current_Word
                O_Words.push_back(w);
                //increase O_Count
                O_Count++;
            }
        }
    }

    //Sort D_Words alphabetically
    sort(D_Words.begin(), D_Words.end(), CompareWords); 

    //Sort O_Words alphabetically
    sort(O_Words.begin(), O_Words.end(), CompareWords ); 

    //Display all D_Words
    cout << "\nWords in " << File_Name << " starting with 'D' or 'd'(Word: Occurances):\n";
    for(int i = 0; i < D_Words.size(); i++) {
        D_Words[i].display();
    }
    //Display all O_Words
    cout << "\nWords in " << File_Name << " starting with other characters (Word: Occurances):\n";
    for(int i = 0; i < O_Words.size(); i++) {
        O_Words[i].display();
    }

    //Format ouput
    cout << "\n";

    //close the file
    fileIn.close();

    return 0;
}

//key function for sorting a vector of 'Word' objects
bool CompareWords(Word A, Word B) {
    /*
    Author               : Matthew Barrington
    Date of creation     : 4/9
    Date of last revision: 4/9
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Function Description : This function is the key function for sorting
                           a vector of 'Word' objects alphabetically.
    */
    return A.GetWord() < B.GetWord();
}
