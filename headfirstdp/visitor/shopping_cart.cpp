/*  think of a Shopping cart where we can add different type of items (Elements).
 *  When we click on checkout button, it calculates the total amount to be paid.
 *  in Shopping cart, we provide discounts if the book price > 20, gives 5 Rs discount
 *  and for fruits, gives discount if it's apple
 */

#include <iostream>

class visitor;

struct item
{
    int price;
    virtual int accept(visitor &&sv) = 0;
    item (int price) : price(price) {}
};

struct book : public item
{
    std::string name;
    book(std::string &&name, int price): item(price), name(std::move(name))  {}
    int accept(visitor &&sv) override;
};

struct fruit: public item
{
    std::string name;
    fruit(std::string &&name, int price): item(price), name(std::move(name)) {}
    int accept(visitor &&sv) override;
};

struct visitor
{
    public:
    virtual int visit(book &b) = 0;
    virtual int visit(fruit &f) = 0;
};

int book::accept(visitor &&v)
{
    return v.visit(*this);
}

int fruit::accept(visitor &&v)
{
    return v.visit(*this);
}

struct shopping_cart : public visitor
{
    int visit(book &b) override
    {
        int cost = 0;
        if (b.price > 20)
            cost = b.price - 5; //gives 5% discount
        else cost = b.price;

        return cost;
    }

    int visit(fruit &f) override
    {
        int cost = 0;
        if (f.name == "Apple" and f.price > 30)
            cost = f.price - 10;
        else
            cost = f.price;

        return cost;
    }
};

int main()
{
    book b("C++", 700);
    fruit apple("Apple", 40);

    int total_cost = b.accept(shopping_cart{}) + apple.accept(shopping_cart{});

    std::cout << "total cost: " << total_cost << '\n';


    return 0;
}