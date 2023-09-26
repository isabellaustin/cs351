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
    file.open("test.txt");

    int n, capacity = 0;
    file >> n >> capacity;

    //Priority Queue
    pq pq;
    string name;
    double value; //pesos
    double weight; //pounds

    for(int i = 0; i < n; i++){
        file >> name >> value >> weight;

        Item* name = new Item(value, weight);
        cout << name.ratio() << endl; //to check..?
        pq.enqueue(name);
    }

    file.close();


    //Knapsack; greedy algorithm
    pq knapsack;
    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value





    cout << sackItems << endl;
    cout << totalWeight << endl;
    cout << totalValue << endl;
    for(int i = 0; i < numSacked; i++){
        item* sacked_item = new item();
        sacked_item = knapsack.dequeue();
        std::cout << sacked_item-> name << " " << sacked_item-> value << " " << sacked_item-> weight << std::endl;
    }

    return 0;
}