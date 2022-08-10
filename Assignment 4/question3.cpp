#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

// This is the user defined template class for implementing SET.
template <class T>
class SetExample {

private:
vector<T> elems;

public:

void push(T const&);
void display();
};

// This template function is used to insert element into the SET.
template <class T>
void SetExample<T>::push (T const& elem) {
// calculate the size of the SET.
int size = elems.size();

// If the element to insert already exist in the SET, then return without inserting.
for(int i=0;i<size;i++){
if (!elem.compare(elems[i]))
return;
}

elems.push_back(elem);
}

// This template function is to display the elements in the SET.
template <class T>
void SetExample<T>::display () {
// calculate the size of the SET.
int size = elems.size();

for(int i=0;i<size;i++){
cout << elems[i] << " ";
}

cout << endl;
}

int main()
{
// This is set template from STL library.
std::set<std::string> setSTL;

// Inserting four elements
setSTL.insert("first");
setSTL.insert("second");
setSTL.insert("third");

// This is the duplicate element we are trying to insert into setSTL.
setSTL.insert("first");

// Display the elements in setSTL.
// As we can see in the output, there are no Duplicate entries.
cout << "Elements from STL Set" << endl;

for (std::set<std::string>::iterator it=setSTL.begin(); it!=setSTL.end(); ++it)
std::cout << ' ' << *it;

cout<<"\n";

// This is the user defined set from the template class.
SetExample<string> setUserDefined;

// Insert elements into the setUserDefined SET.
// Passing the same parameters as earlier.
setUserDefined.push("first");
setUserDefined.push("second");
setUserDefined.push("third");

// Insert duplicate element into setUserDefined SET.
setUserDefined.push("first");

// Display the elements in setUserDefined SET.
cout << "Elements from USER defined SET" << endl;
setUserDefined.display();

cout << "\n";

return 0;
}