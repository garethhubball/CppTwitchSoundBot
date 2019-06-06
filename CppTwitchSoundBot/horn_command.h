#pragma once
#include "command_definitions.h"
namespace gh {
	class horn_command
	{
	public:
		horn_command(int cooldown);
		command cmd;
	private:
		int cooldown;
		std::chrono::system_clock clock;
		std::chrono::time_point<std::chrono::system_clock> last_horn;
		void cmd_impl(std::string const& body, gh::twitch_user const& user, message_sender send_message);
	};
}