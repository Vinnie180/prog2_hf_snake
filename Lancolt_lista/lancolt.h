#ifndef LANCOLT_H
#define LANCOLT_H

#include <iostream>


#include "coord.h"
#include "memtrace.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#endif // !CPORTA


enum Dir {UP,DOWN,LEFT,RIGHT};			// a kigyo altal felveheto iranyok

std::ostream& operator<<(std::ostream& os, Coord rhs);

struct Node {
	Coord data;							// a lancolt listanak az elemeinek az adata
	Node* next;							// a lancolt listaban a kovetkezo elemre mutato pointer
};

class Snake {
private:
	Node *head, *tail;					// a lancolt lista elejere es a vegere mutato pointer
	int points;							// a kigyo pontjai amit elert
	size_t len;							// a kigyo hossza
	Dir dir;							// a kigyo iranya amerre mozogni fog
	bool was_button_pressed;			// a jatekos nyomott e gombot
public:

	/// Default ctor 
	Snake() : head(nullptr), tail(nullptr), points(0), len(0), dir(UP), was_button_pressed(false){}

	/// ctor
	/// @param len - a kigyo hossza
	/// @param width - az ablak szelessege, a kigyo kozepre igazitasahoz kell
	/// @param height  - az ablak magassaga
	/// @param side - a negyzetek szelessege
	/// @param gap - a negyzetek kozotti hezag
	Snake(size_t len, const unsigned int width, const unsigned int height, const unsigned int side, const unsigned int gap);

	/// a kigyo lancolt listaja vegere fuz egy elemet
	/// @param coord - a koordinata amit hozzafuz a lancolt listahoz
	void addToEnd(Coord coord);

	/// kiirja a kigyo koordinatait
	void print() const;

	/// @brief a kigyo lancolt listaja elejere fuzi az elemet
	/// @param coord - a koordinata amit hozzafuz
	void addToStart(Coord coord);

	/// @brief a kigyo lancolt listajanak felszabaditasahoz kell
	void destroy();

	/// @brief a kigyo destruktora, automatikusan meghivja a destroy() fv-t es kiirja a szerzett pontot
	virtual ~Snake() {
		//std::cout << std::endl << std::endl << "-----------------------" << std::endl << "Points earned: " << points << std::endl << "-----------------------" << std::endl << std::endl;
		destroy();
	}

	/// @brief a kigyo mozgasaert felel
	void move();

	/// @brief a kigyo hosszat noveli es egy uj elemet fuz a kigyo farkahoz
	void grow();

#ifndef CPORTA

	/// @brief a kigyot kirajzolja
	/// @param side - a negyzetek szelessege
	/// @param gap - a negyzetek kozotti hezag
	/// @param win - az ablak referenciaja, ide rajzolja ki a fv a kigyot
	void draw(const unsigned int side, const unsigned int gap, sf::RenderWindow& win) const;

#endif // !CPORTA

	/// @brief a kigyo egyik darabkajanak a koordinatajat adja vissza
	/// @param i - i. elem amivel vissza fog terni
	/// @return - egy koordinata ami a kigyo i. elemenek a koordinataja
	Coord operator[](size_t i);

	/// @brief a kigyo egyik darabkajanak a koordinatajat adja vissza
	/// @param i - i. elem amivel vissza fog terni
	/// @return - egy koordinata ami a kigyo i. elemenek a koordinataja
	const Coord operator[](size_t i) const;

	/// @brief a kigyo meretevel ter vissza
	/// @return - a kigyo hossza
	size_t size() const { return len; }

	/// @brief a kigyo iranyat allitja be
	/// @param dir - erre az iranyra allitja be
	void set_dir(Dir dir) { this->dir = dir; }

	/// @brief a kigyo iranyaval ter vissza
	/// @return a kigyo iranya 
	Dir get_dir() const { return dir; }

	/// @brief megvizsgalja utkozik e a kigyo feje a sajat testreszeivel
	/// @return egy booleannal ter vissza hogy a kigyo utkozott e magaval
	bool collide_with_self()const;

	/// @brief megvizsgalja, hogy a kigyo utkozott e a fallal
	/// @param side - a negyzetek szelessege
	/// @param gap - a negyzetek kozotti hezag
	/// @param width - az ablak szelessege 
	/// @param height - az ablak magassága
	/// @return egy boolean, hogy utkozott e
	bool collide_with_wall(unsigned int side, unsigned int gap, unsigned int width, unsigned int height) const;

	/// @brief noveli  a kigyo pontjat egy bizonyos osszeggel
	/// @param p - ennyit ad hozza
	void pointInc(int p) { points += p; }
	
	/// @brief a kigyo pontjaval visszater
	/// @return - a kigyo pontja
	int getp() const { return points; }
	
	/// @brief lekerdezi hogy nyomott e mar gombot a kigyo a frame-ben
	/// @return - nyomott e mar gombot
	bool getwbp() const { return was_button_pressed; }

	/// @brief beallitja hogy nyomott e mar gombot
	/// @param wbp - erre allitja be a kigyo was_button_pressed valtozojat
	void setwbp(bool wbp) { was_button_pressed = wbp; }
};
#endif // !LANCOLT_H
