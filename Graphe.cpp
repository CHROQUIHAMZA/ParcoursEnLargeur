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
        cout << "Graphe vide" << endl;
        return;
    }

    int node;
    while (true) {
        cout << "Give a node: ";
        cin >> node;

        if (node >= 0 && node < G.size() && G[node]) {
            break;
        }
        else {
            cout << "Invalid node or no edges for this node!" << endl;
        }
    }

    vector<bool> visitedNode(G.size(), false);  // Use G.size() instead of nbrElem
    queue<int> q;
    q.push(node);
    visitedNode[node] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        if (G[current]) {
            LST* temp = G[current]->L;  // Make sure G[current] is valid
            while (temp) {
                int currentNode = temp->value;

                if (currentNode >= 0 && currentNode < G.size() && !visitedNode[currentNode]) {
                    visitedNode[currentNode] = true;
                    q.push(currentNode);
                }

                temp = temp->svt;  // Move to the next node
            }
        }

    }
    cout << endl;
}
