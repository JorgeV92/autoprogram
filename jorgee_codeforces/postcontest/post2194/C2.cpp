#include <iostream>
#include <vector>
#include <string>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 =  unsigned __int128;

// Helper function to print a bitmask as actual characters
void print_mask(int mask) {
    std::cout << "{ ";
    for (int i = 0; i < 26; i++) {
        if ((mask >> i) & 1) {
            std::cout << (char)('a' + i) << " ";
        }
    }
    std::cout << "}\n";
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(k);
    for (int i = 0; i < k; i++){
        std::cin >> s[i];
    }
    
    std::cout << "\n--- Starting new test case with n=" << n << ", k=" << k << " ---\n";

    for (int d = 1; d <= n; d++) {
        if (n % d) {
            continue; // Skip if d doesn't divide n
        }
        
        std::cout << "\n>>> Testing period (informativity) d = " << d << " <<<\n";
        std::string t;
        
        for (int j = 0; j < d; j++) {
            std::cout << "  Building pattern character at position j = " << j << "\n";
            int a = (1 << 26) - 1; // Start with all letters allowed
            
            for (int x = j; x < n; x += d) {
                std::cout << "    Checking full string index x = " << x << "\n";
                int b = 0;
                for (int i = 0; i < k; i++) {
                    b |= 1 << (s[i][x] - 'a');
                }
                std::cout << "      Letters available across all strips at index " << x << ": ";
                print_mask(b);
                
                a &= b; // Intersect current valid options with new options
                std::cout << "      Running intersection of valid letters for pattern position " << j << ": ";
                print_mask(a);
            }
            
            if (!a) {
                std::cout << "  [!] Intersection is empty. No valid letter found for pattern position " << j << ".\n";
                break; // Impossible to form pattern of length d
            }
            
            char selected_char = 'a' + __builtin_ctz(a);
            t += selected_char;
            std::cout << "  -> Selected letter '" << selected_char << "' for pattern position " << j << "\n";
            std::cout << "  -> Current pattern built so far: \"" << t << "\"\n";
        }
        
        if (t.size() < d) {
            std::cout << ">>> Period d = " << d << " FAILED.\n";
            continue;
        }
        
        std::cout << "\n>>> SUCCESS! Found valid base pattern: \"" << t << "\"\n";
        while (t.size() < n) {
            t += t.substr(0, d);
        }
        std::cout << "Final repeated string: " << t << "\n";
        return; // We found the minimum d, so we are done
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }    
}