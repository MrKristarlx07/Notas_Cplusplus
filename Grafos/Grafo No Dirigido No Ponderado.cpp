/*
    Autor: @MrKristarlx07 (GitHub) | @marbasz (Twitter)
    Script: Como generar & guardar un grafo que sea de tipo no dirigido no ponderado
    Lenguaje: C++
    Notas:
            De las líneas 10-18 se añade el caso prueba para utilizar
*/

/*
7 8
1 2
1 3
1 4
1 5
5 6
5 7
6 7
6 1
*/

#include <iostream>
#include <vector>

using namespace std;

/*struct dato ///otra forma de generar el tipo de dato, quedaría la línea 32 como: vector <dato> grafo[1000]
{
    int dir;
    vector <int> conexiones;
};*/

vector <int> grafo[1000]; ///tenemos un vector de vectores, donde grafo[] tendrá un vector exclusivo para todos sus vecinos
int n, k, x, y;

int main()
{
    cin>>n>>k; ///se recibe la cantidad de nodos & la cantidad de aristas que tendrá nuestro grafo
    for(int i=0; i<k; i++)
    {
        cin>>x>>y; ///se reciben ambos nodos [x<->y; peso: -]
        grafo[x].push_back(y); ///se coloca a y como vecino de x [x->y]
        grafo[y].push_back(x); ///se coloca a x como vecino de y [y->x]
    }

    for(int i=1; i<=n; i++)
    {
        if(!grafo[i].empty())
        {
            cout<<i<<": ";
            for(int j=0; j<grafo[i].size(); j++) ///línea utilizable para poder recorrer el vector de vectores del index correspondiente
                cout<<grafo[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
