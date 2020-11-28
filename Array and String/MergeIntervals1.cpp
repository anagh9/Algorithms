
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


struct interval {
	int start;
	int end;
	interval(int s, int e): start(s), end(e) {}
};


bool intervalCompare(interval a, interval b) {
	if (a.start < b.start)
		return true;
	return false;
}



void mergeIntervals(vector<interval>& t) {

	list<interval> stack;

	if (t.empty())
		return;


	sort(t.begin(), t.end(), intervalCompare);
	stack.push_back(t[0]);

	for (int i = 1; i < t.size(); i++) {

		interval top = stack.back();


		if (top.end < t[i].start) {
			stack.push_back(t[i]);
		}

		else if (top.end < t[i].end) {
			top.end = t[i].end;
			stack.pop_back();
			stack.push_back(top);
		}


	}



	for (auto it = stack.begin(); it != stack.end(); ++it)
		cout << it->start << "," << it->end << "  ";


}




int main()
{
	vector<interval> t = {{1, 4}, {2, 6}, {5, 8}};
	mergeIntervals(t);

}