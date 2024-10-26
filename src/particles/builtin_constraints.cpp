#include "particles/particles.h"

class C_OP_ConstrainDistance : public CParticleOperatorInstance 
{
public:
	virtual bool EnforceConstraint(int nStartBlock, int nNumBlocks, CParticleCollection* pParticles, void* pContext, int nNumValidParticlesInLastChunk)
	{
	}
	virtual uint32 GetReadAttributes() { return PARTICLE_ATTRIBUTE_XYZ | PARTICLE_ATTRIBUTE_LIFE_DURATION; }
	virtual uint32 GetWrittenAttributes() { return PARTICLE_ATTRIBUTE_XYZ | PARTICLE_ATTRIBUTE_LIFE_DURATION; }

protected:
	float m_fMinDistance;
	float m_fMaxDistance;
	int m_nControlPointNumber;
	Vector m_CenterOffset;
	bool m_bGlobalCenter;
};

class C_OP_ConstrainDistanceToPath : public CParticleOperatorInstance
{
protected:
	float m_fMinDistance;
	float m_flMaxDistance0;
	float m_flMaxDistanceMid;
	float m_flMaxDistance1;
	CPathParameters m_PathParameters;
	float m_flTravelTime;
};

class C_OP_PlanarConstraint : public CParticleOperatorInstance
{
protected:
	Vector m_PointOnPlane;
	Vector m_PlaneNormal;
	int m_nControlPointNumber;
	bool m_bGlobalOrigin;
	bool m_bGlobalNormal;
};

class C_OP_WorldCollideConstraint : public CParticleOperatorInstance
{
};

class C_OP_WorldTraceConstraint : public CParticleOperatorInstance
{
protected:
	Vector m_vecCpOffset;
	int m_nCollisionMode;
	float m_flBounceAmount;
	float m_flSlideAmount;
	float m_flRadiusScale;
	float m_flCpMovementTolerance;
	float m_flTraceTolerance;
	bool m_bKillonContact;
	char m_CollisionGroupName[128];
	int m_nCollisionGroupNumber;
	bool m_bBrushOnly;
};

/*
class CWorldCollideContextData : public CParticleOperatorInstance
{
public:

	void CalculatePlanes();
	void SetBaseTrace(int nIndex, Vector* rayStart, Vector* traceDir, int nCollisionGroup, bool bKeepMisses);

	FourVectors m_TraceStartPnt[41];
	FourVectors m_TraceEndPnt[41];
	FourVectors m_PointOnPlane[41];
	FourVectors m_PlaneNormal[41];

	int m_nActivePlanes;
	int m_nNumFixedPlanes;

	float m_flLastUpdateTime;
	Vector m_vecLastUpdateOrigin;

	bool m_bPlaneActive[41];
};

class C_OP_WorldCollideConstraint : public CParticleOperatorInstance 
{
public:

	bool EnforceConstraint(int nStartBlock, int nNumBlocks, CParticleCollection* pParticles, void* pContext, int nNumValidParticlesInLastChunk);

	uint32 GetReadAttributes();
	uint64 GetReadControlPointMask();
	size_t GetRequiredContextBytes();
	uint32 GetWrittenAttributes();

	void SetupConstraintPerFrameData(CParticleCollection* pParticles, void* pContext);

protected:

};*/

void AddBuiltInParticleConstraints(void)
{
	//g_pParticleSystemMgr->AddParticleOperator(FUNCTION_CONSTRAINT, );
}