#include <iostream>

#include "lancolt.h"
#include "kaja.h"
#include "memtrace.h"
#include "kozos_fv.h"
#include "rajztabla.h"
#include "gtest_lite.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "SFML_fvg.h"
#include "gomkezeles.h"
#endif // !CPORTA

using std::cout;
using std::endl;
using std::cin;

int main() {
	/*---------------------------------------initalising-------------------------------------------------*/
	unsigned int width = 500;		// az ablak szelessege
	unsigned int height = 500;		// az blak magassaga
	unsigned int side = 20;			// a negyzetek szelessege
	unsigned int gap = 5;			// a hezag a negyzetek kozott
#ifndef CPORTA
	bool gameOver = false;			// SFML-hez a jatek veget jelzo valtozo
#endif // !CPORTA

#ifndef CPORTA
	sf::RenderWindow window(sf::VideoMode(width, height), "Snek");
	window.setFramerateLimit(10);
	srand(time(0));

	Table table(width, height, side, gap);

	/*---------------------------------------Game loop---------------------------------------------------*/
	while (window.isOpen() && gameOver == 0) {
		sf::Event evnt;

		/*---------------------------------------Event polling-----------------------------------------------*/
		buttonProcessing(window, evnt, table);

		/*---------------------------------------Update------------------------------------------------------*/
		table.snake.move();
		table.generateFruits();
		table.eat();
		table.death(gameOver);

		/*---------------------------------------drawing-----------------------------------------------------*/
		window.clear();
		table.draw_table(window);

		/*---------------------------------------rendering---------------------------------------------------*/
		window.display();
	}
	cout << "-----------------------\n*   Final points: "<< table.snake.getp() << "   *\n-----------------------"<< endl;
#endif // !CPORTA

	srand(time(0));			// a random szamok generalasahoz kell

	TEST(Snake, size) {
		Snake snek(4, width, height, side, gap);
		EXPECT_EQ(4, snek.size()) << "Nem jó a méret";
	}END
	TEST(Snake, grow) {
		Snake snek(4, width, height, side, gap);
		snek.grow();
		EXPECT_EQ(5, snek.size()) << "Nem nõtt a méret!";
		if (snek[3].x == 10 && snek[3].y == 13) {
			EXPECT_EQ(14, snek[4].y) << "Nem jó a koordináta";
		}
	}END
	TEST(Snake, move) {
		Snake snek(4, width, height, side, gap);
		if (snek[0].x == 10 && snek[0].y == 10) {
			snek.move();
			EXPECT_EQ(9, snek[0].y) << "Valamiert nem jol lep a kigyo";
			EXPECT_EQ(10, snek[1].y) << "Valamiert nem jol lep a kigyo";
			EXPECT_EQ(11, snek[2].y) << "Valamiert nem jol lep a kigyo";
			EXPECT_EQ(12, snek[3].y) << "Valamiert nem jol lep a kigyo";
		}
	}END
	TEST(Snake, operator[]) {
		Snake snek(4, width, height, side, gap);
		EXPECT_EQ(10, snek[0].x) << "Nem jo az x koordinata";
		EXPECT_EQ(10, snek[0].y) << "Nem jo az y koordinata";
		EXPECT_EQ(10, snek[1].x) << "Nem jo az x koordinata";
		EXPECT_EQ(11, snek[1].y) << "Nem jo az y koordinata";
		EXPECT_THROW(snek[4], const char*) << "Nem dobott kivetelt";
		EXPECT_THROW(snek[5], const char*) << "Nem dobott kivetelt";
	}END
	TEST(Snake, collide_with_wall) {
		Snake snek(4, width, height, side, gap);
		EXPECT_FALSE(snek.collide_with_wall(side, gap, width, height)) << "Valamiert meghal amikor nem kellene";
		for (size_t i = 0; i < 100; i++) {
			snek.move();
		}
		EXPECT_TRUE(snek.collide_with_wall(side, gap, width, height)) << "Nem jol erzekeli a fallal valo utkozest";
	}END
	TEST(Snake, pointInc) {
		Snake snek(4, width, height, side, gap);
		snek.grow();
		int inc = 3;
		int old = snek.getp();
		snek.pointInc(inc);
		int new_ = snek.getp();
		EXPECT_TRUE(new_-inc == old) << "Nem noveli jol";
	}END
	TEST(Snake, addToStart){
		Snake snek(4, width, height, side, gap);
		if (snek[0].x == 10 && snek[0].y == 10) {
			snek.addToStart({ 3,3 });
			EXPECT_EQ(3, snek[0].x) << "Nem stimmel az x koordinata";
			EXPECT_EQ(3, snek[0].y) << "Nem stimmel az y koordinata";
		}
	}END
	TEST(Fruit, generate_in_range) {
		int u = 10;
		int l = 0;
		for (int i = 0; i < 100; i++) {
			int temp = generate_in_range(u, l);
			EXPECT_TRUE(temp >= l && temp <= u) << "Nem jo az intervallum";
		}
	}END
	TEST(Fruit, set_x_y) {
		Apple apple(10, 10, 1);
		apple.set_x(3);
		apple.set_y(3);
		EXPECT_EQ(3, apple.get_c().x) << "Nem lett jol beallitva az x";
		EXPECT_EQ(3, apple.get_c().y) << "Nem lett jol beallitva az y";
	}END
	TEST(Apple, ctor) {
		Apple apple(3, 4, 5);
		EXPECT_EQ(3, apple.get_c().x) << "Nem jo x inicializalasa";
		EXPECT_EQ(4, apple.get_c().y) << "Nem jo y inicializalasa";
		EXPECT_EQ(5, apple.getp()) << "Nem jo a pont inicializalasa";
	}END
	TEST(Table, def_ctor) {
		Table table;
		EXPECT_EQ(0, table.side) << "Nem jo az oldal inicializalasa";
		EXPECT_EQ(0, table.gap) << "Nem jo a hezag inicializalasa";
		EXPECT_EQ(0, table.width) << "Nem jo az ablakszelesseg inicializalasa";
		EXPECT_EQ(0, table.height) << "Nem jo az ablakmagassag inicializalasa";
		EXPECT_FALSE(table.fruit_exists) << "Nem jo letezik_alma inicializalasa";

		EXPECT_EQ(0, table.snake.size()) << "Nem jo a kigyo hossza";
		EXPECT_EQ(0, table.snake.getp()) << "Nem jo a kigyo pontja";

		EXPECT_EQ(0, table.apple.get_c().x) << "Nem jo az alma x koordinataja";
		EXPECT_EQ(0, table.apple.get_c().y) << "Nem jo az alma y koordinataja";

		EXPECT_EQ(0, table.gapple.get_c().x) << "Nem jo az aranyalma x koordinataja";
		EXPECT_EQ(0, table.gapple.get_c().y) << "Nem jo az aranyalma y koordinataja";
	}END
	TEST(Table, ctor){
		Table table(width, height, side, gap);
		EXPECT_EQ(side, table.side) << "Nem jo az oldal inicializalasa";
		EXPECT_EQ(gap, table.gap) << "Nem jo a hezag inicializalasa";
		EXPECT_EQ(width, table.width) << "Nem jo az ablakszelesseg inicializalasa";
		EXPECT_EQ(height, table.height) << "Nem jo az ablakmagassag inicializalasa";
		EXPECT_FALSE(table.fruit_exists) << "Nem jo letezik_alma inicializalasa";

		EXPECT_EQ((table.width / (side + gap))/2, table.snake[0].x) << "Nem jo a kigyo kezdopontja";
		EXPECT_EQ((table.height / (side + gap))/2, table.snake[0].y) << "Nem jo a kigyo kezdopontja";
	}END
	TEST(Table, generateFruits) {
		Table table(width, height, side, gap);
		bool wasILucky = false;
		for (int i = 0; i < 100; i++) {
			table.generateFruits();
			if (table.gapple.get_c().x != -1 && table.gapple.get_c().y != -1) {
				wasILucky = true;
				break;
			}
			table.fruit_exists = false;
		}
		EXPECT_TRUE(wasILucky) << "Vagy nagy balszerencse, vagy nem generalodik aranyalma valami okot kovetoen";
		EXPECT_TRUE(table.gapple.get_c().x < int(width / (side + gap)) - 1 && table.gapple.get_c().x > 1) << "Nem jok a hatarok";
		EXPECT_TRUE(table.gapple.get_c().y < int(height / (side + gap)) - 1 && table.gapple.get_c().x > 1) << "Nem jok a hatarok";
	}END
	TEST(Table, death){
		Table table(width, height, side, gap);
		bool gameOverTMP = false;
		table.death(gameOverTMP);
		EXPECT_FALSE(gameOverTMP) << "Meg nem kellene meghalnia";
		for (int i = 0; i < 100; i++) {
			table.snake.move();
		}
		table.death(gameOverTMP);
		EXPECT_TRUE(gameOverTMP) << "Valamiert meg el a kigyo";
	}END
	TEST(Table, death) {
		Table table(width, height, side, gap);
		bool gameOverTMP = false;
		table.death(gameOverTMP);
		EXPECT_FALSE(gameOverTMP) << "Meg nem kellene meghalnia";
		table.snake.grow();
		table.snake.move();
		table.snake.grow();
		table.snake.set_dir(LEFT);
		table.snake.move();
		table.snake.set_dir(DOWN);
		table.snake.move();
		table.snake.set_dir(RIGHT);
		table.snake.move();
		table.death(gameOverTMP);
		EXPECT_TRUE(gameOverTMP) << "Nem halt meg amikor magaba utkozott";
	}END
	TEST(Table, eat) {
		Table table(width, height, side, gap);
		size_t old = table.snake.size();
		table.apple.set_x(10);
		table.apple.set_y(9);
		table.snake.move();
		table.eat();
		EXPECT_EQ(old + 1, table.snake.size()) << "Nem nott a meret";
		EXPECT_EQ(1, table.snake.getp()) << "Nem nott a pont";
		EXPECT_FALSE(table.fruit_exists) << "Nem allitodott at a letezikagyumolcs";
		table.gapple.set_x(10);
		table.gapple.set_y(8);
		table.snake.move();
		table.eat();
		EXPECT_EQ(old + 2, table.snake.size()) << "Nem nott a meret";
		EXPECT_EQ(1 + 5, table.snake.getp()) << "Nem nott a pont";
		EXPECT_FALSE(table.fruit_exists) << "Nem allitodott at a letezikagyumolcs";

	}END
	return 0;
}