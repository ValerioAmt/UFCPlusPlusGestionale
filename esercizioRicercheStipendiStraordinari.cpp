// matricola.txt
//  11485 Marius
//  11486 Marco
//  11487 Marcellus
//  11488 Marcella
//  stripendio.txt
//  11485 5000
//  11486 5005
//  11487 3000
//  11488 5000
//  straordinari.txt
//  11485 0
//  11486 2
//  11487 1
//  11488 5
 
#include <iostream>
#include <fstream>
 
using namespace std;
 
string cerca(string nomefile, string cod){
    string risultato = "";
 
    ifstream fileAperto(nomefile);
    if (fileAperto.is_open())
    {
        cout << "File .txt aperto correttamente" << endl;
        string line;
        while (getline(fileAperto, line))
        {
 
            for (int i = 0; i < 6; i++)
            {
                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4) // ultimo carattere della matricola
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        risultato += line[j];
                    }
                }
                else
                {
                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt" << endl;
    }
 
    return risultato;
}
 
 
void findNameByCod(string cod)
{
    string risultato=cerca("fileMatricole.txt", cod);
    cout << "La matricola: " << cod << " corrisponde al nome: " << risultato << endl;
}
 
void findSalaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("fileStipendi.txt", cod) << endl;
}
 
void findStraordinaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("fileStraordinari.txt", cod) << endl;
}
 
void findSalaryByName(string nome){
    ifstream fileAperto("matricola.txt");
    string cod = "";
    if (fileAperto.is_open())
    {
        cout << "File .txt aperto correttamente" << endl;
        string line;
        while (getline(fileAperto, line))
        {
 
            for (int i = 6; i < line.length(); i++)
            {
                if (line[i] != nome[i])
                {
                    break;
                }
                else if (i == 4) // ultimo carattere della matricola
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cod += line[j];
                    }
                }
                else
                {
                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt" << endl;
    }
 
    int stipendioValore = stoi(cerca("stipendio",cod));
 
    cout << "Il nome: " << nome << " corrisponde alla matricola: " << cod << " e al stipendio: " << stipendioValore << endl;
 
}

void findSalaryAndStraordinaryByCod(string cod)
{
    
    int straordinario = stoi(cerca("fileStraordinari.txt", cod));
    int stipendio = stoi(cerca("stipendio", cod));
    int stipendioPiuStraordinari = straordinario + stipendio;
    cout << "matricola" << cod << "ha uno stipendio, compreso di straordinari, di :" << stipendioPiuStraordinari <<endl;
    
    
    //cout << "matricola: " << cod << " stipendio: " << cerca("fileStipendi.txt", cod)<<"straordinari" <<cerca("fileStraordinari.txt", cod) << endl;
    //cout << "matricola: " << cod << " stipendio: " << cerca("straordinari.txt", cod) << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;
 
    bool flag = true;
    while (flag) 
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalità che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Matricola -> Straordinari" << endl;
        cout << "4. Nome -> Stipendio" << endl;
        cout << "5. Matricola -> Stipendio + straordinari (35h)" << endl;
        cout << "0. EXIT" << endl;
        int scelta ;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare\n";
        string input ;
        cin >> input;
 
        if (scelta < 0 || scelta > 5) // DA MODIFICARE IN CASO DI AGGIUNTE NEL MENU
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
 
            }
            else if (scelta == 3){
                findStraordinaryByCod(input);
            }
            else if (scelta == 4)
            {
                findSalaryByName(input);
            }
            else if (scelta == 5)
            {
                findSalaryAndStraordinaryByCod(input);
            }
            else if (scelta == 0)
            {
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }
 
    cout << "Fine" << endl;
}