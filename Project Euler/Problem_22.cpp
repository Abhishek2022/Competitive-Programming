#include<bits/stdc++.h>
using namespace std;

int count(string &s)
{
	int ans = 0;
	for(char ch : s)
		ans += ch-64;
	return ans;
}

int main()
{
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);

	sort(v.begin(),v.end());
	int n = v.size();
	long long ans = 0;

	for(int i=0;i<n;i++)
		ans += (i+1)*count(v[i]);
	cout<<ans;
	return 0;
}