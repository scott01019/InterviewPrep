#include <chrono>
#include <iostream>
#include <random>
#include <unordered_set>
using std::cout;
using std::chrono::system_clock;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::unordered_set;

const int N = 25;

struct Point {
	Point() : x_(0), y_(0) {}
	Point(int x, int y) : x_(x), y_(y) {}
	size_t operator()(const Point &p) const { return p.x_ * 1000 + p.y_; }
	bool operator==(const Point &p) const { return p.x_ == x_ && p.y_ == y_; }
	int x_, y_;
};

void Print(const unordered_set<Point, Point> &);
int Paths(const unordered_set<Point, Point> &, const Point &);

int main() {
	unsigned seed = system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(0, 4);

	unordered_set<Point, Point> grid;
	grid.insert(Point(0,0));
	grid.insert(Point(N - 1, N - 1));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (dist(gen) != 0)
				grid.insert(Point(i, j));

	Print(grid);
	cout << "\n" << Paths(grid, Point(0,0)) << "\n\n";
	return 0;
}

int Paths(const unordered_set<Point, Point> &grid, const Point &p) {
	if (p.x_ >= N || p.y_ >= N) return 0;
	if (p.x_ == N - 1 && p.y_ == N - 1) return 1;
	else {
		int sum = 0;
		Point right(p.x_ + 1, p.y_), down(p.x_, p.y_ + 1); 
		if (grid.find(right) != grid.end()) sum += Paths(grid, right);
		if (grid.find(down) != grid.end()) sum += Paths(grid, down);
		return sum;
	}
}

void Print(const unordered_set<Point, Point> &grid) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (grid.find(Point(i, j)) != grid.end())
				cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
}
