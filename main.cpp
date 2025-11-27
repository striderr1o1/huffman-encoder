#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char, int> GetFrequency(string str);
int main(){
string s = "aaabbcddd";
map<char, int> mp = GetFrequency(s);
 for(auto &p : mp){
         cout << p.first << " " << p.second << endl;
    }
}

map<char, int> GetFrequency(string str){
    map<char, int> mp;
    for(int i = 0; i < str.length(); i++){
            mp[str[i]] = mp[str[i]] + 1;
    }
    
    return mp;
}
