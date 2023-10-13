#include "SFML_fvg.h"
#include "memtrace.h"

#ifndef CPORTA
void box_draw(Coord coord, unsigned int side, unsigned int gap, sf::RenderWindow& win, const sf::Color color) {
	sf::RectangleShape r(sf::Vector2f(side, side));
	r.setPosition(float(coord.x * (gap + side)), float(coord.y * (gap + side)));
	r.setFillColor(color);
	win.draw(r);
}

void top_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win) {
	for (unsigned i = 0; i < (win.getSize().x / (side + gap)); i++) {
		box_draw(Coord{ int(i),0 }, side, gap, win, sf::Color(255, 255, 255, 255));
	}
}

void bottom_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win) {
	for (unsigned i = 0; i < (win.getSize().x / (side + gap)); i++) {
		box_draw(Coord{ int(i), int((win.getSize().y) / (side + gap) - 1) }, side, gap, win, sf::Color(255, 255, 255, 255));
	}
}

void left_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win) {
	for (unsigned i = 1; i < (win.getSize().y / (side + gap)) - 1; i++) {
		box_draw(Coord{ 0, int(i) }, side, gap, win, sf::Color(255, 255, 255, 255));
	}
}

void right_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win) {
	for (unsigned i = 1; i < (win.getSize().y / (side + gap)) - 1; i++) {
		box_draw(Coord{ int(win.getSize().x / (side + gap) - 1), int(i) }, side, gap, win, sf::Color(255, 255, 255, 255));
	}
}

void cage(unsigned int side, unsigned int gap, sf::RenderWindow& win) {
	top_cage(side, gap, win);
	bottom_cage(side, gap, win);
	left_cage(side, gap, win);
	right_cage(side, gap, win);
}
#endif // !CPORTA