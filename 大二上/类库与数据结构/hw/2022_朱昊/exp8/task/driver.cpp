#include<iostream>
#include "driver.h"    // declares hashmapDriver class
using namespace std;

unsigned long hash_func::operator() (const string key)
{
    //please implement this!
}

void HashMapDriver::setUpFiles()
{
    const string INFILE_PROMPT =
        "Please enter the path for the input file: ";

    const string IN_FAILURE =
        "*** Error opening input file: ";

    string inFileName;

    cout << INFILE_PROMPT;
    cin >> inFileName; //get input file path and name
    inFile.open(inFileName.c_str(), ios::in); //open input file

    while (inFile.fail())
    {
        cout << endl << IN_FAILURE << inFileName << endl;
        cout << endl << INFILE_PROMPT;
        cin >> inFileName;
        inFile.open(inFileName.c_str(), ios::in); //open input file
    } // if input file incorrect

    getline(cin, inFileName);//eat ENTER key
} // setUpFiles

void HashMapDriver::readAndProcess()
{
    string curr_line;

    while (getline(inFile, curr_line)) //repeatealy read a new line into curr_line
                                        //from input file until EOF
                                        //and meanwhile set up the dictionary
    {
        //please implement this processing!

    } // while

    inFile.close(); //close input file
} // readAndProcess

void HashMapDriver::testDictionary()
{
    system("chcp 65001"); //set the encoding of console to UTF-8 if necessary

    string word;

    cout << endl << "Please input a word; input QUIT to quit." << endl;
    getline(cin, word); //read a new word from user input

    //please implement the testing!
        
}