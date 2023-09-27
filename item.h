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
	
	Item(double, double);	
	double ratio() const;
	void print() const;
	bool operator<(const Item &) const;
};

Item::Item(double value_, double weight_) {
    value = value_;
    weight = weight_;
 }


double Item::ratio() const {
    return (value / weight);
}

void Item::print() const {
    cout << name << " " << value << " " << weight << endl; //idk what it's supposed to print
}

// Compares one item's ratio to another
// Item & right: memory location of pointer called right
bool Item::operator<(const Item & right) const {
    // https://www.geeksforgeeks.org/c-program-for-the-fractional-knapsack-problem/ 
    // https://www.geeksforgeeks.org/difference-between-constant-pointer-pointers-to-constant-and-constant-pointers-to-constants/ 

    double r1 = (value / weight); //Item.ratio();
    double r2 = (right.value / right.weight);
    return r2 < r1;
}