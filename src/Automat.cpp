/*
 * Automat.cpp
 *
 *  Created on: 17/03/2011
 *  Author: Christina Heltoft, Klaus Møllnitz, Thomas ? & Viktor Pontoppidan
 */

#include "Automat.h"
#include <iostream>

Automat::Automat() {
	x.fem  = 0;
	x.ti   = 0;
	x.tyve = 0;

	y.zone_2 = 0;
	y.zone_3 = 0;
	y.zone_4 = 0;
	y.zone_5 = 0;
	y.zone_6 = 0;
	y.zone_7 = 0;
	y.zone_8 = 0;
	y.zone_A = 0;
}

Automat::~Automat() {

}

void Automat::addCoins(coinType c, int antal){
	if (c == FEM){
		x.fem += antal;
	} else if (c == TI){
		x.ti += antal;
	} else if (c == TYVE){
		x.tyve += antal;
	}
}
void Automat::addCards(cardType k, int antal){
	switch(k){
	case _2z:
		y.zone_2=y.zone_2+antal;
		break;
	case _3z:
		y.zone_3 += antal;
		break;
	case _4z:
		y.zone_4 += antal;
		break;
	case _5z:
		y.zone_5 += antal;
		break;
	case _6z:
		y.zone_6 += antal;
		break;
	case _7z:
		y.zone_7 += antal;
		break;
	case _8z:
		y.zone_8 += antal;
		break;
	case Az:
		y.zone_A += antal;
		break;
	}
}

void Automat::print(Automat::indhold in){
	std::cout<<"Femmere: "<<in.fem<<"\n";
	std::cout<<"Tiere:   "<<in.ti<<"\n";
	std::cout<<"Tyvere:  "<<in.tyve<<"\n";
}

void Automat::print(){
	print(x);

	std::cout<<"\n";
	std::cout<<"2 Zoners kort:    "<<y.zone_2<<"\n";
	std::cout<<"3 Zoners kort:    "<<y.zone_3<<"\n";
	std::cout<<"4 Zoners kort:    "<<y.zone_4<<"\n";
	std::cout<<"5 Zoners kort:    "<<y.zone_5<<"\n";
	std::cout<<"6 Zoners kort:    "<<y.zone_6<<"\n";
	std::cout<<"7 Zoners kort:    "<<y.zone_7<<"\n";
	std::cout<<"8 Zoners kort:    "<<y.zone_8<<"\n";
	std::cout<<"Alle Zoners kort: "<<y.zone_A<<"\n";
}

void Automat::udRegn(int tilbage){
    int antaltyvere = tilbage/20, antaltiere=0, antalfemmere=0;

	// Beregn fordelingen af mønter
    if (tilbage%20 != 0){
    	antaltiere = (tilbage-(antaltyvere*20))/10;
    	if ((tilbage-(antaltyvere*20))%10 != 0){
    		antalfemmere = (tilbage-(antaltyvere*20+antaltiere*10))/5;
    	}
    }

    // Udskriv antallet af hver enkelt mønttype
    std::cout<<"Femmere: "<<antalfemmere<<"\n";
    std::cout<<"Tiere:   "<<antaltiere<<"\n";
    std::cout<<"Tyvere:  "<<antaltyvere<<"\n";
}

void Automat::buy(cardType k, seddelType s){
	int amount = 0;

	switch(s){
	case EN_HUND:
		amount = 100;
		break;
	case TO_HUND:
		amount = 200;
		break;
	case FEM_HUND:
		amount = 500;
		break;
	case INVALID:
		std::cout<<"FEJL !!!!!!!!!!!";
		break;
	}

	if (amount > 0){
		std::cout<<"Du har betalt "<<amount<<" kr.\n";

		switch(k){
		case _2z:
			amount-=140;
			std::cout<<"Du har k�bt et 2 zoners kort.\n";
			break;
		case _3z:
			amount-=180;
			std::cout<<"Du har k�bt et 3 zoners kort.\n";
			break;
		case _4z:
			amount-=230;
			std::cout<<"Du har k�bt et 4 zoners kort.\n";
			break;
		case _5z:
			amount-=285;
			std::cout<<"Du har k�bt et 5 zoners kort.\n";
			break;
		case _6z:
			amount-=335;
			std::cout<<"Du har k�bt et 6 zoners kort.\n";
			break;
		case _7z:
			amount-=390;
			std::cout<<"Du har k�bt et 7 zoners kort.\n";
			break;
		case _8z:
			amount-=435;
			std::cout<<"Du har k�bt et 8 zoners kort.\n";
			break;
		case Az:
			std::cout<<"Du har k�bt et allezoners kort.\n";
			amount-=455;
			break;
		}

		if(amount<0){
			std::cout<<"Der er ikke penge nok";
		} else {
			udRegn(amount);
		}

		// TODO: Remove 1 card from stack (1 card has been taken out of machine)
	}
}

