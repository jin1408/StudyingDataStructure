#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#define MAX_ELEMENT 200
using namespace std;
//MinHeap을 구현하며 단어의 빈도 수에 따라 그에맞는 코드를 결정할 수 있는 허프만 코드를 구현함
// 기초적인 단계이므로 만들어진 트리로 가변 길이 코드를 만들기 위해서는 추가적인 코드가 필요함

class HeapNode {
	int key;
public:
	HeapNode(int k=0) :key(k){}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() {
		printf("%4d", key);
	}

};

class MinHeap {
	HeapNode node[MAX_ELEMENT];
	int size;
public:
	MinHeap() :size(0) {}
	bool isEmpty(){ return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }
	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i *2]; }
	HeapNode& getRight(int i) { return node[i * 2 +1]; }

	void insert(int key) {
		if (isFull()) return;

		int i = ++size;
		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while(child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child  *= 2;
		}

		node[parent] = last;
		return root;
	}
};

void MakeTree(int freq[], int n) {
	MinHeap heap;
	for (int i = 0; i < n; i++) {
		heap.insert(freq[i]);
	}
		

	for (int i = 1; i < n; i++) {
		HeapNode e1 = heap.remove();
		HeapNode e2 = heap.remove();
		heap.insert(e1.getKey() + e2.getKey());
	}
}

int main(void) {
	
	int freq[] = { 15, 12, 8, 6,4 };
	MakeTree(freq, 5);
	return 0;
}
