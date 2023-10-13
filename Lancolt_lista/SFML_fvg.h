#ifndef SFML_FGV_H
#define SFML_FGV_H

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#endif // !CPORTA

#include "lancolt.h"
#include "memtrace.h"

#ifndef CPORTA

/// @brief kirajzol a kpernyore egy negyzetet
/// @param coord - a koordinata ahova kirajzolja a negyzetet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a negyzetet
/// @param color - a szine a negyzetnek
void box_draw(Coord coord, unsigned int side, unsigned int gap, sf::RenderWindow& win, sf::Color color);

/// @brief kirajzolja a felsõ keretet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a keretet
void top_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win);

/// @brief kirajzolja az also keretet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a keretet
void bottom_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win);

/// @brief kirajzolja a bal keretet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a keretet
void left_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win);

/// @brief kirajzolja a jobb keretet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a keretet
void right_cage(unsigned int side, unsigned int gap, sf::RenderWindow& win);

/// @brief kirajzolja az osszes keretet
/// @param side - a negyzetek szelessege
/// @param gap - a negyzetek kozotti hezag
/// @param win - az ablak referenciaja ahova kirajzolja a kereteket
void cage(unsigned int side, unsigned int gap, sf::RenderWindow& win);

#endif // !CPORTA

#endif // !SFML_FGV_H
