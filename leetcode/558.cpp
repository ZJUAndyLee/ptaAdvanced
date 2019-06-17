class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (quadTree1->isLeaf) {
			if (quadTree1->val) {
				return quadTree1;
			}
			else {
				return quadTree2;
			}
		}
		if (quadTree2->isLeaf) {
			if (quadTree2->val) {
				return quadTree2;
			}
			else {
				return quadTree1;
			}
		}
		Node *tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
		Node *tr = intersect(quadTree1->topRight, quadTree2->topRight);
		Node *bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
		Node *br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
		if (tl->isLeaf&&tr->isLeaf&&bl->isLeaf&&br->isLeaf) {
			if (tl->val&&tr->val&&bl->val&&br->val) {
				Node *tmpnode = new Node(true, true, NULL, NULL, NULL, NULL);
				return tmpnode;
			}
			else if (!tl->val && !tr->val && !bl->val && !br->val) {
				Node *tmpnode = new Node(false, true, NULL, NULL, NULL, NULL);
				return tmpnode;
			}
		}
		Node *node = new Node(false, false, tl, tr, bl, br);
		return node;
	}
};
