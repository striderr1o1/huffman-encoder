#include "hfm.h"

HuffmanEncoder::HuffmanEncoder(){
    CharacterList = nullptr;
    BTlist = {};
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
        BinaryTree MinTree1 = GetMinimumTree();
        BinaryTree MinTree2 = GetMinimumTree();
        BinaryTree newTree;
        int Tree1Freq = MinTree1.returnFrequency();
        int Tree2Freq = MinTree2.returnFrequency();
        int addedFreq = Tree1Freq + Tree2Freq;
        newTree.CreateNode('-', addedFreq);
        //add trees to new tree as nodes
        // BinaryTree* pt1 = &MinTree1;
        // BinaryTree* pt2 = &MinTree2;
        // newTree.AddTreeNode(MinTree1.GetRoot());
        
        // newTree.AddTreeNode(MinTree2.GetRoot());
        if(Tree1Freq < newTree.GetRoot()->frequency){
            newTree.GetRoot()->right = MinTree1.GetRoot();
            newTree.GetRoot()->left = MinTree2.GetRoot();
        }
        else{
            newTree.GetRoot()->right = MinTree2.GetRoot();
            newTree.GetRoot()->left = MinTree1.GetRoot();
        }
        //this is giving 10 when it should be 1+1 = 2
        cout << " adding " << newTree.returnFrequency() << endl;
        newTree.PrintTree();
        BTlist.push_back(newTree);

        for(int i = 0; i < BTlist.size(); i++){
            cout << BTlist[i].returnFrequency() << " ";
        }
        size = BTlist.size();
    }
    cout << endl;
    cout << BTlist[0].returnFrequency() << endl;
    
}

void HuffmanEncoder::encode(){
    // CreateLists("");
    CreateLists(R"(The Value of Learning and Consistency in the Modern World

In today's fast-moving world, one of the biggest challenges people face is staying grounded while still growing in knowledge and skills. Technology evolves quickly, industries shift, and new tools appear every year. For someone studying computer science, traveling through these changes can feel overwhelming at times. But the key to navigating this landscape is consistency — not bursts of effort, not shortcuts, but slow, steady progress that builds real strength.

When someone first enters the world of programming, it often feels like a maze. There are dozens of languages, each with its own patterns and quirks. Tools change, libraries get replaced, and best practices keep evolving. But once a person adopts the mindset of continuous learning, the field stops feeling intimidating and becomes something enjoyable. You start solving problems not because you memorized solutions, but because you understand how to think about them. That mindset is what truly separates a beginner from someone who grows into a capable engineer.

At the same time, a person should remember that growth in worldly knowledge doesn't have to conflict with spiritual grounding. For a believer, learning is not simply about increasing information. It's about becoming more responsible, more thoughtful, and more disciplined. Even the classical scholars emphasized the importance of sincere intention and humility when seeking knowledge. The lesson is simple: when a person learns with sincerity and keeps their heart clean, their knowledge becomes a benefit and not a burden.

In software engineering specifically, consistency builds a kind of quiet confidence. When you write code every day, even if it's just a small function or debugging a minor error, your mind starts forming patterns. You notice mistakes faster, and you understand how systems behave under the hood. Over time, what used to take you an hour starts taking only a few minutes. That progress isn't sudden; it's the natural result of steady effort. Senior engineers aren't necessarily smarter than everyone else — they just spend years refining the way they think, plan, and troubleshoot.

But learning isn't limited to technical skills. Character, discipline, and patience matter just as much. When someone stays calm during challenges, treats others with respect, avoids arrogance, and keeps their heart connected to Allah (subhanahu wa ta'ala), they carry themselves differently. Their work becomes cleaner, their relationships become healthier, and their path becomes easier to walk. This balance between technical effort and spiritual grounding is what keeps a person steady in a world full of distractions.

In the end, the journey of learning is lifelong. Whether someone is building their first small program or working on a complex system with thousands of lines of code, the principle remains the same: show up, stay consistent, and keep your intention pure. When a person combines sincerity, discipline, and reliance on Allah (subhanahu wa ta'ala), the path forward opens in ways they never expected. Steady effort, done day after day, is what truly shapes a person — both in their career and in their character.)");

    MergeBinaryTrees();
    map<char, string> mp;
    mp = BTlist[0].GetCodeByTraversal();

    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

//1. use vectors