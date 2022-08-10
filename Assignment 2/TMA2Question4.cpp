//TMA2Question4.cpp
//Author Joshua Bard
//AU# 3453236
//Date June 24, 2020

/*Program Purpose:
Write a program in which you create a Text class that contains a string object
to hold the text of a file. Give it two constructors: a default constructor, 
and a constructor that takes a string argument that is the name of the file to open. 
When the second constructor is used, open the file and read the contents of the file into the 
string member object. Add a member function contents() to return the string 
so that you can display it. In main(), open a file using Text, and display the contents.


Plan of Attack:
	Create text class and constructors
    we want to loop every line of the file. We can use TMA1Question2 as a reference
    We then add a delimiter to each word and at the end we add the new line

    contents will just return the line after formatted

    MAIN:
    Error if no input is inserted
    exit

    loop 
    add new object and call contents



compile: g++ TMA4Question4.cpp -o TMA2Question4.exe
Execution: ./TMA4Question4 Testfiles\Test0

Testfiles Test0-3 Should work with no issue
-----------------------------------------------------------------
./TMA2Question4 Testfiles\Test0
Output:

File: Testfiles\Test0:
This is test0 and should work with no errors
-----------------------------------------------------------------
./TMA2Question4 Testfiles\Test1
Output:

File: Testfiles\Test1:
Test 1 is a longer
file that goes
on multiple lines
-----------------------------------------------------------------
Test 3 is a blank file so this is expected
./TMA2Question4 Testfiles\Test3
Output:

-----------------------------------------------------------------
Also works on multiple files as intended:
./TMA2Question4 Testfiles\Test3 Testfiles\Test0
Output:

File: Testfiles\Test1:
Test 1 is a longer
file that goes
on multiple lines

File: Testfiles\Test0:
This is test0 and should work with no errors
-----------------------------------------------------------------
An invalid testcase is when the testcase is not named example 5
./TMA2Question4 Testfiles\Test5

File: Testfiles\Test5:

(breaks system in infinite loop)

A solution would be add error handling somewhere before the loop
//Example of solution below
if(!file.good){
    new string("error no file")
    return
}

NOTE is does display error if no input is entered
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Text
{
	//This is the string object that denotes the pointer literal reference below
    //https://en.cppreference.com/w/cpp/language/nullptr
	string *tempString = nullptr;
    
    public:
    	//This is the default constructor which has no arguments
        Text()
        {}

        //This is the second constructor
        Text(string &filename)
        {
            ifstream file;
            file.open(filename, ios::in);

            this -> tempString = new string();
            //setting a delimiter 
            string delimeter = "";

            // loop to read every line of the file
            while(!file.eof())
            {
                getline(file, delimeter);
                *this -> tempString += delimeter;
                *this -> tempString += '\n';
            }

           file.close();
        }
     

    string contents()
    {
        return *this -> tempString;
    }

};

//For reference about the main used stack overflow solution
//https://stackoverflow.com/questions/3898021/regarding-mainint-argc-char-argv
//it goes in depth for covering the main argument and what argc and argv do in C and C++
int main(int argc, char const *argv[])
{
    //when no input is input will print No input file and return 1
    if (argc == 1)
    {
        cout << "No input file" << endl;
        //this is equivalent to exit as no need to continue without a input file
        return 1;
    }
    //loops based on file
    for (int i = 1; i < argc; i++)
    {

        cout << endl << "File: " << argv[i] << ":" << endl;
        //creates new Text object
        Text* object1 = new Text();
        object1 = new Text(*new string(argv[i]));
        //displays the input
        cout << object1 -> contents();
        //to free storage
        delete object1;
    }
    
return 0;
}