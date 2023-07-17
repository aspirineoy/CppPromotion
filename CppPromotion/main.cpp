#include "CustomString.h"
#include "StackInfo.h"
#include "SkipList.h"

/*
class Test
{
public:
    int p1 = 1;
    bool p2 = false;
    std::string p3 = "p33333333";

    void testWithStack(StackInfo& stack)
    {
        int v1 = 0;
        std::string v2;
        Test v3;
        Test* v4 = nullptr;

        stack.pop<Test*>(v4);
        stack.pop(v3);
        stack.pop(v2);
        stack.pop(v1);

        std::cout << "testWithStack " << std::endl;
        std::cout << v1 << std::endl;
        std::cout << v2 << std::endl;
        std::cout << v3.p3 << std::endl;
        std::cout << v4->p3 << std::endl;

        stack.push(1);
    }
};

void test2()
{
    Test t1;

    StackInfo stack;  // ʵ�ִ��࣬����ģ�庯����push��pop
    stack.push(111);
    stack.push<std::string>("asdfasdfasdf");

    Test t2;
    t2.p3 = "t2teststring";
    stack.push(t2);
    stack.push(&t1);

    t1.testWithStack(stack);

    int ret = 0;
    stack.pop(ret);
    std::cout << "testWithStack ret " << ret << std::endl;
}

*/
int main() {
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");

	cout << str1.len() << endl;
	cout << str2.len() << endl;
	str1 = "test31";
	cout << str1.len() << endl;

	auto str3=str1.append(str2);
	cout << str3.len() << endl;


    // ����һ�����㼶Ϊ4������
    SkipList skipList(4);

    // ���������Ԫ��
    skipList.insert(3);
    skipList.insert(1);
    skipList.insert(5);
    skipList.insert(2);

    // ����Ԫ��
    bool found = skipList.search(5);
    if (found) {
        std::cout << "Ԫ��5������������" << std::endl;
    }
    else {
        std::cout << "Ԫ��5��������������" << std::endl;
    }

    // ɾ��Ԫ��
    skipList.remove(1);

    // �ٴ�����Ԫ��
    found = skipList.search(1);
    if (found) {
        std::cout << "Ԫ��1������������" << std::endl;
    }
    else {
        std::cout << "Ԫ��1��������������" << std::endl;
    }

    return 0;
}