#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    PQueue<int> queue(5);
    Node<int> noda(12, 5);
    queue.push(noda);
    Node<int> noda2(18, 3);
    queue.push(noda2);
    Node<int> noda3(15, 12);
    queue.push(noda3);
    Node<int> noda4(1, 9);
    queue.push(noda4);
    Node<int> noda5(43, 1);
    queue.push(noda5);
    queue.Show();
    cout << "Peek() :: " << queue.Peek().data << "(" << queue.Peek().pr << ")" << endl;

    queue.pop();
    queue.Show();
    queue.pop();
    queue.Show();
}

