#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "SWektor.hh"
#include <iostream>

using namespace std;

template <typename typ, int rozmiar>
class Macierz
{
    SWektor<typ, rozmiar> tab[rozmiar];

    public:
    Macierz()
    {
        for (int i=0; i<rozmiar; i++)
        {
            for (int j=0; j<rozmiar; j++)
            {
                tab[i][j]=0;
            }
        }
    }

    const SWektor<typ, rozmiar> & operator[] (int index) const {if(index>rozmiar || index<0){exit(1);}else return tab[index];}
    SWektor<typ, rozmiar> & operator[] (int index) {if(index>rozmiar || index<0){exit(1);}else return tab[index];}

    void transpozycja();
    void odwrotnosc();

    typ wyznacznik();

    SWektor<typ, rozmiar> operator * (SWektor<typ, rozmiar> W);
    Macierz<typ, rozmiar> operator * (Macierz<typ,rozmiar> W);
    Macierz<typ, rozmiar> operator + (Macierz<typ,rozmiar>);
    Macierz<typ, rozmiar> operator - (Macierz<typ, rozmiar> W);
    Macierz<typ, rozmiar> operator * (typ l);

    const SWektor<typ,rozmiar> & zwroc_kolumne(int ind);
    void zmien_kolumne(int ind, SWektor<typ,rozmiar> nowy);

    bool operator == (const Macierz<typ, rozmiar> & W) const;
    bool operator != (const Macierz<typ, rozmiar> & W) const;
};

template<typename typ, int rozmiar>
void Macierz<typ, rozmiar>::transpozycja()
{
    Macierz<typ,rozmiar> pomoc;
    
    for (int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            pomoc[i][j]=tab[i][j];
        }
    }

    for (int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            tab[i][j]=pomoc[j][i];
        }
    }
}

template<typename typ, int rozmiar>
typ Macierz<typ,rozmiar>::wyznacznik()
{
    Macierz<typ,rozmiar> kopia;
    SWektor<typ,rozmiar> pomoc;
    typ Wyznacznik=1;

    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            kopia[i][j]=tab[i][j];
        }
    }


    for (int i=0; i<rozmiar; i++)
    {
        pomoc[i]=tab[i][i];
        for (int j=i; j<rozmiar; j++)
        {
            if(pomoc[i]!=0)
            {
                tab[i][j]=tab[i][j]/pomoc[i];
            }
            else
            {
                Wyznacznik=0;
                return Wyznacznik;
            }
        }

        for (int k=(i+1); k<rozmiar; k++)
        {
            while(tab[k][i]!=0)
            {
                tab[k]=tab[k]-tab[i];
            }
        }
    }
    
    for(int l=0; l<rozmiar; l++)
    {
        Wyznacznik=Wyznacznik*pomoc[l];
    }
    return Wyznacznik;
}

template<typename typ, int rozmiar>
void Macierz<typ,rozmiar>::odwrotnosc()
{
    Macierz<typ,rozmiar> kopia;
    typ Wyznacznik;
    Macierz<typ,(rozmiar-1)> mac;
    
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            kopia[i][j]=tab[i][j];
        }
    }

    Wyznacznik = kopia.wyznacznik();

    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {   
            s=0;
            m=0;
            for (int k=0; k<rozmiar; k++)
            {
                for (int l=0; l<rozmiar; l++)
                {
                    if (k != i && l != j)
                    {
                        mac[s][m]=tab[k][l];
                        m++;
                        if(m==(rozmiar-2))
                        {
                            m=0;
                            s++;
                        }
                    }
                }
            }
            if ((i+j)%2 != 0)
            {
                kopia[i][j]=-(mac.wyznacznik);
            }
            else
            {
                kopia[i][j]=mac.wyznacznik);
            }
            
        }
    }
    kopia.transpozycja();

    if (Wyznacznik==0)
    {
        return 0;
    }
    else
    {
    for(int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            tab[i][j]=(1/Wyznacznik)*kopia[i][j];
        }
    }
    }
}

template<typename typ, int rozmiar>
SWektor<typ,rozmiar> Macierz<typ,rozmiar>::operator * (SWektor<typ,rozmiar> W)
{
    SWektor<typ, rozmiar> Wynik;

    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            Wynik[i][j]=W[i]+(tab[i][j]);
        }
    }
    return Wynik;
}

template<typename typ, int rozmiar>
Macierz<typ,rozmiar> Macierz<typ,rozmiar>::operator* (Macierz<typ,rozmiar> W)
{
    Macierz<typ,rozmiar> Wynik;


    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            Wynik[i][j]=tab[i]*W[j];
        }
    }
    return Wynik;
}

template<typename typ, int rozmiar>
Macierz<typ,rozmiar> Macierz<typ,rozmiar>::operator+ (Macierz<typ,rozmiar> W)
{
    Macierz<typ,rozmiar> Wynik;

    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            Wynik[i][j]=tab[i][j]+W[i][j];
        }
    }
    return Wynik;
}

template<typename typ, int rozmiar>
Macierz<typ,rozmiar> Macierz<typ,rozmiar>::operator- (Macierz<typ,rozmiar> W)
{
    Macierz<typ,rozmiar> Wynik;

    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            Wynik[i][j]=tab[i][j]-W[i][j];
        }
    }
    return Wynik;
}

template<typename typ, int rozmiar>
Macierz<typ,rozmiar> Macierz<typ,rozmiar>::operator* (typ l)
{
    Macierz<typ,rozmiar> Wynik;

    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            Wynik[i][j]=tab[i][j]*l;
        }
    }
    return Wynik;
}

template<typename typ, int rozmiar>
bool Macierz<typ,rozmiar>::operator==(const Macierz<typ,rozmiar> & W2) const
{
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            if (abs(tab[i][j]-W2[i][j]) >= 0.000001)
            {
                return false;
            }
        }
    }
    return true;
}

template<typename typ, int rozmiar>
bool Macierz<typ,rozmiar>::operator!=(const Macierz<typ,rozmiar> & W2) const
{
    if((*this)==W2)
    return false;
    else 
    return true;
}

template<typename typ, int rozmiar>
const SWektor<typ,rozmiar> & Macierz<typ,rozmiar>::zwroc_kolumne (int ind)
{
    SWektor<typ,rozmiar> Wynik;

    for (int i=0; i<rozmiar; i++)
    {
        Wynik[i] = tab[ind][i];
    }
    return Wynik;
}

template<typename typ, int rozmiar>
void Macierz<typ,rozmiar>::zmien_kolumne (int ind, SWektor<typ,rozmiar> nowy)
{
    for (int i=0; i<rozmiar; i++)
    {
        tab[ind][i] = nowy[i];
    }
}

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<typ,rozmiar> &Mac)
{
    for (int i=0; i<rozmiar; i++)
    {
        for (int j=0; j<rozmiar; j++)
        {
            Strm<<" "<<Mac[i][j];
        }
        Strm<<endl;
    }
    return Strm;
}

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Macierz<typ,rozmiar> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm>>Mac[i];        
    }
    return Strm;
    Mac.transpozycja();
}


#endif