#ifndef KAJA_H
#define KAJA_H

#include <iostream>

#include "coord.h"
#include "memtrace.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#endif // !CPORTA

using std::cout;
using std::endl;

/// general egy szamot egy intervallumban
/// @param upper - a felso hatar
/// @param lower - az also hatar
int generate_in_range(int upper, int lower);

class Fruit {
protected:
	Coord coord;		// a gyumolcs koordinataja
	int point;			// a gyumolcs ponterteke
public:
	/// Default ctor 
	Fruit() : coord{ 0,0 }, point(0) {};

	/// ctor x es y al
	/// @param x - az x koordinataja
	/// @param y - az y koordinataja a gyumolcsnek
	/// @param p - a gyumolcs pontja
	Fruit(int x, int y,int p) : coord{x,y}, point(p) {}

	/// ctor Coord-val
	/// @param coord - a koordinata amivel inicializalom a gyumolcsot
	/// @param p - a gyumolcs pontja
	Fruit(Coord coord, int p) : coord(coord), point(p) {}

#ifndef CPORTA
	/// kirajzolo fv
	/// @param side - a negyzet oldala
	/// @param gap - a hezag a negyzetek kozott
	/// @param win - az ablak referenciaja, ide rajzolom ki a negyzetet
	/// virtualis fuggveny
	virtual void draw(const int side, const int gap, sf::RenderWindow& win) const = 0;
#endif // !CPORTA

	/// dtor
	virtual ~Fruit() {}

	/// koordinata getter
	Coord get_c() const { return coord; }

	/// point getter
	int getp() const { return point; }

	/// x setter
	void set_x(int x) { coord.x = x; }

	/// y setter
	void set_y(int y) { coord.y = y; }
};

class Apple : public Fruit {
public:
	/// Default ctor 
	Apple() : Fruit(){}

	/// ctor x es y al
	/// @param x - az x koordinataja
	/// @param y - az y koordinataja az almanak
	/// @param p - az alma pontja 
	Apple(int x, int y, int p) : Fruit(x, y, p){}

	/// ctor Coord-val
	/// @param coord - a koordinata amivel inicializalom a gyumolcsot
	Apple(Coord coord) : Fruit(coord, 1){}

#ifndef CPORTA

	/// kirajzolo fv
	/// @param side - a negyzet oldala
	/// @param gap - a hezag a negyzetek kozott
	/// @param win - az ablak referenciaja, ide rajzolom ki a negyzetet
	void draw(const int side, const int gap, sf::RenderWindow& win)const;

#endif // !CPORTA

	/// dtor
	~Apple() {}
};

class GoldenApple : public Fruit {
public:

	/// Default ctor 
	GoldenApple() : Fruit(){}

	/// ctor x es y al
	/// @param x - az x koordinataja
	/// @param y - az y koordinataja az almanak
	/// @param p - az aranyalma pontja
	GoldenApple(int x, int y, int p) : Fruit(x, y, 5) {}

	/// ctor Coord-val
	/// @param coord - a koordinata amivel inicializalom az aranyalmat
	GoldenApple(Coord coord) : Fruit(coord, 5) {}
	
#ifndef CPORTA

	/// kirajzolo fv
	/// @param side - a negyzet oldala
	/// @param gap - a hezag a negyzetek kozott
	/// @param win - az ablak referenciaja, ide rajzolom ki a negyzetet
	void draw(const int side, const int gap, sf::RenderWindow& win) const;

#endif // !CPORTA

	/// dtor
	~GoldenApple() {}
};


#endif // !KAJA_H