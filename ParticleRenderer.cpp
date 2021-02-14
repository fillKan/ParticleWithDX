#include "DXUT.h"
#include "ParticleRenderer.h"

ParticleRenderer::ParticleRenderer() : m_Transform(nullptr), m_RenderingForm()
{
}

ParticleRenderer::~ParticleRenderer()
{
}

void ParticleRenderer::Init(Transform* transform)
{
	m_Transform = transform;
}

void ParticleRenderer::Render()
{
	m_RenderingForm =
	{
		m_Transform->Position,
		m_Transform->Scale,
		m_Transform->Rotation,
		m_Transform->Depth,

		Pivot, Color, IsVlew
	};
	IMAGE->Render(Image, m_RenderingForm);
}

void ParticleRenderer::Render(RECT rect)
{
	m_RenderingForm =
	{
		m_Transform->Position,
		m_Transform->Scale,
		m_Transform->Rotation,
		m_Transform->Depth,

		Pivot, Color, IsVlew
	};
	IMAGE->RenderRect(Image, m_RenderingForm, rect);
}

void ParticleRenderer::Release()
{
}
