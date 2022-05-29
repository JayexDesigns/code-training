#include <queue>

using namespace std;

// Pre: Rep dues cues d'enters positius q1 i q2.
// Post: Retorna una cua, on al seu front hi ha el màxim dels fronts de q1,q2, després,
// en segon lloc el màxim dels segons llocs de q1,q2, i així successivament.
// Quan una de les dues cues no té valors definits en alguna posició, la cua resultant hi té
// el valor de l'altra cua en aquella posició.
queue<int> maximumQueue(queue<int> q1,queue<int> q2) {
    queue<int> newQ;
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty() && !q2.empty()) {
            if (q1.front() >= q2.front()) newQ.push(q1.front());
            else newQ.push(q2.front());
            q1.pop();
            q2.pop();
        }
        else if (q1.empty() && !q2.empty()) {
            newQ.push(q2.front());
            q2.pop();
        }
        else if (!q1.empty() && q2.empty()) {
            newQ.push(q1.front());
            q1.pop();
        }
    }
    return newQ;
}

int main() {
    return 0;
}