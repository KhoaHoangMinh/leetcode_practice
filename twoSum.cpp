#include <iostream>
#include <vector>
#include <unordered_map>

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

vector<int> twoSumHash(vector<int>& nums, int target) {
	int size = nums.size();
	unordered_map<int, int> hash;
	for(int i = 0 ; i < size; i++) {
		// each element is key, value is index i
		hash[nums[i]] = i;
	}
	for(int i = 0; i < size; i++) {
		int complement = target - nums[i];
		if(hash.find(complement) != hash.end() && hash[complement] != i) {
			return {i, hash[complement]};
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
	cout << twoSum(i, 9) << ", " << twoSumHash(i, 9) << endl;

	vector<int> j = {3,2,4};
	cout << twoSum(j, 6) << ", " << twoSumHash(j, 6) << endl;

	vector<int> k = {3,3};
	cout << twoSum(k, 6) << ", " << twoSumHash(k, 6) << endl;

	return 0;
}
