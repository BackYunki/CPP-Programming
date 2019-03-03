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
	cout << "활성화 된 기능\n";
	
	if (funcFlag & GL_COLOR_BUFFER_BIT)
	{
		cout << "컬러 버퍼가 초기화 되었습니다.\n";
	}
	if (funcFlag & GL_DEPTH_BUFFER_BIT)
	{
		cout << "깊이 버퍼가 초기화 되었습니다.\n";
	}

	return 0;
}