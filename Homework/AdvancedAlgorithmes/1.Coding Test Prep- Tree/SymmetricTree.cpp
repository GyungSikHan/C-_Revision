//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int n{};
//vector<int> v;
//
//int Solution(int idx, bool& bFlag)
//{
//	if (bFlag)
//		return 0;
//
//	if (v.size() <= idx)
//		return 1;
//	if (v[idx] == -1)
//		return 0;
//	
//	int left = Solution(idx * 2, bFlag);
//	int right = Solution(idx*2+1, bFlag);
//
//	if (left != right)
//		bFlag = true;
//	return left+right;
//}
//
//bool Solution(int left, int right)
//{
//	// 둘 다 범위를 벗어나거나 null이면 대칭
//	bool leftNull = left > n || v[left] == -1;
//	bool rightNull = right > n || v[right] == -1;
//
//	if (leftNull && rightNull)
//		return true;
//
//	// 하나만 null이면 비대칭
//	if (leftNull || rightNull)
//		return false;
//
//	// 값이 다르면 비대칭
//	if (v[left] != v[right])
//		return false;
//
//	// 거울 방향으로 비교
//	return Solution(left * 2, right * 2 + 1) &&
//		Solution(left * 2 + 1, right * 2);
//}
//
//int main()
//{
//	cin >> n;
//	v.assign(n + 1, 0);
//	for (int i = 1; i <= n; ++i)
//	{
//		string s{};
//		cin >> s;
//		if (s == "null")
//			v[i] = -1;
//		else
//			v[i] = stoi(s);
//	}
//
//	bool bFlag{};
//	//Solution(1, bFlag);
//	cout << (Solution(2, 3) ?"true" : "false");
//}