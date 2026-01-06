#include <iostream>
#include <queue>
using namespace std;

struct Client {
    int arrival;
    int service;
};

int main() {
    queue<Client> q;
    int K = 3;               // максимальная очередь
    int freeAt = 0;
    int served = 0, left = 0;
    int totalWait = 0;

    Client clients[] = {
        {0, 5},
        {1, 3},
        {2, 4},
        {6, 2}
    };

    for (Client c : clients) {
        if (c.arrival >= freeAt && q.empty()) {
            freeAt = c.arrival + c.service;
            served++;
        } else {
            if (q.size() < K) {
                q.push(c);
            } else {
                left++;
            }
        }

        while (!q.empty() && freeAt <= c.arrival) {
            Client next = q.front(); q.pop();
            totalWait += freeAt - next.arrival;
            freeAt += next.service;
            served++;
        }
    }

    cout << "Обслужено: " << served << endl;
    cout << "Ушло: " << left << endl;
    cout << "Среднее ожидание: "
         << (served ? totalWait / served : 0) << endl;
}