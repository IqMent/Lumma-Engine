//
// Created by iqment on 3/9/25.
//

#include <vector>
#include <iostream>
#include <unordered_map>


class VirtualMachine {
private:
    std::vector<int> stack;
    std::unordered_map<int, int> memory;

public:
    void push(int value) { stack.push_back(value); }
    int pop() {
        if (stack.empty()) throw std::runtime_error("Stack underflow!");
        int value = stack.back();
        stack.pop_back();
        return value;
    }

    void execute(std::vector<int> bytecode) {
        for (int op : bytecode) {
            switch (op) {
                case 1: push(10); break;
                case 2: std::cout << "POP: " << pop() << std::endl; break;
                default: std::cerr << "Unknown opcode: " << op << std::endl;
            }
        }
    }
};

int main() {
    VirtualMachine vm;
    std::vector<int> bytecode = {1, 1, 2, 2};
    vm.execute(bytecode);
    return 0;
}