/*
    Autor: @MrKristarlx07 (GitHub) | @marbasz (Twitter)
    Scrip: A partir de un número n, nos devuelve todos los primos menores
    Lenguaje: C++

    Notas:
        Este scrip soportará hasta primos menores a 1000002, de requerir primos mayores, modifique el tamaño & tipo de dato de los arrays criba[] & marcas[].
            Pd. Cuidado con su RAM
*/

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int criba[1000002], n;
vector <int> primos; // Guarda todos los primos
bool marcas[1000002]={false};

void crea_criba(int a)
{
    criba[1]=0;
    for(int i=4; i<=a; i+=2)
        criba[i]=1;
    for(int i=3; i<=sqrt(a); i+=2)
        if(!criba[i])
            for(int j=i*i; j<=a; j+=i)
                criba[j]=i;
    for(int i=2; i<=a; i++)
        if(!criba[i])
            primos.push_back(i);
}

int main()
{
    cin>>n;
    crea_criba(n);
    for(vector <int> :: iterator it=primos.begin(); it<primos.end(); ++it)
        cout<<*it<<" ";
    return 0;
}
