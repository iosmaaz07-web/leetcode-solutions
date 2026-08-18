class Solution {
public:
bool isHappy(int n){
        
int slow = n;
        int fast = n;

    

        
        while (fast != 1) {
            // If they meet at any number other than 1, there's a cycle
           
            
            // Move slow by 1 step, fast by 2 steps
            slow = getNext(slow);
            fast = getNext(getNext(fast));
             if (slow == fast && slow!=1) {
                return false;
            }
        }

        return true;
    }

    // Helper method to calculate the sum of squares of digits
   int getNext(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
   }         
};