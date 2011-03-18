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
	a.buy(_2z, EN_HUND);
	return 0;
}
