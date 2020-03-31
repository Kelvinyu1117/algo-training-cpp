
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool visited[26] = {false};
vector<char> node;
vector<vector<char>> g(256);
map<char, int> mp;
int N = 0;

void clear() {
    for(int i = 0; i < 26; i++)
        visited[i] = false;
        
    node.clear();
    for(int i = 0; i < 26; i++)
        g[i].clear();
        
    mp.clear();
}
// to check whether the neighour of the current node has been visited or not (cycle)
bool check(char c) {
    for(int i = 0; i < g[mp[c]].size(); i++) 
        if(visited[g[mp[c]][i]]) return false;
        
    return true;
}

bool dfs(string path) {
    if(path.length() == N) {
        for(int i = 0; i < path.length(); i++) {
            cout << path[i];
            if(i != path.length() - 1)
                cout << " ";
        }
    
        cout << endl;
    
        return true;
    }
    
    bool res = false;
    
    for(int i = 0; i < node.size(); i++) {
        if(!visited[mp[node[i]]]) {
            if(check(node[i])) {
                visited[mp[node[i]]] = true;
                res = dfs(path + node[i]) || res;
                visited[mp[node[i]]] = false;
            }
        }
    }
    
    return res;
}

int main()
{
    int n;
    scanf("%d\n\n", &n);
    
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << endl;
        clear();
        string line;
        stringstream ss;
        
        getline(cin, line);
        ss.clear();
        ss.str(line);
        
        char c;
        int t = 0;
        while(ss >> c) {
            node.push_back(c);
            mp[c] = t++;
        }
        
        N = t;
        
        sort(node.begin(), node.end());
        
        getline(cin, line);
        ss.clear();
        ss.str(line);
        char x, y, z;
        while(ss >> x >> y >> z)
            g[mp[x]].push_back(mp[z]);
            
        if(!dfs(""))
            cout << "NO" << endl;
        
        if(!getline(cin, line)) break;
    }

    return 0;
}
