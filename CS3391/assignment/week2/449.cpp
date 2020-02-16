#include <iostream>

using namespace std;

char a[100][100];

// m = # of rows, n = # of columns
int count(int m, int n, int i, int j) {
    int sum = 0;
    
    if(i % 2) { // odd (i - 1, j), (i - 1, j + 1), (i, j - 1), (i, j + 1), (i + 1, j), (i + 1, j + 1)
        if(i - 1 >= 0 && a[i - 1][j] == '.')
            sum++;

        if(i - 1 >= 0 && j + 1 < n && a[i - 1][j + 1] == '.')
            sum++;
        
        if(j - 1 >= 0 && a[i][j - 1] == '.')
            sum++;
        
        if(j + 1 < n && a[i][j + 1] == '.')
            sum++;
        
        if(i + 1 < m && a[i + 1][j] == '.')
            sum++;
        
        if(i + 1 < m && j + 1 < n && a[i + 1][j + 1] == '.')
            sum++;
            
    }else { // even (i - 1, j - 1), (i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j - 1), (i + 1, j)
        if(i - 1 >= 0 && j - 1 >= 0 & a[i - 1][j - 1] == '.')
            sum++;
            
        if(i - 1 >= 0 && a[i - 1][j] == '.')
            sum++;
        
        if(j - 1 >= 0 && a[i][j - 1] == '.')
            sum++;
        
        if(j + 1 < n && a[i][j + 1] == '.')
            sum++;
        
        if(i + 1 < m && j - 1 >= 0 && a[i + 1][j - 1] == '.')
            sum++;
        
        if(i + 1 < m && a[i + 1][j] == '.')
            sum++;
    }
    return sum;
}

void mFun() {
    int i = 0;
    string x[50];
	int n = 0;
	int m = 0;
	while(getline(cin, x[0]))
	{
	    int res = 0;
		m = 1;
		while(getline(cin, x[m]) and x[m][0] != '\0'){
			m ++ ;
		}
		
		n = x[0].size();
		
		for(int i = 0; i < m; i++) {
		    for(int j = 0; j < n; j++) {
		        a[i][j] = x[i][j];
		    }
		}
		
	    for(int f = 0; f < m; f++) {
            for(int g = 0; g < n; g++) {
                if(a[f][g] == '#') {
                    res += count(m, n, f, g);
                    a[f][g] = 'X';
                }
            }
        }
        
        cout << res << endl;
	}
}

int main()
{
    mFun();
    return 0;
}