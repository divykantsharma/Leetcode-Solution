class Solution{
public:
    int mirrorReflection(int p,int q){
        while(p%2==0 && q%2==0){
            p=p/2;
            q=q/2;
        }
        if(p%2==1 && q%2==1) return 1;  //p->odd and q->odd - 1
        if(p%2==0 && q%2==1) return 2;  //p->even and q->odd - 2
        return 0;                       //p->odd and q->even - 0
    }
};