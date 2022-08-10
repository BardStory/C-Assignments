#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DVD
{       string productName; 
        string movieGenre;
        string client;
        string dateRented;
        string rentReturn;
public:
        void setproductName (string z) {
            productName = z;
        }
        string getproductName(){
            return productName;
        }

        void setmovieGenre (string w) {
            movieGenre = w;
        }
        string getmovieGenre (){
            return movieGenre;
        }
        void setclient (string v){
            client = v;
        }
        string getclient (){
            return client;
        }
        void setdateRented (string u) {
            dateRented = u;
        }
        string getdateRented (){
            return dateRented;
        }
        void setrentReturn (string t) {
            rentReturn = t;
        }
        string getrentReturn (){
            return rentReturn;
        }   
        
    //  Read one DVD from the input file
    //  Assumes one field per line in input file
    bool Read (istream & is)
    {   getline (is, productName);
        getline (is, movieGenre);
        getline (is, client);
        getline (is, dateRented);
        getline (is, rentReturn);
        return is.good();
    }
    
    //  Print one DVD
    void Print (ostream & os) const
    {   os << "Product: " << productName << endl;
        os << "Genre: " << movieGenre << endl;
        os << "Client: " << client << endl;
        os << "Date Rented: " << dateRented << endl;
        os << "Date Returned: " << rentReturn << endl;
    }

 };

 int main()
{   DVD a[10];
    ifstream dvdfile ("Testfile_DVD");    //  Declare and open the file of DVDs
    
    for(int i = 0; i<10; i++)
        a[i].Read (dvdfile);        //  Read one DVD from the file
    for(int i = 0; i<10; i++)   
        a[i].Print (cout);          //  Print one DVD 
    system ("pause");
    return 0;
 }