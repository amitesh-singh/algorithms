#include <iostream>

struct Ivisitor;

class person
{
   std::string name_;
   int age_;

  public:
   person(std::string &&name, int age): name_(std::move(name)), age_(age) {}
   void accept(Ivisitor &&v);
   void accept(Ivisitor &v);
   friend class write_to_db;
   friend class write_to_txt;
   friend class write_to_json;
};

class landmark
{
   std::string name_;
   std::string city_;
  public:
   landmark(std::string &&name, std::string &&city):
       name_(std::move(name)), city_(std::move(city)) {}
   void accept(Ivisitor &&v);
   friend class write_to_db;
   friend class write_to_txt;
   friend class write_to_json;
};

class car
{
   std::string make_;
   std::string model_;
  public:
   car(std::string &&make, std::string &&model): make_(std::move(make)),
    model_(std::move(model)) {}
   void accept(Ivisitor &&v);
   friend class write_to_db;
   friend class write_to_txt;
   friend class write_to_json;
};


struct Ivisitor
{
    virtual void handle(person &p) = 0;
    virtual void handle(car &c) = 0;
    virtual void handle(landmark &l) = 0;
    virtual ~Ivisitor()
      {
         std::cout << __PRETTY_FUNCTION__ << std::endl;
      }
};

void person::accept(Ivisitor &&v)
{
   v.handle(*this);
}
void person::accept(Ivisitor &v)
{
   v.handle(*this);
}
void landmark::accept(Ivisitor &&v)
{
   v.handle(*this);
}

void car::accept(Ivisitor &&v)
{
   v.handle(*this);
}

struct write_to_db : public Ivisitor
{
   void handle(person &p) override
     {
        std::cout << "writing " << p.name_  << ", " << p.age_ << " to DB\n";
     }

   void handle(landmark &l) override
     {
     }
   void handle(car &c) override
     {
     }
   ~write_to_db()
     {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
     }
};

struct write_to_txt: public Ivisitor
{
   //TODO
};

struct write_to_json: public Ivisitor
{
   //TODO
};


int main()
{
   person person("ami", 22);
   landmark landmark("spuddy", "noida");
   car car("1920", "Honda City");

   person.accept(write_to_db{});
     {
        write_to_db wdb;
        person.accept(wdb);
     }
   return 0;
}
