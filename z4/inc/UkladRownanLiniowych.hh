#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "SWektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename typ, int rozmiar>
class UkladRownanL {
  
  Macierz A;
  SWektor b;
  
  public:
  SWektor<typ,rozmiar> oblicz()const;
  UkladRownanL();
  UkladRownanL(Macierz<typ,rozmiar> A, SWektor<typ,rozmiar> b);   

  const Macierz<typ,rozmiar> & get_A() const; {return A;}
  const SWektor<typ,rozmiar> & get_b() const; {return b;}

  void set_A(const Macierz<typ,rozmiar> & in);
  {
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            A[i][j]=in[i][j];
        }
    }
}
  void set_b(const SWektor<typ,rozmiar> & in);
  {
    for (int i=0; i<ROZMIAR; i++)
    {
        b[i]=in[i];
    }
}
};

template<typename typ, int rozmiar>
SWektor<typ,rozmiar> UkladRownanL<typ,rozmiar>::oblicz() const
{
    SWektor Wynik;


    A.odwrotnosc;
    Wynik = A.operator*(b);

    return Wynik;
}

template<typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanL<typ,rozmiar> &UklRown);
{
    Strm>>UklRown.Set_A()>>UklRown.Set_b();
    return Strm;
}

template<typename typ, int rozmiar>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanL<typ,rozmiar>    &UklRown);
{
    Strm<<"Macierz:"<<std::endl<<UklRown.get_A<<std::endl<<"SWektor:"<<std::endl<<UklRown.get_b;
    return Strm;
}

#endif