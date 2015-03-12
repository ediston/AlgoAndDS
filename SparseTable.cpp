#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long N, MAXN, LOGMAXN;
int M[MAXN][LOGMAXN];
int A[MAXN];

void process2( )
  {
      int i, j;

  //initialize M for the intervals with length 1
      for (i = 0; i < N; i++)
          M[i][0] = i;
  //compute values from smaller to bigger intervals
      for (j = 1; 1 << j <= N; j++) // till 2^j 
          for (i = 0; i + (1 << j) - 1 < N; i++)  // till N -(2^j -1)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (A[M[i][k]] <= A[M[j-(1<<k)+1][k]])
        return M[i][k];
    else
        return M[j-(1<<k)+1][k];
}
 int main() {
    return 0;
}
