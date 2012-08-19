#ifndef __CLC_KERNEL_H__
#define __CLC_KERNEL_H__

#include "Common.h"
#include "Scene/SceneManager.h"

BEGIN_NAMESPACE

class Kernel
{
public:
	static Kernel *getInstance();

	bool isRunning() const;
	void shutdown();

	CL_GraphicContext getGraphicContext() const;
	CL_DisplayWindow getDisplayWindow() const;
	CL_InputContext getInputContext() const;
	CL_ResourceManager getResourceManager() const;
	SceneManager *getSceneMenager();

private:
	bool _isRunning;

	CL_GraphicContext _graphicContext;
	CL_DisplayWindow _displayWindow;
	CL_InputContext _inputContext;
	CL_ResourceManager _resourceManager;

	SceneManager _sceneManager;

	Kernel();
	~Kernel();
};

END_NAMESPACE

#endif

