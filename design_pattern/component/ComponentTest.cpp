#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

class Leaf;
class Composite;

class Component
{
protected:
    string name;

public:
    virtual void add(Component *component) = 0;
    virtual void remove(Component *component) = 0;
    virtual void display(int depth) = 0;
};

class Leaf : public Component
{
public:
    void add(Component *component)
    {
        cout << "cannot add node" << endl;
    }
    void remove(Component *component)
    {
        cout << "cannot remove node" << endl;
    }
    void display(int depth)
    {
        for (size_t i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << this->name << endl;
    }
    Leaf(string name)
    {
        this->name = name;
    }
};

class Composite : public Component
{
private:
    vector<Component *> components;

public:
    void add(Component *component)
    {
        components.push_back(component);
    }
    void remove(Component *component)
    {
        auto it = find(components.begin(), components.end(), component);
        if (it != components.end())
        {
            components.erase(it);
        }
    }
    void display(int depth)
    {
        for (size_t i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << this->name << endl;
        for (auto component : components)
        {
            if (component)
            {
                component->display(depth + 2);
            }
        }
    }
    Composite(string name)
    {
        this->name = name;
    }
};

int main()
{
    Composite *compsite = new Composite("root");
    compsite->add(new Leaf("Leaf A"));
    compsite->add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->add(new Leaf("Leaf XA"));
    comp->add(new Leaf("Leaf XB"));
    compsite->add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->add(new Leaf("Leaf XYA"));
    comp2->add(new Leaf("Leaf XYB"));
    comp->add(comp2);

    Leaf *leaf = new Leaf("Leaf C");
    compsite->add(leaf);

    Leaf *leaf2 = new Leaf("Leaf D");
    compsite->add(leaf2);
    compsite->remove(leaf2);

    compsite->display(1);
    return 0;
}