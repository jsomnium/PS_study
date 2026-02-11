#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main(){
    int P;
    cin >> P;
    
    while (P--){
        int testCase = 0;
        int totalSteps = 0;
        
        vector<int> Student(20, 0);
        set<int> Height;
        
        cin >> testCase;
        for (int i = 0; i < 20; i++) cin >> Student[i];
        
        for (int j = 0; j < 20; j++){
            int curStudent = Student[j];
            
            auto it = Height.lower_bound(curStudent);
            totalSteps += distance (it, Height.end());
            
            Height.insert(curStudent);
        }
        
        cout << testCase << " " << totalSteps << endl;
    }
    
    return 0;
}