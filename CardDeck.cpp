#include "CardDeck.h"

CardDeck::Node::Node(Card* c) : card(c), next(NULL) {}

void CardDeck::Node::print() {
    card->print();
	std::cout<<next<<"\n";
}

CardDeck::CardDeck() : head(NULL) {}

CardDeck::CardDeck(Card* cards[], int n) : head(NULL) {
    buildDeck(cards,n);
}

CardDeck::~CardDeck() {
	Node* cur = head;
	while (cur->next!=NULL && cur->next!=head) {
		Node* t = cur;
		Node* n = cur->next;
		delete t;
		cur = n;
		n = n->next;
	}
	delete cur;
	delete head;
}

void CardDeck::shuffle(Card* cards[],int n) {
    if (n>1) {
        int r = rand() % n;
        Card* temp = cards[r];
        cards[r]=cards[n-1];
        cards[n-1]=temp;
        shuffle(cards,n-1);
    }
}

void CardDeck::removeAfter(Node* prev) {
    Node* cur = prev->next;
    prev->next=cur->next;
    delete cur;
}
    
void CardDeck::insertAfter(Node* prev, Card* c) {
    Node* cur = new Node(c);
    Node* n=prev->next;
    prev->next=cur;
    cur->next=n;
}

void CardDeck::buildDeck(Card* cards[], int n) {
    shuffle(cards,n);
    head = new Node(cards[0]);
    Node* prev = head;
    Node* cur = head->next;
    for (int i=1; i<n; i++) {
        cur = new Node (cards[i]);
        prev->next=cur;
        prev=cur;
        cur=cur->next;
    }
    cur=head;
    prev->next=cur;
}
    
void CardDeck::print(Node* n) {
    if (n!=NULL) {
        n->print();
        if (n->next != head) {
            print(n->next);
        }
    }
}
    
void CardDeck::print() {
    print(head);
    std::cout<<"\n";
}
    
Card* CardDeck::drawCard() {
    Node* n = head->next;
    Card* temp = n->card;
    if (temp->jail) {
        removeAfter(head);
    }
    head=head->next;
    return temp;
}
    
void CardDeck::returnCard(Card* c) {
    if (c->jail) {
        insertAfter(head,c);
        std::cout<<"Returned ";
        c->print();
        std::cout<<"\n";
        head=head->next;
    } else {
        c->print();
        std::cout<<"is not a jail card\n";
    }
}
