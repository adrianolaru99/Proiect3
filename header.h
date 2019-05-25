#include <bits/stdc++.h>
using namespace std;
template  <class K, class V, class F>
class HashMap
{

    vector <V> valori;
    list <V> *a;
public:
    unsigned long keyHash(const V &key);
    HashMap();
    ~HashMap();
    HashMap(HashMap &x);
    void adaugare(V f);
    bool cautare(V f);
    void stergere(V f);
    vector <V> returnare(K f);
    int numarchei();
    int operator [](K q);
};


template  <class K, class V, class F>
unsigned long HashMap <K,V,F> :: keyHash(const V &key)
{
    return reinterpret_cast<unsigned long> (&key)%111;
}
template  <class K, class V, class F>
HashMap <K,V,F> :: HashMap()
{
    a=new list<V>[112];
}
template  <class K, class V, class F>
HashMap <K,V,F> :: ~HashMap()
{
    valori.clear();
    for(int i=0; i<=111; i++)
        a[i].clear();
}
template  <class K, class V, class F>
HashMap <K,V,F> ::   HashMap(HashMap &x)
{
    a=x.a;
    valori=x.valori;
}
template  <class K, class V, class F>
void HashMap <K,V,F> ::    adaugare(V f)
{
    bool ok=0;
    int i;
    for(i=0; i<valori.size(); i++)
        if(valori[i]==f)
            ok=1;
    if(ok==0)
    {
        valori.push_back(f);
        i=valori.size()-1;
        unsigned long key=keyHash(valori[i]);
        a[key].push_back(f);
    }
}
template  <class K, class V, class F>
bool HashMap <K,V,F> :: cautare(V f)
{
    V m;
    for(int i=0; i<valori.size(); i++)
        if(valori[i]==f)
            m=i;
    unsigned long h=keyHash(valori[m]);
    for(auto i=a[h].begin(); i!=a[h].end(); ++i)
        if(*i==f)
            return 1;
    return 0;
}
template  <class K, class V, class F>
void HashMap <K,V,F> :: stergere(V f)
{
    unsigned int m;
    for(int i=0; i<valori.size(); i++)
        if(valori[i]==f)
            m=i;
    unsigned long h=keyHash(valori[m]);
    for(auto i=a[h].begin(); i!=a[h].end(); ++i)
        if(*i==f)
        {
            a[h].erase(i);
            return;
        }
}
template  <class K, class V, class F>
vector <V>  HashMap <K,V,F> :: returnare(K f)
{
    vector <V> retur;
    V m;
    for(int i=0; i<valori.size(); i++)
        if(valori[i]==f)
            m=i;
    unsigned long  h=keyHash(valori[m]);
    for(auto i=a[h].begin(); i!=a[h].end(); ++i)
        retur.push_back(*i);
    return retur;
}
template  <class K, class V, class F>
int  HashMap <K,V,F> :: numarchei()
{
    int nr=0;
    for(int i=0; i<=110; i++)
        if(a[i].end()!=a[i].begin())
            nr++;
    return nr;
}
template  <class K, class V, class F>
int   HashMap <K,V,F> :: operator [](K q)
{
    V m;
    for(int i=0; i<valori.size(); i++)
        if(valori[i]==q)
            m=i;
    unsigned long  h=keyHash(valori[m]);
    for(auto i=a[h].begin(); i!=a[h].end(); ++i)
        return *i;
}
