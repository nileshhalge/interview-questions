
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> max_sliding_window(const vector<int> &stream, vector<int>::size_type window_sz) {
	vector<int> res;
	deque<vector<int>::size_type > maxs;

	for (vector<int>::size_type i = 0; i < stream.size() && i < window_sz; i++) {
		while (!maxs.empty() && stream[i] >= stream[maxs.back()]) {
			maxs.pop_back();
		}
		maxs.push_back(i);
	}

	res.push_back(stream[maxs.front()]);

	for (vector<int>::size_type i = window_sz; i < stream.size(); i++) {
		while (!maxs.empty() && maxs.front() <= i-window_sz) {
			maxs.pop_front();
		}
		while (!maxs.empty() && stream[i] >= stream[maxs.back()]) {
			maxs.pop_back();
		}
		maxs.push_back(i);
		res.push_back(stream[maxs.front()]);
	}

	return res;
}

int main(void) {
	cout << "Enter size of array, followed by the elements, followed by size of sliding window" << endl;
	cout << "> ";

	vector<int>::size_type arr_sz;
	while (cin >> arr_sz) {
		vector<int> arr(arr_sz);
		for (vector<int>::size_type i = 0; i < arr_sz; i++) {
			cin >> arr[i];
		}
		vector<int>::size_type k;
		cin >> k;

		vector<int> res = max_sliding_window(arr, k);

		for (vector<int>::const_iterator it = res.begin(); it != res.end(); it++) {
			cout << *it << " ";
		}

		cout << endl;
		cout << "> ";
	}

	return 0;
}
