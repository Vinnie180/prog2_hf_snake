#pragma once
#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include <iostream>

#include "lancolt.h"
#include "kaja.h"
#include "kozos_fv.h"
#include "memtrace.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#endif // !CPORTA


using std::cout;
using std::endl;

class Table {
public:
	unsigned int side, gap, width, height;			// a negyzet szelessege, a negyzetek kozotti hezag, az ablak szelessege, az ablak magassaga
	Snake snake;									// egy kigyo ami a rajztablan meg fog jelenni, ez a jatekos
	Apple apple;									// egy alma ami a palyan fog lenni ezt eszi meg a kigyo 1 pontert
	GoldenApple gapple;								// egy aranyalma amit a kigyo megehet 5 pontert, de csak egy hosszusagot no, hogy ne legyen sokkal nehezebb a jatek, jelenleg 1/3 eselye van spawnolni
	bool fruit_exists;								// egy valtozo, hogy van e a palyan gyumolcs(aranyalma / alma)
public:

	/// @brief default ctor
	Table() : side(0), gap(0), width(0), height(0), snake(), apple(), gapple(), fruit_exists(false) {}

	/// @brief ctor
	/// @param width - az ablak szelessege
	/// @param height - az ablak magassaga
	/// @param side - a negyzetek szelessege
	/// @param gap - a negyzetek kozotti hezag
	Table(const unsigned int width, const unsigned int height, const unsigned int side, const unsigned int gap) :
		side(side), gap(gap), width(width), height(height), snake(4, width, height, side, gap), apple(-1, -1, 1), gapple(-1, -1, 5), fruit_exists(false) {}

	///// @brief kiir mindent a rajztablabol (debug kellek)
	//void info() const;

#ifndef CPORTA

	/// @brief kirajzol mindent ami a tablan van
	/// @param win - az ablak referenciaja, ide rajzol ki mindent a fv
	void draw_table(sf::RenderWindow& win) const;

#endif // !CPORTA

	/// @brief general gyumolcsot, ha eppen nincs mar
	void generateFruits();

	/// @brief vizsgalja, hogy a rajztablan levo kigyo meghal e
	/// @param gameOver a jatek futasahoz kello gameOver valtozot megvaltoztatja, ha a kigyo meghalt, ilyenkor a jateknak vege
	void death(bool& gameOver);

	/// @brief vizsgalja hogy a kigyo eszik, es ha igen akkor noveli a pontjat, hosszat, es uj gyumolcsot general
	void eat();
};

#endif // !RAJZTABLA_H
