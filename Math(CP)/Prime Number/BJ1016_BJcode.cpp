#include <cstdio>
bool check[1000001];
long long min, max;
int main(){
    scanf("%lld %lld",&min,&max);
    for (long long i = 2; i*i<=max; i++){
        long long start = i*i-min%(i*i);
        if (start == i*i) {
            start = 0;
        }
        for (long long j = start; j <= max-min; j += i*i) {
            check[j] = true;
        }
    }
    int ans = 0;
    for (int i=0; i<=max-min; i++) {
        if (check[i] == 0) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}