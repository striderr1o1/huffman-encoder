#include "hfm.h"

HuffmanEncoder::HuffmanEncoder(){
    CharacterList = nullptr;
    BTlist = {};
    Text = "";
    BitStream = "";
    DecodedText = "";
}

void HuffmanEncoder::readFile(const string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        throw runtime_error("file not found  " + filename);
    }
    // using sstream library creating a buffer to store the file using osteamstring
    ostringstream buffer;
    buffer << file.rdbuf();// reads the whole file and temporaryly stores to buffer as string
    Text = buffer.str();
    return;
}


void HuffmanEncoder::CreateLists(string str){
    map<char, int> mp;//declaring map
    for(int i = 0; i < str.length(); i++){
            mp[str[i]] = mp[str[i]] + 1;//looping over the map to generate frequency against the string
    }
    int size = mp.size();//getting map size and initializing a binary tree array
    
    CharacterList = new char[size];

    // map<char, int>::iterator it = mp.begin();//assigning an iterator to the beginning of the map

    int i = 0;//loop i counter

    for(auto it = mp.begin(); it!=mp.end(); it++){// will run while map doesnt end
        CharacterList[i] = it->first;
        BinaryTree newTree;
        
        newTree.CreateNode(it->first, it->second);
        BTlist.push_back(newTree);
        //create node for each BTlist binary tree
        i++;//increment i
    }
    SortList();
}

void HuffmanEncoder::SortList(){
    BinaryTree temp;
    for(int i = 0; i < BTlist.size(); i++){
        for(int j = 0; j < BTlist.size()-1; j++){
            if(BTlist[j].returnFrequency() > BTlist[j+1].returnFrequency()){
                temp = BTlist[j];
                BTlist[j] = BTlist[j+1];
                BTlist[j+1] = temp;
            }
        }
    }
    
}

BinaryTree HuffmanEncoder::GetMinimumTree(){
    int min = BTlist[0].returnFrequency();
    int index = 0;

    for(int i = 0; i < BTlist.size(); i++){
        int curr = BTlist[i].returnFrequency();
        for(int j = 0; j < BTlist.size(); j++){
            if(BTlist[j].returnFrequency() < min){
                min = BTlist[j].returnFrequency();
                index = j;
            }
        }
    }

    vector<BinaryTree>::iterator it = BTlist.begin();
    BinaryTree returningTree = BTlist[index];
    
    cout << "Removing " << returningTree.returnFrequency() << " " << endl;
    BTlist.erase(it + index);
    
    return returningTree;
}

void HuffmanEncoder::MergeBinaryTrees(){
    int size = BTlist.size();
    for(int i = 0; i < BTlist.size(); i++){
            cout << BTlist[i].returnFrequency() << " ";
        }
    while(size!=1){
        BinaryTree MinTree1 = GetMinimumTree();//get minimum tree
        BinaryTree MinTree2 = GetMinimumTree();//get minimum tree
        BinaryTree newTree;//create new tree
        int Tree1Freq = MinTree1.returnFrequency();//get frequency of miminum tree 1
        int Tree2Freq = MinTree2.returnFrequency();//get frequency of minimum tree 2
        int addedFreq = Tree1Freq + Tree2Freq;//add both frequencies of both extracted trees
        newTree.CreateNode('-', addedFreq);//create a new node and push the added frequency (will make root node)
       
        if(Tree1Freq < newTree.GetRoot()->frequency){//if first extracted trees's freq is less than new trees added frequency, push it as left child of new tree and the other tree as right child 
            newTree.GetRoot()->right = MinTree1.GetRoot();
            newTree.GetRoot()->left = MinTree2.GetRoot();
        }
        else{//otherwise the opposite
            newTree.GetRoot()->right = MinTree2.GetRoot();
            newTree.GetRoot()->left = MinTree1.GetRoot();
        }
        
        cout << " adding " << newTree.returnFrequency() << endl;
        //push the new tree in the binary trees list
        BTlist.push_back(newTree);
        //print the binary trees
        for(int i = 0; i < BTlist.size(); i++){
            cout << BTlist[i].returnFrequency() << " ";
        }
        size = BTlist.size();
    }
    cout << endl;
    cout << BTlist[0].returnFrequency() << endl;
    
}
void HuffmanEncoder::WriteAsBitStream(){
    for(int i = 0; i < Text.length(); i++){
        BitStream+=BinaryCodes[Text[i]];
        //  cout << Text[i];
    }
    // cout << BitStream << endl;
}

void HuffmanEncoder::WriteBytesToFile(){
    std::remove("bf.bin");
    fstream fileObj;
    fileObj.open("bf.bin", ios::binary | ios::out);
    if(fileObj.is_open()){
        string s;
        for(int i = 0; i < BitStream.length(); i++){
            
            s+=BitStream[i];
            if((i+1)%8 == 0 && i!= 0){
                if(s.size() < 8){
                    while(s.size()!=8){
                        s+="0";
                    }
                }
                
                u_int8_t B= stoi(s);
                fileObj.write(reinterpret_cast<char*>(&B), 1);
                s = "";
            }
        }
    }
}

void HuffmanEncoder::encode(string filename){//main function wrapper over other function which user can access
    readFile(filename);
    CreateLists(Text);
    MergeBinaryTrees();
    map<char, string> mp;
    BinaryCodes = BTlist[0].GetCodeByTraversal();
    WriteAsBitStream();
    WriteBytesToFile();

}
//################################DECODE###############################



void HuffmanEncoder::decode(){

}


