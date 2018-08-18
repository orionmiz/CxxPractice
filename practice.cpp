#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class String {
private:
	char* m_sStr;
public:
	String() {
		cout << "String 디폴트 생성자가 호출되었습니다." << endl;
		m_sStr = NULL;
	}

	String(char* str) {
		cout << "String 생성자가 호출되었습니다." << endl;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}

	String(String &str) {
		cout << "복사 생성자가 호출되었습니다." << endl;
		m_sStr = new char[strlen(str.get()) + 1];
		strcpy(m_sStr, str.get());
	}

	~String() {
		cout << "String 파괴자가 호출되었습니다." << endl;
		delete m_sStr;
	}

	void operator=(const char* str) {
		cout << "연산자 오버로딩이 호출되었습니다." << endl;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}

	char* get() {
		return m_sStr;
	}

	void set(const char* str) { // 인수는..
		delete m_sStr;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}
	static void testReference(String&);
	static void testCopy(String);
};

int main() {
	String str;
	str = "후후";
	cout << str.get() << endl;
	String::testReference(str);
	cout << str.get() << endl;
	String::testCopy(str);
	cout << str.get() << endl;
	system("pause");
}

void String::testReference(String &str) { // 참조된 str.
	str.set("크크");
}

void String::testCopy(String str) { // str은 복사 생성됨.
	str.set("케케");
}