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

int parse(ListNode* lst) {
	ListNode* it = lst;
	int num = 0;
	int i = 0;
	while(it != NULL) {
		num += it->val * pow(10,i);
		i++;
		it = it->next;
	}
	return num;
}

ListNode* unParse(int n) {
	ListNode* head = NULL;
	ListNode* tail;
	ListNode* curr;

	int remainder = 0;
	if(n == 0) return new ListNode(n);
	while(n > 0) {
		remainder = n % 10;
		n = (n-remainder)/10;

		if(!head) {
			head = new ListNode(remainder);
			tail = head;
		} else {
			curr = new ListNode(remainder);
			tail->next = curr;
			tail = curr;
		}
	}

	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int num1 = 0, num2 = 0;
	num1 = parse(l1);
	num2 = parse(l2);
	cout << "num1 + num2 = " << num1 + num2 << endl;
	return NULL;
	return unParse(num1 + num2);
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
	addTwoNumbers(l1, l2);

	// printLL(addTwoNumbers(l1, l2));
}

int main() {
	cout << "Sum 2 numbers" << endl;
	// tc1();
	// tc2();
	// tc3();
	tc4();	// Overflow happens
	return 0;
}
