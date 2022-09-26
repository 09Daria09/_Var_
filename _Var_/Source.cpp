#include<iostream>
using namespace std;
class MyString
{
private:
	char* str;
	int length;
	static int count;

public:
	MyString();
	MyString(int length);
	MyString(const char* str);
	MyString(const MyString& obj);
	~MyString();

	MyString& operator=(const MyString& obj);
	MyString& operator=(const char* str);
	void operator()() const;
	char operator[](int index) const;
	operator int() const;
	operator const char* () const;

	void Enter();

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c) const;
	int MyStrLen() const;
	void MyStrCat(const MyString& b);
	void MyStrCat(const char* b);
	void MyDelChr(char c);
	int MyStrCmp(const MyString& b) const;
	const char* MyC_Str() const;
	static int GetCount();

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};
int MyString::count = 0;
MyString::MyString()
{
	count++;
	str = new char[80];
	str[0] = '\0';
	length = 0;
}
MyString::MyString(int length)
{
	count++;
	this->length = length;
	str = new char[length + 1];
	str[0] = '\0';
}
MyString::MyString(const char* str)
{
	count++;
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->str[i] = str[i];
	this->str[length] = '\0';
}
MyString::MyString(const MyString& obj)
{
	count++;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';
}
MyString::~MyString()
{
	count--;
	delete[] str;
}
MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
		return *this;

	delete[]str;

	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';

	return *this;
}
MyString& MyString::operator=(const char* str)
{
	this->length = strlen(str);
	delete[]this->str;
	this->str = new char[length + 1];
	for (int i = 0; i < length + 1; i++)
		this->str[i] = str[i];
	this->str[length] = '\0';
	return *this;
}
void MyString::operator()() const
{
	std::cout << str;
}
char MyString::operator[](int index) const
{
	if (index >= 0 && index < length)
		return str[index];
	else
		return '\0';
}
MyString::operator int() const
{
	return length;
}
MyString::operator const char* () const
{
	return str;
}
void MyString::Enter()
{
	const char BUFSIZE = 256;
	char buffer[256];
	delete[] str;
	std::cin.getline(buffer, 256);
	length = strlen(buffer);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = buffer[i];
	str[length] = '\0';
}
void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';
}
bool MyString::MyStrStr(const char* str)
{
	bool result = false;
	if (strlen(str) > length)
		return result;
	for (int i = 0; i < length; i++)
	{
		result = true;
		for (int j = 0; j < strlen(str); j++)
		{
			if (this->str[j + i] != str[j])
			{
				result = false;
				break;
			}
		}
		if (result)
			break;
	}
	return result;
}
int MyString::MyChr(char c) const
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}
int MyString::MyStrLen() const
{
	return length;
}
void MyString::MyStrCat(const MyString& b)
{
	char* temp = new char[length + b.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		temp[i + length] = b.str[i];
	}
	length += b.length;
	temp[length] = '\0';
	delete[] str;
	str = temp;
}
void MyString::MyStrCat(const char* b)
{
	char* temp = new char[length + strlen(b) + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < strlen(b); i++)
	{
		temp[i + length] = b[i];
	}
	length += strlen(b);
	temp[length] = '\0';
	delete[] str;
	str = temp;
}
void MyString::MyDelChr(char c)
{
	bool check = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			check = true;
			for (int j = i; j < length - 1; j++)
				str[j] = str[j + 1];
			str[length] = '\0';
			i--;
			length--;
		}
	}
	if (check)
	{
		char* temp = new char[length + 1];
		for (int i = 0; i < length; i++)
			temp[i] = str[i];
		temp[length] = '\0';
		delete[] str;
		str = temp;
	}
}
int MyString::MyStrCmp(const MyString& b) const
{
	char* str1 = str;
	char* str2 = b.str;

	if (strlen(str1) < strlen(str2))
	{
		return -1;
	}
	while (*str2 == '\0')
	{
		if (*str1 != *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
const char* MyString::MyC_Str() const
{
	return str;
}
int MyString::GetCount()
{
	return count;
}
std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	for (int i = 0; i < obj.length; i++)
	{
		os << obj[i];
	}
	return os;
}
class var
{
	int Int;
	double Double;
	MyString Str;
	short type;

public:
	var();
	var(int value);
	var(double value);
	var(const char* str);
	var(const MyString& str);
	var(const var& obj);
	operator int();
	operator double();
	operator const char* ();
	var& operator=(int value);
	var& operator=(double value);
	var& operator=(const MyString& str);
	var& operator=(const char* str);
	var& operator=(const var& obj);
	var operator+(int value) const;
	var operator+(double value) const;
	var operator+(const MyString& str) const;
	var operator+(const char* str) const;
	var operator+(const var& obj) const;
	var operator-(int value) const;
	var operator-(double value) const;
	var operator-(const MyString& str) const;
	var operator-(const char* str) const;
	var operator-(const var& obj) const;
	var operator*(int value) const;
	var operator*(double value) const;
	var operator*(const MyString& str) const;
	var operator*(const char* str) const;
	var operator*(const var& obj) const;
	var operator/(int value) const;
	var operator/(double value) const;
	var operator/(const MyString& str) const;
	var operator/(const char* str) const;
	var operator/(const var& obj) const;
	var& operator+=(int value);
	var& operator+=(double value);
	var& operator+=(const MyString& str);
	var& operator+=(const char* str);
	var& operator+=(const var& obj);
	var& operator-=(int value);
	var& operator-=(double value);
	var& operator-=(const MyString& str);
	var& operator-=(const char* str);
	var& operator-=(const var& obj);
	var& operator/=(int value);
	var& operator/=(double value);
	var& operator/=(const MyString& str);
	var& operator/=(const char* str);
	var& operator/=(const var& obj);
	var& operator*=(int value);
	var& operator*=(double value);
	var& operator*=(const MyString& str);
	var& operator*=(const char* str);
	var& operator*=(const var& obj);
	bool operator!=(int value) const;
	bool operator!=(double value) const;
	bool operator!=(const MyString& str) const;
	bool operator!=(const char* str) const;
	bool operator!=(const var& obj) const;
	bool operator==(int value) const;
	bool operator==(double value) const;
	bool operator==(const MyString& str) const;
	bool operator==(const char* str) const;
	bool operator==(const var& obj) const;
	bool operator>(int value) const;
	bool operator>(double value) const;
	bool operator>(const MyString& str) const;
	bool operator>(const char* str) const;
	bool operator>(const var& obj) const;
	bool operator<(int value) const;
	bool operator<(double value) const;
	bool operator<(const MyString& str) const;
	bool operator<(const char* str) const;
	bool operator<(const var& obj) const;
	bool operator>=(int value) const;
	bool operator>=(double value) const;
	bool operator>=(const MyString& str) const;
	bool operator>=(const char* str) const;
	bool operator>=(const var& obj) const;
	bool operator<=(int value) const;
	bool operator<=(double value) const;
	bool operator<=(const MyString& str) const;
	bool operator<=(const char* str) const;
	bool operator<=(const var& obj) const;
	const char* GetConstChar() const {
		char* buffer = new char[Str.MyStrLen() + 1];
		strcpy_s(buffer, Str.MyStrLen() + 1, Str.MyC_Str());
		return buffer;
	}
	int GetInt() const
	{
		return Int;
	}
	double GetDouble() const
	{
		return Double;
	}
	MyString GetString() const { return Str; }
	friend std::ostream& operator<<(std::ostream& os, const var& obj);
};
var::var()
{
	Int = 0;
	Double = 0;
	type = -1;
}
var::var(int value) : var()
{
	type = 0;
	Int = value;
}
var::var(double value) : var()
{
	type = 1;
	Double = value;
}
var::var(const char* str) : var()
{
	type = 2;
	Str = str;
}
var::var(const MyString& str) : var()
{
	type = 2;
	Str = str;
}
var::var(const var& obj)
{
	Int = obj.Int;
	Double = obj.Double;
	Str = obj.Str;
	type = obj.type;
}
std::ostream& operator<<(std::ostream& os, const var& obj)
{
	if (obj.type == 0)
		os << obj.Int;
	else if (obj.type == 1)
		os << obj.Double;
	else if (obj.type == 2)
		os << obj.Str;
	return os;
}
int operator+(int value, const var& obj)
{
	var temp = value;
	temp = temp + obj;
	return temp.GetInt();
}
double operator+(double value, const var& obj)
{
	var temp = value;
	temp = temp + obj;
	return temp.GetDouble();
}
MyString operator+(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp + obj;
	return temp.GetString();
}
const char* operator+(const char* str, const var& obj)
{
	var temp = str;
	temp = temp + obj;
	return temp.GetConstChar();
}
int operator-(int value, const var& obj)
{
	var temp = value;
	temp = temp - obj;
	return temp.GetInt();
}
double operator-(double value, const var& obj)
{
	var temp = value;
	temp = temp - obj;
	return temp.GetDouble();
}
MyString operator-(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp - obj;
	return temp.GetString();
}
const char* operator-(const char* str, const var& obj)
{
	var temp = str;
	temp = temp - obj;
	return temp.GetConstChar();
}
int operator*(int value, const var& obj)
{
	var temp = value;
	temp = temp * obj;
	return temp.GetInt();
}
double operator*(double value, const var& obj)
{
	var temp = value;
	temp = temp * obj;
	return temp.GetDouble();
}
MyString operator*(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp * obj;
	return temp.GetString();
}
const char* operator*(const char* str, const var& obj)
{
	var temp = str;
	temp = temp * obj;
	return temp.GetConstChar();
}
int operator/(int value, const var& obj)
{
	var temp = value;
	temp = temp / obj;
	return temp.GetInt();
}
double operator/(double value, const var& obj)
{
	var temp = value;
	temp = temp / obj;
	return temp.GetDouble();
}
MyString operator/(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp / obj;
	return temp.GetString();
}
const char* operator/(const char* str, const var& obj)
{
	var temp = str;
	temp = temp / obj;
	return temp.GetConstChar();
}
var& var::operator=(int value)
{
	Int = value;
	Double = 0;
	Str = "\0";
	type = 0;
	return *this;
}
var& var::operator=(double value)
{
	Double = value;
	Int = 0;
	Str = "\0";
	type = 1;
	return *this;
}
var& var::operator=(const char* str)
{
	Str = str;
	Int = 0;
	Double = 0;
	type = 2;
	return *this;
}
var& var::operator=(const MyString& str)
{
	Str = str;
	Int = 0;
	Double = 0;
	type = 2;
	return *this;
}
var& var::operator=(const var& obj)
{
	if (this == &obj || this->type == -1)
		return *this;

	Int = obj.Int;
	Double = obj.Double;
	Str = obj.Str;
	type = obj.type;
	return *this;
}
var var::operator+(int value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int + value;
	else if (temp.type == 1)
		temp.Double = temp.Double + (double)value;
	else if (temp.type == 2)
	{
		char buffer[20];
		_itoa_s(value, buffer, 20, 10);
		temp.Str.MyStrCat(buffer);
	}
	return temp;
}
var var::operator+(double value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int + (int)value;
	else if (temp.type == 1)
		temp.Double = temp.Double + value;
	else if (temp.type == 2)
	{
		char buffer[20];
		_itoa_s(int(value * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		temp.Str.MyStrCat(buffer);
	}
	return temp;
}
var var::operator+(const MyString& str) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = str;
	else if (temp.type == 0)
	{
		temp.Int = temp.Int + atoi(str.MyC_Str());
	}
	else if (temp.type == 1)
	{
		temp.Double = temp.Double + strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.type == 2)
	{
		temp.Str.MyStrCat(str);
	}
	return temp;
}
var var::operator+(const char* str) const
{
	return (*this + MyString(str));
}
var var::operator+(const var& obj) const
{
	var temp(*this);
	if (obj.type == 0)
		temp = temp + obj.Int;
	else if (obj.type == 1)
		temp = temp + obj.Double;
	else if (obj.type == 2)
		temp = temp + obj.Str;

	return temp;
}
var var::operator-(int value) const
{
	if (this->type == 2)
		return *this;

	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int - value;
	else if (temp.type == 1)
		temp.Double = temp.Double - (double)value;
	return temp;
}
var var::operator-(double value) const
{
	if (this->type == 2)
		return *this;

	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int - (int)value;
	else if (temp.type == 1)
		temp.Double = temp.Double - value;
	return temp;
}
var var::operator-(const MyString& str) const
{
	if (this->type == 2)
		return *this;

	var temp(*this);
	if (temp.type == -1)
		temp = str;
	else if (temp.type == 0)
	{
		temp.Int = temp.Int - atoi(str.MyC_Str());
	}
	else if (temp.type == 1)
	{
		temp.Double = temp.Double - strtod(str.MyC_Str(), nullptr);
	}
	return temp;
}
var var::operator-(const char* str) const
{
	return(*this - MyString(str));
}
var var::operator-(const var& obj) const
{
	var temp(*this);
	if (obj.type == 0)
		temp = temp - obj.Int;
	else if (obj.type == 1)
		temp = temp - obj.Double;
	else if (obj.type == 2)
		temp = temp - obj.Str;

	return temp;
}
var var::operator*(int value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int * value;
	else if (temp.type == 1)
		temp.Double = temp.Double * (double)value;
	return temp;
}
var var::operator*(double value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int * (int)value;
	else if (temp.type == 1)
		temp.Double = temp.Double * value;
	return temp;
}
var var::operator*(const MyString& str) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = str;
	else if (temp.type == 0)
	{
		temp.Int = temp.Int * atoi(str.MyC_Str());
	}
	else if (temp.type == 1)
	{
		temp.Double = temp.Double * strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.type == 2)
	{
		for (int i = 0; i < temp.Str.MyStrLen(); i++)
		{
			if (str.MyChr(temp.Str[i]) == -1)
			{
				temp.Str.MyDelChr(temp.Str[i]);
				i = 0;
			}
		}
	}
	return temp;
}
var var::operator*(const char* str) const
{
	return (*this * MyString(str));
}
var var::operator*(const var& obj) const
{
	var temp(*this);
	if (obj.type == 0)
		temp = temp * obj.Int;
	else if (obj.type == 1)
		temp = temp * obj.Double;
	else if (obj.type == 2)
		temp = temp * obj.Str;

	return temp;
}
var var::operator/(int value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int / value;
	else if (temp.type == 1)
		temp.Double = temp.Double / (double)value;
	return temp;
}
var var::operator/(double value) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = value;
	else if (temp.type == 0)
		temp.Int = temp.Int / (int)value;
	else if (temp.type == 1)
		temp.Double = temp.Double / value;
	return temp;
}
var var::operator/(const MyString& str) const
{
	var temp(*this);
	if (temp.type == -1)
		temp = str;
	else if (temp.type == 0)
	{
		temp.Int = temp.Int / atoi(str.MyC_Str());
	}
	else if (temp.type == 1)
	{
		temp.Double = temp.Double / strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.type == 2)
	{
		for (int i = 0; i < str.MyStrLen(); i++)
		{
			temp.Str.MyDelChr(str[i]);
		}
	}
	return temp;
}
var var::operator/(const char* str) const
{
	return (*this / MyString(str));
}
var var::operator/(const var& obj) const
{
	var temp(*this);
	if (obj.type == 0)
		temp = temp / obj.Int;
	else if (obj.type == 1)
		temp = temp / obj.Double;
	else if (obj.type == 2)
		temp = temp / obj.Str;

	return temp;
}
var& var::operator+=(int value)
{
	*this = *this + value;
	return *this;
}
var& var::operator+=(double value)
{
	*this = *this + value;
	return *this;
}
var& var::operator+=(const MyString& str)
{
	*this = *this + str;
	return *this;
}
var& var::operator+=(const char* str)
{
	*this = *this + str;
	return *this;
}
var& var::operator+=(const var& obj)
{
	*this = *this + obj;
	return *this;
}
var& var::operator-=(int value)
{
	*this = *this - value;
	return *this;
}
var& var::operator-=(double value)
{
	*this = *this - value;
	return *this;
}
var& var::operator-=(const MyString& str)
{
	*this = *this - str;
	return *this;
}
var& var::operator-=(const char* str)
{
	*this = *this - str;
	return *this;
}
var& var::operator-=(const var& obj)
{
	*this = *this - obj;
	return *this;
}
var& var::operator*=(int value)
{
	*this = *this * value;
	return *this;
}
var& var::operator*=(double value)
{
	*this = *this * value;
	return *this;
}
var& var::operator*=(const MyString& str)
{
	*this = *this * str;
	return *this;
}
var& var::operator*=(const char* str)
{
	*this = *this * str;
	return *this;
}
var& var::operator*=(const var& obj)
{
	*this = *this * obj;
	return *this;
}
var& var::operator/=(int value)
{
	*this = *this / value;
	return *this;
}
var& var::operator/=(double value)
{
	*this = *this / value;
	return *this;
}
var& var::operator/=(const MyString& str)
{
	*this = *this / str;
	return *this;
}
var& var::operator/=(const char* str)
{
	*this = *this / str;
	return *this;
}
var& var::operator/=(const var& obj)
{
	*this = *this / obj;
	return *this;
}
var::operator double()
{
	if (type == -1)
		return -1.0;
	else if (type == 0)
		return (double)Int;
	else if (type == 1)
		return Double;
	else if (type == 2)
		return strtod(Str.MyC_Str(), nullptr);
}
var::operator const char* ()
{
	if (type == -1)
		return nullptr;
	else if (type == 0)
	{
		char* buffer = new char[20];
		_itoa_s(Int, buffer, 20, 10);
		return buffer;
	}
	else if (type == 1)
	{
		char* buffer = new char[20];
		_itoa_s(int(Double * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		return buffer;
	}
	else if (type == 2)
	{
		return Str.MyC_Str();
	}
}
bool var::operator==(int value) const
{
	if (type == -1)
		return false;
	else if (type == 0)
		return Int == value;
	else if (type == 1)
		return Double == (double)value;
	else if (type == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool var::operator==(double value) const
{
	if (type == -1)
		return false;
	else if (type == 0)
		return Int == (int)value;
	else if (type == 1)
		return Double == value;
	else if (type == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) == 0)
			return true;
		else
			return false;
	}
}
bool var::operator==(const MyString& str) const
{
	if (type == -1)
		return false;
	else if (type == 0)
	{
		return Int == atoi(str.MyC_Str());
	}
	else if (type == 1)
	{
		return Double == strtod(str.MyC_Str(), nullptr);
	}
	else if (type == 2)
	{
		if (Str.MyStrCmp(str) == 0)
			return true;
		else
			return false;
	}
}
bool var::operator==(const char* str) const
{
	return (*this == MyString(str));
}
bool var::operator==(const var& obj) const
{
	if (obj.type == 0)
		return *this == obj.Int;
	else if (obj.type == 1)
		return *this == obj.Double;
	else if (obj.type == 2)
		return *this == obj.Str;
	else
		return false;
}
bool var::operator!=(int value) const
{
	return !(*this == value);
}
bool var::operator!=(double value) const
{
	return !(*this == value);
}
bool var::operator!=(const MyString& str) const
{
	return !(*this == str);
}
bool var::operator!=(const char* str) const
{
	return !(*this == str);
}
bool var::operator!=(const var& obj) const
{
	return !(*this == obj);
}
bool var::operator>(int value) const
{
	if (type == -1)
		return false;
	else if (type == 0)
		return Int > value;
	else if (type == 1)
		return Double > (double)value;
	else if (type == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) > 0)
			return true;
		else
			return false;
	}
	return false;
}
bool var::operator>(double value) const
{
	if (type == -1)
		return false;
	else if (type == 0)
		return Int > (int)value;
	else if (type == 1)
		return Double > value;
	else if (type == 2)
	{
		char buffer[20];
		_itoa_s(int(value * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		if (Str.MyStrCmp(MyString(buffer)) > 0)
			return true;
		else
			return false;
	}
}
bool var::operator>(const MyString& str) const
{
	if (type == -1)
		return false;
	else if (type == 0)
	{
		return Int > atoi(str.MyC_Str());
	}
	else if (type == 1)
	{
		return Double > strtod(str.MyC_Str(), nullptr);
	}
	else if (type == 2)
	{
		if (Str.MyStrCmp(str) > 0)
			return true;
		else
			return false;
	}
}
bool var::operator>(const char* str) const
{
	return (*this == MyString(str));
}
bool var::operator>(const var& obj) const
{
	if (obj.type == 0)
		return *this > obj.Int;
	else if (obj.type == 1)
		return *this > obj.Double;
	else if (obj.type == 2)
		return *this > obj.Str;
	else
		return false;
}
bool var::operator<(int value) const
{
	return ((*this != value) && !(*this > value));
}
bool var::operator<(double value) const
{
	return ((*this != value) && !(*this > value));

}
bool var::operator<(const MyString& str) const
{
	return ((*this != str) && !(*this > str));

}
bool var::operator<(const char* str) const
{
	return ((*this != str) && !(*this > str));

}
bool var::operator<(const var& obj) const
{
	return ((*this != obj) && !(*this > obj));
}
bool var::operator>=(int value) const
{
	return ((*this > value) || (*this == value));
}
bool var::operator>=(double value) const
{
	return ((*this > value) || (*this == value));
}
bool var::operator>=(const MyString& str) const
{
	return ((*this > str) || (*this == str));
}
bool var::operator>=(const char* str) const
{
	return ((*this > str) || (*this == str));
}
bool var::operator>=(const var& obj) const
{
	return ((*this > obj) || (*this == obj));
}
bool var::operator<=(int value) const
{
	return ((*this < value) || (*this == value));
}
bool var::operator<=(double value) const
{
	return ((*this < value) || (*this == value));
}
bool var::operator<=(const MyString& str) const
{
	return ((*this < str) || (*this == str));
}
bool var::operator<=(const char* str) const
{
	return ((*this < str) || (*this == str));
}
bool var::operator<=(const var& obj) const
{
	return ((*this < obj) || (*this == obj));
}
bool operator==(int value, const var& obj)
{
	return (obj == value);
}
bool operator==(double value, const var& obj)
{
	return (obj == value);
}
bool operator==(const MyString& str, const var& obj)
{
	return (obj == str);
}
bool operator==(const char* str, const var& obj)
{
	return (obj == str);
}
bool operator!=(int value, const var& obj)
{
	return (obj != value);
}
bool operator!=(double value, const var& obj)
{
	return (obj != value);
}
bool operator!=(const MyString& str, const var& obj)
{
	return (obj != str);
}
bool operator!=(const char* str, const var& obj)
{
	return (obj != str);
}
bool operator>(int value, const var& obj)
{
	return (obj < value);
}
bool operator>(double value, const var& obj)
{
	return (obj < value);
}
bool operator>(const MyString& str, const var& obj)
{
	return (obj < str);
}
bool operator>(const char* str, const var& obj)
{
	return (obj < str);
}
bool operator<(int value, const var& obj)
{
	return (obj > value);
}
bool operator<(double value, const var& obj)
{
	return (obj > value);
}
bool operator<(const MyString& str, const var& obj)
{
	return (obj > str);
}
bool operator<(const char* str, const var& obj)
{
	return (obj > str);
}
bool operator>=(int value, const var& obj)
{
	return (obj <= value);
}
bool operator>=(double value, const var& obj)
{
	return (obj <= value);
}
bool operator>=(const MyString& str, const var& obj)
{
	return (obj <= str);
}
bool operator>=(const char* str, const var& obj)
{
	return (obj <= str);
}
bool operator<=(int value, const var& obj)
{
	return (obj >= value);
}
bool operator<=(double value, const var& obj)
{
	return (obj >= value);
}
bool operator<=(const MyString& str, const var& obj)
{
	return (obj >= str);
}
bool operator<=(const char* str, const var& obj)
{
	return (obj >= str);
}
int main()
{
	//var a = 15;
	//var b = "Hello";
	//var d = "50";
	//b = a + d;
	//cout<<b;// Βϋβεδες 65
	//cout << endl;
	//var h = 10, b1 = "120", c,v;
	//c = a + b1;
	//cout<<c; // Βϋβεδες 130
	//cout << endl;
	//v = b1 + h;
	//cout << v; // Βϋβεδες “12010”
	//cout << endl;
	var g = "Microsoft", e = "Windows", c1;
	c1 = g * e;
	cout << c1;		// Βϋβεδες “ioso”
	var a1 = "Microsoft", b1 = "Windows", c4;
	c4 = a1 / b1;
	cout << c4;


	return 0;
}