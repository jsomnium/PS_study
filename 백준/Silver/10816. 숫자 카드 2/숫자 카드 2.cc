#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	vector<int> ans;
	int N, M;

	cin >> N;
	vector<int> arr;
	while (N--){
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	cin >> M;
	while (M--){
		int target;
		cin >> target;

		int low = -1;
		int high_start = arr.size();
		while (low + 1 < high_start){
			int mid = low + (high_start - low) / 2;
			if (arr[mid] >= target){
				high_start = mid;
			} else {
				low = mid;
			}
		}

		low = -1;
		int high_end = arr.size();
		while (low + 1 < high_end){
			int mid = low + (high_end - low) / 2;
			if (arr[mid] > target){
				high_end = mid;
			} else {
				low = mid;
			}
		}

		ans.push_back(high_end - high_start);
	}

	for (auto a : ans)
		cout << a << " ";
}