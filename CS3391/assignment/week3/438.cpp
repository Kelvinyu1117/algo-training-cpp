#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)


using namespace std;

/*
    The number of people in the party after the leave process finished has maximum number of fds,
    Therefore, to maximize the number of these kind of people, we can start with  
    forming a fully connected graph, all people has n - 1 friend. In this case, all people will leave at k = n - 1
    let try to disconnect one of the pair , let say 1th and nth person
    it can be observed that only these two persons have n - 2 friends, 
    the number of fds of other people remains the same.
    Now, start the leave process for k = 0 -> n - 1
    for the 1th and nth person, they will leave at k = n - 2. the number of fd of the rest of the people = n - 2
    when k = n - 1, as no one have n - 1 fds, no one leave 
    result in the number of people in the party = n - 2 (1th and nth have leaved)
*/
void mFun() {
    int n;
    cin >> n;
    while(n--) {
        int nums;
        cin >> nums;
        if(nums == 1) cout << 0 << endl;
        else cout << nums - 2 << endl;
    }
}


int main() {
    mFun();
    return 0;
}