class Solution {
public:
    // Computes the index you land on after taking one "jump" from index i.
    // nums[i] tells you how far and which direction to jump.
    // The double modulo handles negative jumps (C++'s % can return negative numbers).
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        // Try starting a cycle search from every index.
        // A valid cycle could exist starting anywhere in the array.
        for (int i = 0; i < n; i++) {

            // 0 means this index was already proven "dead" (no cycle possible)
            // by an earlier iteration — skip re-checking it.
            if (nums[i] == 0) continue;

            // Lock in the direction we must stay consistent with for this attempt.
            // true = all jumps must stay positive, false = all must stay negative.
            bool direction = nums[i] > 0;

            // Standard Floyd's slow/fast pointers, both starting at i.
            int slow = i, fast = i;
            bool valid = true; // assume this path leads to a valid cycle until proven otherwise

            while (true) {
                // --- Move slow pointer by 1 jump ---
                slow = getNext(nums, slow);
                // If the sign at the new position doesn't match our locked direction,
                // this path is broken — no valid cycle through here.
                if ((nums[slow] > 0) != direction) { valid = false; break; }

                // --- Move fast pointer by 2 jumps ---
                fast = getNext(nums, fast);
                if ((nums[fast] > 0) != direction) { valid = false; break; }
                fast = getNext(nums, fast);
                if ((nums[fast] > 0) != direction) { valid = false; break; }

                // If slow and fast land on the same index, we've found a cycle
                // (or a self-loop, which we check for next) — exit the loop to inspect it.
                if (slow == fast) break;
            }

            // We only get here with valid == true if slow and fast actually met.
            // Now rule out a cycle of length 1: if the meeting point points to itself,
            // that's not a real cycle by LC 457's rules.
            if (valid && slow == getNext(nums, slow)) valid = false;

            // Found a genuine cycle (length > 1, consistent direction) — done.
            if (valid) return true;

            // This starting index didn't lead to a cycle.
            // Walk the same path again and mark every index we touched as 0 ("dead"),
            // so future outer-loop iterations skip them instead of re-tracing the same
            // failed path. This is what keeps the algorithm O(n) overall.
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == direction) {
                int next = getNext(nums, j);
                nums[j] = 0; // mark visited/dead
                j = next;
            }
        }

        // No index led to a valid cycle.
        return false;
    }
};