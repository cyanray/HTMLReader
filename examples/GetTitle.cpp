#include <HTMLReader.h>
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	using namespace Cyan;

	// ���ַ�����ʽ���� HTML �ĵ�
	string htmlStr = "<html><head><title>Hello World!</title></head><body><h1>Hello HTMLReader!</h1></body></html>";

	HTMLDoc hdoc;
	// ���� htmlStr �е�����
	hdoc.Parse(htmlStr);

	try
	{
		// ����ʹ�� operator[] �������ĵ���ǩ
		HTMLDoc head = hdoc["html"]["head"];
		// ʹ�� GetInner() ��ȡ��ǩ����������
		cout << head["title"].GetInner() << endl;
		// GetInner() ������״̬����˱��� head ʼ��ָ�� head ��ǩ��
		// ��������Ϊ��һ����룬ָ�� title ��ǩ
		cout << head["title"].GetInner() << endl;
		// ������һ�д��뽫�������쳣����Ϊ head ��ǩ�²����� title2 ��ǩ
		cout << head["title2"].GetInner() << endl;
	}
	catch (const CantFindTag & cft)
	{
		// ����ĸ���ǩ�Ҳ�����
		cout << cft.what() << endl;
		// ��ӡ�������������ǲ��ǽ���������
		hdoc.PrintTree(cout);
	}

	return 0;
}