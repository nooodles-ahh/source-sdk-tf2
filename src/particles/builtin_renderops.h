#pragma once
#include "particles.h"

#define BASE_OP_CONTEXT_DATA \
	CParticleVisibilityData m_VisibilityData;\
	int m_nQueryHandle; \

class C_OP_RenderPoints : public CParticleRenderOperatorInstance {
public:

	void InitializeContextData(CParticleCollection* pParticles, void* pContext);
	void Render(IMatRenderContext* pRenderContext, CParticleCollection* pParticles, void* pContext);

	uint32 GetReadAttributes() { return 1; }
	uint32 GetWrittenAttributes() { return 0; }
	size_t GetRequiredContextBytes() { return 0x14; }

	struct C_OP_RenderPointsContext_t {
		BASE_OP_CONTEXT_DATA
	};
};

class C_OP_RenderRope : public CParticleRenderOperatorInstance {
public:

	void InitializeContextData();
	void InitParams(CParticleSystemDefinition* pDef, CDmxElement* pElement);

	void Render(IMatRenderContext* pRenderContext, CParticleCollection* pCollection, void* pContext);
	void RenderSpriteCard(CParticleCollection* pCollection, void* pContext, IMaterial* pMat);

	void RenderUnsorted(CParticleCollection* pParticles, void* pContext, IMatRenderContext* pRenderContext,
		CMeshBuilder* meshBuilder, int nVertexOffset, int nFirstParticle, int nParticleCount);

	int GetParticlesToRender(CParticleCollection* pParticles, void* pContext, int nFirstParticle,
		int nRemainingVertices, int nRemainingIndices, int* pVertsUsed, int* pIndicesUsed);

	uint32 GetReadAttributes() { return 0xc9; }
	uint32 GetWrittenAttributes() { return 0; }
	size_t GetRequiredContextBytes() { return m_nSubDivCount * 4 + 4; }
	
	bool RequiresorderInvariance() { return true; }

	int m_nSubDivCount;
	float m_flTexelSizeUnits;
	float m_flTextureScale;
	float m_flTextureScrollRate;
	float m_flTStep;
};

class C_OP_RenderScreenVelocityRotate : public CParticleRenderOperatorInstance {
public:

	uint32 GetReadAttributes() { return 0x15; }
	uint32 GetWrittenAttributes() { return 0x10; }
	size_t GetRequiredContextBytes() { return 0x14; }

	struct C_OP_RenderScreenVelocityRotateContext_t {
		BASE_OP_CONTEXT_DATA
	};

	float m_flRotateRateDeg;
	float m_flForwardDegrees;
};

class C_OP_RenderSprites : public CParticleRenderOperatorInstance {
public:

	uint32 GetReadAttributes() { return 0x23db; }
	uint32 GetWrittenAttributes() { return 0; }
	size_t GetRequiredContextBytes() { return 0x1c; }

	struct C_OP_RenderSpritesContext_t {
		unsigned int m_nOrientationVarToken;
		unsigned int m_nOrientationMatrixVarToken;

		BASE_OP_CONTEXT_DATA
	};

	float m_flAnimationRate;
	float m_flAnimationRate2;

	bool m_bFitCycleToLifetime;
	bool m_bAnimationInFPS;

	int m_nOrientationType;
	int m_nOrientationControlPoint;
};

class C_OP_RenderSpritesTrail : public CParticleRenderOperatorInstance {
public:

	uint32 GetReadAttributes() { return 0x14; }
	uint32 GetWrittenAttributes() { return 0; }
	size_t GetRequiredContextBytes() { return 0x14; }

	float m_flAnimationRate;
	float m_flLengthInFadeTime;
	float m_flMaxLength;
	float m_flMinLength;
};

