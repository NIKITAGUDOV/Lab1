#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


void printing()
{
    cout<< "\nEnter a digit from 1 to 8\n"
        << "1. Add pipe"<<"\n"
        << "2. Add CS" << "\n"
        << "3. View all objects" << "\n"
        << "4. Redact pipe" << "\n"
        << "5. Redact CS" << "\n"
        << "6. Save" << "\n"
        << "7. Load" << "\n"
        << "8. Exit" << "\n\n";
}

struct TRUBA {
    string name_tr;
    double len=0;
    double diam=0;
    bool rep;
};

struct KOMPRES {
    string name_ks;
    int workshops=0;
    int workshop_on=0;
    double effect;
};

void clc_p(TRUBA& tr)
{
    tr.name_tr = "";
    tr.len = 0;
    tr.diam = 0;
}

void clc_cs(KOMPRES& cs)
{
    cs.name_ks = "";
    cs.workshops = 0;
    cs.workshop_on = 0;
    cs.effect = 0;
}

int Add_pp(TRUBA& tr)
{
    cout << "Enter the name of pipe\n";
    cin >> tr.name_tr;

    double buft = 0;
    cout << "Enter the Lenght of pipe\n";
    cin >> buft;
    if (buft > 0)
    {
        tr.len = buft;
        buft = 0;
    }
    else
    {
        cout << "Incorrect data!\n";
        clc_p(tr);
        return 0;
    }

    cout << "Enter the Diameter of pipe\n";
    cin >> buft;
    if (buft > 0)
    {
        tr.diam = buft;
        buft = 0;
    }
    else
    {
        cout << "Incorrect data!\n";
        clc_p(tr);
        return 0;
    }

    cout << "Enter the status of repair:\n0 for inrepair\n1 for repaired\n";
    cin >> buft;
    if (buft == 0)
        tr.rep = 0;
    else if (buft == 1)
        tr.rep = 1;
    else
    {
        cout << "Incorrect data!\n";
        clc_p(tr);
        return 0;
    }
    cout << "\nPipe is added\n";
    return 0;
}

int Add_cs(KOMPRES& cs)
{
    cout << "Enter the name of kompres\n";
    cin >> cs.name_ks;
    int buf = 0;

    cout << "Enter the number of workshops\n";
    cin >> buf;
    if (buf > 0)
    {
        cs.workshops = buf;
        buf = 0;
    }
    else 
    {
        cout << "Ïncorrect data\n";
        clc_cs(cs);
        return 1;
    }

    cout << "Enter the number of working workshops\n";
    cin >> buf;
    if (buf > 0&&buf<=cs.workshops)
    {
        cs.workshop_on = buf;
        buf = 0;
    }
    else
    {
        cout << "Ïncorrect data\n";
        clc_cs(cs);
        return 1;
    }

    cout << "Enter the effectivity of kompres in %\n";
    double buft=0;
    cin >> buft;
    if (buft > 0 && buft < 100)
    {
        cs.effect = (buft / 100);
    }
    else
    {
        cout << "Ïncorrect data\n";
        clc_cs(cs);
        return 1;
    }
    cout << "\nkompres is added\n";
    return 0;
}

void seep(const TRUBA& tr)
{
    cout << "Name of pipe is "
        << tr.name_tr
        << "\nLenght of pipe is "
        << tr.len
        << "\nDiameter of pipe is "
        << tr.diam
        << "\nPipe is ";
    if (tr.rep == 'i')
        cout << "inrepair\n";
    else
        cout << "repaired\n";
}

void seecs(const KOMPRES& cs)
{
    cout << "Name of kompres is "
        << cs.name_ks
        << "\nNumber of workshops is "
        << cs.workshops
        << "\nNumber of working workshops is "
        << cs.workshop_on
        << "\nEffectivity is "
        << cs.effect * 100
        << "%\n";
}

