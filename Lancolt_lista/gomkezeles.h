#pragma once
#ifndef GOMBKEZELES_H
#define GOMBKEZELES_H

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#endif // !CPORTA

#include "lancolt.h"
#include "rajztabla.h"
#include "memtrace.h"

#ifndef CPORTA
/// SFML-ben a gomb kezeles megvalositasa
/// @param win - az ablak referenciaja, a bezarashoz kell
/// @param ev - az event referenciaja, az alap jatekmukodeshez kell
/// @param table - a rajztabla referenciaja, mivel a kigyo gyors mozgasvaltoztatasaval magaba tudott lepni 1 frame megjelenites alatt ezert korlatozni kellett a lepesek szamat
void buttonProcessing(sf::RenderWindow& win, sf::Event& ev, Table& table);
#endif // !CPORTA

#endif // !GOMBKEZELES_H
