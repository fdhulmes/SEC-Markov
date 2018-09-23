#include <string>
#include "markovNode.h"
using namespace std;

markovNode::markovNode(string text){
        next = NULL;
        prev = NULL;
        this->text = text;
}