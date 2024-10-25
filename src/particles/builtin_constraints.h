#pragma once
#include "particles.h"

class C_OP_ConstrainDistance {
public:

protected:

	float m_flMinDistance;
	float m_flMaxDistance;

	int m_nControlPointNumber;
	Vector m_vecCenterOffset;
	bool m_bGlobalCenter;
};

class C_OP_ConstrainDistanceToPath {
public:

protected:

	float m_flMinDistance;
	float m_flMaxDistance;
	float m_flMaxDistanceMid;
	float m_flMaxDistance1;
	
	CPathParameters m_PathParameters;
	float m_flTravelTime;
};

class C_OP_PlanarConstraint {
public:

protected:

	Vector m_vecPointOnPlane;
	Vector m_vecPlaneNormal;

	int m_nControlPointNumber;

	bool m_bGlobalOrigin;
	bool m_bGlobalNormal;
};

class CWorldCollideContextData {
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

class C_OP_WorldCollideConstraint : public CParticleOperatorInstance {
public:

	bool EnforceConstraint(int nStartBlock, int nNumBlocks, CParticleCollection* pParticles, void* pContext, int nNumValidParticlesInLastChunk);

	uint32 GetReadAttributes();
	uint64 GetReadControlPointMask();
	size_t GetRequiredContextBytes();
	uint32 GetWrittenAttributes();

	void SetupConstraintPerFrameData(CParticleCollection* pParticles, void* pContext);

protected:
	
};

class C_OP_WorldTraceConstraint : public CParticleOperatorInstance {
public:

protected:

	Vector m_vecCpOffset;
	int m_nCollisionMode;

	float m_flBounceAmount;
	float m_flSlideAmount;
	float m_flRadiusScale;
	float m_flCpMovementTolerance;
	float m_flTraceTolerance;
	
	bool m_bKillOnContact;
	char m_CollisionGroupName[128];
	int m_nCollisionGroupNumber;
	bool m_bBrushOnly;
};