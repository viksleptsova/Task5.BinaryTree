#ifndef TASK5_BINARYTREE_H
#define TASK5_BINARYTREE_H
#include <vector>

using namespace std;

struct TreeElem { // элемент бинарного дерева
    int info;
    TreeElem *left;
    TreeElem *right;

    TreeElem() : info(0), left(nullptr), right(nullptr) {}

    TreeElem(int theInfo,
             TreeElem *theLeft = nullptr,
             TreeElem *theRight = nullptr) : info(theInfo), left(theLeft), right(theRight) {}
};


class BinaryTree {
public:
    bool operator==(const BinaryTree &rhs) const;

    bool operator!=(const BinaryTree &rhs) const;


    using TElem = TreeElem *;

    BinaryTree();

    BinaryTree(int value);

    BinaryTree(BinaryTree &object);

    virtual ~BinaryTree();

    void clear(TreeElem *&root);

    bool insertElem(int x, const vector <bool> &boolArr);

    TreeElem *copyTree(const TreeElem *elem) {
        if (!elem) { return {}; }
        auto *rootCopy = new TreeElem(elem->info);
        try {
            rootCopy->left = copyTree(elem->left);
            rootCopy->right = copyTree(elem->right);
            return rootCopy;
        } catch (bad_alloc) {
            clear(rootCopy);
            throw; // без параметра означает выбросить повторно то же самое исключение
        }
    }

    friend ostream &operator<<(ostream &out, BinaryTree &obj);

    BinaryTree &operator=(const BinaryTree &obj);

    void printDown(const TreeElem *elem, ostream &out);

    unsigned int countOfEven();

    bool allPositive();

    void deleteLeaves();

    double arithMean();

    bool elemSearch(int x);

private:

    TElem root;

    void print(ostream &out);

    unsigned int count(TElem e);

    bool allPositive(TElem const e);

    bool deleteLeaves(TElem elem);

    void ArithMean(TreeElem *elem, int &value, int &counter);

    bool elemSearch(TreeElem *root, int x);
};


#endif
