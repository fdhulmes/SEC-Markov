#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include "markovLL.h"
using namespace std;

int rand();
    
        
        markovLL::markovLL(){
            head = NULL;
        }
    
        void markovLL::addNode(string text){
            // Adds a new node onto the linked list
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
        
        void markovLL::buildMap(){
            // Builds the map using the linked list
            markovNode *tmp = head;
            // Iterate through the list
            while(tmp != NULL){
                // If there is a next word...
                if(tmp->next !=NULL){
                    // Add the next word onto the map
                    table[tmp->text].push_back(tmp->next->text);
                    // If there is a prev word ...
                    if(tmp->prev != NULL){
                        // Add both words together as an entry as well
                        string twoWords = tmp->prev->text + " " + tmp->text;
                        table[twoWords].push_back(tmp->next->text);
                    }
                }
                tmp = tmp->next;
            }
            return;
        }
        
        void markovLL::printList(){
            // Prints the LL like a tweet
            markovNode *tmp = head;
            int cnt = 0;
            while(tmp != NULL){
                cout << tmp->text + " ";
                // Go to next line every ~80 characters
                cnt += tmp->text.length() + 1;
                if(cnt > 80){
                    cout << endl;
                    cnt = 0;
                }
                tmp = tmp->next;
            }
        }
        
        int markovLL::size(){
            // Returns the size of the LL
            int c = 0;
            markovNode *tmp = head;
            while(tmp != NULL){
                c += 1;
                tmp = tmp->next;
            }
            return c;
        }
        
        string markovLL::findWord(int index){
            // Returns a single word at the given index
            int i = 0;
            markovNode *tmp = head;
            while(i < index && tmp != NULL){
                i += 1;
                tmp = tmp->next;
            }
            return tmp->text;
        }
        
        string markovLL::getText(string in){
            // Returns a random string from the training data
            if(table.find(in) == table.end()){
                // in doesn't exist, return empty
                return "";
            }
            else{
                int s = rand() % table[in].size();
                return table[in][s];
            }
            
        }






