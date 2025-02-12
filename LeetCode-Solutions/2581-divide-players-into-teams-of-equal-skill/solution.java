class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        Arrays.sort(skill);
        long temp = -1;
        long ans = 0;
        for ( int i = 0 ; i < n/2 ; ++i ) {
            if ( temp == -1 ) {
                temp = skill[i] + skill[n-i-1];
                
            } else {
                if ( skill[i] + skill[n-i-1] != temp ) {
                    return -1;
                }
            }
            ans += skill[i] * skill[n-i-1];
        } 
        return ans;
    }
}
