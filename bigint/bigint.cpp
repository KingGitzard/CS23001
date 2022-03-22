#include "bigint.hpp"

void bigint::zero(){
for (int i =0; i < capacity; ++i)
numArray[i] = 0;
}

bool bigint::operator==(const bigint& rhs){
	bool equal = true;
	for(int i=0; i < capacity; ++i){
		if(numArray[i] == rhs.numArray[i])
			equal = true;
		else
			return false;
	}
	return equal;
}

bigint bigint::operator+(bigint rhs) const{
	int num = 0;
	int temp = 0;
	for (int i = 0; i < capacity; ++i){
		num = numArray[i] + rhs.numArray[i] + num;
		temp = num % 10;
		num = num / 10;
		rhs.numArray[i] = temp;
	}
	return rhs;
}

bigint bigint::timesDigit(int x) const {
	bigint product = *(this);
	if (x == 0)
		return (product = 0);
	if(x == 1)
		return product;
	if (x <= 9){
		int remainder = 0;
		int result = 0;
		for (int i = 0; i < capacity; ++i){
			remainder = numArray[i] * x + remainder;
			result = remainder % 10;
			remainder /=10;
			product. numArray[i] = result;
		}
	}
	return product;
}

bigint bigint::times10(int x) const{
	bigint temp;
	if (x == 0){
		temp = *(this);
		return temp;
	}
	if (x > 0)
		for (int i = capacity - x - 1; i >= 0; --i)
			temp.numArray[i + x] = numArray[i];
	return temp;
}

int bigint::operator[](int i) const{
	return numArray[i];
}

bigint bigint::operator*(bigint rhs){ 
    bigint product;
    for(int i = 0; i < capacity; ++i)
        product = product + (timesDigit(rhs.numArray[i])).times10(i);

    return product; 
}

void bigint::debugPrint(std::ostream& out) const{
	for(int i = 0; i < (capacity-1); --i)
		out <<"|" << numArray[i] << "|";
	out << std::endl;
}

bigint::bigint(){
	zero();
}

bigint::bigint(int num){
	for(int i = 0; i < capacity; ++i){
		numArray[i] = num % 10;
		num = num /10;
	}
}

bigint::bigint(const char myChar[]){
	zero();
	int arrayLength = 0;
	int k = 0;
	while(myChar[arrayLength] != '\0')
		++arrayLength;
	for (int j = arrayLength - 1; j >= 0; j--, k++)
		numArray[k] = int(myChar[j]) - int('0');
}

std::istream& operator>>(std::istream& in, bigint& rhs){
	char ch;
	char charArray[capacity];
	for (int j = 0; j < capacity; ++j){
		charArray[j] = 0;
	}

	in >> ch;
	for(int i = 0; i < capacity && ch != ';'; ++i){
		charArray[i]= ch;
		in >> ch;
	}
	rhs = charArray;
	return in;
}

std::ostream& operator <<(std::ostream& out, bigint rhs){
	int lineControl = capacity;
	while(lineControl > 0 && rhs.numArray[lineControl] == 0)
		--lineControl;
	while(lineControl >= 0){
		if (lineControl % 80)
			out <<rhs.numArray[lineControl];
		else
			out << rhs.numArray[lineControl] << std::endl;
	--lineControl;
	}
	return out;
}
