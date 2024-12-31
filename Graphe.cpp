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

    int node;
    while (true) {
        cout << "Donnez un n�ud de d�part : ";
        cin >> node;

        if (node >= 0 && node < G.size() && G[node] != nullptr) {
            break;
        }
        else {
            cout << "N�ud invalide ou sans connexions !" << endl;
        }
    }

    vector<string> visitedNode(G.size(), "white"); 
    queue<int> q;
    q.push(node);
    visitedNode[node] = "grey"; 


    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " " << endl;
        visitedNode[current] = "black"; 

        
        if (G[current]) {
            LST* temp = G[current]->L;
            while (temp) {
                int neighbor = temp->value;

                if (neighbor >= 0 && neighbor < G.size() && visitedNode[neighbor] == "white") {
                    visitedNode[neighbor] = "grey"; 
                    q.push(neighbor);
                }

                temp = temp->svt; 
            }
        }

    }

    cout << endl;

    cout << "�tat final des n�uds :" << endl;
    for (int i = 0; i < visitedNode.size(); ++i) {
        cout << "N�ud " << i << " : " << visitedNode[i] << endl;
    }
}
