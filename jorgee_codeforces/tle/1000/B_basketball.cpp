#include <iostream>
#include <vector>
#include <algorithm>

// int main() {
//     std::ios::sync_with_stdio(0); std::cin.tie(0);
//     int n, d;
//     std::cin >> n >> d;
//     std::vector<int> p(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> p[i];
//     }
//     std::sort(p.begin(), p.end(), std::greater());
//     int r = n;
//     int ans = 0;
//     for (int l = 0; l < r; l++) {
//         int t = d / p[l] + 1;
//         if (r -l < t) break;
//         r -= t-1;
//         ans++;
//     }
//     std::cout << ans << '\n';
    
//     return 0;
// }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) std::cin >> p[i];

    std::sort(p.begin(), p.end(), std::greater<int>());

    // Print sorted powers
    std::cout << "[debug] sorted p: ";
    for (int x : p) std::cout << x << ' ';
    std::cout << "\n";

    int r = n;      // exclusive right boundary of remaining players
    int ans = 0;

    for (int l = 0; l < r; l++) {
        int maxPower = p[l];
        int t = d / maxPower + 1;     // minimum team size needed if max is p[l]
        int remaining = r - l;

        std::cout << "\n[debug] iteration start\n";
        std::cout << "  l = " << l << ", r = " << r << " (remaining players = " << remaining << ")\n";
        std::cout << "  chosen maxPower = p[l] = " << maxPower << "\n";
        std::cout << "  need team size t = floor(d/maxPower)+1 = " << t
                  << "  (because " << t << "*" << maxPower << " > " << d << ")\n";

        if (remaining < t) {
            std::cout << "  BREAK: remaining (" << remaining << ") < t (" << t
                      << "), can't form a winning team.\n";
            break;
        }

        // We will use indices [l] plus (t-1) weakest players from the right end: [r-(t-1) .. r-1]
        int take_from_right = t - 1;
        int right_start = r - take_from_right; // first index taken from right side

        std::cout << "  Form a team of size " << t << " using:\n";
        std::cout << "    captain index l=" << l << " (power " << p[l] << ")\n";
        if (take_from_right > 0) {
            std::cout << "    plus " << take_from_right << " weakest from the right indices ["
                      << right_start << ".." << (r - 1) << "]: ";
            for (int i = right_start; i < r; i++) std::cout << p[i] << ' ';
            std::cout << "\n";
        } else {
            std::cout << "    plus none from the right (t=1)\n";
        }

        // Consume those (t-1) players from the right
        r -= take_from_right;
        ans++;

        std::cout << "  After consuming right side: new r = " << r << "\n";
        std::cout << "  wins so far = " << ans << "\n";
    }

    std::cout << "\nanswer = " << ans << "\n";
    return 0;
}