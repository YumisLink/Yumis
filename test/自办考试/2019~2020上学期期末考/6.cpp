#include <cstdio>
int cnt[30010]; 
int n, m, tmp, sum, j, usem, use3, use2, use1;
int main() {
    freopen("lscs.in","r",stdin);
    freopen("lscs.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &tmp), cnt[tmp]++;
    use1 = cnt[1]; use2 = cnt[2]; use3 = cnt[3];
    sum = use3*3 + use2*2 + use1;
    for(int i = 4; i + 2 < 30010 && sum < m; i += 3) {
        usem++;
        use1 += cnt[i], use2 += cnt[i+1], use3 += cnt[i+2];
        sum += cnt[i] + cnt[i+1]*2 + cnt[i+2]*3;
    }
    while(sum >= m + 3 && use3) use3--, sum-=3;
    while(sum >= m + 1 && use1) use1--, sum--;
    while(sum >= m + 2 && use2) use2--, sum-=2;
    if(sum < m) puts("Human Cannot Win Dog");
    else printf("%d %d", usem, (use3 << 2) + use2 + use1 + usem);
}