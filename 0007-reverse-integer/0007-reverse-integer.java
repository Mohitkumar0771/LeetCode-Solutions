class Solution {
    public int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            // Get the last digit
            int pop = x % 10; 
            // Remove the last digit from x
            x /= 10;
            
            // Check for positive overflow before multiplying by 10
            // Integer.MAX_VALUE is 2147483647
            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) {
                return 0;
            }
            
            // Check for negative overflow before multiplying by 10
            // Integer.MIN_VALUE is -2147483648
            if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) {
                return 0;
            }
            
            // Add the digit to the reversed number
            rev = rev * 10 + pop;
        }
        
        return rev;
    }
}