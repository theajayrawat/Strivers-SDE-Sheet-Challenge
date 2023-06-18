// Time Complexity: O(N)
//  Space Complexity: O(N)

#include <bits/stdc++.h>
class LRUCache
{
public:
    struct Node
    {
        int key;
        int val;
        struct Node *next;
        struct Node *prev;

        Node(int k, int v)
        {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    int maxSize, currSize;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        maxSize = capacity;
        currSize = 0;
        head = NULL;
        tail = NULL;
    }

    void moveToTail(Node *node, int value)
    {
        node->val = value;
        if (node == tail)
            return;
        if (node == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = tail;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

    Node *addToTail(int key, int value)
    {
        Node *n = new Node(key, value);
        if (!tail)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        currSize++;
        return n;
    }

    void deleteAtHead()
    {
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        else
            tail = head;

        delete (temp);
        currSize--;
    }

    int get(int key)
    {
        int ans;
        if (mp.find(key) == mp.end())
        {
            ans = -1;
        }
        else
        {
            Node *n = mp[key];
            ans = n->val;
            moveToTail(n, ans);
        }
        return ans;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            moveToTail(mp[key], value);
            return;
        }
        if (maxSize > currSize)
        {
            mp[key] = addToTail(key, value);
        }
        else
        {
            mp.erase(head->key);
            deleteAtHead();
            mp[key] = addToTail(key, value);
        }
    }
};
