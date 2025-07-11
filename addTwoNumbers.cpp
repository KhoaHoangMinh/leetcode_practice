#include <iostream>
#include <math.h>

using namespace std;

struct ListNode {
  	int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLL(int* arr, int size) {
	ListNode* head;
	ListNode* tail;
	ListNode* curr;
	for(int i = 0; i < size; i++) {
		if(i == 0) {
			head = new ListNode(*arr);
			tail = head;
		} else {
			curr = new ListNode(*arr);
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
		}
		arr++;
	}
	tail->next = NULL;
	return head;
}

void printLL(ListNode* ll) {
	ListNode* it = ll;
	while(it != NULL) {
		cout << it->val << ' ';
		it = it->next;
	}
	cout << endl;
}

void append(ListNode*& lst, ListNode*& tail, int val) {
	if(!lst) {
		lst = new ListNode(val);
		tail = lst;
	}
	else {
		ListNode* curr = new ListNode(val);
		tail->next = curr;
		tail = curr;
	}
}

ListNode* process(ListNode* l1, ListNode* l2) {
	ListNode* result = NULL;
	ListNode* tail;
	ListNode* it1 = l1;
	ListNode* it2 = l2;
	bool carry = false;
	int sum = 0;
	while( it1 && it2) {
		sum = it1->val + it2->val;
		if(carry) {
			sum++;
			carry = false;
		};
		if(sum >=10) {
			carry = true;
			sum %= 10;
		};
		append(result, tail, sum);
		it1 = it1->next;
		it2 = it2->next;
	}
	while(it1) {
		sum = (carry) ? it1->val + 1 : it1->val;
		if(sum >= 10) {
			sum %= 10;
			carry = true;
		} else carry = false;
		append(result, tail, sum);
		it1 = it1->next;
	}
	while(it2) {
		sum = (carry) ? it2->val + 1 : it2->val;
		if(sum >= 10) {
			sum %= 10;
			carry = true;
		} else carry = false;
		append(result, tail, sum);
		it2 = it2->next;
	}
	if(carry) append(result, tail, carry);
	return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	return process(l1, l2);
}

void tc1() {
	int n1 = 3;
	int arr1[] = {2, 4, 3};
	ListNode* l1 = createLL(arr1, n1);

	int n2 = 3;
	int arr2[] = {5, 6, 4};
	ListNode* l2 = createLL(arr2, n2);
	printLL(addTwoNumbers(l1, l2));
}

void tc2() {
	int n1 = 1;
	int arr1[] = {0};
	ListNode* l1 = createLL(arr1, n1);

	int n2 = 1;
	int arr2[] = {0};
	ListNode* l2 = createLL(arr2, n2);

	printLL(addTwoNumbers(l1, l2));
}

void tc3() {
	int n1 = 7;
	int arr1[] = {9,9,9,9,9,9,9};
	ListNode* l1 = createLL(arr1, n1);

	int n2 = 4;
	int arr2[] = {9,9,9,9};
	ListNode* l2 = createLL(arr2, n2);

	printLL(addTwoNumbers(l1, l2));
}

void tc4() {
	int n1 = 1;
	int arr1[] = {9};
	ListNode* l1 = createLL(arr1, n1);

	int n2 = 10;
	int arr2[] = {1,9,9,9,9,9,9,9,9,9};
	ListNode* l2 = createLL(arr2, n2);

	printLL(l1);
	printLL(l2);
	printLL(addTwoNumbers(l1, l2));
}

int main() {
	cout << "Sum 2 numbers" << endl;
	tc1();
	// tc2();
	// tc3();
	// tc4();
	return 0;
}
