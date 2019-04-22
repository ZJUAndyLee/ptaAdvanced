//这个题要重新生成一个图返回和原图完全一样的图 并且所有的结点都必须重新申请内存生成
class Solution {
public:
  Node* cloneGraph(Node* node) {
	unordered_map<Node *, Node *> vis;//给一个散列来判断结点是否被访问过
	Node *root = new Node;
	root->val = node->val;
	vis.insert(pair<Node *, Node *>(node, root));
	queue<Node *> qMain;
	queue<Node *> qCopy;
	qMain.push(node);
	qCopy.push(root);
	while (!qMain.empty()) {
		Node *tmp = qMain.front();
		qMain.pop();
		Node *tmpc = qCopy.front();
		qCopy.pop();
		for (auto x : tmp->neighbors) {
			if (vis.find(x) != vis.end()) {
				tmpc->neighbors.push_back(vis[x]);
			}
			else {
				Node *tmpnode = new Node;
				tmpnode->val = x->val;
				tmpc->neighbors.push_back(tmpnode);
				qCopy.push(tmpnode);
				qMain.push(x);
				vis.insert(pair<Node *, Node *>(x, tmpnode));//每次访问过了的结点直接被散列表标记然后进队列 这样也就保证每个结点只有一次机会进入队列
			}
		}
	}
	return root;
}
};
