#include <iostream>
#include <string>

class String
{
public:
	String (const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		std::cout << "Copy String ! " << std::endl;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
private:
	char* m_Buffer;
	unsigned int m_Size;
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{
	String string = "Hello";
	String second = string;

	second[2] = 'q';

	PrintString(string);
	PrintString(second);
}