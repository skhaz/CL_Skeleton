#ifndef __CLC_COMMON_H__
#define __CLC_COMMON_H__

//TODO CHANGE ME!!!

#ifdef USE_NAMESPACE
	#define BEGIN_NAMESPACE namespace Incoming {
	#define END_NAMESPACE }
#else
	#define BEGIN_NAMESPACE
	#define END_NAMESPACE
#endif

#include <ClanLib/core.h>
#include <ClanLib/application.h>
#include <ClanLib/display.h>

#define GAME_NAME "GameName"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#endif