/* P-0006 */

#include <stdio.h>

int main() {
  int t, n, ans;
  int mat[301][301];
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        scanf("%d", &mat[i][j]);
      }     
    }

    for(int k = 1; k <= n; k++) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          if(mat[i][j] > mat[i][k] + mat[k][j]) {
            mat[i][j] = mat[i][k] + mat[k][j];
          }         
        }     
      }
    }

    ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(mat[i][j] > ans) {
          ans = mat[i][j];
        }         
      }     
    }

    printf("#%d %d", tc, ans);
  }
}