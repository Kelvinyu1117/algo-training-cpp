#include <iostream>
#include <vector>
using namespace std;
#define N 8


void print(bool m[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "-----------" << endl << endl;
}

bool isSafe(bool m[N][N], int r, int c) {
    // same column
    for(int i = 0; i < N; i++) {
        if(m[i][c])
            return false;
    }
    
    // same row
    for(int i = 0; i < N; i++) {
        if(m[r][i])
            return false;
    }
    
    // left upper diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (m[i][j]) 
            return false;
    }
    
    // left lower diagonal
    for (int i = r, j = c; i < N && j >= 0; i++, j--) {
        if (m[i][j]) 
            return false;
    }
    
    return true;
}

void printAns(vector<vector<int>> &ans, int r, int c) {
    printf("SOLN       COLUMN\n");
    printf(" #     ");
    for(int i = 1; i <= N; i++) {
        printf("%2d", i);
    }
    printf("\n\n");
    for(int i = 0, k = 0; i < ans.size(); i++) {
       
        if(ans[i][c] == r) {
            printf("%2d     ", k + 1);
            for(int j = 0; j < N; j++) {
                printf("%2d", ans[i][j] + 1);
            }
            printf("\n");
            k++;
        }
    }
}


vector<int> getQueensPos(bool m[N][N]) {
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(m[j][i]) {
                ans.push_back(j);
                break;
            }
        }
    }
    
    return ans;
}

bool solve(vector<vector<int>> &ans, bool m[N][N], int c) {
    if(c == N) {
        ans.push_back(getQueensPos(m));
        return true;
    }
    
    bool res = false;
    
    for(int i = 0; i < N; i++) {
        if(isSafe(m, i, c)) {
            m[i][c] = 1;
            
            solve(ans, m, c + 1);
            
            m[i][c] = 0;
        }
    }
    
    return res;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    bool m[N][N] = {0};
    solve(ans, m, 0);
    
    while(n--){
    
        int r, c;
        cin >> r >> c;
        
        printAns(ans, r - 1 , c - 1);
        
        if(n)
            printf("\n");
    }

    return 0;
}
