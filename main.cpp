#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Person
{
    int personIdNumber;
    string personName, personSurname, personPhoneNumber, personEmail, personAddress;
};

int loadDataFromFile(Person contacts[]);
void findPersonByName(Person contacts[], int numberOfContacts);
void findPersonBySurname(Person contacts[], int numberOfContacts);
void showAllContacts(Person contacts[], int numberOfContacts);
void findContactMenu(Person contacts[], int numberOfContacts);
int addNewPerson(Person contacts[], int numberOfContacts);

int main()
{
    Person contacts[1000];
    char choiceSign;

    int numberOfContacts = loadDataFromFile(contacts);

    while(1)
    {
        system("cls");

        cout << "Ilosc wszystkich kontaktow: " << numberOfContacts << endl;
        cout << "-------------------------" <<endl;
        cout << "1. Dodaj nowy kontakt" << endl;
        cout << "2. Znajdz kontakt" << endl;
        cout << "9. Zakoncz" << endl;
        cout << "-------------------------" <<endl;
        cout << "Podaj cyfre: ";

        cin >> choiceSign;

        switch(choiceSign)
        {
        case '1':
            numberOfContacts = addNewPerson(contacts, numberOfContacts);
            break;
        case '2':
            findContactMenu(contacts, numberOfContacts);
            break;

        case '9':
            exit(0);
            break;
        default:
            cout << "Nie ma takiej cyfry w menu! Sprobuj jeszcze raz." << endl;
            Sleep(1500);
        }
    }
}

int loadDataFromFile(Person contacts[])
{
    int numberOfContacts=0;
    int lineNumber = 1;
    string lineOfTextFromFile;

    fstream plik;
    plik.open("ksiazka_adresowa.txt", ios::in);

    if(plik.good() == false)
    {
        cout << "Nie mozna odznalezc pliku!" << endl;
    }

    while(getline(plik, lineOfTextFromFile))
    {
        switch(lineNumber)
        {
        case 1:
            contacts[numberOfContacts].personIdNumber = atoi(lineOfTextFromFile.c_str());
            break;
        case 2:
            contacts[numberOfContacts].personName = lineOfTextFromFile;
            break;
        case 3:
            contacts[numberOfContacts].personSurname = lineOfTextFromFile;
            break;
        case 4:
            contacts[numberOfContacts].personPhoneNumber = lineOfTextFromFile;
            break;
        case 5:
            contacts[numberOfContacts].personEmail = lineOfTextFromFile;
            break;
        case 6:
            contacts[numberOfContacts].personAddress = lineOfTextFromFile;
            break;
        }

        if(lineNumber == 6)
        {
            lineNumber = 0;
            numberOfContacts++;
        }
        lineNumber++;
    }

    plik.close();

    return numberOfContacts;
}

void findPersonByName(Person contacts[], int numberOfContacts)
{
    string personName;
    int searchedName = 0;
    char choiceSign;

    cout << "Wpisz imie: ";
    cin >> personName;
    cout << endl;

    for(int i=0; i< numberOfContacts; i++)
    {
        if(personName == contacts[i].personName)
        {
            cout << contacts[i].personName << endl;
            cout << contacts[i].personSurname << endl;
            cout << contacts[i].personPhoneNumber << endl;
            cout << contacts[i].personEmail << endl;
            cout << contacts[i].personAddress << endl;
            cout << endl;
            searchedName++;
        }
    }

    if( searchedName == 0)
    {
        cout << "Nie ma osoby o takim imieniu w Twoich kontaktach." << endl;
        cout << endl;
    }

    cout << "Aby zakonczyc wcisnij dowolny klawisz";
    choiceSign = getch();
}

