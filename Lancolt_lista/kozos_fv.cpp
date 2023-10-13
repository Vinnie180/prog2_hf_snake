#include "kozos_fv.h"
#include "memtrace.h"

void addPoints(Snake& s, const Fruit& f) {
	cout << "amount added: " << f.getp() << endl;
	s.pointInc(f.getp());
}
