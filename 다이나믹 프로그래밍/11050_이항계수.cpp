#include <iostream>
using namespace std;
 
int binomial2(int n, int k) {
	int dp[100][100] = { 0, };

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= min(k, i); j++)
			if (i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	
	return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
 
    int result = binomial2(n, k);
 
    cout << result;
}
