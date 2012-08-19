#ifndef __CLC_SCENEMANAGER_H__
#define __CLC_SCENEMANAGER_H__

#include <map>

#include "Scene.h"

BEGIN_NAMESPACE

class SceneManager
{
public:
    SceneManager(void);
    ~SceneManager(void);

    void addScene(Scene *scene);
    void removeScene(const CL_String &name);

    void changeCurrentScene(const CL_String &name);
    Scene *getCurrentScene();
    Scene *getScene(const CL_String &name);

    void update(float delta);
    void draw();

private:
    std::map<CL_String, Scene *> _sceneList;
    CL_String _currentSceneName;
};

END_NAMESPACE

#endif

