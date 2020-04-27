#include "Wektor.hh"

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator + (const Wektor<TYP, ROZMIAR> & W2) const
{
    Wektor Wynik<TYP, ROZMIAR>;

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=tab[i]+W2[i];
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator - (const Wektor<TYP, ROZMIAR> & W2) const
  {
      Wektor Wynik<TYP, ROZMIAR>;

      for (int i=0; i<ROZMIAR; i++)
      {
      Wynik[i]=tab[i]-W2[i];
      }
      return Wynik;
  }

template<class TYP, int ROMZIAR>
TYP operator * (const Wektor<TYP,ROZMIAR> & W2) const
{
    TYP Wynik=0;

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik = Wynik + (tab[i]*W2[i]);
    }
    return Wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator * (double l1) const
{
  Wektor Wynik<TYP, ROZMIAR>;
    
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=tab[i]*l1;
    }
  return Wynik;
}

bool Wektor<TYP, ROZMIAR>::operator == (const Wektor<TYP, ROZMIAR> & W2) const
{
  for (int i=0; i<ROZMIAR; i++)
    {
        if(abs(tab[i]-W2[i]) >= 0.000001)
          return false;
    }
  return true;
}

bool Wektor<TYP, ROZMIAR>::operator != (const Wektor<TYP, ROZMIAR> & W2) const
{
  for (int i=0; i<ROZMIAR; i++)
    {
        if(tab[i] == W2[i])
          return false;
    }
  return true;
}

double Wektor<TYP, ROZMIAR>::dlugosc() const
  {
  double dlugosc;

  for (int i=0; i<ROZMIAR; i++ )
      {
      dlugosc =  dlugosc + pow(tab[i], 2);
      }

  dlugosc = pow(dlugosc, (1/2));

  return dlugosc;
  }

double & Wektor<TYP, ROZMIAR>::operator[] (int index)
{
    if (index < 0 || index >= ROZMIAR) 
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

    return tab[index];
}

const double & Wektor<TYP, ROZMIAR>::operator[] (int index) const
{
    if (index < 0 || index >= ROZMIAR) 
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

    return tab[index];
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Wek[i];
        return Strm;
    }
}

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
        return Strm;
    }
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> operator * (Wektor<TYP, ROZMIAR> W2, double l1)
{
    Wektor Wynik;

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=W2[i]*l1;
    }
    return Wynik;
}
