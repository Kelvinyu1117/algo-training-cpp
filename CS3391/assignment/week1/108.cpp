#include <iostream>

using namespace std;

struct Birthday {
    string name;
    int dd;
    int mm;
    int yyyy;
};

int cmp(Birthday d1, Birthday d2) {
    if(d1.yyyy == d2.yyyy)
        if(d1.mm == d2.mm) 
            return d1.dd - d2.dd;   
        else
            return d1.mm - d2.mm;
    else
        return d1.yyyy - d2.yyyy;
}

int main()
{
    int n;
    cin >> n;

    Birthday largest;
    Birthday smallest;
    for(int i = 0; i < n; i++){
        string name;
        int dd;
        int mm;
        int yyyy;
        cin >> name >> dd >> mm >> yyyy;
        
        Birthday tmp = {name, dd, mm, yyyy};
        if(i == 0) {
           largest = {name, dd, mm, yyyy};
           smallest = {name, dd, mm, yyyy};
        }else {
            if(cmp(tmp, smallest) < 0) {
                smallest = tmp;
            }
            
            if(cmp(tmp, largest) > 0) {
                largest = tmp;
            }
        }    
    }
    
    cout << largest.name << '\n' << smallest.name << endl;

    return 0;
}
