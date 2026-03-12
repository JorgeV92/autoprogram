import java.io.*;
import java.util.*;

public class BuildingQueue {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) { adj[i] = new ArrayList<>(); }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            adj[a].add(b);
            adj[b].add(a);
        }

        boolean[] vis = new boolean[n];
        List<Integer> city = new ArrayList<>();
        for (int i = 0; i< n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                city.add(i);
                ArrayDeque<Integer> q = new ArrayDeque<>();
                q.add(i);
                while (!q.isEmpty()) {
                    int v = q.poll();
                    for (int u : adj[v]) {
                        if (!vis[u]) {
                            vis[u] = true;
                            q.add(u);
                        }
                    }
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        ans.append(city.size() -1).append('\n');
        for (int i =0 ;i < city.size() - 1; i++) {
            ans.append(city.get(i) + 1)
                .append(' ')
                .append(city.get(i+1) + 1)
                .append('\n');
        }
        System.out.println(ans);
    }
}