/*
    Autor: @MrKristarlx07 (GitHub) | @marbasz (Twitter)
    Script: Como generar & guardar un árbol
    Lenguaje: C++
    Notas:
            Para efectos de eficacia, todos los hijos se crearán con valor de -1, por ello, si quiere verificar o no la existencia de alguno, solamente verifiqie si arbol[i].hijo(izquierdo/derecho)!=-1
*/

#include <iostream>
#include <vector>

using namespace std;

struct dato
{
    int hijo_izquierdo=1, hijo_derecho=-1; ///se arma un struct el cual tendrá dos enteros, uno para su nodo izquierdo & otro para el nodo derecho
};

vector <dato> arbol; ///se construye un vector el cual deberá ser de tipo "dato", que contendrá en cada index el espacio disponible para acomodar el par de nodos
int n;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arbol[i].hijo_izquierdo>>arbol[i].hijo_derecho;

    ///imprimir
    for(int i=0; i<n; i++)
        cout<<arbol[i].hijo_izquierdo<<" "<<arbol[i].hijo_derecho;
}
