struct Node {
    int val;
    Node* left;
    Node* right;
};

// Возвращает высоту дерева, если AVL, иначе -1
int checkAVL(Node* root) {
    if (!root) return 0; // пустое дерево — высота 0

    int leftHeight = checkAVL(root->left);
    if (leftHeight == -1) return -1; // левое поддерево не AVL

    int rightHeight = checkAVL(root->right);
    if (rightHeight == -1) return -1; // правое поддерево не AVL

    if (abs(leftHeight - rightHeight) > 1) return -1; // нарушение AVL

    return max(leftHeight, rightHeight) + 1; // возвращаем высоту
}

bool isAVL(Node* root) {
    return checkAVL(root) != -1;
}