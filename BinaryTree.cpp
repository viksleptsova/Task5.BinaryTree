#include <unordered_map>
#include <unordered_set>
#include <iosfwd>
#include <vector>
#include <iostream>
#include "BinaryTree.h"

/**
 * количество четных чисел в дереве,
 * проверка того, что в дереве только положительные числа (в пустом дереве считаем результат true),
 * удаление в дереве всех листьев (при этом листьями станут новые узлы, их не трогаем),
 * среднее арифметическое всех чисел в дереве,
 * поиск заданного элемента x в дереве (если такое число входит в дерево несколько раз, то одного любого вхождения), результат — путь от корня к найденному узлу в виде массива из 0 и 1. Массив можно хранить в виде объекта класса std::vector.
 */

using namespace std;


TreeElem *clearElems(TreeElem *root) {
    if (!root) {
        root->left = clearElems(root->left);
        root->right = clearElems(root->right);
        delete root;
        return nullptr;
    }
}

void BinaryTree::clear(TreeElem *&root) {
    clearElems(root);
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    clear(root);
}


BinaryTree &BinaryTree::operator=(const BinaryTree &obj) {
    if (this != &obj) {
        delete root;
        root = copyTree(obj.root);
    }
    return *this;
}

/**
 * Прямой обход дерева, он же обход сверху вниз
 * @param elem
 * @param out
 */
void BinaryTree::printDown(const TreeElem *elem, ostream &out) {
    if (!elem) { // если дошли до листа
        return; // более ничего не делаем
    }
    cout << elem->info << " "; // распечатать текущий
    printDown(elem->left, out); // распечатать левое поддерево
    printDown(elem->right, out); // распечатать правое поддерево
}

void BinaryTree::print(ostream &out) {
    printDown(root, out);
}

ostream &operator<<(ostream &out, BinaryTree &obj) {
    obj.print(out);
    return out;
}


BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(int value) : root(new TreeElem()) {
    root->info = value;
    root->left = nullptr;
    root->right = nullptr;
}

BinaryTree::BinaryTree(BinaryTree &object) {
    root = copyTree(object.root);
}

bool BinaryTree::operator==(const BinaryTree &rhs) const {
    return root == rhs.root;
}

bool BinaryTree::operator!=(const BinaryTree &rhs) const {
    return !(rhs == *this);
}


bool BinaryTree::insertElem(int x, const vector<bool> &boolArr) {
    if (!root) {
        if (!boolArr.empty()) {
            throw;
        }
        root = new TreeElem;
        root->info = x;
    } else {
        TElem current = root;
        unsigned arrSize = boolArr.size();
        for (unsigned i = 0; i < arrSize; i++) {
            if (i == arrSize - 1) {
                TElem old = current;
                current = new TreeElem;
                boolArr[i] ? old->right = current : old->left = current;
                current->left = nullptr;
                current->right = nullptr;
            } else if (boolArr[i] && current->right != nullptr) {
                current = current->right;
            } else if (!boolArr[i] && current->left != nullptr) {
                current = current->left;
            } else {
                throw;
            }
        }
        current->info = x;
    }
}

unsigned BinaryTree::countOfEven() {
    return count(root);
}

unsigned BinaryTree::count(BinaryTree::TElem e) {
    return (e == nullptr ? 0 : (e->info % 2 == 0) + count(e->left) + count(e->right));
}

bool BinaryTree::allPositive() {
    return allPositive(root);
}

bool BinaryTree::allPositive(const BinaryTree::TElem e) {
    return (e == nullptr ? true : e->info > 0 && allPositive(e->left) && allPositive(e->right));
}


void BinaryTree::deleteLeaves() {
    deleteLeaves(root);
}

bool BinaryTree::deleteLeaves(BinaryTree::TElem elem) {
    if (!elem) {
        return false;
    } else {
        if (elem->right == nullptr && elem->left == nullptr) {
            delete elem;
            return true;
        }
        if (deleteLeaves(elem->left)) {
            elem->left = nullptr;
        }
        if (deleteLeaves(elem->right)) {
            elem->right = nullptr;
        }
        return false;
    }
}

double BinaryTree::arithMean() {
    int value = 0;
    int counter = 0;
    ArithMean(root, value, counter);
    return (double) value / counter;
}


void BinaryTree::ArithMean(TreeElem *elem, int &value, int &counter) {
    if (elem) // если узел существует
    {
        if (elem->info <= 0) {
            ArithMean(root->right, value,
                      counter); // обходим правое поддерево, а в левом нет смысла искать, т.к. значения упорядочены
        } else {
            value += elem->info; // записываем значение узла
            counter++;
            ArithMean(elem->left, value, counter); // обходим левое поддерево
            ArithMean(elem->right, value, counter); // обходим правое поддерево
        }
    }
}

bool BinaryTree::elemSearch(int x) {
    return elemSearch(root, x);
}
bool BinaryTree::elemSearch(TreeElem *root, int x)
{
    if(root->info==x)
        return true;
    else
    if(root->left->info==x)
        return true;
    else
    if(root->right->info==x)
        return true;
    else
        elemSearch(root->left, x);
//и так пока не будет найден искомый элемент
}

/*
вика самая красивая девочка в мире
                <3*/

