#ifndef LISTCLASS_H
#define LISTCLASS_H
class ListClass
{
    public:
        int vertice;
        int peso;

        ListClass(int v, int p) : vertice(v), peso(p) {}
        ListClass(int v) : vertice(v), peso(1) {}
};

#endif 