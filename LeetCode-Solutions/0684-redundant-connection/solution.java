class Solution {
    private int root(int u, int[] parent) {
        if (parent[u] != u) {
            parent[u] = root(parent[u], parent);
        }
        return parent[u];
    }

    private void join(int x, int y, int[] parent) {
        int u = root(x, parent);
        int v = root(y, parent);
        parent[v] = u;
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        for (int[] edge : edges) {
            int u = root(edge[0], parent);
            int v = root(edge[1], parent);
            
            if (u == v) {
                return edge;
            } else {
                join(edge[0], edge[1], parent);
            }
        }
        return new int[0];
    }
}

