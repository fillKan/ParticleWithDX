#pragma once

class SampleScene : public Scene
{
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual string Name() override;
};

