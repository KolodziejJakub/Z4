#include<iostream>
#include<cmath>
#include "LZespolona.hh"

using std::cout;
using std::cin;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im + Skl2.re);
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re/Skl2;
  Wynik.im = Skl1.im/Skl2;
  return Wynik;
}

LZespolona sprzezenie (LZespolona Skl1)
{
  Skl1.im = -Skl1.im;
  return Skl1;
}

double modul2 (LZespolona Skl1)
{
  double Wynik;

  Wynik = (Skl1.re*Skl1.re+Skl1.im*Skl1.im);

  return Wynik;
}


LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = Skl1*sprzezenie(Skl2)/modul2(Skl2);

  return Wynik;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if (Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else 
  {
  return false;
  }
}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  if (Skl1.re != Skl2.re || Skl1.im != Skl2.im)
    return true;
  else
    return false;
}

LZespolona utworz(double re, double im)
{
  LZespolona Z;
  Z.re = re;
  Z.im = im;
  return Z;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & Z)
{
  strm<<"("<<Z.re<<std::showpos<<Z.im<<std::noshowpos<<"i)";
  return strm;
}

std::istream & operator >> (std::istream & strm, LZespolona &Z1)
{
  char znak;
  strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
  strm>>Z1.re;
  strm>>znak;
  strm>>Z1.im;
  if(znak=='-')
    Z1.im=(-Z1.im);
  strm>>znak;
  if(znak!='i')
  {
    strm.setstate(std::ios::failbit);
  }
  strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm;
}