//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
#include "Address.h"
#include <fstream>

using namespace std;
int findPosition(LinkedList<AddressItem>& list, AddressItem adr);

int main()
{
	LinkedList<AddressItem> list;
	AddressItem address;
	AddressItem tempAdr;
	int foundPosition;
	int position = 0;

	ifstream infile;
	infile.open("addresses.txt");

	if (!infile) {
		cout << "Not in file" << endl;
	}


	while (!infile.eof()) {
		AddressItem address;
		infile >> address;

		//find position
		foundPosition = findPosition(list, address);

		if (foundPosition != 0) {
			tempAdr = list.getEntry(foundPosition);
			cout << "Address before: " << tempAdr << endl;
			tempAdr.Tally();
			cout << "Address after: " << tempAdr << endl;
			list.replace(foundPosition, tempAdr);
		}
		else {
			address.Tally();
			position++;
			list.insert(position, address);
		}	
		
	}
	for (int i = 1; i <= list.getLength(); i++) {
		cout << list.getEntry(i) << endl;
	}
	//cout << list.getLength() << endl;

   return 0;
}  // end main

int findPosition(LinkedList<AddressItem>& list, AddressItem adr) {
	for (int i = 1; i <= list.getLength(); i++) {
		if (list.getEntry(i) == adr) {
			return i;
		}
	}
	return 0;
}