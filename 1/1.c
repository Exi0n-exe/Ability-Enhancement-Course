#include<iostream>
using namespace std;

const int MAX = 1e5 + 5;  // Setting maximum integer value

int minMoves(int X, int Y) {
    int dp[MAX];
    for(int i=0; i<MAX; i++) {
        dp[i] = MAX;  // Initializing array with max integer value
    }
    dp[0] = 0;  // Base case 1
    dp[1] = 1;  // Base case 2
    
    for(int i=2; i<=X; i++) {
        if(i >= Y) {
            dp[i] = min(dp[i], dp[i-Y] + 1);  // Using Y-step move
        }
        if(i >= 11) {
            dp[i] = min(dp[i], dp[i-11] + 1);  // Using 11-step move
        }
    }
    
    return dp[X];  // Returning the minimum number of moves required to reach X
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    
    while(T--) {
        int X, Y;
        cout << "Enter the value of X and Y: ";
        cin >> X >> Y;
        cout << "Minimum number of moves required: " << minMoves(X, Y) << endl;
    }
    
    return 0;
}
