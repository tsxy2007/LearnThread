#pragma once
#include <string>
#include <thread>

namespace thread_2_4
{
	void open_document_and_display_gui(std::string const& filename)
	{}

	bool done_editing()
	{
		return true;
	}

	enum command_type
	{
		open_new_document
	};

	struct user_command
	{
		command_type type;
		user_command() :
			type(open_new_document)
		{}
	};

	user_command get_user_input()
	{
		return user_command();
	}

	std::string get_filename_from_user()
	{
		return "foo.doc";
	}

	void process_user_input(user_command const& cmd)
	{

	}

	void editor_document(std::string const& filename)
	{
		open_document_and_display_gui(filename);
		while (!done_editing())
		{
			user_command cmd = get_user_input();
			if (cmd.type == open_new_document)
			{
				std::string const new_name = get_filename_from_user();
				std::thread t(editor_document, new_name);
				t.detach();
			}
			else
			{
				process_user_input(cmd);
			}
		}
	}

	class X
	{
	public:
		void do_lenghty_work()
		{
			std::cout << "X::do_lenghty_work" << std::endl;
		}
	};

};

