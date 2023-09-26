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

    return 0;
}