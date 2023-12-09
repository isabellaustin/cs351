// BY: Isabell Austin, Noah Baker, and Anna Vadella
#include<iostream>
#include<fstream>
#include "item.h"
#include "pq.h"

using namespace std;

// global variables as instructed by the book (pg 262)
int maxProfit(0); 
int numItems(0);
int profitTracker(0);
int weightTracker(0);
int capacity(0);

Item * items(nullptr);
bool * best(nullptr); 
bool * include(nullptr); 

float bound(Item u, int numItems, int capacity, const Item * items)
{
    int j(0);
    int k(0);
    int totW(0);
    float result(0);
    
    if (u.weight >= capacity)
    {
        return 0;
    }

    int profitBound = u.value;
    for(int x=0; x<numItems; x++)
    {
        best[x] = include[x];
    }

    j = u.level + 1;

    totW = u.weight;

    while ((j < numItems) && (totW + items[j].weight <= capacity))
    {
        totW += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    if (j < numItems)
    {
        profitBound += (capacity -totW) * items[j].ratio();
    }
    return profitBound;
}

// Best-First Search with B&B from the book
int knapsack(int numItems, const Item * items, int capacity)
{
    pq<Item> pq;
    Item u,v;

    // initalize include array
    for(int x=0; x<numItems; x++)
    {
        include[x] = false;
    }

    u.level = -1;
    u.value = 0;
    u.weight = 0;

    int maxProfit(0);
    pq.enqueue(u);

    while (!pq.empty())
    {
        u = pq.dequeue();

        if (u.level == -1)
        {   v.level = 0; }
        if (u.level == numItems - 1)
        {   continue; }
        
        v.level = u.level + 1;

        v.weight = u.weight + items[v.level].weight;
        v.value = u.value + items[v.level].value;

        if (v.weight <= capacity && v.value > maxProfit)
        {   maxProfit = v.value; }

        v.bound = bound(v, numItems, capacity, items);

        if (v.bound > maxProfit)
        {   q.enqueue(v); }

        v.weight = u.weight;
        v.value = u.value;
        v.bound = bound(v, numItems, capacity, items);

        if (v.bound > maxProfit)
        {   pq.enqueue(v); }
    }


    // printing solution: 
    int numSacked(0);
    int totalW(0);
    int totalV(0);

    return maxProfit;
}

int main()
{
    // item data
    double weight(0);
    double value(0);
    double ratio(0);
    string itemName(" ");

    ifstream file;
    string filename = " ";
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 

    file >> numItems >> capacity;

    items = new Item [numItems+1];
    include = new bool [numItems];
    best = new bool [numItems];

    // priority queue to store item objects 
    pq<Item> pq;

    // create item objects and read in their values from a file
    for(int i1=0; i1< numItems; i1++)
    {
        file >> itemName >> value >> weight; 
        Item itemObj = Item(value, weight);
        itemObj.name = itemName;
        pq.enqueue(itemObj);
    }

    file.close();

    // sort items in PQ in nonincreasing order based on ratio
    for(int i2=1; i2<= numItems; i2++)
    {
        items[i2] = pq.dequeue();
    }

    // Backtracking
    knapsack(0,0,0);

    // knapsack data
    int numSackItems(0);
    int totalW(0);
    int totalV(0);

    string outfilename  = "knapsackRun" + to_string(numItems) + ".txt"; 
    ofstream outfile;
    outfile.open(outfilename);

    outfile <<"Optimal Knapsack Items: "<< "\n";
    
    for(int i3 = 0; i3 < numItems; i3++)
    {
        if(best[i3]==true)
        {
            outfile << items[i3+1].name << " " << items[i3+1].value << " " << items[i3+1].weight << "\n";
            totalW += items[i3+1].weight;
            totalV += items[i3+1].value;
            numSackItems++;
        }
    }

    // print knapsack data
    outfile << "\nNumber of knapsack items: " << numSackItems << "\n";
    outfile << "Total weight: " << totalW << " lbs" << "\n";
    outfile << "Total profit: " << totalV << " pesos" << "\n";

    return 0;
}