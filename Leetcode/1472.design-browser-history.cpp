/** 1472. Design Browser History
 *  @brief Using two stack
 */
class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();
    }

    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }

    string back(int steps) {
        while (steps-- != 0 && history.size() != 1) {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }

    string forward(int steps) {
        while (steps-- != 0 && future.size() != 0) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};

/**
 *  @brief Using double Linkedlist
 */
// class Node {
// public:
//     Node *prev = nullptr;
//     Node *next = nullptr;
//     const string url;

//     Node(const string &url) : url(url) {}
// };

// class BrowserHistory {
// private:
//     Node *current = nullptr;

// public:
//     BrowserHistory(string homepage) {
//         current = new Node(homepage);
//     }
//     void visit(string url) {
//         current->next = new Node(url);
//         current->next->prev = current;
//         current = current->next;
//     }
//     string back(int steps) {
//         while (steps-- != 0 && current->prev != nullptr)
//             current = current->prev;

//         return current->url;
//     }
//     string forward(int steps) {
//         while (steps-- != 0 && current->next != nullptr)
//             current = current->next;

//         return current->url;
//     }
// };

/**
 *  @brief Using vector
 */
// class BrowserHistory {
// public:
//     vector<string> history;
//     int cur = 0;
//     BrowserHistory(string homepage) {
//         history.push_back(homepage);
//     }

//     void visit(string url) {
//         cur++;
//         if (cur <= history.size() - 1) {
//             history[cur] = url;
//             history.resize(cur + 1);
//         } else
//             history.push_back(url);
//     }
//     string back(int steps) {
//         cur -= steps;
//         if (cur < 0)
//             cur = 0;
//         return history[cur];
//     }

//     string forward(int steps) {
//         cur += steps;
//         if (cur > history.size() - 1)
//             cur = history.size() - 1;
//         return history[cur];
//     }
// };
