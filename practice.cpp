#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class String {
private:
	char* m_sStr;
public:
	String() {
		cout << "String ����Ʈ �����ڰ� ȣ��Ǿ����ϴ�." << endl;
		m_sStr = NULL;
	}

	String(char* str) {
		cout << "String �����ڰ� ȣ��Ǿ����ϴ�." << endl;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}

	String(String &str) {
		cout << "���� �����ڰ� ȣ��Ǿ����ϴ�." << endl;
		m_sStr = new char[strlen(str.get()) + 1];
		strcpy(m_sStr, str.get());
	}

	~String() {
		cout << "String �ı��ڰ� ȣ��Ǿ����ϴ�." << endl;
		delete m_sStr;
	}

	void operator=(const char* str) {
		cout << "������ �����ε��� ȣ��Ǿ����ϴ�." << endl;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}

	char* get() {
		return m_sStr;
	}

	void set(const char* str) { // �μ���..
		delete m_sStr;
		m_sStr = new char[strlen(str) + 1];
		strcpy(m_sStr, str);
	}
	static void testReference(String&);
	static void testCopy(String);
};

int main() {
	String str;
	str = "����";
	cout << str.get() << endl;
	String::testReference(str);
	cout << str.get() << endl;
	String::testCopy(str);
	cout << str.get() << endl;
	system("pause");
}

void String::testReference(String &str) { // ������ str.
	str.set("ũũ");
}

void String::testCopy(String str) { // str�� ���� ������.
	str.set("����");
}