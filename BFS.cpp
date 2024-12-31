#include <iostream>
#include "Graphe.h"
using namespace std;

int main() {
    Graphe graph;

    Liste* list1 = new Liste();
    list1->inserer(1);
    list1->inserer(2);
    list1->inserer(3);

    Liste* list2 = new Liste();
    list2->inserer(4);
    list2->inserer(5);

    Liste* list3 = new Liste();
    list3->inserer(6);
    list3->inserer(7);
    list3->inserer(8);
    list3->inserer(9);

    graph.inserer(list1,0);
    graph.inserer(list2,2);
    graph.inserer(list3,3);

    cout << "Affichage du graphe :" << endl;
    graph.afficher();

    cout << "parcours en largeur : " << endl;
    graph.BFS();
    

    return 0;
}
