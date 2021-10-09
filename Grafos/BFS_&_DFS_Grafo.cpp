/*
    Autor: @MrKristarlx07 (GitHub) | @marbasz (Twitter)
    Script: Búsqueda en Amplitud & Búsqueda en Profundidad en un Grafo
    Lenguaje: C++
    Notas:

*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector <int> vec[100001]; ///vector de vectores donde cada index de vec[] tiene un vector dentro, donde se almacenan todos los vecinos adyacentes
queue <int> cola;
int n, v, h;
bool visitado[100001]; ///cadena de bools donde se marcaran como TRUE los index correspondientes a los nodos ya visitados

void dfs(int a) ///la idea básica de DFS es visitar el siguiente hijo de nuestro actual nodo hasta que se acaben, tras ello, retorna al anterior nodo & prosigue con el siguiente hijo
{
    printf("%d ", a);
    visitado[a]=true; ///marca la posición actual como visitada
    for(int l=0; l<vec[a].size(); l++)
    {
        int h=vec[a][l];
        if(visitado[h]==false) ///¿aún no ha sido visitado este nodo?
            dfs(h); ///llama recursión para visitar el nodo
    }
}

void bfs(int a) ///la idea general de BFS es visitar todos los nodos que estén al mismo nivel de profundidad del nodo ancestro inicial, cuando se terminen, proceder con el siguiente nivel, cuando este se termine, proceder con el nivel siguiente, sucesivamente
{
    cola.push(a); ///hacemos push del primer nodo a procesar
    visitado[a]=true; ///le marcamos como visitado
    while(!cola.empty()) ///mientras que tengamos nodos por verificar sus hijos
    {
        a=cola.front(); ///asignamos el nodo del frente de la queue
        cola.pop(); ///lo eliminamos de la estructura para después dar paso al siguiente
        printf("%d ", a);
        for(int y=0; y<vec[a].size(); y++) ///recorremos todos los vecinos de mi nodo actual
        {
            int u=vec[a][y];
            if(!visitado[u]) ///¿Aún no hemos visitado al vecino x de mi nodo actual?
            {
                visitado[u]=true; ///le marcamos como visitado
                cola.push(u); ///mandamos al final de la queue
            }
        }
    }
}

int main()
{
    scanf("%d", &n); ///cantidad de nodos que contiene nuestro grafo
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &v, &h); ///nodo de donde parte el arista; cantidad de vecinos
        for(int j=0; j<h; j++)
        {
            int x;
            scanf("%d", &x); ///se lee el vecino
            vec[v].push_back(x); ///se añade el vecino x al vector de vecinos del nodo "v"
        }
    }

    ///bfs
    for(int i=0; i<n; i++)
        if(!visitado[i])
            bfs(i); ///llamamos recursivamente la bfs por cada nodo que encontremos sin revisar, por si existen grafos islas

    printf("\n");
    for(int i=0; i<n; i++)
        visitado[i]=0; ///como reutilizamos aquí bfs & dfs, debemos limpiar nuestro vector de visitados

    ///dfs
    for(int i=0; i<n; i++)
        if(!visitado[i])
            dfs(i); ///llamamos recursivamente la dfs por cada nodo que encontremos sin revisar, por si existen grafos islas

    return 0;
}
