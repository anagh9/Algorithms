// Largest Sum Contiguous Subarray
/***
Kadane algo
--------------
Initialize Two var say maxSoFar and maxEndHere
Loop for each element of the array
maxEndHere = maxEndHere + a[i];
if(maxSoFar < maxEndHere)
	maxSoFar = maxEndHere
if(maxEndHere < 0)
	maxEndHere = 0;
return maxSoFar

***/

int maxSubArray(int a[], int size) {
	int maxSoFar = INT_MIN, maxEndHere = 0;
	for (int i = 0; i < size; i++) {
		maxEndHere = maxEndHere + a[i];
		if (maxSoFar < maxEndHere)
			maxSoFar = maxEndHere;

		if (maxEndHere < 0)
			maxEndHere = 0
		}

	return maxSoFar;
}

// TC = O(n);

/*
Input :
arr = -2,-3,-4,-1,-2,1,5,-3

Output :
7

*/