#include <bits/stdc++.h>
using namespace std;
void right_rotate_by_one(int arr[], int n)
{

/* Shift operation to the right */
int temp = arr[n - 1], i;
for (i = n - 1; i > 0; i--)
arr[i] = arr[i - 1];
arr[0] = temp;
}
void array_right_rotate(int arr[], int no_of_rotations, int n)
{
for (int i = 0; i < no_of_rotations; i++)
right_rotate_by_one(arr, n);     // Function is called for no_of_rotations times
}
int main()
{
int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n = sizeof(arr) / sizeof(arr[0]);    // Finding the size of the array
cout<<"\nArray elements before rotating : \n";
for(int i = 0; i < n; i++)
{
cout<<arr[i]<<"\t";     // Printing the array elements
}
int no_of_rotations = 2;
array_right_rotate(arr, no_of_rotations, n);
cout<<"\n\nArray elements after rotating : \n";
for(int i = 0; i < n; i++)
{
cout<<arr[i]<<"\t";    // Printing the array elements after rotation of elements
}
cout<<"\n";
return 0;
}
