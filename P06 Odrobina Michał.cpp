#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <fstream>

using namespace std;


int tab[100], ciag[100]; // Wyrazy ciagu w formie tablic
ofstream out("Wyniki.txt",fstream::app);   // Deklaracja strumienia wyjściowego do pliku "Wyniki.txt"
int t, p, k, z, m, n, e;

// t - numery kolejnych wyrazów ciagow
// p - licznik petli do...while w przeliczaniu ciagow
// k - zadana liczba
// z - ilosc liczb w ciagu
// m - wynik sumy najkrotszego ciagu, wiekszego od 'k'
// n - indeks tablic tab[n] i ciag[n]
// e - zmienna "szufladkujaca ostatni wyraz ciagu


void wymaz_txt();  // Funkcja wymazujaca plik "Wyniki.txt"
void ciag1_8();     // Ciag z zakresu 1 do 8, o roznicy = 1
void dowolny_ciag();    // Dowolny ciag wpisany przez uzytkownika
void sprawdz_k();   // Funkcja sprawdzajaca czy k jest wieksze od sumy calego ciagu
void przelicz_ciag();    // Funkcja wyliczajaca sume najkrotszego ciagu liczb naturalnych, wiekszych od zadanej liczby 'k'



int main()
{


    char nr_wyboru;

    cout << endl << "Witaj!" << endl << endl;
    Sleep(1000);


    do
    {
        system("cls");


        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "Program oblicza sume najkrotszego ciagu liczb naturalnych, wiekszych od zadanej liczby 'k'." << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "MENU WYBORU" << endl << endl;

        cout << "Zatwierdzanie w MENU WYBORU odbywa sie poprzez wcisniecie odpowiedniego klawisza." << endl << endl;
        cout << "Wybierz '1': Dla zadanego ciagu od 1 do 8, roznica = 1." << endl;
        cout << "Wybierz '2': Dla dowolnego wlasnego ciagu." << endl;
        cout << "Wybierz '3': Aby wymazac zawartosc pliku \"Wyniki.txt\"." << endl;
        cout << "Wybierz '4': Aby zamknac program." << endl << endl;


        cout << "Wybierz opcje: ";
        nr_wyboru = getch();    // Zatwierdzenie wyboru tylko klawiszem
        cout << nr_wyboru;
        Sleep(500);


        // MENU WYBORU


        switch(nr_wyboru)
        {
        case '1':       // Wybor 1, dla ciagu 1 do 8
            ciag1_8();
            sprawdz_k();
            if(ciag[n]<=k)  // Jesli 'k' bedzie wieksze lub rowne od sumy calego ciagu przerywa wykonywanie funkcji
            {
                break;
            }
            przelicz_ciag();
            break;
        case '2':       // Wybor 2, dla dowolnego ciagu
            dowolny_ciag();
            sprawdz_k();
            if(ciag[n]<=k)  // Jesli 'k' bedzie wieksze lub rowne od sumy calego ciagu przerywa wykonywanie funkcji
            {
                break;
            }
            przelicz_ciag();
            break;
        case '3':       // Wybor 3, wymazuje plik "Wyniki.txt"
            wymaz_txt();
            break;
        case '4':       // Wybor 4, konczy program
            break;
        default:
            cout << endl << endl << "Blad ! Mozesz wybrac tylko opcje podane wyzej..." << endl;     // Dla kazdego innego wyboru
            Sleep(3000);
            break;

        }
    } while(nr_wyboru!='4');









    return 0;
}


//--------------------------------------------------------------------------------------


void wymaz_txt()
{
    ofstream oout("Wyniki.txt");

    oout << "";     // Wyczeszczenie zawartosci pliku



    cout << endl << endl <<  "Wymazano zawartosc pliku \"Wyniki.txt\" !...";

    Sleep(2000);
}


//--------------------------------------------------------------------------------------



void ciag1_8()
{
    system("cls");


    ciag[0]=1;  // Pierwszy wyraz ciagu
    z=8;        // Ilosc liczb w ciagu
    int r=1;    // Roznica ciagu



        cout << "Pierwszy wyraz ciagu: " << ciag[0] << endl;
        cout << "Ilosc liczb w ciagu: " << z << endl;
        cout << "Roznica ciagu: " << r << endl;



    cout << "Oto liczby ciagu: " << endl;
    out << endl << "Dla liczb ciagu: ";

    for(n=0;n<z;n++)    // Wylicza i wyswietla wszystkie liczby ciagu
    {
        ciag[n] = ciag[0] + n * r;
        cout << ciag[n] << " ";
        out << ciag[n] << " ";
    }

    cout << endl;

    n = 0; // reset do 0 indeksu



}




