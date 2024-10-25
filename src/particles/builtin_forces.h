#pragma once
#include "particles.h"

class C_OP_AttractToControlPoint : public CParticleOperatorInstance {
public:

	void AddForces(FourVectors* pAccumulatedForces, CParticleCollection* pParticles, int nBlocks, float flStrength, void* pContext);

	uint32 GetReadAttributes() { return 0; }
	uint32 GetWrittenAttributes() { return 0; }

	uint64 GetReadControlPointMask();
	
protected:

	float m_flForceAmount;
	float m_flFalloffPower;

	int m_nControlPointNumber;
};

class C_OP_RandomForce : public CParticleOperatorInstance {
public:

	void AddForces(FourVectors* pAccumulatedForces, CParticleCollection* pParticles, int nBlocks, float flStrength, void* pContext);

	uint32 GetReadAttributes() { return 0; }
	uint32 GetWrittenAttributes() { return 0; }

protected:

	Vector m_vecMinForce;
	Vector m_vecMaxForce;
};

class C_OP_TwistAroundAxis : public CParticleOperatorInstance {
public:

	void AddForces(FourVectors* pAccumulatedForces, CParticleCollection* pParticles, int nBlocks, float flStrength, void* pContext);

	uint32 GetReadAttributes() { return 1; }
	uint32 GetWrittenAttributes() { return 0; }

protected:

	float m_flForceAmount;
	Vector m_vecTwistAxis;
	bool m_bLocalSpace;
};