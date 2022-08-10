#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// the abstraction of a DVD class being used here
class DVD
{ string genre;
string type;
string year;
string dateRented;
string dateReturned;
string title;
public:
// various methods which may separately used for updating the respective fields
void setName (string z) {
title = z;
}
string getName(){
return title;
}

void setmovierating (string w) {
type = w;
}
string getmovierating (){
return type;
}
void setyear (string v){
year = v;
}
string getyear (){
return year;
}
void setdateRented (string u) {
dateRented = u;
}
string getdateRented (){
return dateRented;
}
void setdateReturned (string t) {
dateReturned = t;
}
string getdateReturned (){
return dateReturned;
}   
void setmoviegenre (string t) {
genre = t;
}
string getmoviegenre (){
return genre;
}
// Read one DVD from the input file
// Assumes one the mentioned set of fields in their respective orders per line in input file
bool Read (istream & is)
{   
is >> genre >> type >> year >> dateRented >> dateReturned >> title;
return is.good();
}
  
// Print one DVD
void Print (ostream & os) const
{ os << "Name: " << title << endl;
os << "Genre: " << genre << endl;
os << "Rated: " << type << endl;
os << "Date Released: " << year << endl;
os << "Date Rented: " << dateRented << endl;
os << "Date Returned: " << dateReturned << endl;
os << endl;
}

};

int main()
{ DVD a[10];
// using an ifstream object from the fstream library
ifstream dvdfile ("sample.txt"); // Declare and open the file of DVDs
int ent = 1; // for holding the current state of choice for a user
do{
       //Menu
       cout<<"----------------------------------";
       cout<<"\nSimple DVD Rental Management System";
       cout<<"\n----------------------------------";
       cout<<"\nWelcome Customer!";   //Menu for the user
       cout<<"\n\n\t <1> Display Rental Records";
       cout<<"\n\t <2> Exit \n\n";
       cout<<"Enter Your Choice :"<<"\t";
       cin>>ent;
   switch(ent)
   {
   case 1:
{
for(int i = 0; i<10; i++)
a[i].Read (dvdfile); // Read one DVD from the file
for(int i = 0; i<10; i++)   
a[i].Print (cout); // Print one DVD
  
cout << " These are the required records ! "<<endl;
ent = 0;
break;
  
}
  
default:
ent = 0;
break;
   }
  
}while(ent);
  
return 0;
}