#include "Program.h"

#ifdef USE_SWRENDER
	#include <ClanLib/swrender.h>
#else
	#include <ClanLib/gl.h>
#endif

BEGIN_NAMESPACE

int Program::Main(const std::vector<CL_String> &args)
{
	try
	{
		CL_SetupCore setupCore;
		CL_SetupDisplay setupDisplay;

#ifdef USE_SWRENDER
		CL_SetupSWRender setupSWRender;
#else
		CL_SetupGL setupGL;
#endif

		Game game(args);
		return game.run();
	}
	catch(CL_Exception &exception)
	{
		// Create a console window for text-output if not available
		CL_ConsoleWindow console("Console", 80, 160);
		CL_Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console.display_close_message();

		return -1;
	}
}

CL_ClanApplication app(&Program::Main);

END_NAMESPACE
