#pragma once
#ifndef KOZOS_FV_H
#define KOZOS_FV_H

#include "lancolt.h" 
#include "kaja.h"
#include "memtrace.h"

/// A kigyohoz hozza adja a gyumolcs pontszamat
/// @param s - kigyo referenciaja, ennek a pontjahoz adja a gyumolcs pontjat
/// @param f - gyumolcs referenciaja ennek a pontjat adja hozza a kigyohoz
void addPoints(Snake& s, const Fruit& f);

#endif // !KOZOS_FV_H
