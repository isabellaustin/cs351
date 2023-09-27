// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include<iostream>
#include<fstream>
#include"pq.h"
#include"item.h"

using namespace std;

/* pq.h functions:
- class pq
    - constructor, empty(), enqueue, dequeue, print() [preorder traversal]
- class node
    - constructor
*/

int main(){

    ifstream file;
    file.open("test2.txt"); 

    int n, capacity = 0;
    file >> n >> capacity;

    //Priority Queue
    typedef pq<Item*> priorityQ;
    typedef pq<Item*> knapsackQ;
    priorityQ pq;

    string name;
    double value = 0; //pesos
    double weight = 0; //pounds

    for(int i = 0; i < n; i++){
        file >> name >> value >> weight;

        Item* queue_item = new Item(value, weight);
        queue_item->name = name;

        pq.enqueue(queue_item); //compare func is wrong

    }
    file.close();
    pq.print();

    //=============================================================

    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value
    //Knapsack; greedy algorithm
    // pq<Item*> knapsack;
    knapsackQ knapsack;

    //for loop for knapsack;
    for(int i = 0; i < n; i++){
        Item* retrieved_item = pq.dequeue();
        // retrieved_item->print();

        if (totalW + retrieved_item->weight < capacity){
            knapsack.enqueue(retrieved_item);
            totalV = totalV + retrieved_item->value;
            totalW = totalW + retrieved_item->weight;
            sackItems++;
            // retrieved_item->print();
        }
    }
    // cout << sackItems << endl;
    // cout << totalW << endl;
    // cout << totalV << endl;

    string filename  = "knapsackRun + to_string(sackItems) + ".txt"; 
    ofstream outfile;
    outfile.open(filename);

    outfile << n << "\n";
    outfile << totalW << "\n";
    outfile << totalV << "\n";
    outfile << "\n" << "Items in the Solution:" << "\n";
    // outfile << 

    for(int i = 0; i < sackItems; i++){
        Item* sack_item = knapsack.dequeue();
        outfile << sack_item->name << " " << sack_item->value << " " << sack_item->weight << "\n";
        // sack_item->print();
    }

    return 0;
}