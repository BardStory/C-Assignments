//: TMA2Question4.cpp

/**
 * Title: TMA2Question4.cpp
 * Description:
 *      A program that display the given file contents.
 * Date: July 13, 2019
 * Author: Tommy Wu
 */

/**
 * DOCUMENTATION
 * 
 * Program Purpose:
 *      1. Create a Text class instance by using a constructor that accept a 
 *         string of filename.
 *      2. Read the file into a string object.
 *      3. Return the string by calling contents().
 *      4. Display returned string.
 *      5. Delete this Text instance.
 * 
 * Compile: clang++ TMA2Question4.cpp -o TMA2Question4
 * Execution : ./TMA2Question4 <file1> <file2> <file3> ...
 */

/*
    TEST PLAN (copied from TMA1Q2)

    normal case:
        > ./TMA2Question4 GoodFile1.txt GoodFile2.txt
        File "GoodFile1.txt":
        // ***file content***
        File "GoodFile2.txt":
        // ***file content***

    Bad case 1:
        > ./TMA2Question4 GoodFile1.txt nonexist.txt
        File "GoodFile1.txt":
        // ***file content***
        error: no such file or directory: nonexist.txt

    Bad case 2:
        > ./TMA2Question4 nonexist.txt GoodFile1.txt
        error: no such file or directory: nonexist.txt
        File "GoodFile1.txt":
        // ***file content***

    Bad case 3:
        > ./TMA2Question4 SpaceOnly.txt ZeroLength.txt
        File "SpaceOnly.txt":
        // lines of spaces
        File "ZeroLength.txt":

    Bad case 4:
        > ./TMA2Question4
        error: no input file.

    Bad case 5:
        > ./TMA2Question4 NonEnglishScript.txt
        File "NonEnglishScript.txt":
        // ***file content***

    Bad case 6: 
        > ./TMA2Question4 SpaceOnly.txt
        File "SpaceOnly.txt":
        // lines of spaces

    Discussion:
        This program will works properly on plain text files.
        These example files can be found in TMA2Test folder.
        These tests are included in test.sh
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Text
{
    private:
        string* holder = nullptr;
    
    public:
        // default constructor
        Text()
        {
            this -> holder = new string("Nothing is read!\n");
        }

        // constructor accepts filename
        Text(string& filename)
        {
            if (this -> holder != nullptr)  // if initialized, re-initialize it
            {
                delete this -> holder;
            }

            ifstream file;
            file.open(filename, ios::in);

            if (!file.good())  // check if a file is in good shape
            {
                this -> holder = 
                            new string("error: no such file or directory: ");
                *this -> holder += filename;
                return;
            }

            this -> holder = new string();
            string temp = "";

            // loop to read every line of the file
            while(!file.eof())
            {
                getline(file, temp);
                *this -> holder += temp;
                *this -> holder += '\n';
            }

            file.close();
        }

        // destructor
        ~Text()
        {
            if (this -> holder != nullptr)
            {
                delete this -> holder;
            }
        }

        // getter for the string object
        string contents()
        {
            return *this -> holder;
        }

};

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        cout << "Give me something to read!" << endl;
        
        return 1;
    }


    for (int i = 1; i < argc; i++)
    {
        cout << "File: " << argv[i]<< endl;
        Text* text = new Text();
        text = new Text(*new string(argv[i]));

        cout << text -> contents();

        delete text;
        cout << endl;
    }
    
    return 0;
} ///:~