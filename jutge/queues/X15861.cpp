#include <iostream>
#include <queue>

using namespace std;

queue<int> remove01(queue<int> q) {
    int elements = 0;
    queue<int> newQ;
    while (!q.empty()) {
        int elem = q.front();
        if (!(elem == 0 && elements % 2 == 0) && !(elem == 1 && elements % 2 == 1)) newQ.push(elem);
        q.pop();
        ++elements;
    }
    return newQ;
}

int main() {
    return 0;
}