#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Text {
       string text;

       public:
       Text(){}; //default constructor
       Text(string file)
       { //constructor with filename argument
              string line;
              ifstream myfile (file.c_str());
              
              if (myfile.is_open())
              {
              
              while ( getline (myfile,line) )
              {
                     text += line + '\n';
              }
                     myfile.close();
              }
};

string contents()
{ // contents function
return text;
}
};

int main()
{
Text text1; //text
Text text2 ("file1.txt"); //text object 2
//print output
cout << "text1: " << text1.contents() << endl;
cout << "text2: " << text2.contents() << endl;
}