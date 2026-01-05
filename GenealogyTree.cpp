#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    vector<Person*> children;

    Person(const string &s) : name(s) {};
};

class GenealogyTree {
public:
    GenealogyTree(const string& rootName) {
        root = new Person(rootName);
    }
    ~GenealogyTree() {
        clear(root);
    }
    Person* find(Person* node, const string& name) {
        if (!node) return nullptr;
        if (node->name == name) return node;
        for (Person* c : node->children) {
            return find(c, name);
        }
        return nullptr;
    }
    void addChild(const string&parent, const string&child) {
        Person* p = find(root, parent);
        if (!p) return;
        p->children.push_back(new Person(child));
    }
    void print() const {
        printRec(root, 0);
    }

private:
    Person* root;

    void printRec(Person* node, int depth) const {
        if (!node) return;
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << node->name;
        for (Person* c : node->children)
            printRec(c, depth + 1);
    }
    void clear(Person* node) {
        if (!node) return;
        for (Person* c : node->children) 
            clear(c);
        delete node;
    }
};
