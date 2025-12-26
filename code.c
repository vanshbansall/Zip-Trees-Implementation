#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------ Node Definition ------------------ */
typedef struct Node {
    int key;
    int rank;
    struct Node* left;
    struct Node* right;
} Node;

/* ------------------ Create New Node ------------------ */
Node* newNode(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->rank = rand();
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* ------------------ Zip ------------------ */
Node* zip(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->rank > b->rank) {
        a->right = zip(a->right, b);
        return a;
    } else {
        b->left = zip(a, b->left);
        return b;
    }
}

/* ------------------ Unzip ------------------ */
void unzip(Node* t, int key, Node** a, Node** b) {
    if (!t) {
        *a = *b = NULL;
        return;
    }

    if (key <= t->key) {
        unzip(t->left, key, a, &t->left);
        *b = t;
    } else {
        unzip(t->right, key, &t->right, b);
        *a = t;
    }
}

/* ------------------ Insert ------------------ */
Node* insert(Node* root, int key) {
    Node *a, *b;
    unzip(root, key, &a, &b);
    Node* n = newNode(key);
    return zip(zip(a, n), b);
}

/* ------------------ Delete ------------------ */
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key == root->key) {
        Node* merged = zip(root->left, root->right);
        free(root);
        return merged;
    }

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);

    return root;
}

/* ------------------ Search ------------------ */
int search(Node* root, int key) {
    if (!root) return 0;
    if (key == root->key) return 1;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

/* ------------------ Inorder ------------------ */
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

/* ------------------ Free Tree ------------------ */
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* ------------------ MAIN (User Input) ------------------ */
int main() {
    srand(time(NULL));
    Node* root = NULL;

    int choice, key;

    while (1) {
        printf("\n--- ZIP TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Key FOUND\n");
            else
                printf("Key NOT FOUND\n");
            break;

        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            freeTree(root);
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
