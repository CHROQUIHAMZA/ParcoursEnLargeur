#pragma once
#include<iostream>
#include<vector>
#include"Liste.h"
using namespace std;
class Graphe
{

private:
	vector<Liste*> G;
	int nbrElem;
	vector<int> elemts;
public:
	Graphe();
	void inserer(Liste* L,int index);
	void afficher();
	void BFS() const;
	~Graphe();
};

