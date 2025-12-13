#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "hfm.h"
#include <fstream>
#include "crow_all.h"
using namespace std;
int main(){
    // hf.decode();
    crow::SimpleApp App;
    
    CROW_ROUTE(App, "/sendFile/<string>")
    ([](string filename){
    crow::response res;
    HuffmanEncoder hf;
    string encodedStream = hf.encode(filename);
    cout << encodedStream;
    string s = hf.decode();
    
    return "Encoded bits: \n" + encodedStream + "\n\n" + "Decoded text: \n" + s;
});
App.port(18080).run();
}




//1. frequency calculation
//2. unique characters numbers
//3. choose numbers of bits
//4. create binary tree for each character, with its frequency as the root value
//5. keep on taking two minimum frequency roots, add them to create a new root, add those minimum roots as subtrees of the new root
//6. repeat until one root is achieved

//decoding:
//7. calculate bit, if left 0, else right 1
//8. 




