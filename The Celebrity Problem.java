class Solution {
    public int celebrity(int mat[][]) {
        int candidate = 0;
        for (int i = 1; i < mat.length; ++i) {
            if (mat[candidate][i] == 1) {
                candidate = i;
            }
        }
        for (int i = 0; i < mat.length; ++i) {
            if ((i != candidate && mat[candidate][i] == 1) || (i != candidate && mat[i][candidate] == 0)) {
                return -1;
            }
        }
        return candidate;
    }
}
