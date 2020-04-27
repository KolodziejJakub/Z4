#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*class Wektor
{
  double tab[ROZMIAR];

  public:

  Wektor operator + (Wektor & W2);
};*/
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<class TYP, int ROZMIAR>
class Wektor {
  
  TYP tab[ROZMIAR];
  
  public:
  
  Wektor<TYP, ROZMIAR> operator + (const Wektor<TYP, ROZMIAR> & W2) const;
  Wektor<TYP, ROZMIAR> operator - (const Wektor<TYP, ROZMIAR> & W2) const;
  TYP operator * (const Wektor<TYP, ROZMIAR> & W2) const;

  Wektor<TYP, ROZMIAR> operator * (double li) const;

  bool operator == (const Wektor<TYP, ROZMIAR> & W2) const;
  bool operator != (const Wektor<TYP, ROZMIAR> & W2) const;
  
  
  double dlugosc() const;
  
  
  const double & operator[] (int index) const;
  double & operator[] (int index);    
};

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> operator * (double l1, Wektor<TYP, ROZMIAR> W2);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek);


#endif
