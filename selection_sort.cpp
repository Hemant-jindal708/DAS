#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    int y = 2;
    while (y > 0)
    {
        y = 0;
        int x = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[x] > arr[j])
            {
                x = j;
            }
        }
        if (x != i)
        {
            arr[i] += arr[x];
            arr[x] = arr[i] - arr[x];
            arr[i] = arr[i] - arr[x];
            y++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}