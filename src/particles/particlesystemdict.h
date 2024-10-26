#ifndef PARTICLESYSTEMDICT_H
#define PARTICLESYSTEMDICT_H
#pragma once

#include "particles/particles.h"


using ParticleNameMap_t = CUtlStringMap<CParticleSystemDefinition*>;
using ParticleIdMap_t = CUtlVector<CParticleSystemDefinition*>;

class CParticleSystemDictionary
{
public:
	CParticleSystemDefinition* AddParticleSystem(CDmxElement* pParticleSystem);
	int Count() const;
	void DestroyExistingElement(CDmxElement* pElement);
	CParticleSystemDefinition* FindParticleSystem(int id) const;
	CParticleSystemDefinition* FindParticleSystem(const char* pName) const;
	CParticleSystemDefinition* FindParticleSystem(UniqueId_t *id) const;
	UtlSymId_t FindParticleSystemHandle(const char* pName) const;
	CParticleSystemDefinition* GetParticleSystem(int index) const;
	unsigned short NameCount() const;

private:
	ParticleNameMap_t m_ParticleNameMap;
	ParticleIdMap_t m_ParticleIdMap;
};

#endif