#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// "struct" is just like "class" except that everything is public by default
// You need to define the four functions listed below to use this function.
// You will not be able to use a priority queue without defining the operator function.

struct Item {
	string name;
	double value;
	double weight;
    // double ratio; //do we add this?
	
	Item (double, double);	
	double ratio() const;
	void print() const;
	bool operator<(const Item &) const;
};

Item::Item(value, weight) {
    Item* value = value;
    Item* weight = weight;
    // i dont think this is right
 }


double Item::ratio() const {
    // ratio = (Item->value / Item->weight);
    return (Item->value / Item->weight);
}

void print() const {
    cout << Item->name << " " << Item->value << " " << Item->weight << endl; //idk what it's supposed to print
}

// Compares one item's ratio to another
// Item & right: memory location of pointer called right
bool Item::operator<(const Item & right) const {
    // https://www.geeksforgeeks.org/c-program-for-the-fractional-knapsack-problem/ 
    double r1 = (Item->value / Item->weight); //Item.ratio();
    double r2 = (right->value / right->weight);
    return r1 > r2;
}