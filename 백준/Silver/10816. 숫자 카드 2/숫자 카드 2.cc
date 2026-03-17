#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int N, M, n;
	std::vector<int> v;

	std::cin >> N;
	while (N--)
	{
		std::cin >> n;
		v.push_back(n);
	}

	std::sort(v.begin(), v.end());

	std::cin >> M;
	while (M--)
	{
		std::cin >> n;
		std::cout << std::upper_bound(v.begin(), v.end(), n)
			- std::lower_bound(v.begin(), v.end(), n) << ' ';
	}
}