#include <iostream>
#include <memory>
#include <vector>


class canvas 
{
    std::vector<std::string> shapes;

    struct memento
    {
        const std::vector<std::string> shapes;
        memento(const std::vector<std::string> shapes): shapes(shapes) {}
    };

    std::vector<std::shared_ptr<memento>> changes;
    public:

    void add_shape(const std::string &shape)
    {
        changes.push_back(std::make_shared<memento>(shapes));
        shapes.push_back(shape);
    }

    std::shared_ptr<memento> undo()
    {
        auto prev = changes.back();
        shapes = prev->shapes;

        return prev;
    }

    void clearAll()
    {
        shapes.clear();
    }

    friend std::ostream &operator<<(std::ostream &os, const canvas &c)
    {
        for (const auto &shape: c.shapes)
        {
            os << shape << ",";
        }
        os << '\n';

        return os;
    }
};

int main()
{
    canvas canvas;
    canvas.add_shape("Triangle");
    canvas.add_shape("Circle");
    std::cout << canvas;
    canvas.undo();
    std::cout << canvas;

    return 0;
}