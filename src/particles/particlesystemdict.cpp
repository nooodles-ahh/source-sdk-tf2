#include "particlesystemdict.h"

CParticleSystemDefinition* CParticleSystemDictionary::AddParticleSystem(CDmxElement* pParticleSystem)
{
    if (V_stricmp(pParticleSystem->GetTypeString(), "DmeParticleSystemDefinition") != 0) 
    {
        return nullptr;
    }

    DestroyExistingElement(pParticleSystem);
    CParticleSystemDefinition* pParticleDef = new CParticleSystemDefinition();
    if (!pParticleSystem->GetValue<bool>("preventNameBasedLookup", false))
    {
        m_ParticleNameMap[pParticleSystem->GetName()] = pParticleDef;
    }
    else
    {
		m_ParticleIdMap.AddToTail(pParticleDef);
    }

	pParticleDef->Read(pParticleSystem);
    return pParticleDef;
}

int CParticleSystemDictionary::Count() const
{
	return m_ParticleIdMap.Count();
}

void CParticleSystemDictionary::DestroyExistingElement(CDmxElement* pElement)
{
    if (pElement->GetValue<bool>("preventNameBasedLookup", false))
    {
		FOR_EACH_VEC(m_ParticleIdMap, i)
		{
			if (IsUniqueIdEqual(m_ParticleIdMap[i]->GetId(), pElement->GetId()))
			{
				delete m_ParticleIdMap[i];
				m_ParticleIdMap.Remove(i);
				break;
			}
		}
	}
	else
	{
        UtlSymId_t id = m_ParticleNameMap.Find(pElement->GetName());
        if (id != UTL_INVAL_SYMBOL)
        {
            delete m_ParticleNameMap[id];
            m_ParticleNameMap[id] = nullptr;
        }
	}
}

CParticleSystemDefinition* CParticleSystemDictionary::FindParticleSystem(int id) const
{
	 if(id != m_ParticleNameMap.InvalidIndex() && id < m_ParticleNameMap.GetNumStrings())
	 {
		 return m_ParticleNameMap[id];
	 }
	 return nullptr;
}

CParticleSystemDefinition* CParticleSystemDictionary::FindParticleSystem(const char* pName) const
{
	UtlSymId_t id = m_ParticleNameMap.Find(pName);
	if (id != UTL_INVAL_SYMBOL)
	{
		return m_ParticleNameMap[id];
	}
	return nullptr;
}

CParticleSystemDefinition* CParticleSystemDictionary::FindParticleSystem(UniqueId_t* id) const
{
	FOR_EACH_VEC(m_ParticleIdMap, i)
	{
		if (IsUniqueIdEqual(m_ParticleIdMap[i]->GetId(), *id))
		{
			return m_ParticleIdMap[i];
		}
	}
	return nullptr;
}

UtlSymId_t CParticleSystemDictionary::FindParticleSystemHandle(const char* pName) const
{
	return m_ParticleNameMap.Find(pName);
}

CParticleSystemDefinition* CParticleSystemDictionary::GetParticleSystem(int index) const
{
	return m_ParticleIdMap[index];
}

unsigned short CParticleSystemDictionary::NameCount() const
{
	return m_ParticleNameMap.GetNumStrings();
}

