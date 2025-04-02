class Solution {
    private int root(int u, int[] parent) {
        if (parent[u] != u) {
            parent[u] = root(parent[u], parent);
        }
        return parent[u];
    }

    private void join(int a, int b, int[] parent) {
        int u = root(a, parent);
        int v = root(b, parent);
        parent[v] = u;
    }

    public int countCompleteComponents(int n, int[][] edges) {
        int[][] mark = new int[n][n];
        int[] parent = new int[n];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            mark[i][i] = 1;
        }
        
        for (int[] e : edges) {
            mark[e[0]][e[1]] = 1;
            mark[e[1]][e[0]] = 1;
            join(e[0], e[1], parent);
        }
        
        List<List<Integer>> save = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            save.add(new ArrayList<>());
        }
        
        for (int i = 0; i < n; i++) {
            int u = root(i, parent);
            save.get(u).add(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            boolean check = true;
            for (int j : save.get(i)) {
                for (int z : save.get(i)) {
                    if (mark[j][z] == 0) {
                        check = false;
                    }
                }
            }
            if (!save.get(i).isEmpty()) {
                ans += check ? 1 : 0;
            }
        }
        
        return ans;
    }
}

