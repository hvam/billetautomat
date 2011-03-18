/*
 * Name  : Billet_automat.cpp
 * Author: Christina Heltoft, Klaus Møllnitz, Thomas ? & Viktor Pontoppidan
 */

#include <iostream>
#include "Automat.h"

using namespace std;

int main() {
	Automat a;
	//a.print();
	a.addCoins(FEM, 10);
	a.addCards(_3z, 3);
	a.print();
	a.buy(_5z, FEM_HUND);
	return 0;
}
