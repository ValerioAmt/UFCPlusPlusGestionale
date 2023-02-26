#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cerca(string nomefile, string cod)
{
    string risultato = "";

    ifstream fileAperto(nomefile);
    if (fileAperto.is_open())
    {
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
    string risultato = cerca("matricola.txt", cod);
    cout << "La matricola: " << cod << " corrisponde al nome: " << risultato << endl;
}

void findSalaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("stipendio.txt", cod) << endl;
}

void findStraordinaryByCod(string cod)
{
    cout << "La matricola " << cod << ", ha " << cerca("straordinari.txt", cod) << " ore di straordinario" << endl;
}

void findSalaryByName(string nome)
{
    ifstream fileAperto("matricola.txt");
    string cod = "";
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            int k = 0;
            for (int i = 6; i < line.length(); i++)
            {
                if (line[i] != nome[k])
                {
                    break;
                }
                else if (k == nome.length() - 1) // ultimo carattere del nome
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cod += line[j];
                    }
                }

                k++;
            }
        }

        fileAperto.close();
    }
    else
    {
        cout << "1 Impossibile aprire il file .txt" << endl;
    }

    string stipendioValore = cerca("stipendio.txt", cod);

    cout << "Il nome: " << nome << " corrisponde alla matricola: " << cod << " e al stipendio: " << stipendioValore << endl;
}

void findSalaryAndStraordinaryByCod(string cod)
{

    int salario = stoi(cerca("stipendio.txt", cod));
    int straodinario = stoi(cerca("straordinari.txt", cod));
    int salarioTotale = salario + straodinario * 35;
    cout << "matricola: " << cod << " stipendio totale: " << salarioTotale << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalita' che vuoi attivare" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Matricola -> Straordinari" << endl;
        cout << "4. Nome -> Stipendio" << endl;
        cout << "5. Matricola -> Stipendio + straordinari (35h)" << endl;
        cout << "0. EXIT" << endl;
        cout << "------------------------------------------------------" << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare \n";
        string input;
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
            else if (scelta == 3)
            {
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