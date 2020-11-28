/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one duplicate number in nums, return this duplicate number.


Input : nums = [1,3,4,2,2]
Output : 2
*/



#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
	//TC = O(n^2)
	int findDuplicate(vector<int>& nums) {
		int temp = -1;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] == nums[j])
					temp = nums[i];
			}
		}

		return temp;
	}


	//TC = O(nlogn)
	int findDuplicate2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				return nums[i];
			}
		}
		return -1;
	}

//TC = O(n)
	int findDuplicate3(vector<int>& nums) {
		int tortoise = nums[0];
		int hare = nums[0];
		do {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		} while (tortoise != hare);

		tortoise = nums[0];
		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[hare];
		}
		return hare;
	}

};

int main() {
	Solution s;
	vector<int> arr{1, 2, 3, 4, 6, 7, 2, 2};
	cout << s.findDuplicate(arr) << endl;
	cout << s.findDuplicate2(arr) << endl;
	cout << s.findDuplicate3(arr) << endl;

	return 0;
}
