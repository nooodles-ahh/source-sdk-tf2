#pragma once
#include "particles.h"

class C_OP_ContinuousEmitter : public CParticleOperatorInstance {
public:

protected:

	float m_flEmissionDuration;
	float m_flStartTime;
	float m_flEmitRate;
	float m_flTimePerEmission;
	float m_flEmissionScale;

	bool m_bScalePerParticle;
};

class C_OP_InstantaneousEmitter : public CParticleOperatorInstance {
public:

protected:

	int m_nParticlesToEmit;
	int m_nMinParticlesToEmit;
	float m_flStartTime;
	
	int m_nPerFrameNum;
	int m_nScaleControlPoint;
	int m_nScaleControlPointField;
};

class C_OP_NoiseEmitter : public CParticleOperatorInstance {
public:

protected:

	float m_flEmissionDuration;
	float m_flStartTime;
	float m_flEmitRate;
	float m_flTimePerEmission;
	float m_flEmissionScale;
	
	bool m_bAbsVal;
	bool m_bAbsValInv;
	
	float m_flOffset;
	float m_flOutputMin;
	float m_flOutputMax;
	float m_flNoiseScale;
	float m_flNoiseScaleLoc;

	Vector m_vecOffsetLoc;
	float m_flWorldTimeScale;
};