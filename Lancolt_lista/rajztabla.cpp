#include "rajztabla.h"
#include "memtrace.h"

#ifndef CPORTA
#include "SFML_fvg.h"
#endif // !CPORTA


//void Table::info() const{
//	cout << "Specs: " << "S:" << side << " G:" << gap << " W:" << width << " H:" << height << endl;
//	snake.print();
//	cout << "Apple: " << apple.get_c() << endl;
//	cout << "Gapple: " << gapple.get_c() << endl;
//}

#ifndef CPORTA
void Table::draw_table(sf::RenderWindow& win) const {
	apple.draw(side, gap, win);
	gapple.draw(side, gap, win);
	snake.draw(side, gap, win);
	cage(side, gap, win);
}
#endif // !CPORTA

void Table::generateFruits() {
	if (!fruit_exists) {
		bool lucky = false;
		if (generate_in_range(2, 0) == 1) {
			lucky = true;
		}

		if (!lucky) {
			gapple.set_x(-1); gapple.set_y(-1);
			bool inside = true;
			while (inside) {
				int u = int(width / (side + gap) - 1);
				int l = int(1);
				apple.set_x(generate_in_range(u - 1, l));

				u = int(height / (side + gap) - 1);
				l = int(1);
				apple.set_y(generate_in_range(u - 1, l));

				inside = false;
				for (size_t i = 0; i < snake.size(); i++) {
					if (snake[i].x == apple.get_c().x && snake[i].y == apple.get_c().y) {
						inside = true;
						break;
					}
				}
			}
		}
		else {
			apple.set_x(-1); apple.set_y(-1);
			bool inside = true;
			while (inside) {
				int u = int(width / (side + gap) - 1);
				int l = int(1);
				gapple.set_x(generate_in_range(u - 1, l));

				u = int(height / (side + gap) - 1);
				l = int(1);
				gapple.set_y(generate_in_range(u - 1, l));

				inside = false;
				for (size_t i = 0; i < snake.size(); i++) {
					if (snake[i].x == gapple.get_c().x && snake[i].y == gapple.get_c().y) {
						inside = true;
						break;
					}
				}
			}
		}

		fruit_exists = true;
		lucky = false;
	}
}

void Table::death(bool& gameOver) {
	if (snake.collide_with_self() == 1 || snake.collide_with_wall(side, gap, width, height) == 1) {
		gameOver = true;
	}
}

void Table::eat() {
	if (snake[0].x == apple.get_c().x && snake[0].y == apple.get_c().y) {
		fruit_exists = false;
		snake.grow();
		addPoints(snake, apple);
		cout << "Points: " << snake.getp() << endl;
	}
	else if (snake[0].x == gapple.get_c().x && snake[0].y == gapple.get_c().y) {
		fruit_exists = false;
		snake.grow();
		addPoints(snake, gapple);
		cout << "Points: " << snake.getp() << endl;
	}
}