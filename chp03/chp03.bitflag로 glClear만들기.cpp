#include <iostream>

#define GL_COLOR_BUFFER_BIT (1 << 0)
#define GL_DEPTH_BUFFER_BIT (1 << 1)

using namespace std;

typedef unsigned int GLuint;
typedef double GLdouble;
typedef float GLfloat;
typedef int GLmask;

int funcFlag = 0;

void glClear(GLmask mask)
{
	funcFlag |= mask;
}

int main()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cout << "Ȱ��ȭ �� ���\n";
	
	if (funcFlag & GL_COLOR_BUFFER_BIT)
	{
		cout << "�÷� ���۰� �ʱ�ȭ �Ǿ����ϴ�.\n";
	}
	if (funcFlag & GL_DEPTH_BUFFER_BIT)
	{
		cout << "���� ���۰� �ʱ�ȭ �Ǿ����ϴ�.\n";
	}

	return 0;
}