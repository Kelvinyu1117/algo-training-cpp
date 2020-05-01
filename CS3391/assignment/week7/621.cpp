#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility> 
#include <algorithm>

using namespace std;
#define MAXN 150

struct Edge {
    int s;
    int t;
    int w;
    Edge() {s = t = 0;}
    Edge(int from, int to, int weight): s(from), t(to), w(weight) {}
};

bool cmp_old(Edge e1, Edge e2) {
    return e1.w > e2.w;
}


bool cmp_new(Edge e1, Edge e2) {
    return e1.w < e2.w;
}



struct UnionFind {
    int size[MAXN];
    int arr[MAXN];
    int max_size;
    int min_size;
    UnionFind() {
        max_size = 1;
        min_size = 1;
        for(int i = 0; i < MAXN; i++) {
            size[i] = 1;
            arr[i] = i;
        }
    }
    
    void clear() {
        for(int i = 0; i < MAXN; i++) {
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

vector<Edge> old_roads(MAXN);
vector<Edge> new_roads(MAXN);

bool has_old[MAXN][MAXN];
void clear() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            has_old[i][j] = 0;
        }
    }
    
    old_roads.clear();
    new_roads.clear();
}

void m() {
    string input;
	int n;
	while(getline(cin, input)) {
	    clear();
	    stringstream s1(input);
		s1 >> n;
		
		if(!n) return;
		
		int len1 = 0;
		int len2 = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, input);
			for (int j = 0; j < n; j++) {
				has_old[i][j] = input[j] - '0';
			}
		}
		
		for(int i = 0; i < n; i++) {
		    getline(cin, input);
			stringstream ss(input);
			
		    for(int j = 0; j < n; j++) {
		        int a;
				ss >> a;
		        if (j > i) {
    		        if(!has_old[i][j]) {
    		            new_roads.push_back({i, j, a});
    		        }
		        }
		    }
		}
		
		
		UnionFind uf;
		for(int i = 0; i < n; i++) {
		    getline(cin, input);
			stringstream ss(input);
		    for(int j = 0; j < n; j++) {
		        int a;
				ss >> a;
		        if (j > i) {
    		        if(has_old[i][j]) {
    		            old_roads.push_back({i, j, a});
    		        }
		        }
		    }
		}
		
		sort(old_roads.begin(), old_roads.end(), cmp_old);
		
		int res = 0;
		for (int i = 0; i < old_roads.size(); i++) {
			int root1 = uf.root(old_roads[i].s);
			int root2 = uf.root(old_roads[i].t);
			if (root1 == root2) {
				res += old_roads[i].w;
				continue;
			}
			uf.unify(root1, root2);
		}
		
		sort(new_roads.begin(), new_roads.end(), cmp_new);
		
	
	    for (int i = 0; i < new_roads.size(); i++) {
			int root1 = uf.root(new_roads[i].s);
			int root2 = uf.root(new_roads[i].t);
			if (root1 == root2) 
				continue;
			
			res += new_roads[i].w;
			uf.unify(root1, root2);
		}
		
		cout << res << endl;
	}
    
}
int main()
{
    m();

    return 0;
}
