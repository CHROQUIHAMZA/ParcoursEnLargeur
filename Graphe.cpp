#include "Graphe.h"
#include <queue>
using namespace std;

Graphe::Graphe() {
    nbrElem = 0;
    elemts = vector<int>(10, -1); 
    G = vector<Liste*>(10, nullptr);
}

Graphe::~Graphe() {
    for (auto liste : G) {
        delete liste;
    }
}

void Graphe::inserer(Liste* L, int index) {
    for (LST* courant = L->L; courant; courant = courant->svt) {
        auto it = find(elemts.begin(), elemts.end(), courant->value);

        if (it == elemts.end()) {
            elemts.insert(elemts.begin() + index, courant->value);
            nbrElem++;
        }
    }

    if (index >= 0 && index <= G.size()) {
        G.insert(G.begin() + index, L);
    }
    else {
        cout << "Index out of bounds!" << endl;
    }
  


}

void Graphe::afficher() {
    for (int i = 0; i < nbrElem; ++i) {
        cout << "Noeud " << i << " : ";
        if (G[i]) {
            G[i]->afficher();
        }
        cout << endl;
    }
}

void Graphe::BFS() const {
    if (G.empty()) {
        cout << "Graphe vide." << endl;
        return;
    }

    // Demander un nœud de départ
    int node;
    while (true) {
        cout << "Donnez un neoud de depart : ";
        cin >> node;

        if (node >= 0 && node < G.size() && G[node] != nullptr) {
            break;
        }
        else {
            cout << "Neoud invalide ou sans connexions !" << endl;
        }
    }

    vector<string> visitedNode(G.size(), "white"); // Initialisation des couleurs des nœuds
    queue<int> q;
    q.push(node);
    visitedNode[node] = "grey"; // Marquer comme en cours de traitement

    cout << "Debut du parcours BFS avec couleurs a partir du neoud " << node << " :" << endl;

    while (!q.empty()) {
        // Afficher l'état actuel de la file
        cout << "Etat de la file : [ ";
        queue<int> tempQueue = q; // Copie temporaire de la file pour affichage
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << "]" << endl;

        // Traiter l'élément en tête de la file
        int current = q.front();
        q.pop();
        cout << "Traitement du neoud : " << current << " (grey -> black)" << endl;
        visitedNode[current] = "black"; // Marquer comme terminé

        // Parcourir les voisins
        if (G[current]) {
            LST* temp = G[current]->L; // Accéder à la liste des voisins
            while (temp) {
                int neighbor = temp->value;

                if (neighbor >= 0 && neighbor < G.size() && visitedNode[neighbor] == "white") {
                    visitedNode[neighbor] = "grey"; // Marquer comme en cours de traitement
                    q.push(neighbor);
                    cout << "Ajout du neoud " << neighbor << " dans la file (white -> grey)." << endl;
                }

                temp = temp->svt; // Passer au voisin suivant
            }
        }
        cout << "neoud " << current << " termine." << endl;
        cout << "--------------------" << endl;
    }

    cout << endl;

    // Afficher les états finaux des nœuds
    cout << "État final des neouds :" << endl;
    for (int i = 0; i < visitedNode.size(); ++i) {
        cout << "Neoud " << i << " : " << visitedNode[i] << endl;
    }
}


