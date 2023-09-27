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
    pq<Item*> priorityQ;

    string name;
    double value = 0; //pesos
    double weight = 0; //pounds

    for(int i = 0; i < n; i++){
        file >> name >> value >> weight;

        Item* queue_item = new Item(value, weight);
        queue_item->name = name;

        priorityQ.enqueue(queue_item);
        // queue_item->print();

        //have to sort the items by ratio somewhere
        // queue_item->operator<(queue_item); //idfk how this work x(
            // node<Item*> * right = new node<Item*>(queue_item); //maybe using this, but i dont think so
    }


    file.close();

    //=============================================================

    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value
    //Knapsack; greedy algorithm
    pq<Item*> knapsack;

    //for loop for knapsack;
    for(int i = 0; i < n; i++){
        Item* retrieved_item = priorityQ.dequeue();
        // retrieved_item->print();

        if (totalW + retrieved_item->weight < capacity){
            knapsack.enqueue(retrieved_item);
            totalV = totalV + retrieved_item->value;
            totalW = totalW + retrieved_item->weight;
            sackItems++;
            // retrieved_item->print();
        }
    }

    cout << sackItems << endl;
    cout << totalW << endl;
    cout << totalV << endl;

    for(int i = 0; i < sackItems; i++){
        Item* sack_item = knapsack.dequeue();
        sack_item->print();
    }

    return 0;
}