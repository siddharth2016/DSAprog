#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void print_opt_parens(int , int , int ,int*, char&);

void matrixChainOrder(int [], int );

void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int s[n][n];

    for (int i=1; i<n; i++)
        m[i][i] = 0;
    for (int L=2; L<n; L++)
    {
        for (int i=1; i<n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    char name = 'A';

    cout << "Parenthesization : \n";

    print_opt_parens(1, n-1, n, (int *)s, name);

    cout << "\n Optimised Multiplications : " << m[1][n-1];


}


void print_opt_parens(int i, int j, int n,int *s, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "( ";

    print_opt_parens(i, *((s+i*n)+j), n,s, name);

    print_opt_parens(*((s+i*n)+j) + 1, j,n, s, name);

    cout << " )";
}

int main()
{
      int m;
      cout<<"\nNumber of matrices : ";
      cin>>m;
      int arr[m+1];
         cout<<"\nDimensions: ";
        for(int i =0;i<m+1;i++){
            cin>> arr[i];
}
    int n = sizeof(arr)/sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
