// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, sackCap = 0, itemN, itemV, itemW;  
    // n: # of items, sackCap: sack capacity, itemN: name, itemV: value, itemW: weight

    srand(time(NULL)); 

    ifstream file;
    file.open("test.txt");

    // while(n <= 0 || sackCap <= 0){
    //     cout << "Number of Items: ";
    //     cin >> n; //10, 20, 100, 1000, 10000
    //     cout << "Knapsack Capacity: ";
    //     cin >> sackCap;
    // }
    
    file << n << " " << sackCap << "\n";

    cout << "Items in the Solution: ";
    for(int i = 0; i < n; i++)
    {   
        itemN = i++; //incrementing item number
        itemV = rand()%(176) + 25; //randomized item values between 25 and 200
        itemW = rand()%(3*n) + 1; //randomized item weights between 1 and 3 * n
        file << itemN << " " << itemV << " " << itemW << endl; 
    }

    file.close();

    return 0;
}