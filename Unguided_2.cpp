#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;  // untuk melacak jumlah elemen dalam antrian
    const int maksimalQueue;

public:
    Queue(int size) : front(nullptr), rear(nullptr), count(0), maksimalQueue(size) {}

    bool isFull() {
        return count == maksimalQueue;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(string nama, string nim) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
        } else {
            Node* newNode = new Node{nama, nim, nullptr};
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            count++;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            cout << "Dequeued: " << temp->nama << " (" << temp->nim << ")" << endl;
            delete temp;
            count--;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            index++;
        }
        for (; index <= maksimalQueue; index++) {
            cout << index << ". (kosong)" << endl;
        }
    }
};

int main() {
    Queue queue(5); // membuat antrian dengan maksimal 5 elemen

    queue.enqueue("Andi", "21102320");
    queue.enqueue("Maya", "2211102003");
    queue.enqueue("Toyo", "20112032");
    queue.enqueue("Dodo", "2311103146");
    queue.enqueue("Agus", "21102183");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}