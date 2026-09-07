//#include <iostream>
//
//using namespace std;
//
//const int chose = 3;
//string n{};
//
//void dfs(int level, string str)
//{
//	if (level == chose)
//	{
//		cout << str << endl;
//		return;
//	}
//
//	for (int i = 0; i < n.size(); ++i)
//	{
//		
//		dfs(level + 1, str + n[i]);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	dfs(0, "");
//}