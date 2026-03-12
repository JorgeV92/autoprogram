#include <chrono>
#include <concepts>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

template<typename T>
concept Streamable = requires(std::ostream& os, const T& x) {
    { os << x } -> std::same_as<std::ostream&>;
};

template<Streamable... Args> 
std::string join_to_string(std::string_view sep, Args&&... args) {
    std::ostringstream oss;

    bool first = true;
    auto add_one = [&](auto&& x) {
        if (!first) oss << sep;
        first = false;
        oss << std::forward<decltype(x)>(x);
    };

    (add_one(std::forward<Args>(args)), ...);

    return oss.str();
}

class ScopedTimer {
public: 
    explicit ScopedTimer(std::string label)
        : label_(std::move(label)),
          start_(std::chrono::steady_clock::now()) {}

    ~ScopedTimer() {
        using namespace std::chrono;
        auto end = steady_clock::now();
        auto ms = duration_cast<microseconds>(end - start_).count() / 1000.0;
        std::cout << "[TIMER] " << label_ << " took" 
                << std::fixed << std::setprecision(3) << ms << " ms\n";
    }
private:
    std::string label_;
    std::chrono::steady_clock::time_point start_;
};

template<Streameable... Args>
void log(std::string_view tag, Args&&... args) {
    std::cout << "[" << tag << "] "
              << join_to_string(" ", std::forward<Args>(args)...)
              << "\n";
}

template<typename F, typename... Args>
requires std::invocable<F, Args...>
decltype(auto) time_call(std::string label, F&& f, Args&&... args) {
    ScopedTimer timer(std::move(label));
    return std::invoke(std::forwad<F>(f), std::forward<Args>(args)...);
}

int add(int a, int b) { return a + b; }

struct Math {
    int mul(int a, int b) const { return a * b; }
};

int main() {
    log("INFO", "starting", 42, 3.14);
    int s = time_call("add()", add, 10 , 32);
    log("RESULT", "sum = ",  s);

    auto slow = [](int n) {
        long long acc =0 ;
        for (int i = 0 ; i < n; i++) acc += i;
        return acc;
    };

    auto v = time_call("slow lambda", slow, 50'000'000);
    log("RESULT", "acc = ", v);

    Math m ;
    int p = time_call("member funciton mul()", &Math::mul, m, 6 ,7);
    log("RESULT", "prod = ", p);
    return 0;
}