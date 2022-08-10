#include <iostream>

using namespace std;

class Hen

{

public:

Hen()

{

cout<<"Hen object has been created"<<endl;

display();

}

~Hen()

{

cout<<"Hen object has been deleted"<<endl;

}

void display()

{

cout<<"you are in Hen class"<<endl;

}

class Egg

{

public:

Egg()

{

{

cout<<"Egg object has been created"<<endl;

display();

}

}

~Egg()

{

cout<<"Egg object has been deleted"<<endl;

}

void display()

{

cout<<"you are in Egg class"<<endl;

}

};

};

int main() {

Hen* hen=new Hen[1];

Hen::Egg* egg=new Hen::Egg[1];

delete[] egg;

delete[] hen;

return 0;

}