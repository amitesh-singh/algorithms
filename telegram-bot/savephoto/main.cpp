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
    std::cout << "Token: " << token << std::endl;

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

                                // if there is a photo in the message
                                if (!message->photo.empty()) {
                                    auto file_id = message->photo[2]->fileId;
                                    auto file_info = bot.getApi().getFile(file_id);
                                    //download a file from telegram and save it in memory
                                    // returns the content of the file in string?
                                    auto downloaded = bot.getApi().downloadFile(file_info->filePath);
                                    std::ofstream out("image.jpg", std::ios::binary);
                                    out << downloaded;
                                }
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