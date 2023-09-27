#include <string>
#include <vector>
#include <iostream>

using namespace std;


void printing()
{
    cout<< "1. Add pipe"<<"\n"
        << "2. Add CS" << "\n"
        << "3. View all objects" << "\n"
        << "4. Redact pipe" << "\n"
        << "5. Redact CS" << "\n"
        << "6. Save" << "\n"
        << "7. Load" << "\n"
        << "0. Exit" << "\n";
}

void main()
{
    struct TRUBA {
        string name_tr; 
        double len;
        double diam;
        bool rep;
    } TRUBA1;

    struct KOMPRES {
        string name_ks;
        int workshops;
        int workshop_on;
        double effect;
    } KOMPRES1;
    printing();

    while (true)
    {
        printing();
        int un;
        cin >> un;
        switch (un)
        {
        case 1: 
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        default:
            cout << "Unknown command!";
            break;
        }
    }
}


