#include <bits/stdc++.h>
#include <map>

using namespace std;

int main (){
    map<int, int> m;
    m[100] = 200; // key = 100, value = 200
    m[200] = 300; // key = 200, value = 300
    
    m.insert({300, 400}); // key = 300, value = 400
    m.insert({400,500}); // key = 400, value = 500
    cout << "Size of map1: " << m.size() << endl; 
 
    for (pair<int,int> x : m){
        cout << "Key: " << x.first << ", Value: " << x.second << endl;
    }
    // for ( auto it : m){
    //     cout << "Key: " << it.first << ", Value: " << it.second << endl;
    // }
    
}