#pragma once

#include <iostream>
#include <string>
#include "Address.h";

using namespace std;

void AddressItem::Tally() {
	count++;
}

string AddressItem::getAddress() const {
	return address;
}

int AddressItem::getCount() const {
	return count;
}

bool AddressItem::operator==(const AddressItem& addr2) const {
	return address == addr2.address;
}

istream& operator>>(istream& in, AddressItem& a) {
	in >> a.address;
	return in;
}

ostream& operator<<(ostream& out, const AddressItem& a) {
	out << "Address: " << a.address << "; Count: " << a.count;
	return out;
}
