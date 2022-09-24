#include <iostream>
#include <memory>
#include<vector>

class bankaccount {
   int32_t balance {0};

   struct memento
   {
      int32_t balance {0};
      memento(int32_t balance): balance(balance)
      {
      }
   };

   std::vector<std::shared_ptr<memento>> changes;
   public:
   bankaccount(int32_t balance): balance(balance) {}

   void deposit(int32_t amount)
   {
      changes.emplace_back(std::make_shared<memento>(balance));
      balance += amount;
   }

   int32_t get_balance() const
   {
      return balance;
   }

   std::shared_ptr<memento> undo()
   {
      auto prev = changes.back();
      balance = prev->balance;
      changes.pop_back();

      return prev;
   }

   friend std::ostream &operator<<(std::ostream &os, const bankaccount &ba)
   {
      return os << "balance: " << ba.balance;
   }
};

int main()
{
   bankaccount ami_account(100);
   ami_account.deposit(-30);
   std::cout << ami_account << '\n';
   ami_account.undo();
   std::cout << ami_account << '\n';
   ami_account.deposit(20);
   ami_account.deposit(30);
   std::cout << ami_account << '\n';
   ami_account.undo();
   std::cout << ami_account << '\n';

   return 0;
}
