import java.util.*;

class BFSDemo {
    public static void main(String[] args) {
        int n = 6;
        boolean[] vis = new boolean[n];
        List<Integer>[] adj = new ArrayList[6];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        adj[0] = new ArrayList<>(Arrays.asList(1,2,4));
        adj[1] = new ArrayList<>(Arrays.asList(3, 4));
        adj[2] = new ArrayList<>(Arrays.asList(5));

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                Queue<Integer> q = new LinkedList<Integer>();
                q.add(i);
                while (!q.isEmpty()) {
                    int u = q.peek();
                    q.poll();
                    vis[u] = true;
                    for (int v : adj[u]) {
                        if (!vis[v]) {
                            q.add(v);
                        }
                    }
                } 
            }
        }
    }
}