// Merge Intervals

/***
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals,
and return an array of the non-overlapping intervals
that cover all the intervals in the input.


Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Explanation: Since Intervals [1,3] and [2,6] overlaps, merge them into [1,6].


Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
***/

#include <iostream>
#include <algorithm>
#include <stack>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
struct interval {
   int start;
   int end;
};
bool compareInterval(interval i1, interval i2) {
   return (i1.start < i2.start);
}
void mergeOverlappingIntervals(interval *arr, int n) {
   if (n <= 0) {
      return;
   }
   stack<interval> s;
   sort(arr, arr + n, compareInterval);
   s.push(arr[0]);
   for (int i = 1; i < n; ++i) {
      interval top = s.top();
      if (top.end < arr[i].start) {
         s.push(arr[i]);
      } else if (top.end < arr[i].end) {
         top.end = arr[i].end;
         s.pop();
         s.push(top);
      }
   }
   cout << "Merged intervals: " << endl;
   while (!s.empty()) {
      interval i = s.top();
      cout << "{" << i.start << ", " << i.end << "}" << " ";
      s.pop();
   }
   cout << endl;
}
int main() {
   interval arr[] = {{12, 14}, {11, 13}, {20, 22}, {21, 23}};
   mergeOverlappingIntervals(arr, SIZE(arr));
   return 0;
}


