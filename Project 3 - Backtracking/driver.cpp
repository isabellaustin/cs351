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

// Pseudocode found on page 261 in the online book
bool promising(int i, int profitTracker, int weightTracker)
{
    int j(0); 
    int k(0);
    int totW(0);
    float bound(0);

    // Node is promising only if we should expand to its children. There must be some capacity left for children. 
    if (weightTracker >= capacity)
    {
        return false;
    }
    else
    {
        j = i+1;
        bound = profitTracker;
        totW = weightTracker;

        while ((j <= numItems) && (totW + items[j].weight <= capacity)) 
        {
            totW += items[j].weight;
            bound += items[j].value;
            j++;
        }
        k = j;

        if (k <= numItems)
        {
            bound = bound + (capacity - totW)*(items[k].ratio());
        }
        return bound > maxProfit; 
   }
 }

// Pseudocode found on page 261 in the online book
void knapsack(int i, int profitTracker, int weightTracker)
{
    if (weightTracker <= capacity && profitTracker > maxProfit)
    {
        maxProfit = profitTracker;
        for (int x=0; x <= numItems; x++)
        {
            best[x] = include[x];
        }
    }

    if (promising(i, profitTracker, weightTracker))
    {
        include[i] = true;
        knapsack(i+1, profitTracker + items[i+1].value, weightTracker + items[i+1].weight);
        include[i] = false;
        knapsack (i+1, profitTracker, weightTracker);
     }
}

int main()
{
    // item data
    double weight(0);
    double value(0);
    double ratio(0);
    string itemName(" ");

    // file io and user input data
    ifstream file;
    string filename = " ";
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 

    file >> numItems >> capacity;

    // Array initialization
    items = new Item [numItems+1];
    include = new bool [numItems];
    best = new bool [numItems];

    // priority queue to store item objects 
    pq<Item> pq;

    // create item objects and read in their values from a file
    for(int i1=0; i1< numItems; i1++)
    {
        fileToReadIn >> itemName >> value >> weight; 
        Item itemObj = item(value, weight);
        itemObj.name = itemName;
        pq.enqueue(itemObj);
    }

    fileToReadIn.close();

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

    // print numItems and capcaity
    cout<< "\nNumber of items considered: "<<numItems<<endl;
    cout<<"Knapsack capactiy: "<< capacity<<endl;

    // print optimal items from best
    cout <<"\nOptimal Knapsack Items: "<<endl;
    
    for(int i3 = 0; i3 < numItems; i3++)
    {
        if(best[i3]==true)
        {
            items[i3+1].print();
            totalW += items[i3+1].weight;
            totalV += items[i3+1].value;
            numSackItems++;
        }
    }

    // print knapsack data
    cout<< "\nNumber of knapsack items: " << numSackItems << endl;
    cout<< "Total weight: " << totalW<< " lbs" << endl;
    cout<< "Total profit: " << totalV<< " pesos" << endl;

    return 0;
}