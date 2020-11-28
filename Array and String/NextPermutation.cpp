/***

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).


Input: nums = [1,2,3]
Output: [1,3,2]

***/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, n) for(int i = 1; i <= n; i++)
#define ALL(obj) (obj).begin(), (obj).end()

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		int n = nums.size();
		int index = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] >= nums[i + 1]) index = i;
			else break;
		}
		if (index == 0) {
			reverse(ALL(nums));
			return;
		}
		index--;
		int target = index + 1;
		for (int i = index + 1; i < n; i++) if (nums[index] < nums[i]) target = i;
		swap(nums[index], nums[target]);
		reverse(nums.begin() + (index + 1), nums.end());
		return;
	}
};
int main() {

	vector<int> v1 = {1, 2, 3, 4, 5};
	Solution s;
	s.nextPermutation(v1);
	for (auto x : v1)
		cout << x << " ";


	return 0;
}