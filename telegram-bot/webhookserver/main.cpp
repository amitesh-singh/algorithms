#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <iostream>

#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;

int main()
{
   string token(getenv("TOKEN"));
   string webhookUrl(getenv("WEBHOOK_URL"));

   Bot bot(token);
   
   bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
      bot.getApi().sendMessage(message->chat->id, "Hi Webserver");
   });

   bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
      if (StringTools::startsWith(message->text, "/start"))
      {
         return;
      }

      bot.getApi().sendMessage(message->chat->id, "You wrote " + message->text);
   });

   signal(SIGINT, [](int s) {
      exit(0);
   });

   try {
      TgWebhookTcpServer webhookServer(8080, bot);
      std::cout << "Server is starting..\n";
      bot.getApi().setWebhook(webhookUrl);
      webhookServer.start();

   } catch (exception &e) {
      std::cerr << "error: " << e.what() << std::endl;
   }

   return 0;
}
