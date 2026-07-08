class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (n == 1) {
            cout << 1 << endl;
            return 1;   
        }
        int f = 0, s = 1, next;
        for (int i = 2; i <= n; i++) {
            next = f + s;
            f = s;
            s = next;
        }

        cout << n << endl;
        return s;  
    }
};