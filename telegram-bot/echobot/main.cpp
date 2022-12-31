#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>

#include <tgbot/tgbot.h>

#include <iostream>

using namespace std;
using namespace TgBot;

int main()
{
   string token(getenv("TOKEN"));
   cout << "Token: " << token << '\n';

   //create Bot
   Bot bot(token);
   bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
                             bot.getApi().sendMessage(message->chat->id, "Hi!");
                             });

   bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
                                cout << "User Wrote: " << message->text << '\n';

                                //don't handle /start since it's handled already
                                if (StringTools::startsWith(message->text, "/start")) {
                                    return;
                                }

                                bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
                                });

   signal(SIGINT, [](int s) {
           exit(0);
          });

   try {
        std::cout << "Bot username: " << bot.getApi().getMe()->username << '\n';
        bot.getApi().deleteWebhook();
        TgLongPoll longPoll(bot);
        while (true) {
             std::cout << "Long Poll started\n";
             longPoll.start();
        }
   } catch (exception &e) {
        cout << "error: " << e.what() << '\n';
   }

   return 0;
}
