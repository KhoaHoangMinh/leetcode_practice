#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size();
	for(int i = 0 ; i < size - 1; i++) {
		for(int j = i + 1; j < size; j++) {
			if (nums[i] + nums[j] == target) {
				return {i, j};
			}
		}
	}
	return {};
}
template <typename S>
ostream& operator<<(ostream& os,
					const vector<S>& vector) {

	// Printing all the elements using <<
	for (auto i : vector)
		os << i << " ";
	return os;
}

int main() {
	vector<int> i = {2,7,11,15};
	cout << twoSum(i, 9) << endl;

	vector<int> j = {3,2,4};
	cout << twoSum(j, 6) << endl;

	vector<int> k = {3,3};
	cout << twoSum(k, 6) << endl;

	return 0;
}
