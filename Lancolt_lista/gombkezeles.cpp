#include "gomkezeles.h"
#include "rajztabla.h"
#include "memtrace.h"

#ifndef CPORTA
void buttonProcessing(sf::RenderWindow& win, sf::Event& ev, Table& table) {
	while (win.pollEvent(ev)) {
		if (ev.type == sf::Event::Closed)
			win.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && table.snake.get_dir() != RIGHT && table.snake.getwbp() == false) {
		table.snake.set_dir(LEFT);
		table.snake.setwbp(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && table.snake.get_dir() != LEFT && table.snake.getwbp() == false) {
		table.snake.set_dir(RIGHT);
		table.snake.setwbp(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && table.snake.get_dir() != DOWN && table.snake.getwbp() == false) {
		table.snake.set_dir(UP);
		table.snake.setwbp(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && table.snake.get_dir() != UP && table.snake.getwbp() == false) {
		table.snake.set_dir(DOWN);
		table.snake.setwbp(true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		win.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		table.snake.grow();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
		table.fruit_exists = false;
	}
	table.snake.setwbp(false);
}
#endif // !CPORTA