#include "SceneManager.h"

BEGIN_NAMESPACE

SceneManager::SceneManager(void)
    : _currentSceneName("")
{
}

SceneManager::~SceneManager(void)
{
}

void SceneManager::addScene(Scene *scene)
{
    _sceneList[scene->getName()] = scene;
}

void SceneManager::removeScene(const CL_String &name)
{
    Scene *scene = _sceneList[name];
    _sceneList.erase(name);
    delete scene;
}

void SceneManager::changeCurrentScene(const CL_String &name)
{
	_currentSceneName = name;
}

Scene *SceneManager::getCurrentScene()
{
    return _sceneList[_currentSceneName];
}

Scene *SceneManager::getScene(const CL_String &name)
{
    return _sceneList[name];
}

void SceneManager::update(float delta)
{
	if (!_currentSceneName.empty())
    {
        _sceneList[_currentSceneName]->update(delta);
    }
}

void SceneManager::draw()
{
    if (!_currentSceneName.empty())
    {
        _sceneList[_currentSceneName]->draw();
    }
}

END_NAMESPACE
