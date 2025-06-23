#include <iostream>
using namespace std;
 
int main() {
	
	int total = 0;
	
	for(int i = 0; i < 5; i++){
    	int n = 0;
    	cin >> n;
    
    	if(n < 40) n = 40;
    	total += n;
    }
	
    cout << total / 5;
 
}
