#pragma once
#include "../Entity/minEntity.h"
#include "minComponent.h"
#include "../Resource/minTexture.h"

namespace min
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }
	private:
		Texture* mTexture;
		Vector2 mSize;
	};
}