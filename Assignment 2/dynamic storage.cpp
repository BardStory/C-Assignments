//https://github.com/tommyvct/COMP306TMA2/blob/master/src/TMA2Question2.cpp


#include <iostream>

using namespace std;

//main
int main() {
//Creates variables
int *i = new int[100];
long *l = new long[100];
char *ch = new char[100];
float *f = new float[100];

cout<<"Int @"<<i<<endl;
cout<<"long @"<<l<<endl;
cout<<"Char @"<<ch<<endl;
cout<<"float @"<<f<<endl;

for(int index=0 ;index<100;++index)

cout<<i[index];

cout<<endl;

for(int index=0 ;index<100;++index)

cout<<l[index];

cout<<endl;

for(int index=0 ;index<100;++index)

cout<<ch[index];

cout<<endl;

for(int index=0 ;index<100;++index)

cout<<f[index];

for(int index=0 ;index<100;++index)

f[index] = index+1;

char c ='a';

for(int index=0 ;index<26;++index){

ch[index] = c + index;

}

c = 'A';

int inc = 0;

for(int index=26 ;index<100;++index){

ch[index] = c + inc;

if(c + inc =='Z')

break;

inc++;

}

cout<<endl;

for(int index=0 ;index<100;++index)

cout<<ch[index];

delete i;

delete l;

delete ch;

delete f;

}