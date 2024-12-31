#include <iostream>
#include "Graphe.h"
using namespace std;

int main() {
    Graphe graph;

    // Création de listes représentant les connexions
    Liste* list0 = new Liste();
    list0->inserer(1); // Connexion de 0 vers 1
    list0->inserer(2); // Connexion de 0 vers 2

    Liste* list1 = new Liste();
    list1->inserer(0); // Connexion de 1 vers 0
    list1->inserer(3); // Connexion de 1 vers 3
    list1->inserer(5); // Connexion de 1 avec 5

    Liste* list2 = new Liste();
    list2->inserer(0); // Connexion de 2 vers 0
    list2->inserer(3); // Connexion de 2 vers 3

    Liste* list3 = new Liste();
    list3->inserer(1); // Connexion de 3 vers 1
    list3->inserer(2); // Connexion de 3 vers 2
    list3->inserer(4); // Connexion de 3 vers 4

    Liste* list4 = new Liste();
    list4->inserer(3); // Connexion de 4 vers 3
    list4->inserer(5); // Connexion de 4 vers 5

    Liste* list5 = new Liste();
    list5->inserer(4); // Connexion de 5 vers 4
    list5->inserer(1); // Connexion de 5 vers 1

    // Insérer les listes dans le graphe
    graph.inserer(list0, 0);
    graph.inserer(list1, 1);
    graph.inserer(list2, 2);
    graph.inserer(list3, 3);
    graph.inserer(list4, 4);
    graph.inserer(list5, 5);

    // Affichage du graphe
    cout << "Affichage du graphe non orienté :" << endl;
    graph.afficher();

    // Parcours en largeur (BFS)
    cout << "Parcours en largeur : " << endl;
    graph.BFS();

    return 0;
}
