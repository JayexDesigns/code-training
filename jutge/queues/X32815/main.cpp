#include <iostream>
#include <queue>

using namespace std;

void reverse(queue<int> &q) {
    if (q.empty()) return;
    int elem = q.front();
    q.pop();
    reverse(q);
    q.push(elem);
}

queue<int> reverseQueue(queue<int> q) {
    reverse(q);
    return q;
}

int main() {
    return 0;
}