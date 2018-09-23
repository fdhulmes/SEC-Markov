// Main file for building a Markov Chain text generator
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "markovLL.h"
using namespace std;

// Global Variables
markovLL list;
markovLL chain;
int rand();

// Function declarations
void readFile(char *filename);


void createMarkov();


void printMarkov();


int main(int argc, char* argv[]){
    // Create the linked list
    srand(time(NULL));
    readFile(argv[1]);
    createMarkov();
    printMarkov();
}

void readFile(char *filename){
    // Read in the text file, create a linked list of words
    fstream file;
    string word;
    file.open(filename);
    if(!file){
        cout<<"Cannot open"<<endl;
        exit(1);
    }
    while(file >> word){
        // Create a node using each word
        list.addNode(word);
    }
    file.close();
    return;
}

void createMarkov(){
    // Uses the linked list, create the chain
    int c = 0;
    int ind = 0;
    string newWord = "";
    // Random number of characters in the chain
    int max = (rand() % 250) + 20;
    int s = rand() % list.size();
    // Grabs a random word from the list
    list.buildMap();
    string currentState = list.findWord(s);
    chain.addNode(currentState);
    while(c < max){
        newWord = list.getText(currentState);
        if(newWord.compare("") == 0){
            // If the double word doesn't work, get the last word by itself
            newWord = chain.getText(chain.findWord(ind));
        }
        chain.addNode(newWord);
        c += newWord.length();
        currentState = chain.findWord(ind) + " " + newWord;
        ind++;
    }
    return;
}

void printMarkov(){
    // Print the message
    chain.printList();
    cout<<endl;
    return;
}

