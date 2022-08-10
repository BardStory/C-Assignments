//TMA2Question1
//Author Joshua Bard
//AU# 3453236
//Date June 24, 2020

/*Program Purpose:
Write a program to manage DVD rental in a “video” rental store. 
Create an abstract data type that represents a DVD in this store. 
Consider all the data and operations that may be necessary for the DVD type 
to work well within a rental management system. 
Include a print() member function that displays all the information about the DVD. 
Test your data type by creating an array of 10 DVD instances and filling them using information read from a test input file that you create.
Display the DVD information.

compile: g++ -o TMA2Question1 TMA2Question1.cpp
Execute ./TMA2Question1

Plan of Attack
first we create the abstract class called DVD that will have tools for dvds.
This will contain title,genre,date rented, if returned, rating 

Notes:
	The input file needs to have each section on a new line to work with this system
	
	Example of the testfile:						
	Spiderman 						
	Romance
	June 1st
	Yes
	9
	Yes

	Example of Output
	DVD Listed Below:
	Title: Spiderman
	Genre: Action
	Date Rented: June 1st
	Returned: Yes
	Rating: 9/10
	Is Blueray Available: Yes




*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DVD{
	//initialise variables
	string title;
	string genre;
	string dateRented;
	string isreturned;
	string rating;
	string Blueray;

//This contains all the getters and setters for setting and retrieving the DVD info
public:
	void setTitle(string temp1){
		title = temp1;
	}
	void setGenre(string temp2){
		genre = temp2;
	}
	void setDateRented(string temp3){
		dateRented = temp3;
	}
	void setReturned(string temp4){
		isreturned = temp4;
	}
	void setRating(string temp5){
		rating = temp5;
	}
	void setBlurayAvailable(string temp6){
		Blueray = temp6;
	}
	string getTitle(){
		return title;
	}
	string getGenre(){
		return genre;
	}
	string getDateRented(){
		return dateRented;
	}
	string getReturned(){
		return isreturned;
	}
	string getRating(){
		return rating;
	}
	string getBlurayAvailbale(){
		return Blueray;
	}
	//This will read each line and add that line to its category
	//I was trying to find ways to seperate words using a delimiter for easier access
	bool read_input(istream & is){
		getline(is, title);
		getline(is, genre);
		getline(is, dateRented);
		getline(is, isreturned);
		getline(is, rating);
		getline(is, Blueray);
		return is.good();
	}
	//print will print the outputs to the system in a organized format
	//it clearly seperates the dvds and core elements
	void print(ostream & os) const{
		os << "DVD Listed Below" << endl;
		os << "Title: " << title << endl;
		os << "Genre: " << genre << endl;
		os << "Date Rented: " << dateRented << endl;
		os << "Returned: " << isreturned << endl;
		os << "Rating: " << rating << "/10 " << endl;
		os << "Is Blueray Available: " << Blueray << endl;
		os << "___________________________________________________" << endl;
	}
};

int main()
{
	//creates a array to hold 10 dvds
	DVD dvd_array[10];
	ifstream thefile ("Testfile_DVD.txt");

	//Calls the read method 10 times then calls the print 10 times
	for(int i=0; i< 10; i++){
		dvd_array[i].read_input(thefile);
	}
	for(int i=0; i<10; i++){
		dvd_array[i].print(cout);
	}
	return 0;
}
