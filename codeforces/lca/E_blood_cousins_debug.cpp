#include <iostream>
#include <vector>
#include <algorithm>

int n, q, dfn;

// e[u] = children of node u
std::vector<std::vector<int>> e;

// queries[u] stores indices of queries currently attached to node u
// In dfs1: original queries are attached to the queried node v
// After dfs1: we move each query to the p-th ancestor of v
std::vector<std::vector<int>> queries;

// k[i] = p value for query i
std::vector<int> k;

// stk = current root-to-node path during dfs1
// If we are at node u with depth dep[u], then:
// stk[0] = root, stk[1] = child of root, ..., stk[dep[u]] = u
// So the p-th ancestor of u is stk[dep[u] - p], if it exists
std::vector<int> stk;

// in[u] = compressed index assigned to node u in dfs2
// This index is used so that f[in[u] + d] means:
// "number of nodes in subtree of u at distance d from u"
std::vector<int> in;

// height[u] = height of subtree rooted at u
// Measured in number of levels:
// leaf has height 1
std::vector<int> height;

// dep[u] = depth of node u from its tree root
std::vector<int> dep;

// ans[i]:
// After dfs1: temporarily stores the p-th ancestor of the queried node
//             or -1 if no such ancestor exists
// After dfs2: stores final answer for query i
std::vector<int> ans;

// f[] is the compressed frequency array used in dfs2
// After dfs2(u), we want:
// f[in[u] + d] = number of nodes in subtree of u at distance d from u
std::vector<int> f;

// parent[u] = parent of u, or -1 if u is a root
std::vector<int> parent;

/*
    dfs1(u) does three things:

    1. Uses the current root-to-u path (stk) to answer:
       "what is the p-th ancestor of u?" for every original query attached to u.

    2. Computes height[u].

    3. Reorders children so that the child with maximum height is placed first.
       This first child is treated as the "heavy child" in dfs2.
*/
void dfs1(int u) {
    // Add current node to root->u path
    stk.push_back(u);

    // For every original query attached to u:
    // query i asks about node u and distance k[i]
    for (int i : queries[u]) {
        // If k[i] <= dep[u], then the p-th ancestor exists
        if (k[i] <= dep[u]) {
            // On the path stack, the p-th ancestor is at position dep[u] - k[i]
            ans[i] = stk[dep[u] - k[i]];
        } else {
            // No such ancestor exists
            ans[i] = -1;
        }
    }

    // Base height: if u is a leaf, height[u] stays 1
    height[u] = 1;

    // Visit all children
    for (int &v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);

        // Update subtree height of u
        height[u] = std::max(height[u], height[v] + 1);

        /*
            Reorder children so the child with largest height becomes e[u][0].

            Why?
            In dfs2, the first child is treated as the heavy child.
            Its "distance-count array" will be reused directly by the parent,
            which is what makes the solution fast.

            Since v is taken by reference, swapping v with e[u][0] actually
            changes the order inside e[u].
        */
        if (height[v] > height[e[u][0]])
            std::swap(v, e[u][0]);
    }

    // Remove u from current path when backtracking
    stk.pop_back();
}

/*
    dfs2(u) builds the count structure for subtree u.

    Goal after dfs2(u):
      f[in[u] + d] = number of nodes in subtree of u at distance d from u

    Example:
      f[in[u] + 0] = 1               -> only u itself
      f[in[u] + 1] = #children of u
      f[in[u] + 2] = #grandchildren of u
      ...

    Then for a query attached to u asking for distance k:
      answer = f[in[u] + k] - 1

    Why minus 1?
    Because the queried person themselves is also counted among the nodes
    with the same p-th ancestor, and we must exclude that person.
*/
void dfs2(int u) {
    // Assign compressed index to u
    in[u] = dfn++;

    // Distance 0 from u contains exactly one node: u itself
    f[in[u]] = 1;

    // Process all children
    for (int v : e[u]) {
        dfs2(v);

        /*
            The first child e[u][0] is the heavy child.

            Its data is NOT merged explicitly here.

            Why can we skip merging the heavy child?
            Because the DFS order and the heavy-child-first ordering are chosen
            so that the heavy child's counts are already laid out in f[]
            exactly where the parent wants them, just shifted by 1 in distance.

            So only the light children need to be merged manually.
        */
        if (v != e[u][0]) {
            /*
                For a light child v:
                if there are X nodes at distance i from v,
                then those same nodes are at distance i+1 from u.

                So we do:
                  count_u[i+1] += count_v[i]

                In the compressed array:
                  f[in[u] + i + 1] += f[in[v] + i]
            */
            for (int i = 0; i < height[v]; ++i)
                f[in[u] + i + 1] += f[in[v] + i];
        }
    }

    /*
        Now answer all queries attached to u.

        Important:
        By the time dfs2 runs, queries are no longer attached to the original
        node v. Instead, each query has been moved to the p-th ancestor of v.

        So if query i is now attached to u, it means:
          "Count how many nodes in subtree of u are exactly k[i] below u."

        Those are exactly the nodes having the same p-th ancestor as the
        original queried node.

        We subtract 1 to exclude the original queried node itself.
    */
    for (int i : queries[u])
        ans[i] = f[in[u] + k[i]] - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    e.resize(n);
    queries.resize(n);
    f.resize(n);
    in.resize(n);
    height.resize(n);
    dep.resize(n);
    stk.reserve(n);
    parent.resize(n);

    // Read parent array and build child lists
    for (int i = 0; i < n; ++i) {
        std::cin >> parent[i];
        --parent[i]; // input uses 1-based parents; 0 becomes -1 (root)

        if (parent[i] != -1)
            e[parent[i]].push_back(i);
    }

    std::cin >> q;
    k.resize(q);
    ans.resize(q);

    /*
        Read original queries.

        Query i = (u, k[i])
        For now, attach it to node u.
        dfs1 will later find the k[i]-th ancestor of u.
    */
    for (int i = 0; i < q; ++i) {
        int u;
        std::cin >> u >> k[i];
        --u;
        queries[u].push_back(i);
    }

    /*
        First pass over every tree root:
        - compute depths
        - find p-th ancestors for every query
        - compute subtree heights
        - reorder children so heavy child is first
    */
    for (int i = 0; i < n; ++i)
        if (parent[i] == -1)
            dfs1(i);

    /*
        Now we no longer need queries attached to original nodes.
        We will rebuild queries so they are attached to the p-th ancestor instead.
    */
    for (int i = 0; i < n; ++i)
        queries[i].clear();

    /*
        After dfs1:
          ans[i] = p-th ancestor of original queried node, or -1 if none exists.

        If no such ancestor exists:
          answer is 0 immediately.

        Otherwise:
          move query i to that ancestor node.

        Why?
        Because now the query becomes:
          "In the subtree of this ancestor, how many nodes are k[i] levels below?"
        which is exactly what dfs2 can answer.
    */
    for (int i = 0; i < q; ++i) {
        if (ans[i] == -1) {
            ans[i] = 0;
        } else {
            queries[ans[i]].push_back(i);
        }
    }

    /*
        Second pass over every root:
        build the distance-count structure and answer all moved queries.
    */
    for (int i = 0; i < n; ++i)
        if (parent[i] == -1)
            dfs2(i);

    // Output final answers
    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << " \n"[i == q - 1];

    return 0;
}