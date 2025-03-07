#include "minDestroy.h"
#include "../GameObject/minGameObject.h"

namespace min
{
	void Destroy(GameObject* obj)
	{
		obj->Death();
	}
}