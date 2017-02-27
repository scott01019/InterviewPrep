#include <iostream>
#include <vector>
using std::cout;
using std::vector;

const int N = 10;

vector<vector<int>> GetSubsets(const vector<int> &);
void GetSubsets(const vector<int> &, const vector<int> &, 
		int, vector<vector<int>> &);

int main() {
	vector<int> set;
	for (int i = 0; i < N; ++i) {
		set.push_back(i);
	}
	
	vector<vector<int>> subsets = GetSubsets(set);
	
	for (const auto &subset : subsets) {
		for (auto i : subset) cout << i << " ";
		cout << "\n";
	}

	return 0;
}

vector<vector<int>> GetSubsets(const vector<int> &set) {
	vector<vector<int>> subsets;
	GetSubsets(set, vector<int>(), 0, subsets);
	return subsets;
}


void GetSubsets(const vector<int> &set, const vector<int> &current, 
		int index, vector<vector<int>> &subsets) {
	if (index == set.size()) {
		subsets.push_back(current);
	} else {
		GetSubsets(set, current, index+1, subsets);
		vector<int> v = current;
		v.push_back(set[index]);
		GetSubsets(set, v, index+1, subsets);
	}
}
