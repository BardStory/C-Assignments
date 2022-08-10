//: TMA2Question3.cpp

/**
 * Title: TMA2Question3.cpp
 * Description:
 *      Matryoshka doll of classes.
 * Date: July 13, 2019
 * Author: Tommy Wu
 */

/**
 * DOCUMENTATION
 * 
 * Program Purpose:
 *      1. Create an instance of Hen, Nest and Egg classes.
 *      2. Create them using constructor
 *      3. Call display() of each classes.
 *      4. Delete them using destructor.
 * 
 * Compile: clang++ TMA2Question3.cpp -o TMA2Question3
 * Execution : ./TMA2Question3
 */

/**
 * No test available for a fully static program.
 * 
 * The program should generate following output:
 *  Hen Created!
 *  Nest Created!
 *  Egg Created!
 *  display Hen!
 *  display Nest!
 *  display Egg!
 *  Hen Destroyed!
 *  Nest Destroyed!
 *  Egg Destroyed!
 */

#include <iostream>

using namespace std;

class Hen
{
    public:
        // constructor
        Hen()
        {
            cout << "Hen Created!" << endl;
        }

        // destructor
        ~Hen()
        {
            cout << "Hen Destroyed!" << endl;
        }

        void display()
        {
            cout << "display Hen!" << endl;
        }

        class Nest
        {
            public:
                // constructor
                Nest()
                {
                    cout << "Nest Created!" << endl;
                }

                // destructor
                ~Nest()
                {
                    cout << "Nest Destroyed!" << endl;
                }

                void display()
                {
                    cout << "display Nest!" << endl;
                }

                class Egg
                {
                    public:
                        // constructor
                        Egg()
                        {
                            cout << "Egg Created!" << endl;
                        }

                        // destructor
                        ~Egg()
                        {
                            cout << "Egg Destroyed!" << endl;
                        }

                        void display()
                        {
                        cout << "display Egg!" << endl;}

                };
        };
};

int main()
{
    Hen* hen = new Hen();
    Hen::Nest* nest = new Hen::Nest();
    Hen::Nest::Egg* egg = new Hen::Nest::Egg();

    hen -> display();
    nest -> display();
    egg -> display();

    delete hen;
    delete nest;
    delete egg;

    return 0;
} ///:~