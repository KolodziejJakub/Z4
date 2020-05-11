#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include "Macierz.hh"

using namespace std;



void Test_SzablonWektor_double()
{
  cout << endl
       << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<double,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
}




void Test_SzablonWektor_LZespolona()
{
  cout << endl
       << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;


  SWektor<LZespolona,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind].re = Ind;      W[Ind].im = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
}

void test_macierz()
{
    Macierz<double, ROZMIAR> test,test2,test3;
     double wyznacznik;

    cout<<"test pierwszy"<<endl;

    for ( int i=0; i<ROZMIAR; i++)
    {
        for ( int j=0; j<ROZMIAR; j++)
        {
            test[i][j]=i+j+5;
            test2[i][j]=i-j;
        }
    }

    test3=test*test2;
    cout<<endl<<test<<endl<<endl<<test2<<endl;
    cout<<"test"<<endl<<test3<<endl;

    wyznacznik=test.wyznacznik();
    cout<<wyznacznik<<endl;
}

int main()
{
  Test_SzablonWektor_double();
  Test_SzablonWektor_LZespolona();
  test_macierz();
}