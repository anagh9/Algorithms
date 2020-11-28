/***
Merge two sorted arrays with O(1) extra space

We are given two sorted array. We need to merge these two arrays such that the initial numbers (after complete sorting) are in the first array and the remaining numbers are in the second array. Extra space allowed in O(1).

Input : arr1 = 10
		arr2 = 2 ,3;

Output : arr1: 2
		 arr2 : 3, 10;

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}

***/

/***Implementation
1} Iterate through every element of arr2[] starting from last
	element. Do following for every element arr2[i]

a) Store last element of arr1[i]: last = arr1[i]
b) Loop from last element of arr1[] while element arr1[j] is grater than arr2[i].
		arr1[j+1]	= arr1[j] // Move element one pos ahead
		j--;
c) If any element of arr1[] was moved or (j!=m-1)
		arr1[j+1] = arr2[i]
		arr2[i] = last
***/
void merge(int arr1[], int arr2[], int m, int n) {
	for (int i = n - 1; i >= 0; i--) {
		last = arr1[m - 1];

		for (int j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--)
			arr1[j + 1] = arr1[j];
		// If there was a greater element
		if (j != m - 2 || last > ar2[i])
		{
			ar1[j + 1] = ar2[i];
			ar2[i] = last;
		}
	}
}

// TC = O(m*n)