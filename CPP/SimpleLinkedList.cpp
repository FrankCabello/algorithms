#include <iostream>
#include <string>

using namespace std;

typedef string Elem;  // char int string 

class Node {
private:
	Elem elem;
	Node* next;
	friend class LinkedList;
	friend ostream& operator<<(ostream& os, const Node* L);
};

ostream& operator<<(ostream& os, const Node* L) {
	const Node* v = L;
	while (v) {
		os << v->elem << " ";
		v = v->next;
	}
	return os;
}

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	bool isEmpty() const;
	const Elem& front() const;
	void addFront(const Elem& e);
	void removeFront();
	void create(const Elem arr[], int n);
	friend ostream& operator<<(ostream& os, const LinkedList* L);
private:
	Node* head;
};

LinkedList::LinkedList() : head(NULL){}
LinkedList::~LinkedList() { 
	while (!isEmpty()) removeFront(); 
}
bool LinkedList::isEmpty() const { return head == NULL; }
const Elem& LinkedList::front() const { return head->elem; }
void LinkedList::addFront(const Elem& e) {
	Node* v = new Node;
	v->elem = e;
	v->next = head;
	head = v;
}
void LinkedList::removeFront() {
	Node* old = head;
	head = old->next;
	delete old;
}

void LinkedList::create(const Elem arr[], int n) {
	int i = 0;
	while (i < n) addFront(arr[i++]);
}

ostream& operator<<(ostream& os, const LinkedList* L) {
	if (L!=nullptr && L->head) os << L->head;
	return os;
}

int main() {

	//int A[] = { 9,0,8,1,7,2,6,3,5,4 };
	//char A[] = { '9','0','8','1','7','2','6','3','5','4' };
	string A[] = { "9","0","8","1","7","2","6","3","5","4" };
	int sz = sizeof(A) / sizeof(A[0]);

	LinkedList* L = new LinkedList;
	L->create(A, sz);
	cout << L << endl;
	L->removeFront();
	cout << L << endl;
	L->addFront("99");
	cout << L << endl;

	delete L;
	L = nullptr;
	cout << L << endl;

	return 0;
}