#include <iostream>
#include <vector>
#include "BinaryTree.h"

using namespace std;

void test1() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(5, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    if (binaryTree1.allPositive() == 1) {
        cout << "All elements positive!!" << endl;
    } else { cout << "Not positive :("; }

}

void test2() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(5, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    BinaryTree binaryTree2(binaryTree1);

    cout << "Copy constructor test (Expected: 1 3 4 5, Actual: " << binaryTree2 << ")" << endl;
}

void test3() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(2, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    cout << "Count of even elements (Expected:2, Actual: " << binaryTree1.countOfEven() << ")" << endl;
}

void test4() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(2, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);


    vector<bool> arr2{};
    BinaryTree binaryTree2(5);

    binaryTree2 = binaryTree1;
    cout << "Equals operator test (Expected:1 3 4 2, Actual: " << binaryTree2 << ")" << endl;
}

void test5() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(2, arr1);
    arr1.pop_back();
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    binaryTree1.deleteLeaves();
    cout << binaryTree1 << endl;
}

void test6() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(2);
    arr1.push_back(true);
    binaryTree1.insertElem(3, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    cout << "Average (Expected: 3, Actual: " << binaryTree1.arithMean() << ")" << endl;
}

void test7() {
    vector<bool> arr1{};
    BinaryTree binaryTree1(1);
    arr1.push_back(true);
    binaryTree1.insertElem(2, arr1);
    arr1.pop_back();
    arr1.push_back(false);
    binaryTree1.insertElem(3, arr1);
    arr1.push_back(true);
    binaryTree1.insertElem(4, arr1);

    if(binaryTree1.elemSearch(2)==1){
        cout<<"Element is found";
    }
}


/*void test2(){
    string str0 = "0";
    string str1 = "1";
    string str10 = "10";
    auto element = new TreeElem();
    auto tree = new BinaryTree(10);
    cout << tree << endl;
    tree->insertElem(element, 11, str0);
    cout << tree << endl;
};*/

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}

