class Node {
public:
    int value;
    string url;
    Node* prev;
    Node* next;
    Node(string u) {
        url = u;
        next = prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* tail;
    Node* curr;
    BrowserHistory(string homepage) {
        head = new Node(" ");
        tail = new Node(" ");
        head->next = tail;
        tail->prev = head;
        curr = head;

        Node* newNode = new Node(homepage);
        head->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
        newNode->prev = head;
        curr = newNode;
    }

    void visit(string url) {
        Node* temp = curr->next;
        while (temp != tail) {
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        curr->next = tail;
        tail->prev = curr;

        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = tail;
        tail->prev = newNode;

        curr = newNode;
    }

    string back(int steps) {
        while (steps-- && curr->prev != head) {
            curr = curr->prev;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (steps-- && curr->next != tail) {
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */