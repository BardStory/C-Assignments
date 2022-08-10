//TMA4Question2
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/* Program Purpose
Using the Standard C++ Library vector as an underlying implementation, 
create a Set template class that accepts only one of each type of object that you put into it. 
Make a nested iterator class that supports the “end sentinel” concept in Unit 16. 
Write test code for your Set in main(), using both your Set template class and the Standard C++ 
Library set template to verify that the behaviour is correct.

compile: g++ TMA4Question3.cpp -o TMA4Question3 
EXECUTION ./TMA4Question3

Problems. I am struggling to understand the implementation of having a inner class iterator.
I dont quite understand its purpose even through using web and textbook resources.
Below is provided an example of set however it does not have hte iterator with "end sentinal"

*/
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;


template <class T>
class Set{
private:
	vector<T> vectors;

public:
	void UserInsert(T const&);
	void display();
	//Concepts of the code following are from the Thinking in C++ 2/e textbook
	//in the introducing iterators section
	class iterator;
	friend class iterator;
};
template <class T>
void Set<T> :: UserInsert (T const& components){
	int size = vectors.size();

	for(int i=0; i<size; i++){
		if(!components.compare(vectors[i])){
			return;
		}
	}

vectors.push_back(components);
}

template <class T>
void Set<T>::display(){
	int size = vectors.size();

	for(int i=0; i<size; i++){
		cout << vectors[i] << " ";
	}
	cout << endl;
}

int main(){

	cout << "Using the C++ Standard Library we receive the following results: " << endl;

	std::set<std::string> Original_Set_Setter;

	Original_Set_Setter.insert("object1");
	Original_Set_Setter.insert("object2");
	Original_Set_Setter.insert("object3");
	Original_Set_Setter.insert("object4");
	Original_Set_Setter.insert("object5");
	Original_Set_Setter.insert("object6");


	//This should not appear on the display
	Original_Set_Setter.insert("object2");
	Original_Set_Setter.insert("object3");
	Original_Set_Setter.insert("object3");

	for(std::set<std::string>::iterator it=Original_Set_Setter.begin(); it!=Original_Set_Setter.end(); ++it)std::cout << " " << *it;

	cout << endl;

	Set<string> User_Version;

	// I dont know why there is blank space at the start when using the library.
	//added one here for good measure
	User_Version.UserInsert(" object1");
	User_Version.UserInsert("object2");
	User_Version.UserInsert("object3");
	User_Version.UserInsert("object4");
	User_Version.UserInsert("object5");
	User_Version.UserInsert("object6");

	User_Version.UserInsert("object2");
	User_Version.UserInsert("object3");
	User_Version.UserInsert("object3");


	cout << "The version we made using the Set Class:" << endl;
	User_Version.display();

	cout << endl;

	return 0;
	}
