#include <dpp/dpp.h>

int main()
{
    auto token = getenv("DISCORD_TOKEN");
    dpp::cluster bot(token);
    bot.intents |= dpp::i_message_content;
    bot.on_log(dpp::utility::cout_logger());
    
    bot.on_message_create([](const dpp::message_create_t& event) {
        if (event.msg.content == "ping")
        {
            event.reply("pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        bot.log(dpp::loglevel::ll_info, "we're ready!");
    });

    bot.start(dpp::st_wait);
}
