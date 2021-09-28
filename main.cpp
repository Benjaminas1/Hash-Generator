#include "includes/functions.hpp"

using namespace std;

int main(){

    // string inputStr = "Lietuva!";
    // int hashed[64];

    // initialiseHash(hashed);

    // hashString(inputStr, hashed);

    // printHash(hashed);

    cout << "1. Input from command line" << endl
    << "2. Input from file" << endl
    << "3. Basic tests" << endl
    << "4. Hash function effectiveness test" << endl
    << "5. Collision test" << endl
    << "6. Diversity test" << endl;
    cout << endl;

    int choise;
    cin >> choise;

    switch(choise)
    {
        case 1:
            inputFromCmd();
            break;
        case 2:
            inputFromFile();
            break;
        case 3:
            basicTests();
            break;
        case 4:
            effectivenessTest();
            break;
        case 5:
            collisionTest();
            break;
        case 6:
            diversityTest();
            break;
    }

}