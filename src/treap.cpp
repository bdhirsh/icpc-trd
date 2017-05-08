typedef int TreapType;
class Treap {
  public:
    TreapType data;
    long long priority;
    Treap * left, * right;
    int sz;
    Treap(TreapType data) : left(NULL), right(NULL), data(data), sz(0) {
      priority = rand();
    }
    ~Treap() {
      if (left != NULL) { delete left; }
      if (right != NULL) { delete right; }
    }
    Treap * find(TreapType t) {
      if (this->data == t) {
        return this;
      } else if (this->data > t) {
        if (this->left == NULL) return NULL;
        else return this->left->find(t);
      } else {
        if (this->right == NULL) return NULL;
        else return this->right->find(t);
      }
    }
    void insert(TreapType t) {
      if (t <= this->data) {
        if (this->left == NULL) {
          this->left = Treap(t);
        } else {
          this->left->insert(t);
        }
      } else {
        if (this->right == NULL) {
          this->right = Treap(t);
        } else {
          this->right->insert(t);
        }
      }
    }
};
