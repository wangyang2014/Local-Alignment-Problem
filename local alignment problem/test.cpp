#include<vector>
void test(std::vector<int> &a)
{
	a.push_back(1);
	a.push_back(3);
}
void testmain()
{
	std::vector<int> a;
	a.push_back(2);
	test(a);
	int size = a.size();
}