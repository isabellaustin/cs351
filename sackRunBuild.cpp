// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, sackCap = 0, itemV, itemW;  
    char itemN;
    // n: # of items, sackCap: sack capacity, itemN: name, itemV: value, itemW: weight

    srand(time(NULL)); 

    ofstream file;
    file.open("knapsackRun20.txt");

    cout << "Number of Items: ";
    cin >> n; //10, 20, 100, 1000, 10000
    cout << "Knapsack Capacity: ";
    cin >> sackCap;

    string filename  = "knapsackRun" + n+ ".txt"
    ofstream file;
    file.open(filename);
    
    file << n << " " << sackCap << "\n";
    file << "Items in the Solution:" << "\n"; //idk if we actually need this, but it was in the handout; ask Gup

    int totalW = 0; //total weight
    int sackItems = 0; //final num of items in the knapsack
    int totalV = 0; //total value

    for(int i = 0; i < n; i++)
    {   char letter[] = "abcdefghijklmnopqrstuvwxyz";
        itemN = letter[i]; //incrementing item number
        itemV = rand()%(176) + 25; //randomized item values between 25 and 200
        totalV = totalV+itemV;
        itemW = rand()%(3*n) + 1; //randomized item weights between 1 and 3 * n
        totalW = totalW+itemW;
        file << itemN << " " << itemV << " " << itemW << endl; 
    }

    file.close();

    return 0;
}