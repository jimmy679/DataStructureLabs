void FindKthNode(BiTree *root, int k) {
    std::stack<BiTree*> nodeStack;
    BiTree *current = root;
    int count = 0;
    
    while (!nodeStack.empty() || current != NULL) {
        while (current != NULL) {
            nodeStack.push(current);
            current = current->lchild;
        }
        
        current = nodeStack.top();
        nodeStack.pop();
        
        // 当前访问的是第count+1个节点
        if (++count == k) {
            printf("第%d个位置的节点为: %c\n", k, current->data);
            return;
        }
        
        current = current->rchild;
    }
    
    printf("在给定的二叉树中找不到第%d个节点。\n", k);
}
