#include <iostream>

#include <fstream>

using namespace std;

class DVD{

	string title;

	int rate;

	bool instock;

	public:

DVD(){

	title="";

	rate=0;

	instock=false;

	}

void setvalue(string t,int r,bool stock){

title=t;

rate=r;

instock=stock;

}

int rent(int day){

if(title.empty())

return 0;

instock=false;

return day*rate;

}

void print(){

cout<<"DVD Title: "<<title<<" \tRate:"<<rate<<" \tIn Stock"<<instock<<endl;

}

};
//------------------------------------------------------------------------------
int main()

{

string name;
int rate;
int totalrent=0;

ifstream iptr("dumbtest"); //file pointer

DVD dvd[10];

for(int i=0;i<10;i++)

{

iptr>>name>>rate; //read file name and rate

dvd[i].setvalue(name,rate,true); //set value for object

}

for(int i=0;i<10;i++) //print dvd array

dvd[i].print();

//rent some dvds

totalrent+=dvd[1].rent(10);

totalrent+=dvd[3].rent(5);

totalrent+=dvd[7].rent(2);

totalrent+=dvd[0].rent(7);

cout<<"Total rent "<<totalrent<<endl;

for(int i=0;i<10;i++) //print dvds after rent

dvd[i].print();

iptr.close();

return 0;

}