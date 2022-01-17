
// C++��Ŀ
// ����C++��������extern "C"{}����ĺ�����C����������ģ����ӵ�ʱ����C�ĺ���������ȥ�ң��Ϳ���������
extern "C"
{
	#include "../../DS/DS/Stack.h"
}

bool isValid(char * s){
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '('
			|| *s == '{'
			|| *s == '[')
		{
			StackPush(&st, *s); 
			++s;
		}
		else
		{
			// �����������ˣ�����ջ����û�����ݣ�˵��
			// ǰ��û�������ţ���ƥ�䣬����false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}

	// ���ջ���ǿգ�˵��ջ�л���������δ��
	// û��ƥ�䣬������false
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()
{
	//cout << isValid("{[]}") << endl;
	//cout << isValid("([)]") << endl;
	printf("%d\n"isValid("{[]}"));
	printf("%d\n"isValid("([)]"));

	return 0;
}
