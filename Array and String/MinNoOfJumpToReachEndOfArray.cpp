// Minimum no. of Jumps to reach end of an array

/*** Input / Output


arr[] = 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9
Output: 3 (1-> 3 -> 8 -> 9)
Explanation: Jump from 1st element
to 2nd element as there is only 1 step,
now there are three options 5, 8 or 9.
If 8 or 9 is chosen then the end node 9
can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
Explanation: In every step a jump
is needed so the count of jumps is 10.

***/



/**Way 1 Naive Recursive Approach
Start From the first Element and Recursively call for all the elements reachable from first element
Min no. of jumps to reach end from first can be calculated using min no. of jumps needed to reach end from first
minJumps(start,end) = Min(minJump(k,end))  all k are reachable from start

***/

int minJump(int arr[], int n) {
	//When Source and Destination are Same
	if (n == 1)
		return 0;

	/**
	Traverse through all the points
	reachable from arr[l]
	Recursively, get the min no.
	of jump neede to reach arr[h] from
	these reachable points

	**/
	int res = INT_MAX;
	for (int i = n - 2; i >= 0; i--) {
		if (i + arr[i] > = n - 1) {
			int sub_res = minJumps(arr, i + 1);
			if (sub_res != INT_MAX)
				res = min(res, sub_res + 1);
		}
	}
	return res;
}

// TC - O(n*n //Overlapping problem occurs

/***Dynamic Programming

Make a jump[] array from left to right such that jump[i] indicate the min no. of jumps
needed to reach arr[i] from arr[0].

To Fill jump Arr run two nested loop i and j as counters
OuterLoop from 1 to n-1
InnerLoop from 0 to n-1

If i is less than j + arr[j] then set jumps[i] to min of jumps[i] and jumps[j] + 1. Initially
set jummp[i] to INT_MAX

finally return jumps [n-1]

***/
int minJumps(int arr[], int n) {
	int *jumps = new int[n];
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	for (int i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

// TC = O(n^2)
