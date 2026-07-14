class Solution {
public:
    int addDigits(int num) {
        if(num<=9){
            return num;
        }
        int s=0;int d;
        for(int i=0;num>0;i++){
            d=num%10;
            s=s+d;
            num=num/10;
            if(num==0&&s>9){
                num=s;
                s=0;
            }

        }
        return s;
    }
};
