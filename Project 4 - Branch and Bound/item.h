// BY: Isabell Austin, Noah Baker, and Anna Vadella

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

struct Item {
	string name;
	double value;
	double weight;
	int level;
	float bound;
	set<Item> sackItems;

	Item();
	Item(double, double);	
	double ratio() const;
	void print() const;
	bool operator<(const Item &) const;
};

Item::Item(double value_, double weight_) {
    value = value_;
    weight = weight_;
}

Item::Item() {
	name = " ";
	value = 0;
	weight = 0;
	level = 0;
	bound = 0;
	sackItems = {};
}

double Item::ratio() const {
    return (value / weight);
}

void Item::print() const {
    cout << name << " " << value << " " << weight << " " << ratio() << endl;
}

bool Item::operator<(const Item & right) const {
	return bound < right.bound;
	// double r1 = ratio();
    // double r2 = right.ratio();
    // return r1 < r2; 
}