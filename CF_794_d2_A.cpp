#include<iostream>

using namespace std;

int arr[55];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		bool f = 0;
		for(int i = 0;i < n;i++)
		{
			if ((sum - arr[i]) / (n - 1) == arr[i])
			{
				f = 1;
				break;
			}
		}
		if (f) cout << "YES" << endl;
		else { cout << "NO" << endl; }
	}

	return 0;
}
