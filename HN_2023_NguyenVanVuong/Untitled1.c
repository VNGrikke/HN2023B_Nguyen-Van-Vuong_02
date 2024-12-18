#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

Node* addToHead(Node* head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        return newNode;
    }
    newNode->next = head;
    head->previous = newNode;
    return newNode;
}

Node* addToTail(Node* head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        return newNode;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->previous = tail;
    return head;
}

Node* deleteElementHead(Node* head) {
    if (!head) {
        printf("Danh sach rong\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head) {
        head->previous = NULL;
    }
    free(temp);
    return head;
}

Node* deleteElementTail(Node* head) {
    if (!head) {
        printf("Danh sach rong\n");
        return NULL;
    }
    if (!head->next) {
        free(head);
        return NULL;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->previous->next = NULL;
    free(tail);
    return head;
}

//Node* deleteByValue(Node* head, int value){
//	Node* temp = head;
//	while(temp->data == value){
//		temp = temp->next;
//	}
//	
//}


void printForward(Node* head) {
    if (!head) {
        printf("Danh sach rong\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printBackward(Node* head) {
    if (!head) {
        printf("Danh sach rong\n");
        return;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (tail) {
        printf("%d <-> ", tail->data);
        tail = tail->previous;
    }
    printf("NULL\n");
}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n*********************MENU*********************\n");
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Chen phan tu vao vi tri cu the\n");
        printf("4. Xoa phan tu dau danh sach\n");
        printf("5. Xoa phan tu cuoi danh sach\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Duyet danh sach tu dau den cuoi\n");
        printf("8. Duyet danh sach tu cuoi den dau\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                head = addToHead(head, value);
                break;

            case 2:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                head = addToTail(head, value);
                break;

            case 3:
               	printf("Em chua lam\n")
                break;

            case 4:
                head = deleteElementHead(head);
                break;

            case 5:
                head = deleteElementTail(head);
                break;

            case 6:
                printf("Em chua lam\n")
                break;

            case 7:
                printForward(head);
                break;

            case 8:
                printBackward(head);
                break;

            case 9:
                freeLinkedList(head);
                printf("Thoat chuong trinh\n");
                return 0;

            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }

    return 0;
}

