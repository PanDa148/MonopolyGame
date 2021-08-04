#pragma once
#include "Card.h"
#include <cstdlib>

class CardDeck {
    private:
    class Node {
        public:
        Card* card;
        Node* next;
        Node(Card* c);
        void print();
    };
    void shuffle(Card* cards[],int n);
    void removeAfter(Node* prev);
    void insertAfter(Node* prev, Card* c);
    Node* head;
    void print(Node* n);

    public:
    CardDeck();
    CardDeck(Card* cards[], int n);
    ~CardDeck();
    void buildDeck(Card* cards[], int n);
    void print();
    Card* drawCard();
    void returnCard(Card* c);
};
