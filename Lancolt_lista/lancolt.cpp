#include <stdexcept>

#include "lancolt.h"
#include "coord.h"
#include "memtrace.h"

#ifndef CPORTA
#include <SFML/Graphics.hpp>
#include "SFML_fvg.h"
#endif // !CPORTA

using std::cout;
using std::endl;
using std::cin;

std::ostream& operator<<(std::ostream& os, Coord rhs) {
	return os << "x:" << rhs.x << " y:" << rhs.y;
}

void Snake::addToEnd(Coord kord) {
    Node* temp = new Node;
    temp->data = kord;
    temp->next = nullptr;
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void Snake::print()const{
    cout << "Snake: "<< endl;
    for (size_t i = 0; i < size(); i++) {
        cout << '[' << i << ']' << operator[](i) << endl;
    }
}

void Snake::addToStart(Coord kord) {
    Node* temp = new Node;
    temp->data = kord;
    temp->next = head;
    head = temp;
}

void Snake::destroy() {
    Node* iter = head;
    while (iter != nullptr) {
        Node* next = iter->next;
        delete iter;
        iter = next;
    }
}

Snake::Snake(size_t len,
    const unsigned int width,
    const unsigned int height,
    const unsigned int side,
    const unsigned int gap) :
    head(nullptr), tail(nullptr),
    points(0), len(len), dir(UP), was_button_pressed(false){

    int x = (width / (side + gap) / 2);
    int y = (height / (side + gap) / 2);
    
    for (size_t i = 0; i <= len; i++) {
        addToEnd(Coord{ x,y++ });
    }
}

void Snake::move() {
    Dir irany = dir;
    Node* iter;
    Coord temp,temp2;
    
    temp.x = (head->data.x);
    temp.y = (head->data.y);

    if (irany == RIGHT) { head->data.x += 1; }
    if (irany == DOWN) { head->data.y += 1; }
    if (irany == LEFT) { head->data.x -= 1; }
    if (irany == UP) { head->data.y -= 1; }
    iter = head->next;
    while (iter != nullptr) {
        temp2.x = iter->data.x;
        temp2.y = iter->data.y;
        iter->data.x = temp.x;
        iter->data.y = temp.y;
        temp = temp2;
        iter = iter->next;
    }
}

void Snake::grow() {
    addToEnd(tail->data);
    len++;
}

Coord Snake::operator[](size_t i) {
    if (i >= len) {
        throw "Tulindexeles";
    }
    Node* iter = head;
    size_t j = 0;
    while (iter != nullptr) {
        if (j == i) {
            return iter->data;
        }
        iter = iter->next;
        j++;
    }
    return { -100,-100 };
}

const Coord Snake::operator[](size_t i) const{
    if (i >= len) {
        throw "Tulindexeles";
    }
    Node* iter = head;
    size_t j = 0;
    while (iter != nullptr) {
        if (j == i) {
            return iter->data;
        }
        iter = iter->next;
        j++;
    }
    return { -100,-100 };
}
#ifndef CPORTA
void Snake::draw(const unsigned int side, const unsigned int gap, sf::RenderWindow& win) const {
    for (size_t i = 0; i < size(); i++) {
        box_draw(operator[](i), side, gap, win, sf::Color(0x009505ff));
    }
}
#endif // !CPORTA

bool Snake::collide_with_self()const {
    for (size_t i = 1; i < size(); i++) {
        if (operator[](0).x == operator[](i).x  && operator[](0).y == operator[](i).y) {
            return true;
        }
    }
    return false;
}

bool Snake::collide_with_wall(unsigned int side, unsigned int gap, unsigned int width, unsigned int height)const {
    if (head->data.x <= 0 ||
        head->data.y <= 0 ||
        unsigned(head->data.x) >= width/(side+gap)-1 ||
        unsigned(head->data.y) >= height/(side+gap)-1 )
        return true;
    else
        return false;
}
