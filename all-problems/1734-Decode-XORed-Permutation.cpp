// LET'S UNDERSTAND THE PROBLEM WITH A DRY RUN TEST
//     clues - n is always odd
//           - encoded[i] = perm[i] XOR perm[i+1] i.e., every encoded element is xor of two elements. In other
//             words, every two adjacent encoded elements share common element

//     an example:
//           - encoded = [6, 5, 4, 6] is decoded as [2, 4, 1, 5, 3]
//           - so [6, 5, 4, 6] == [2^4, 4^1, 1^5, 5^3]. If we carefully observe at alternate indices, for example,
//             at 1 and 3, and taking xor of these, we get 4^1^5^3 i.e., xor of all the elements [1, 2,...,n]
//             except one element(that's why n is always odd) which is nothing but the first element of decoded array!!
//             If you take alternate indices as 0, 2, 4..., you will get last element of decoded array.
//             Note: We take alternate element because, adjacent elements share common element.

//           - so if we compute xor of all the elements([1,2,..,n]) , x = 1^2^3^4^5 and take xor with the elements
//             at alternate indices of encoded array, we get first element of decoded array (taking indices 1, 3,...)
//             i.e., x^4^1^5^3 = 2;

//           - the rest elements of the decoded array can be computed as, perm[i+1] = perm[i] ^ encoded[i]
//             (if c = a^b then, b = c^a)

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = (int)encoded.size() + 1;
        int x = 0;  // xor of all elements
        for (int i = 1; i <= n; ++i) x ^= i;

        vector<int> perm(n, 0);
        int temp = x; // compute first element of decoded array
        for (int i = 1; i < n - 1; i += 2) temp ^= encoded[i];
        perm[0] = temp;

        // compute rest of the elements
        for (int i = 0; i < n - 1; ++i) perm[i + 1] = perm[i] ^ encoded[i];
        return perm;
    }
};