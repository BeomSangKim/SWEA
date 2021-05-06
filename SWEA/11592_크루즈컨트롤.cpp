#include <stdio.h>

int main() {
        int total_tc = 0;
        int D, N = 0;
        int k[2] = {0,}, s[2] = {0,};
        double at[2] = {0,}, lat = 0, result = 0;
        scanf("%d", &total_tc);
        for (int cur_tc = 1; cur_tc <= total_tc; cur_tc++) {
                scanf("%d %d", &D, &N);
                for (int i = 0; i < N; i++) {
                        scanf("%d %d",&k[i], &s[i]);
                        at[i] = ((double)(D - k[i])) / s[i];
                }
                lat = (at[0] > at[1]) ? at[0] : at[1];
                result = D / lat;
                printf("#%d %.7lf\n", cur_tc, result);
                at[1] = 0;
        }
        return 0;
}

