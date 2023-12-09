// BY: Isabell Austin, Noah Baker, and Anna Vadella
#include<iostream>
#include<fstream>
#include "item.h"
#include "pq.h"

using namespace std;

// global variables as instructed by the book (pg 262)
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
    for(int x = 0; x < numItems; x++)
    {   best[x] = include[x]; }

    j = u.level + 1;
    totW = u.weight;

    while ((j < numItems) && (totW + items[j].weight <= capacity))
    {
        totW += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    if (j < numItems)
    {   profitBound += (capacity -totW) * items[j].ratio(); }
    return profitBound;
}

// Best-First Search with B&B from the book
int knapsack(int numItems, const Item * items, int capacity)
{
    pq<Item> pq;
    Item u,v;

    // initalize include array
    for(int x = 0; x < numItems; x++)
    {   include[x] = false; }

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
        {   pq.enqueue(v); }

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


    // print optimal items from bestSet
    cout <<"\nOptimal Knapsack Items: "<<endl;
    for(int i=0; i<numItems;i++)
    {
        if(best[i] == true)
        {
            numSacked++;
            // items[i].print();
            cout << items[i].name << " " << items[i].value << " " << items[i].weight << endl;
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

        // print knapsack data
    cout<< "\nNumber of knapsack items: " << numSacked << endl;
    cout<< "Total weight: " << totalWeight<< " lbs" << endl;
    cout<< "Total profit: " << totalValue<< " pesos" << endl;

    return maxProfit;
}

int main()
{
    // item data
    double weight(0);
    double value(0);
    double ratio(0);
    string itemName(" ");

    int numItems(0);
    int profitTracker(0);
    int weightTracker(0);
    int capacity(0);

    ifstream file;
    string filename = " ";
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 

    file >> numItems >> capacity;

    items = new Item [numItems+1];
    include = new bool [numItems];
    best = new bool [numItems];

    // create item objects and read in their values from a file
    for(int i1=0; i1< numItems; i1++)
    {
        file >> itemName >> value >> weight; 
        Item itemObj = Item(value, weight);
        itemObj.name = itemName;
        items[i1] = itemObj;
    }

    // sorting the items based on ratio
    for (int i=0; i<numItems-1; i++)
    {
        for(int j=0; j< numItems-i-1; j++)
        {
            if (items[j].ratio() < items[j+1].ratio())
            {
                Item tempItem = items[j];
                items[j] = items[j+1];
                items[j+1] = tempItem; 
            }
        }
    }

    file.close();


/**
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
*/
    
    // for(int i = 0; i < numItems; i++)
    // {
    //     // outfile << items[i].name << " " << items[i].value << " " << items[i].weight << "\n";
    //     cout << items[i].name << " " << items[i].value << " " << items[i].weight << endl;
    // } 

    
    int maximumProfit(0);
    maximumProfit = knapsack(numItems,items,capacity);

    cout<< "Maxiumum profit of optimal solution = " << maximumProfit <<endl;

    return 0;
}