#include <iostream>

#include "kaja.h"
#include "memtrace.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#include "SFML_fvg.h"
#endif // !CPORTA


int generate_in_range(const int upper, const int lower){
	return (rand() % (upper - lower + 1)) + lower;
}
#ifndef CPORTA
void Apple::draw(const int side, const int gap, sf::RenderWindow& win)const {
	box_draw(coord, side, gap, win, sf::Color(0xCC0000FF));
}

void GoldenApple::draw(const int side, const int gap, sf::RenderWindow& win)const {
	box_draw(coord, side, gap, win, sf::Color(0xFFD700FF));
}
#endif // !CPORTA
