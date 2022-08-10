#include <iostream>
using namespace std;

class Rodent
{
protected:
int h, l;
public:
void values (int i, int j)
{
h=i; l=j;
}
virtual int count (void) =0;
};

class Mouse: public Rodent
{
public:
int count (void)
{
return (l);
}
};
class Beaver: public Rodent
{
public:
int count (void)
{
return (l);
}
};

class Gerbil: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Hamster: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Squirrel: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Rat: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Cavia: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Lemming: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Dormouse: public Rodent
{
public:
int count (void)
{
return (l);

}
};
class Paca: public Rodent
{
public:
int count (void)
{
return (l);

}
};
int main ()
{

Mouse m;
Gerbil g;
Hamster h;
Squirrel s;
Rat r;
Beaver b;
Cavia c;
Lemming e;
Dormouse d;
Paca p;
Rodent * rod[] = {&h,&c,&s,&m,&b,&e,&g,&d,&r,&p};

cout << "Total count of the Legs : " << endl;
for (int x = 0; x < 10; x++)
{
rod[x]->values(2*(x+1),2*(x+1));
cout << rod[x]->count() << '\n';
}

return 0;
}