/*
    Autor: @MrKristarlx07 (GitHub) | @marbasz (Twitter)
    Script: Como generar & guardar un grafo que sea de tipo dirigido ponderado
    Lenguaje: C++
    Notas:
            De las líneas 10-18 se añade el caso prueba para utilizar
*/

/*
7 8
1 2 3
1 3 8
1 4 5
1 5 2
5 6 4
5 7 9
6 7 2
6 1 10
*/

#include <iostream>
#include <vector>

using namespace std;

/*struct dato ///otra forma de generar el tipo de dato, quedaría la línea 32 como: vector <dato> grafo[1000]
{
    int dir;
    vector <int> conexiones;
};*/

vector < pair <int, int> > grafo[1000]; ///tenemos un vector de vectores de tipo pair con dos int´s, donde grafo[] tendrá un vector exclusivo de tipo pair donde se almacena first & second,el primero indicando el nodo vecino, el segundo indicando el peso del arista
int n, k, x, y, p;

int main()
{
    cin>>n>>k; ///se recibe la cantidad de nodos & la cantidad de aristas que tendrá nuestro grafo
    for(int i=0; i<k; i++)
    {
        cin>>x>>y>>p; ///se recibe el nodo origen, el nodo vecino & el peso del arista [x->y; peso: p]
        grafo[x].push_back(make_pair(y, p));
        ///grafo[y].push_back(make_pair(x, p));
    }

    for(int i=1; i<=n; i++)
    {
        if(!grafo[i].empty())
        {
            cout<<"Nodo "<<i<<":\n";
            for(int j=0; j<grafo[i].size(); j++) ///línea utilizable para poder recorrer el vector de vectores del index correspondiente
                cout<<grafo[i][j].first<<" con peso de: "<<grafo[i][j].second<<"\n"; ///.first hace referencia al nodo vecino; .second hace referencia al peso del arista
            cout<<"\n";
        }
    }
    return 0;
}
