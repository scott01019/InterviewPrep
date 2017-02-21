#include "tower.h"

int main() {
	int n = 5;
	Tower towers[3] = { Tower(0), Tower(1), Tower(2) };
	for (int i = n-1; i >= 0; --i) towers[0].Add(i);
	towers[0].MoveDisks(n, towers[2], towers[1]);
	return 0;
}
