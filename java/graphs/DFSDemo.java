import java.util.*;

public class DFSDemo {
    static  List<Integer>[] adj;
    static boolean[] vis;
    static int n = 6;

    public static void main(String[] args) {
        vis = new boolean[n];
        adj = new ArrayList[n];
        for (int i =0 ;i < n; i++) {
            adj[i] = new ArrayList<>(); 
        }
        adj[0] = new ArrayList<>(Arrays.asList(1, 2, 4));
        adj[1] = new ArrayList<>(Arrays.asList(3, 4));
        adj[2] = new ArrayList<>(Arrays.asList(5));

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
    }

    static void dfs(int v) {
        if (vis[v]) return;
        vis[v] = true;
        for (int u : adj[v]) {
            dfs(u);
        }
    }
}