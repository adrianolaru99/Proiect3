#include <bits/stdc++.h>
#include "header.h"
using namespace std;
int main()
{
   HashMap <int,int,int> a;
   a.adaugare(2);
   a.adaugare(3);
   a.adaugare(4);
   assert(a.numarchei()==3);
   assert(a.cautare(0)==0);  
   return 0;

}