void findPersonBySurname(Person contacts[], int numberOfContacts)
{
    string personSurname;
    int searchedSurname = 0;
    char choiceSign;

    cout << "Wpisz nazwisko: ";
    cin >> personSurname;
    cout << endl;

    for(int i=0; i< numberOfContacts; i++)
    {
        if(personSurname == contacts[i].personSurname)
        {
            cout << contacts[i].personName << endl;
            cout << contacts[i].personSurname << endl;
            cout << contacts[i].personPhoneNumber << endl;
            cout << contacts[i].personEmail << endl;
            cout << contacts[i].personAddress << endl;
            cout << endl;
            searchedSurname++;
        }
    }
    if( searchedSurname == 0)
    {
        cout << "Nie ma osoby o takim nazwisku w Twoich kontaktach." << endl;
        cout << endl;
    }

    cout << "Aby zakonczyc wcisnij dowolny klawisz";
    choiceSign = getch();
}

void showAllContacts(Person contacts[], int numberOfContacts)
{
    char choiceSign;

    for(int i=0; i< numberOfContacts; i++)
    {
        cout << contacts[i].personIdNumber << endl;
        cout << contacts[i].personName << endl;
        cout << contacts[i].personSurname << endl;
        cout << contacts[i].personPhoneNumber << endl;
        cout << contacts[i].personEmail << endl;
        cout << contacts[i].personAddress << endl;
        cout << endl;
    }
    cout << "Aby zakonczyc wcisnij dowolny klawisz";
    choiceSign = getch();
}

void findContactMenu(Person contacts[], int numberOfContacts)
{
    char choiceSign;

    system("cls");
    cout << "ZNAJDZ KONTAKT" << endl;
    cout << "-------------------------" <<endl;
    cout << "1. Podaj imie" << endl;
    cout << "2. Podaj nazwisko" << endl;
    cout << "3. Pokaz wszystkie kontakty" << endl;
    cout << "-------------------------" <<endl;
    cout << "Podaj cyfre: ";

    cin >> choiceSign;

    system("cls");
    switch(choiceSign)
    {
    case '1':
        findPersonByName(contacts, numberOfContacts);
        break;

    case '2':
        findPersonBySurname(contacts, numberOfContacts);
        break;

    case '3':
        showAllContacts(contacts, numberOfContacts);
        break;

    default:
        cout << "Nie ma takiej cyfry w menu! Sprobuj ponownie:" << endl;
        Sleep(2000);
        cin >> choiceSign ;
    }
}

int addNewPerson(Person contacts[], int numberOfContacts)
{
    string personName, personSurname, personPhoneNumber, personEmail, personAddress;
    char choiceSign;

    system("cls");
    cout << "Imie: ";
    cin >> personName;
    cout << "Nazwisko: ";
    cin >> personSurname;

    for(int i=0; i < numberOfContacts; i++)
    {
        if((contacts[i].personName == personName) && (contacts[i].personSurname == personSurname))
        {
            cout << endl;
            cout << "Taka osoba juz istnieje w kontaktach!" << endl;
            cout << endl;
            cout << "Aby zakonczyc wcisnij dowolny klawisz";
            choiceSign = getch();
        }
    }

    cout << "Numer telefonu: ";
    cin >> personPhoneNumber;
    cout << "Adres e-mail: ";
    cin >> personEmail;
    cout << "Adres zamieszkania: ";
    cin.sync();
    getline(cin, personAddress);

    int personIdNumber = numberOfContacts + 1;

    contacts[numberOfContacts].personName = personName;
    contacts[numberOfContacts].personSurname = personSurname;
    contacts[numberOfContacts].personPhoneNumber = personPhoneNumber;
    contacts[numberOfContacts].personEmail = personEmail;
    contacts[numberOfContacts].personAddress = personAddress;
    contacts[numberOfContacts].personIdNumber = numberOfContacts + 1;

    fstream plik;
    plik.open("ksiazka_adresowa.txt", ios::out | ios::app);
    if(plik.good())
    {
        plik << personIdNumber << endl;
        plik << personName << endl;
        plik << personSurname << endl;
        plik << personPhoneNumber << endl;
        plik << personEmail << endl;
        plik << personAddress << endl;

        plik.close();

        cout << endl;
        cout << "Kontakt dodany pomyslnie!" << endl;
        Sleep(1500);
    }
    else
        cout << "Nie mozna odznalezc pliku!" << endl;

    return numberOfContacts+1;
}
