#include <stdio.h>

int main(){
    int S[49] = {0,};
    int k = 0;
    int a,b,c,e,d,f;
    while(1){
        scanf("%d", &k);
        if(k == 0) break;
        for(int i = 0; i < k; i++){
            scanf("%d", &S[i]);    
        }
        
        for(a = 0; a <= k-6; a++)
            for(b = a+1; b <= k-5; b++)
                for(c = b+1; c <= k-4; c++)
                    for(d = c+1; d <= k-3; d++)
                        for(e = d+1; e <= k-2; e++)
                            for(f = e+1; f <= k-1; f++)
                                printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
        printf("\n");
        
    }
    return 0;
}