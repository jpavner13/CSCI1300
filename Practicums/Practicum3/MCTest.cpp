#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v{10, 5, 6, 3, 8};
    v.push_back(2);
    v.push_back(4);
    v.push_back(2);
    cout << v[v.size() -1] << endl;
    return 0;
}