//--------------------------------------------------------------------------------------



void dowolny_ciag()
{
    system("cls");

    int r;


    do
    {


        cout << "Podaj pierwszy wyraz ciagu: ";
        cin >> ciag[0];
        if(ciag[0]<=0)  // Dla wartosci ujemnych jest wyswietlany komunikat
        {
            cout << "Liczba musi byc dodatnia !" << endl;
            Sleep(1000);
            system("cls");
        }

    } while(ciag[0]<=0);


    do
    {

        cout << "Podaj ilosc liczb w ciagu: ";
        cin >> z;
        if(z<=0)    // Dla wartosci ujemnych jest wyswietlany komunikat
        {
            cout << "Liczba musi byc dodatnia !" << endl;
            Sleep(1000);
            system("cls");
            cout << "Podaj pierwszy wyraz ciagu: " << ciag[0] << endl;
        }

    } while(z<=0);


    do
    {
        cout << "Podaj roznice ciagu: ";
        cin >> r;
        if(r<=0)    // Dla wartosci ujemnych jest wyswietlany komunikat
        {
            cout << "Liczba musi byc dodatnia !" << endl;
            Sleep(1000);
            system("cls");
            cout << "Podaj pierwszy wyraz ciagu: " << ciag[0] << endl;
            cout << "Podaj ilosc liczb w ciagu: " << z << endl;
        }

    } while(r<=0);


    cout << "Oto liczby ciagu: " << endl;
    out << endl << "Dla liczb ciagu: ";

    for(n=0;n<z;n++)    // Wylicza i wyswietla wszystkie liczby ciagu
    {
        ciag[n] = ciag[0] + n * r;
        cout << ciag[n] << " ";
        out << ciag[n] << " ";
    }

    cout << endl;

    n = 0; // reset do 0 indeksu

}



//--------------------------------------------------------------------------------------



void sprawdz_k()
{
    cout << "Podaj k: ";
    cin >> k;


    out << endl << "Dla k: " << k << endl << endl;
    cout << endl;


    e = ciag[z-1];      // Szufladkujemy ostatni wyraz ciagu
   for(n=0;n<z-1;n++)   // Liczymy sume wszystkich wyrazow ciagu
    {
        ciag[z-1] += ciag[n];
    }



    if(ciag[n]<=k)  // Jesli ciag jest mniejszy lub rowny od k to wyswietla komunikat
    {
        cout << "Brak podtablic spelniajacych zadane warunki." << endl;
        cout << endl << endl << "Nacisnij ENTER, aby wrocic do MENU WYBORU...";
        getchar();
        getchar();

    }



}




//--------------------------------------------------------------------------------------



void przelicz_ciag()
{

    ciag[z-1] = e;  // Przyrownuje ostatni wyraz ciagu do pierwotnego stanu


   for(n=0;n<z;n++)     // Przyrównanie tab do ciagu
    {
        tab[n] = ciag[n];
    }

    cout << endl;


   cout << "-----------------------------------------------------------" << endl;

    p = -1;
    t = -1;
    m = 0;

    do
    {

        p++;

        for(n=0;n<z;n++)   // Sprawdzamy kazdy wyraz ciagu po kolei
        {

            if(tab[n]>k)    // jesli tab[n] bedzie wiekszy od k...
            {
                m=tab[n];   //  ...przypisujemy go jako m
                break;
            }

        }




        if(m<k) // Jesli 1 podejscie bedzie mniejsze od 'k' dodaj kolejny tab[n+1]
        {

            t++;
            z -= 1;


            for(n=0;n<z;n++) // Przypisanie z kazda petla do.while kolejnego wyrazu do sumy ciagu
            {
                tab[n] += ciag[n+(t+1)];

            }


        }


    } while(m<k);  // Dla m = 0, mniejszego od k, zostaje ponowiona petla



    cout << "Wyjscie: ";
    out << "Wyjscie: ";
    for(int i=0;i<=p;i++) // Wyswietlanie kazdego wyrazu ciagu zawierajacego sie w wyniku sumy
    {

        cout << ciag[n] << " ";
        out << ciag[n] << " ";
        n++;

    }



    cout << endl << "Suma ciagu wyjsciowego: " << m;    // Wyswietlenie wyniku sumy najkrotszego ciagu liczb naturalnych, wiekszego 'k'

    out << endl << "Suma ciagu wyjsciowego: " << m << endl << endl;
    out << "---------------------------------------------" << endl << endl;


    cout << endl << endl << "Nacisnij ENTER, aby wrocic do MENU WYBORU...";
    getchar();
    getchar();



}



