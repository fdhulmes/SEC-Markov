#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include "markovNode.h"
using namespace std;

class markovLL{
    
    markovNode *head;
    
    public:
        map <string, vector<string> > table;
        
        markovLL();
    
        void addNode(string text);
        
        void buildMap();
        
        void printList();
        
        int size();
        
        string findWord(int index);
        
        string getText(string in);
};






