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
    virtual void visit(person &p) = 0;
    virtual void visit(car &c) = 0;
    virtual void visit(landmark &l) = 0;
    virtual ~Ivisitor()
      {
         std::cout << __PRETTY_FUNCTION__ << std::endl;
      }
};

void person::accept(Ivisitor &&v)
{
   v.visit(*this);
}
void person::accept(Ivisitor &v)
{
   v.visit(*this);
}
void landmark::accept(Ivisitor &&v)
{
   v.visit(*this);
}

void car::accept(Ivisitor &&v)
{
   v.visit(*this);
}

struct write_to_db : public Ivisitor
{
   //define DB Connection objects etcs
   void visit(person &p) override
     {
        std::cout << "writing " << p.name_  << ", " << p.age_ << " to DB\n";
     }

   void visit(landmark &l) override
     {
      std::cout << "writing " << l.city_ << ", " << l.name_ << " to DB\n";
     }
   void visit(car &c) override
     {
      std::cout << "writing " << c.make_ << ", " << c.model_ << " to DB\n";
     }

   ~write_to_db()
     {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
     }
};

struct write_to_txt: public Ivisitor
{
   //define file handlers
   void visit(person &p) override
   {
      std::cout << "writing " << p.name_ << ", " << p.age_ << " to txt\n";
   }

   void visit(landmark &l) override
   {
      std::cout << "writing " << l.name_ << ", " << l.city_ << " to txt\n";
   }

   void visit(car &c) override
   {
      std::cout << "writing " << c.model_ << ", " << c.make_ << " to txt\n";
   }
};

struct write_to_json: public Ivisitor
{
   void visit(person &p) override
   {
      std::cout << "writing " << p.name_ << ", " << p.age_ << " to json\n";
   }

   void visit(landmark &l) override
   {
      std::cout << "writing " << l.name_ << ", " << l.city_ << " to json\n";
   }

   void visit(car &c) override
   {
      std::cout << "writing " << c.model_ << ", " << c.make_ << " to json\n";
   }
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
   
   car.accept(write_to_json{});

   landmark.accept(write_to_txt{});
   
   return 0;
}
