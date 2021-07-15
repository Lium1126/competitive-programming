// AOJ 0657 seats

#include<stdio.h>
#include<stdlib.h>

#define MOD 10007
#define INF (1 << 30)

int n;
int sum = 0;
int num[101] = {};
int entered[101] = {};
int mem[10] = {};

// 階乗
int fact(int n){
    if(mem[n] != 0) return mem[n];
    if(n == 1) return 1;
    return fact(n - 1) * n;
}

int dfs(int before, int cnt){
    if(cnt == sum){
        return 1;
    }
    int i;
    int rec = 0;
    for(i = 1;i <= n;i++){
        if(abs(i - before) > 1 && entered[i] < num[i]){
            entered[i]++;
            rec = (rec + dfs(i, cnt + 1)) % MOD;
            entered[i]--;
        }
    }
    return rec;
}
/*
int main(){
    int i;
    int ans = 0;
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = dfs(INF, 0);
    for(i = 1;i <= n;i++){
        ans = (ans * fact(num[i])) % MOD;
    }
    printf("%d\n", ans);
    return(0);
}


*/

int power(int n, int m){
    if(m == 0) return 1;
    int rec = power(n * n, m / 2);
    if(m % 2 == 1){
        rec *= n;
    }
    return rec;
}

int Detaminant(int gyoretsu[3][3], int n){
    if(n == 1){
        return gyoretsu[0][0];
    }
    int j;
    int a, b;
    int cnt = 0;
    int det = 0;
    int gyoretsu2[3][3];
    for(j = 0;j < n;j++){
        //gyoretsu2を求める
        for(a = 1;a < n;a++){
            for(b = 0;b < n;b++){
                if(j != b){
                    gyoretsu2[a][cnt] = gyoretsu[a][b];
                    cnt++;
                }
            }
        }
        det += (gyoretsu[0][j] * power(-1, 1 + j + 1) * Detaminant(gyoretsu2, n - 1));
    }
    return det;
}

int main(){
    int gyo[3][3] = {
        {1, -1, 3},
        {0, 1, 2},
        {-2, 3, 1}
    };
    
    printf("%d\n", Detaminant(gyo, 3));
    return(0);
}











void markof(int field[HEIGHT][WIDTH], int turn){
    int x, y;
    
    if(turn == 1){
        printf("turn O\n");
    }else{
        printf("turn X\n");
    }
    
    do{
        printf("x y? ");
        scanf("%d %d", &x, &y);
        if((x < 0 || x > 2) || (y < 0 || y > 2) || field[y][x] != 0){
            printf("再度入力してください\n");
            continue;
        }else{
            break;
        }
    }while(1);
}
