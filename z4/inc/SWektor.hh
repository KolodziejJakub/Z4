#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &W2) const;
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    STyp operator * (const SWektor<STyp,SWymiar> & W2) const;

    bool operator == (const SWektor<STyp,SWymiar> & W2) const;
    bool operator != (const SWektor<STyp,SWymiar> & W2) const;

    double dlugosc() const;

};


template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator+(const SWektor<STyp,SWymiar> &W2) const
{
    SWektor<STyp,SWymiar> Wynik;

    for (int i=0; i<SWymiar; i++)
      {
          Wynik[i]=_Wsp[i]+W2[i];
      }
      return Wynik;
}

template<typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator*(const SWektor<STyp,SWymiar> &W2) const
{
    double Wynik;

    for (int i=0; i<SWymiar; i++)
    {
        Wynik = Wynik + (_Wsp[i]*W2[i]);
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator ==(const SWektor<STyp,SWymiar> &W2) const
{
    for (int i=0; i<SWymiar; i++)
    {
        if(abs(_Wsp[i]-W2[i]) >= 0.00001)
        return false;
    }
    return true;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator!=(const SWektor<STyp,SWymiar> &W2) const
{
    if ((*this)==W2)
    return false;
    else
    return true;
    
}

template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator * (SWektor<STyp,SWymiar> W, double l1)
{
    for (int i=0; i<SWymiar; i++)
    {
        W[i]=W[i]*l1;
    }
    return W;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek)
{
    for (int i=0; i<SWymiar; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

#endif