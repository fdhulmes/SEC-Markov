#include <iostream>
#include <vector>
using namespace std;

class markovLL{
    
    struct markovNode{
        string text;
        markovNode *next;
        markovNode *prev;
        
        markovNode(string text){
            next = NULL;
            prev = NULL;
            this.text = text;
        }
    };
    
    markovNode *head;
    public:
    
        markovLL(){
            head = NULL;
        }
    
        void addNode(string text){
            markovNode *newNode = new markovNode(text);
            // Initialize LL
            if(head == NULL){
                head = newNode;
            }
            // Add new node onto end
            else{
                markovNode *tmp = head;
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next = newNode;
                newNode->prev = tmp;
            }
            return;
        }
        
        vector<string> nextWords(vector<string> currentState, vector<markovNode*> instances){
            /* IMPORTANT: currentState array needs to be built backwards
                ex: I am human -> [human, am, I]
             Calculate the possible order based on the number of words put in */
            int order = currentState.size();
            //Return vector
            vector<string> v;
            // Find the first word in the current state
            string last = currentState[0];
            // Iterate through each instance of the word
            for(int i = 0; i < instances.size(); i++){
                int count = 0;
                bool flag = true;
                markovNode *currentInstance = instances[i];
                markovNode *tmp = currentInstance;
                //Check if the nodes prev values match the current state
                while(count < order){
                    if(tmp != NULL){
                        if(tmp->text.compare(currentState[count]) != 0){
                            flag = false;
                        }
                        tmp = tmp->prev;
                    }
                    else{
                        flag = false;
                    }
                    count++;
                }
                // If the next node exists and the currentstate matches, add the next word to possibilities
                if(flag && currentInstance->next != NULL){
                    v.push_back(currentInstance->next->text);
                }
            }
            if(v.size() > 0){
                return v;
            }
            else{
                // If matches aren't found, reduce the order
                currentState.pop_back();
                return nextWords(currentState, instances);
            }
        }
        
        string nextInChain(vector<string> currentState){
            //TODO: create the instances of the first word, find the vector of possibilities, return random word
        }
    
        
    private:
        vector<markovNode*> findWord(string text){
            // Creates a vector of all instances of a given word
            vector<markovNode*> v;
            markovNode *tmp = head;
            // Iterate through the LL, finding all nodes with the same text
            while(tmp != NULL){
                if(text.compare(tmp->text) == 0){
                    // Append the node to the vector
                    v.push_back(tmp);
                }
                tmp = tmp->next;
            }
            return v;
        }
    
    
};






