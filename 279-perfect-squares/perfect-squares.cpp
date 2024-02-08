class Solution {
public:
    int numSquares(int n) {
        int i=sqrt(n);
        if(i*i==n) return 1;
        while((n%4)==0){
            n/=4;
        }
        if((n%8)==7) return 4;
        int m=sqrt(n);
        for(int i=1;i<=m;i++){
            int s=sqrt(n-i*i);
            if((s*s)==n-i*i) return 2;

        }
        return 3;
    }
};