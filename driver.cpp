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
    typedef pq<Item*> priorityQ;
    typedef pq<Item*> knapsackQ;

    ifstream file;
    file.open("test2.txt"); 

    int n, capacity = 0;
    file >> n >> capacity;

    // Priority Queue
    priorityQ pq;

    string name;
    double value = 0; //pesos
    double weight = 0; //pounds

    for(int i = 0; i < n; i++){
        file >> name >> value >> weight;
        double ratio = value/weight;
        Item* queue_item = new Item(value, weight);
        queue_item->name = name;
        // queue_item->print();
        cout << queue_item->ratio() << endl;

        pq.enqueue(queue_item); //compare happens in enqueue; compare func is wrong (?)

    }
    file.close();
    pq.print();

    //=============================================================

    // Knapsack; Greedy Algorithm
    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value

    knapsackQ knapsack;

    //for loop for knapsack;
    for(int i = 0; i < n; i++){
        Item* chosen_item = pq.dequeue();
        // chosen_item->print();

        if(totalW + chosen_item->weight <= capacity){
            knapsack.enqueue(chosen_item);
            totalV = totalV + chosen_item->value;
            totalW = totalW + chosen_item->weight;
            sackItems++;
            // chosen_item->print();
        }
    }

    string filename  = "knapsackRunOG.txt"; // + to_string(sackItems) + ".txt"; 
    ofstream outfile;
    outfile.open(filename);

    outfile << n << "\n";
    outfile << totalW << "\n";
    outfile << totalV << "\n\n";
    outfile << "Items in the Solution:" << "\n";

    for(int i = 0; i < sackItems; i++){
        Item* sack_item = knapsack.dequeue();
        outfile << sack_item->name << " " << sack_item->value << " " << sack_item->weight << "\n";
        // sack_item->print();
    }

    return 0;
}