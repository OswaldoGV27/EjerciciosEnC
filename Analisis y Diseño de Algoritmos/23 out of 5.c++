#include <bits/stdc++.h>
using namespace std;

int arr[5];

bool possible (int valorActual, int pos)
{
    if (pos == 5)
    {
        //cout << valoractual <<" ";
        if (valorActual == 23 ) return true;
        else return false;
    }
    else
    {
        bool op1 = possible(valorActual + arr[pos], pos +1);
        bool op2 = possible(valorActual - arr[pos], pos +1);
        bool op3 = possible(valorActual * arr[pos], pos +1);
        if(op1 || op2 || op3)return true;
        return false;
    }
}

int main ()
{
    for(int i=0; i<5; i++)
        cin >>arr[i];
    while(arr[0] !=0 || arr[1] !=0 || arr[2] !=0 || arr[3] !=0 || arr[4] !=0)
    {
        sort(arr, arr +5);
        bool res = possible(arr[0], 1);
        while(next_permutation(arr, arr + 5))
	{
            bool aux =possible(arr[0], 1);
            if(aux) res= true;
        }
        if (res)
                cout<< "Possible\n";
        else cout << "Impossible\n";
        for(int i=0; i<5; i++)
            cin >> arr[i];
    }

    return 0;
}