#include <iostream>	
#include <string>

using namespace std;

class IErrorLog
{
public:
	virtual bool reportError(const char * errorMessage) = 0;
	virtual ~IErrorLog() { }
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char * errorMessage) override
	{
		cout << "Writting error to a file\n";
		return true;
	}
	virtual ~FileErrorLog() override {}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char * errorMessage) override
	{
		cout << "Writting error to a console\n";
		return true;
	}
	// virtual ~ConsoleErrorLog() override {} ����Ʈ �Ҹ��ڴ� �˾Ƽ� ������ش�.
};

void doSomething(IErrorLog & log)
{
	log.reportError("Runtime Error!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}