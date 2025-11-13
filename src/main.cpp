//Bartosz Malolepszy

#include <iostream>
#include <fstream>

using namespace std;

string z3_1_path_symbole_txt = "../zalaczniki-2025/symbole.txt";

bool czy_palindrom(string slowo)
{
    int dlugosc = slowo.length();
    for(int i = 0; i < dlugosc / 2; i++)
    {
        if(slowo[i] != slowo[dlugosc - i - 1])
        {
            return false;
        }
    }
    return true;
}

void zadanie2_1()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
    }

    ofstream wyniki("wynik2_1.txt");

    string linia;
    while(plik >> linia)
    {
        if (czy_palindrom(linia))
        {
            cout << linia << endl;
            wyniki << linia <<endl;
        }
    }

    plik.close();
    wyniki.close();
}


int main(){

    ifstream plik("../zalaczniki-2025/symbole.txt");
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
        return 1;
    }

    vector<string> linie;
    string linia;
    
    while(getline(plik, linia))
    {
        if(!linia.empty())
        {
            linie.push_back(linia);
        }
    }
    plik.close();

    int liczba_kwadratow = 0;
    vector<pair<int, int>> kwadraty; 


    for(int i = 1; i < (int)linie.size() - 1; i++)
    {
        for(int j = 1; j < (int)linie[i].length() - 1; j++)
        {
            char srodek = linie[i][j];
            
            if(linie[i-1][j-1] == srodek && linie[i-1][j] == srodek && linie[i-1][j+1] == srodek &&
               linie[i][j-1] == srodek && linie[i][j] == srodek && linie[i][j+1] == srodek &&
               linie[i+1][j-1] == srodek && linie[i+1][j] == srodek && linie[i+1][j+1] == srodek)
            {
                liczba_kwadratow++;
                kwadraty.push_back({i + 1, j + 1});
            }
        }
    }

    cout << liczba_kwadratow << endl;
    for(auto& kwadrat : kwadraty)
    {
        cout << kwadrat.first << " " << kwadrat.second << endl;
    }

    zadanie2_1();
    return 0;
}