void redact_p(TRUBA& tr)
{
    cout << "Enter the new characteristics of pipe or -1 if you dont want to redact it, if you will enter incorrect data characteristics will not change\n"
        << "Enter the name of pipe\n";
    string n;
    cin >> n;
    if (n!="-1")
        tr.name_tr=n;

    double buft = 0;
    cout << "Enter the Lenght of pipe\n";
    cin >> buft;
    if (buft > 0 && buft!=-1)
    {
        tr.len = buft;
        buft = 0;
    }

    cout << "Enter the Diameter of pipe\n";
    cin >> buft;
    if (buft > 0 && buft != -1)
    {
        tr.diam = buft;
        buft = 0;
    }

    cout << "Enter the status of repair:\n0 for inrepair\n1 for repaired\n";
    cin >> buft;
    if (buft == 0 && buft != -1)
        tr.rep = 0;
    else if (buft == 1 && buft != -1)
        tr.rep = 1;
    cout << "Pipe is redacted\n";
}

void redact_cs(KOMPRES& cs)
{
    cout << "Enter the new characteristics of kompres or -1 if you dont want to redact it, if you will enter incorrect data characteristics will not change\n";
    cout << "Enter the name of kompres\n";
    string n;
    cin >> n;
    if (n != "-1")
        cs.name_ks = n;
    int buf = 0;

    cout << "Enter the number of workshops\n";
    cin >> buf;
    if (buf > 0 && buf != -1)
    {
        cs.workshops = buf;
        buf = 0;
    }

    cout << "Enter the number of working workshops\n";
    cin >> buf;
    if (buf > 0 && buf <= cs.workshops && buf != -1)
    {
        cs.workshop_on = buf;
        buf = 0;
    }

    cout << "Enter the effectivity of kompres in %\n";
    double buft = 0;
    cin >> buft;
    if (buft > 0 && buft < 100 && buf != -1)
    {
        cs.effect = (buft / 100);
    }
    cout << "Kompres is redacted\n";
}

void Save_p(const TRUBA& tr)
{
    ofstream save("Lab_data_tr.txt");
    if (save.is_open())
    {
        save << tr.name_tr << "\n";
        save << tr.len << "\n";
        save << tr.diam << "\n";
        save << tr.rep << "\n";
        cout << "Pipe is saved\n";
    }
    else
        cout << "Unknown error!";
}

void Save_cs(const KOMPRES& cs)
{
    ofstream save("Lab_data_cs.txt");
    if (save.is_open())
    {
        save << cs.name_ks << "\n";
        save <<cs.workshops << "\n";
        save << cs.workshops << "\n";
        save << cs.workshop_on << "\n";
        cout << "Kompress is saved\n";
    }
    else
        cout << "Unknown error!";
}

void Load_p(TRUBA& tr)
{
    ifstream load("Lab_data_tr.txt");
    if (load.is_open())
    {
        load >> tr.name_tr;
        load >> tr.len;
        load >> tr.diam;
        load >> tr.rep;
        cout << "Pipe is loaded\n";
    }
    else
        cout << "Unknown error!";

}

void Load_cs(KOMPRES& cs)
{
    ifstream load("Lab_data_cs.txt");
    if (load.is_open())
    {
        load >> cs.name_ks;
        load >> cs.workshops;
        load >> cs.workshops;
        load >> cs.workshop_on;
        cout << "Kompres is loaded\n";
    }
    else
        cout << "Unknown error!";
}

int main()
{
   /* ofstream fin;
    fin.open("Lab_data.txt");
    cout << fin.is_open();
    fin.close();*/
    TRUBA tr1;
    KOMPRES cs;
    while (true)
    {
        printing();
        int un;
        cin >> un;
        switch (un)
        {
        case 1: 
            Add_pp(tr1);
            break;

        case 2:
            Add_cs(cs);
            break;

        case 3:
            if (tr1.len != 0 )
                seep(tr1);

            if (cs.workshops != 0)
                seecs(cs);

            if (tr1.len == 0 && cs.workshops == 0)
                cout << "There are no objects\n";

            break;

        case 4:
            if (tr1.len != 0)
                redact_p(tr1);

            else
                cout << "There is no pipe to redact\n";

            break;

        case 5:
            if (cs.workshops != 0)
                redact_cs(cs);

            else
                cout << "There is no kompres to redact\n";

            break;

        case 6:
            if (tr1.len != 0)
                Save_p(tr1);

            if (cs.workshops != 0)
                Save_cs(cs);

            if (tr1.len == 0 && cs.workshops == 0)
                cout << "There are no objects to save\n";

            break;

        case 7:
            Load_p(tr1);
            Load_cs(cs);
            break;
        case 8:
            return 0;
            break;

        default:
            cout << "Unknown command!";
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
}


