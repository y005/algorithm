#include <iostream>
#include <cmath>
using namespace std;

int n, ans, col[10];

int promising(int i)
{
for (int j=0; j<i; j++)
{
	// ���ο� ���� ������ ���� ���� �࿡ �ְų� �밢���� ���� ���
	if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
		return 0;
	}
	return 1;
}

void queens(int i)
{
    if (i == n)
        ans += 1;
    else
    {
        for (int j=0; j<n; j++)
        {
    	    col[i] = j;
    	    if (promising(i))
    		    queens(i + 1);
        }
    }
}

int main()
{
    cin >> n;
    queens(0);
    cout << ans << endl;
}

