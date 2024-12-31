#pragma once
#include<iostream>
using namespace std;
typedef struct lst {
	int value;
	bool isVisited;
	struct lst* svt;
}LST;
class Liste
{
public:
	LST* L;
public:
	Liste();
	LST* creerNoeud(int value);
	void inserer(int value);
	void afficher();
	void addList(LST* L);
	~Liste();
};

