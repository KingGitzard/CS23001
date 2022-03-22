#include "string.hpp"

String::String(){
	stringSize = 1;
	str = new char[stringSize];
	str[0] = 0;
}

String::String(char ch){
	stringSize = 2;
	str = new char[stringSize];
	str[0] = ch;
	str[1] = 0;
}

String::String(const char chArray[]){
	int i = 0;
	while(chArray[i] != 0)
		++i;
	stringSize = i +1;
	str = new char[stringSize];
	i = 0;
	while(chArray[i] != 0){
		str[i] = chArray[i];
		++i;
		if (i >= stringSize)
			break;
	}
	str[stringSize - 1] = 0;
}

String::String(const String& rhs){
	stringSize = rhs.stringSize;
    		str = new char[stringSize];
    		for(int i = 0; i < stringSize - 1; ++i) { 
       			 str[i] = rhs.str[i];
    		}
}

int String::length() const {
    int len = 0;
    while(str[len] != 0)
        ++len;
    return len;
}




int String::capacity() const{
    return stringSize - 1;
}



String String::operator+(const String& rhs)const{
    String result(this->length()+rhs.length()+1);
    for (int j=0; j<length(); ++j){
        result.str[j]=str[j];
    }
    int len=length();
    int i=0;
    while((rhs.str[i]!=0) && (i + len < rhs.length()+length())){
        result.str[len+i]=rhs.str[i];
        ++i;
    }
    result.str[len +i]=0;
    return result;
}



String operator+(char lhs, const String &rhs){ return String(lhs) + rhs;};

String operator+(const char lhs[], const String& rhs){ return String(lhs) + rhs;};

String& String::operator+=(const String& rhs){
    int offset = length();
    int i = 0;
    
    while(rhs.str[i] != 0){
        if(offset + i == stringSize)
            break;
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *(this);
}

char String::operator[](int i) const {
    if(i < 0)
        i = 0;
    return str[i];
}

char& String::operator[](int i) {
    return str[i];
}

bool String::operator<(const String& rhs) const{
    int i = 0;
    while(str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i])
        ++i;
    return str[i] < rhs.str[i];
}

bool operator==(char lhs, const String& rhs){ return String(lhs) == rhs;};
bool operator==(const char lhs[], const String& rhs){return String(lhs) == rhs;};

bool String::operator==(const String& rhs) const {
    if (length() == rhs.length()) {
        for (int i=0; str[i] != '\0' && rhs[i] != '\0'; ++i) {
            if (str[i] != rhs[i])
                return false;
        }
        return true;
    }
    return false;
}



std::ostream& operator<<(std::ostream& out, const String& rhs) {
    int i = 0; 
    while(rhs[i] != 0){
        out << rhs.str[i];
        ++i;
    }
    return out;
}


std::istream& getline(std::istream &in, String &rhs) {
    char ch;
    int i = 0;
    in.get(ch);
    while((ch != '\n') && (!in.eof())) {
        if(in.eof())
            break;
              rhs[i] = ch;
        ++i;
        in.get(ch);
    }
    return in;
}



// this is where buff was

String String::substr(int left, int right) const{
    if(right < 0)
        right = length();
    if(left < 0)
        left = 0;
    if(left == right){
        return String(str[left]);
    }
    if (left == 0) {
        String result(right + 1);
        for(int i = 0; i <= right; ++i)
            result.str[i] = str[i];
        return result;
    }
    if(right == 0) {
        String result = str[left];
        return String("");
    }
    int size = (right - left) + 1;
    if(right == length())
        size = (right - left);
    if((right - left) == 1){
        String temp(size + 1);
        temp[0] = str[left];
        temp[1] = str[right];
        temp[2] = 0;
        return temp;
    }
    else if(right - left == 3) {
        String temp(size + 1);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i];
        }
        return temp;
    }
    
    else if(right - left == 4) {
        String temp(size + 1);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i];
        }
        
               return temp;
    }
    else {
        String temp(size);
        for(int i = left; i <= right; ++i){
            temp.str[i - left] = str[i]; 
        }
        return temp;
    }
}



int String::findch(int start, const char ch) const {
    int i = start;
    while ((i <= length()) && (ch != str[i]))
         ++i;
    if(i > length())
        return -1;
    else
        return i;
}

bool operator>(const String& lhs, const String& rhs) {

    if(!(lhs < rhs) && !(lhs == rhs))
        return true;
    else
        return false;
}

bool operator<=(const String& lhs, const String& rhs) {
    if(((lhs < rhs) || (lhs == rhs)) && !(lhs > rhs))
        return true;
    else
        return false;
}

bool operator>=(const String& lhs, const String& rhs) {
    if(((lhs > rhs) || (lhs == rhs)) && !(lhs < rhs))
        return true;
    else
        return false;
}


bool operator!=(const String& lhs, const String& rhs) {
    if((lhs > rhs) || (lhs < rhs))
        return true;
    else
        return false;
}


bool operator<(const char lhs[], const String& rhs){
    if(String(lhs) < rhs)
         return true;
    else
        return false;
}

bool operator<(char ch, const String& rhs){
    if(String(ch) < rhs)
        return true;
    else
        return false;
}


int String::findstr(int pos, const String& rhs) const {
    int foundAt = -1;
    if(pos == 0 && str[0] == rhs[0]){
        foundAt = 0;
        for(int j = 0; j < rhs.length(); ++j){
            if(str[foundAt + j] != rhs[j])
                foundAt = -1;
            else
                 foundAt = 0;
        }
        return foundAt;

    }

    for(int i = pos; i <= length(); ++i){
        if(str[i] == rhs[0]){
            foundAt = i;
        }
        for(int j = 0; j < rhs.length(); ++j){
            if(str[foundAt + j] != rhs[j])
                foundAt = -1;
        }
        
    }
    return foundAt;
}



