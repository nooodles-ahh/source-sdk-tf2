#include "particles/particles.h"

static bool s_DidAddSim = false;
static bool s_DidAddRenderers = false;

void CParticleSystemMgr::AddBuiltinSimulationOperators()
{
	if (s_DidAddSim)
		return;

	s_DidAddSim = true;
	AddBuiltInParticleOperators();
	AddBuiltInParticleInitializers();
	AddBuiltInParticleEmitters();
	AddBuiltInParticleForceGenerators();
	AddBuiltInParticleConstraints();
}

void CParticleSystemMgr::AddBuiltinRenderingOperators()
{
	if (s_DidAddRenderers)
		return;

	s_DidAddRenderers = true;
	AddBuiltInParticleRenderers();
	return;
}