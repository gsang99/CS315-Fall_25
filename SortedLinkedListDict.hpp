#pragma once
#include "Dictionary.hpp"

class SortedLinkedListDict : public Dictionary {
public:
    void insert(int value) override;
    bool lookup(int value) const override;
    void remove(int value) override;

private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
};