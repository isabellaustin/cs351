// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include "item.h"

int max(int a, int b) {
    if(a >= b) {
        return a;
    }
    return b;
}

int refine(int n, int W, item * items, int ** matrix)
{
    // base case
    if (n == 0 || W == 0) {
        return 0;
    }

    if(W < items[n-1].weight) {
        matrix[n][W] = refine(n-1, W, items, matrix);
        return matrix[n][W];
    }
    else {
        matrix[n][W] =  max(refine(n-1, W, items, matrix), 
            (refine(n-1, W - items[n-1].weight, items, matrix) + items[n-1].value));
        return matrix[n][W];
        
    }
}

int main()
{
    // item variables
    int numItems = 0;
    int capacity = 0;

    double weight = 0;
    double value = 0;
    double ratio = 0;

    string nameOfItem = " ";

    // knapsack variables
    int sackItems = 0; 
    int totalV = 0;
    int totalW = 0;
    int skipItem = 0;

    ifstream file;
    string filename = " ";
    
    cout << "Enter filename: ";
    cin >> filename;

    file.open(filename); 
    file >> numItems>> capacity;

    item * items = new item[numItems];
    item * knapsack = new item[numItems];
    for(int i = 0; i < numItems; i++)
    {
        file >> nameOfItem >> value >> weight;
        item itemObj = item(value, weight); 
        itemObj.name = nameOfItem;
        ratio = itemObj.ratio();
        items[i] = itemObj;
    }
    
    int ** matrix = new int * [numItems+1];
    
    // Dynamic Approach for the 0-1 knapsack
    for(int i = 0; i <= numItems; i++)
    {
        // creates 2D array
        matrix[i] = new int[capacity+1]; // each i-th pointer is now pointing to dynamic array (size capacity)

        for(int j=0; j <= capacity;j++)
        {
            if (i == 0 || j == 0)
            {
                continue;
            }
            else if (items[i-1].weight <= j)
            {
                // Formula from 192 in the book!
                matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j - ((int)items[i-1].weight)] + items[i-1].value);
            }
            else
            { 
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    for(int i = numItems; i > 0; i--)
    {
        if(matrix[i][capacity - skipItem] == matrix[i-1][capacity - skipItem])
        {
            continue;
        }
        knapsack[sackItems] = items[i-1];
        totalV += knapsack[sackItems].value;
        totalW += knapsack[sackItems].weight;
        skipItem += knapsack[sackItems++].weight;
    }    

    // print results
    cout << "\n";
    cout << "Dynamic Programming Approach for 0-1 Knapsack:" << "\n";
    cout << "Total number of items in knapsack: " << sackItems << endl;
    cout << "Knapsack capacity: " << capacity <<" lbs" << endl;
    cout << "Total weight: " << totalW << " lbs" << endl;
    cout << "Total profit: " << totalV << " pesos" << endl;
    cout << "\n";
    cout << "Items in the knapsack: " << endl;

    for(int i = 0; i < sackItems; i++)
    {
        knapsack[i].print();
    }

    // reset matrix values
    for(int i = 0; i < numItems+1; i++)
    {
        for(int j=0; j<capacity+1; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Refinement of Dynamic Programming Approach
    refine(numItems, capacity, items, matrix); 

    sackItems = 0;
    totalV = 0;
    totalW = 0;
    skipItem = 0;

    item * knapRefined = new item[numItems];

    // select optimal solutions
    for (int i=numItems; i > 0; i--)
    {
        if(matrix[i][capacity - skipItem] == matrix[i-1][capacity - skipItem])
        {
            continue; 
        }
        knapRefined[sackItems] = items[i-1];
        totalV += knapRefined[sackItems].value;
        totalW += knapRefined[sackItems].weight;
        skipItem += knapRefined[sackItems++].weight;
    } 

    // print results
    cout << "\n";
    cout << "Refinement of Dynamic Programming Approach for 0-1 Knapsack:" << "\n";
    cout << "Total number of items in knapsack: " << sackItems << endl;
    cout << "Knapsack capacity: " << capacity << " lbs" << endl;
    cout << "Total weight: " << totalW<< " lbs" << endl;
    cout << "Total profit: " << totalV << " pesos" << endl;
    cout << "\n";
    cout << "Items in the knapsack: "<<endl;

    for(int i = 0; i < sackItems; i++)
    {
        knapRefined[i].print();
    }

    return 0;
}