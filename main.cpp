#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
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

string ExtractStringFromFile(string fileName){
    fstream fileObject;
    fileObject.open(fileName, ios::in);
    string s;
    if(fileObject.is_open()){
        //read file
        //save in string
        //return string
        
    }
    else{
        return s;
    }
    return s;
}
//1. frequency calculation
//2. unique characters numbers
//3. choose numbers of bits
//4. create binary tree for each character, with its frequency as the root value
//5. keep on taking two minimum frequency roots, add them to create a new root, add those minimum roots as subtrees of the new root
//6. repeat until one root is achieved
//7. calculate bit, if left 0, else right 1
//8. 


