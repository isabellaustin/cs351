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
    return (Item->value / Item->weight);
}

void print() const {
    cout << Item->name << " " << Item->value << " " << Item->weight << endl; //idk what it's supposed to print

}

// Compares one item's ratio to another
bool Item::operator<(const Item & right) const {
    // Fill this in here!
}