#include<iostream>

using namespace std;
using std::cout;

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
class String;
String operator+(const String& left, const String& right);

class String
{
	int size;   //размер строки
	char *str;  //адресс строки в динам памяти
public:
	int get_size()const;
	const char* get_str() const;
	char* get_str();
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	char& operator[](int i);
	const char& operator[](int i) const;
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	void print();

};
int String::get_size()const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}

char* String::get_str()
{
	return str;
}

///////////////////Counstructors//////////////////////////////////

String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char str[])
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;
}


String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyConstructor" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor " << this << endl;
}


String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t" << this << endl;
}

///////////////////Operators////////////////////////
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssigment " << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	/*this->str_temp = this->str;
	delete[] str;
	this->size = this->size + other.size - 1;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)
	{
	this->str[i] = this->str_temp[i];
	}
	for (int i = 0; other.str[i]; i++)
	{
	this->str[i + other.size - 1] = other.str[i];
	}
	delete[] str_temp;
	return *this;*/
	return *this = *this + other;
}

char& String::operator[](int i)
{
	/*char value = this->str[i];
	return value;*/
	return this->str[i];
}

const char& String::operator[](int i) const
{
	/*char value = this->str[i];
	return value;*/
	return this->str[i];
}

///////////Methods///////////////////////////////////////

void String::print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	/*for (int i = 0; left.get_str()[i]; i++)*(cat.get_str() + i) = left.get_str()[i];
	for (int i = 0; right.get_str()[i]; i++)cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	for (int i = 0; left[i]; i++)
		cat[i] = left[i];
	for (int i = 0; right[i]; i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}



ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void main()
{
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTORS_CHECK

	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	//str1.print();
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;
	String str3;
	str2 = str2;
	cout << str2 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + " " + str2;
	//cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	String str3;
	str3 = str1 + " " + str2;
	cout << str3 << endl;
}