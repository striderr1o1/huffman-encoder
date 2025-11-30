#include "hfm.h"

map<char, int> HuffmanEncoder::GetFrequency(string str){
    map<char, int> mp;
    for(int i = 0; i < str.length(); i++){
            mp[str[i]] = mp[str[i]] + 1;
    }
    
    return mp;
}