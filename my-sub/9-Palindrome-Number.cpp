
class Solution {
public:
    /**
     * 9. Palindrome Number
     * @hainingbaby
     * @Time        2019-04-17T10:10:35+0800
     * @param       x                        [description]
     * @return                               [description]
     * 为避免整数溢出，这里的解决方式是换成了unsigned类型
     */
    bool isPalindrome(int x) {
        unsigned res = 0;
        int x_origin = x;
        if(x < 0) return false;
        if(x == 0) return true;
        while(x != 0){
            res = 10 * res + x % 10;
            x = x / 10;
        }
        return res == x_origin;
    }
};