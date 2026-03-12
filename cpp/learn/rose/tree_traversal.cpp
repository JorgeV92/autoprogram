#include <iostream>
#include <memory>
#include <queue>

template<typename T>
class node {
public:
    node(T value) : value_(value) {}
    node(T value, std::unique_ptr<node>&& left) 
        : value_(value), left_(std::move(left)) {}
    node (T value, std::unique_ptr<node>&& left, std::unique_ptr<node>&& right) 
        : value_(value), left_(std::move(left)), right_(std::move(right)) {}

    template<typename Function> 
    void preorder(Function f) {
        f(value_);
        if (left_)
            left_->preorder(f);
        if (right_)
            right_->preorder(f);
    }

    template<typename Funciton>
    void inorder(Funciton f) {
        if (left_) 
            left_->inorder(f);
        f(value_);
        if (right_)
            right_->inorder(f);
    }

    template<typename Function>
    void postorder(Function f) {
        if (left_)
            left_->postorder(f);
        if (right_)
            right_->postorder(f);
        f(value_);
    } 

    template<typename Function>
    void levelorder(Function f) {
        std::queue<node*> queue;
        queue.push(this);
        while (!queue.empty()) {
            node* next = queue.front();
            queue.pop();
            f(next->value_);
            if (next->left_)
                queue.push(next->left_.get());
            if (next->right_)
                queue.push(next->right_.get());
        }
    }

private:
    T value_;
    std::unique_ptr<node> left_;
    std::unique_ptr<node> right_;
};

template<typename T, typename... Args> 
std::unique_ptr<node<T>>
tree(T value, Args&&... args) {
    return std::make_unique<node<T>>(value, std::forward<Args>(args)...);
}

int main() {
    node<int> n(1,
                tree(2,
                     tree(4,
                          tree(7)),
                     tree(5)),
                tree(3,
                     tree(6,
                          tree(8),
                          tree(9))));

    auto print = [](int n) { std::cout << n << ' '; };

    std::cout << "pre-order:   ";
    n.preorder(print);
    std::cout << '\n';

    std::cout << "in-order:    ";
    n.inorder(print);
    std::cout << '\n';

    std::cout << "post-order:  ";
    n.postorder(print);
    std::cout << '\n';

    std::cout << "level-order: ";
    n.levelorder(print);
    std::cout << '\n';
}