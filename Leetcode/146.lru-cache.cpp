/** 46. LRU Cache
 *  @brief Using HashmapLinkedList, very hard question, spends me whole day
 */
class Node {
public:
    Node *prev;
    Node *next;
    int key;
    int value;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node *> map;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;

    void deleteNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNodeToFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        Node *target = map[key];
        deleteNode(target);
        addNodeToFront(target);
        map[key] = head->next;
        return target->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *target = map[key];
            deleteNode(target);
            target->value = value;
            addNodeToFront(target);
            map[key] = head->next;
        } else {
            Node *newNode = new Node(key, value);
            if (map.size() == cap) {
                Node *prev = tail->prev;
                deleteNode(prev);
                map.erase(prev->key);
            }
            addNodeToFront(newNode);
            map[key] = newNode;
        }
    }
};
