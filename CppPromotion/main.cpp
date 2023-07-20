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

    StackInfo stack;  // 实现此类，就俩模板函数，push和pop
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


    // 创建一个最大层级为4的跳表
    SkipList skipList(4);

    // 向跳表插入元素
    skipList.insert(9);
    skipList.insert(3);
    skipList.insert(1);
    skipList.insert(2);
    skipList.insert(4);

    // 搜索元素
    bool found = skipList.search(1);
    if (found) {
        std::cout << "元素1存在于跳表中" << std::endl;
    }
    else {
        std::cout << "元素1不存在于跳表中" << std::endl;
    }

    // 删除元素
    skipList.remove(1);

    // 再次搜索元素
    found = skipList.search(1);
    if (found) {
        std::cout << "元素1存在于跳表中" << std::endl;
    }
    else {
        std::cout << "元素1不存在于跳表中" << std::endl;
    }

    return 0;
}