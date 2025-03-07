#include "minGameObject.h"
#include "../Component/minTransform.h"

namespace min::object
{
	void Destory(GameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->Death();
	}
}

namespace min
{
	GameObject::GameObject()
		:mState(eState::Active)
	{
		mComponents.resize((UINT)eComponentType::End);
		InitializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}


	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{

			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(hdc);
		}
	}

	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}