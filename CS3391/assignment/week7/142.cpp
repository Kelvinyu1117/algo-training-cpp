#include <iostream>

using namespace std;
#define MAXN 30005

struct UnionFind {
    int size[MAXN];
    int arr[MAXN];
    int max_size;
    int min_size;
    UnionFind() {
        max_size = 1;
        min_size = 1;
        for(int i = 1; i < MAXN; i++) {
            size[i] = 1;
            arr[i] = i;
        }
    }
    
    int root(int i) {
        while(arr[i] != i) {
            arr[i] = arr[arr[i]];
            i = arr[i];
        }
        
        return i;
    }
    
    void unify(int a, int b) {
        int root_A = root(a);
        int root_B = root(b); 
        
        if(root_A == root_B) return;
        
        if(size[root_A] < size[root_B]) {
            arr[ root_A ] = root_B;
            size[root_B] += size[root_A];
        }
        else{
            arr[root_B] = root_A;
            size[root_A] += size[root_B];
        }
        
        
        max_size = max(max_size, max(size[root_A], size[root_B]));
        min_size = min(min_size, min(size[root_A], size[root_B]));
    }
    
    bool find(int a, int b) {
        return root(a) == root(b);
    }
    
};



void m() {
    int t;
    
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        UnionFind uf;
        
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            
            uf.unify(a, b);
        }
        
        cout << uf.max_size << endl;
    }
}



int main()
{
    m();

    return 0;
}
