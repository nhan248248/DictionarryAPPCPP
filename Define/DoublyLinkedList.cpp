#include "../Declare/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
  head = NULL;
}
DoublyLinkedList::DoublyLinkedList(Node *n)
{
  head = n;
}

DoublyLinkedList::~DoublyLinkedList() {
    // Hủy danh sách và giải phóng bộ nhớ
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty() const
{
  return head == nullptr;
}

void DoublyLinkedList::append(const Word &word)
{
  Node *newNode = new Node(word);
  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

Word DoublyLinkedList::at(int index) {
        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            return current->data;
        } else {
            return Word();
        }
}

int DoublyLinkedList::size() const {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void DoublyLinkedList::swapNodes(DoublyLinkedList* list, int i, int j) {
    // Kiểm tra nếu i và j có giá trị hợp lệ
    if (i < 0 || j < 0 || i == j) {
        return;
    }

    // Tìm node tại vị trí i và j
    Node* nodeI = list->head;
    for (int k = 0; k < i; k++) {
        nodeI = nodeI->next;
    }

    Node* nodeJ = list->head;
    for (int k = 0; k < j; k++) {
        nodeJ = nodeJ->next;
    }

    // Swap dữ liệu giữa hai node
    Word temp = nodeI->data;
    nodeI->data = nodeJ->data;
    nodeJ->data = temp;
}

bool DoublyLinkedList::compareFirstLetter(const Word& word1, const Word& word2) {
    char firstLetter1 = tolower(word1.getName()[0]);
    char firstLetter2 = tolower(word2.getName()[0]);
    return firstLetter1 < firstLetter2;
}

void DoublyLinkedList::quickSort(DoublyLinkedList* listWords, int left, int right) {
    int i, j;
    if (left >= right) return;

    // Chọn pivot từ danh sách
    Node* pivotNode = listWords->head;
    for (int k = 0; k < (left + right) / 2; k++) {
        pivotNode = pivotNode->next;
    }
    Word pivot = pivotNode->data;

    i = left;
    j = right;

    do {
        while (compareFirstLetter(listWords[i].head->data, pivot)) i++;
        while (compareFirstLetter(pivot, listWords[j].head->data)) j--;

        if (i <= j) {
            // Swap các node trong danh sách liên kết đôi, không phải swap listWords[i] và listWords[j]
            swapNodes(listWords, i, j);
            i++;
            j--;
        }
    } while (i < j);

    if (left < j) quickSort(listWords, left, j);
    if (right > i) quickSort(listWords, i, right);
}