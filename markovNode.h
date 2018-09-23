#include <string>
using namespace std;

class markovNode{
    public:
        string text;
        markovNode *next;
        markovNode *prev;
            
        markovNode(string text);
};