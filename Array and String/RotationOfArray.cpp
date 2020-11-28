//Cyclically Rotate Array By One

/***
Store last element in a variable say x
Shift all element one pos ahead
Replace first element of array with x
***/

void rotate(int arr[], int n) {
	int x = arr[n - 1], i;
	for (i = n - 1; i > 0 ; i--)
		arr[i] = arr[i - 1];
	arr[0] = x;
}

//Program for array rotation
/***
Rotate one by one

leftRotate(arr[],d,n)
start
For 0 to d
	left rotate all element of arr[] by one
end

***/

void leftRotatebyOne(int arr[], int n) {
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}

void leftRotate(int arr[], int d, int n) {
	for (int i = 0; i < d; i++)
		leftRotatebyOne(arr, n);
}

/***
Imput :
arr[] = 1,2,3,4,5,6,7,8,9
d = 2

Output = 3 4 5 6 7 8 9 1 2

TC - O(n*d);

***/


// Most Efficient Method TC - O(n)

/***
Juggling Method
-----------------
Divide the Array in diffrent sets
where sets no. = GCD of n and d

Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
//after juggle
  arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}
//then
   arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}
//finally
   arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}

***/

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void leftRotateJuggle(int arr[], int d, int n) {
	d = d % n;
	int Gcd = gcd(d, n);
	for (int i = 0; i < Gcd; i++) {
		int temp = arr[i];
		int j = i;

		while (1) {
			int k = j + d;
			if (k >= n)
				k = k - n;

			if (k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}