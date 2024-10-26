#include "particles.h"
#include "tier3/tier3.h"
#include "materialsystem/imaterialsystem.h"
#include "materialsystem/imaterialsystemhardwareconfig.h"
#include "particlesystemdict.h"
#include "tier1/KeyValues.h"

CParticleSystemMgr* g_pParticleSystemMgr = nullptr;

CParticleSystemMgr::CParticleSystemMgr()
{
	m_pQuery = nullptr; // s_DefaultParticleSystemQuery
	m_bDidInit = false;
	m_bUsingDefaultQuery = true;
	m_bShouldLoadSheets = true;
	m_pParticleSystemDictionary = nullptr;
	m_flLastSimulationTime = 0.0;
	m_nParticleIndexCount = 0;
	m_nParticleVertexCount = 0;
	m_bFrameWarningNeeded = false;
	m_nNumFramesMeasured = 0;
	V_memset(m_nParticleVertexCountHistory, 0, ARRAYSIZE(m_nParticleVertexCountHistory));
	m_fParticleCountScaling = 1.0;
}

CParticleSystemMgr::~CParticleSystemMgr()
{
}

bool CParticleSystemMgr::Init(IParticleSystemQuery* pQuery)
{
	if (!g_pMaterialSystem->QueryInterface(MATERIAL_SYSTEM_INTERFACE_VERSION))
	{
		Warning("CParticleSystemMgr compiled using an old IMaterialSystem\n");
		return false;
	}

	if ((m_bUsingDefaultQuery != false) && (pQuery != nullptr)) {
		m_pQuery = (IParticleSystemQuery*)pQuery;
		m_bUsingDefaultQuery = false;
	}
	if (!m_bDidInit) {

		m_pParticleSystemDictionary = new CParticleSystemDictionary();
		// TODO
		//AddParticleOperator(FUNCTION_CHILDREN, (IParticleOperatorDefinition*)&_s_ChildOperatorDefinition);
		m_pShadowDepthMaterial = nullptr;

		if (g_pMaterialSystemHardwareConfig->GetDXSupportLevel() >= 90) {
			KeyValues* pKVMaterial = new KeyValues("DepthWrite");
			pKVMaterial->SetInt("$no_fullbright", 1);
			pKVMaterial->SetInt("$model", 0);
			pKVMaterial->SetInt("$alphatest", 0);
			m_pShadowDepthMaterial = g_pMaterialSystem->CreateMaterial("__particlesDepthWrite", pKVMaterial);
		}
		SeedRandSIMD(12345678);
		m_bDidInit = true;
	}
	return true;
}

void CParticleSystemMgr::AddBuiltinSimulationOperators(void)
{

}

void CParticleSystemMgr::AddBuiltinRenderingOperators(void)
{

}

void CParticleSystemMgr::AddParticleOperator(ParticleFunctionType_t nOpType, IParticleOperatorDefinition* pOpFactory)
{

}

bool CParticleSystemMgr::ReadParticleConfigFile(const char* pFileName, bool bPrecache, bool bDecommitTempMemory)
{
	return false;
}

bool CParticleSystemMgr::ReadParticleConfigFile(CUtlBuffer& buf, bool bPrecache, bool bDecommitTempMemory, const char* pFileName)
{
	return false;
}

void CParticleSystemMgr::DecommitTempMemory()
{}

bool CParticleSystemMgr::WriteParticleConfigFile(const char* pParticleSystemName, CUtlBuffer& buf, bool bPreventNameBasedLookup)
{
	return false;
}

bool CParticleSystemMgr::WriteParticleConfigFile(const DmObjectId_t& id, CUtlBuffer& buf, bool bPreventNameBasedLookup)
{
	return false;
}

CParticleCollection* CParticleSystemMgr::CreateParticleCollection(const char* pParticleSystemName, float flDelay, int nRandomSeed)
{
	return nullptr;
}

CParticleCollection* CParticleSystemMgr::CreateParticleCollection(const DmObjectId_t& id, float flDelay, int nRandomSeed)
{
	return nullptr;
}

bool CParticleSystemMgr::IsParticleSystemDefined(const char* pParticleSystemName)
{
	return false;
}

bool CParticleSystemMgr::IsParticleSystemDefined(const DmObjectId_t& id)
{
	return false;
}

ParticleSystemHandle_t CParticleSystemMgr::GetParticleSystemIndex(const char* pParticleSystemName)
{
	return -1;
}

const char* CParticleSystemMgr::GetParticleSystemNameFromIndex(ParticleSystemHandle_t iIndex)
{
	return nullptr;
}

int CParticleSystemMgr::GetParticleSystemCount(void)
{
	return 0;
}

CUtlVector< IParticleOperatorDefinition*>& CParticleSystemMgr::GetAvailableParticleOperatorList(ParticleFunctionType_t nWhichList)
{
	return *m_ParticleOperators;
}

const DmxElementUnpackStructure_t* CParticleSystemMgr::GetParticleSystemDefinitionUnpackStructure()
{
	return nullptr;
}

void CParticleSystemMgr::ShouldLoadSheets(bool bLoadSheets)
{

}

CSheet* CParticleSystemMgr::FindOrLoadSheet(char const* pszFname, ITexture* pTexture)
{
	return nullptr;
}

CSheet* CParticleSystemMgr::FindOrLoadSheet(IMaterial* pMaterial)
{
	return nullptr;
}

void CParticleSystemMgr::FlushAllSheets(void)
{

}

void CParticleSystemMgr::ResetRenderCache(void)
{

}

void CParticleSystemMgr::AddToRenderCache(CParticleCollection* pParticles)
{

}

void CParticleSystemMgr::DrawRenderCache(bool bShadowDepth)
{

}

const char* GetParticleFieldName(int nParticleField)
{
	return nullptr;
}

CParticleSystemDefinition* FindParticleSystem(const char* pName)
{
	return nullptr;
}

CParticleSystemDefinition* FindParticleSystem(const DmObjectId_t& id)
{
	return nullptr;
}

void CParticleSystemMgr::CommitProfileInformation(bool bCommit)
{

}

void CParticleSystemMgr::DumpProfileInformation(void)
{

}

void CParticleSystemMgr::PrecacheParticleSystem(const char* pName)
{

}

void CParticleSystemMgr::UncacheAllParticleSystems()
{

}

void CParticleSystemMgr::SetLastSimulationTime(float flTime)
{

}

float CParticleSystemMgr::GetLastSimulationTime() const
{
	return 0.f;
}

int CParticleSystemMgr::Debug_GetTotalParticleCount() const
{
	return 0;
}

bool CParticleSystemMgr::Debug_FrameWarningNeededTestAndReset()
{
	return false;
}

float CParticleSystemMgr::ParticleThrottleScaling() const
{
	return 0.f;
}

bool CParticleSystemMgr::ParticleThrottleRandomEnable() const
{
	return false;
}

void CParticleSystemMgr::TallyParticlesRendered(int nVertexCount, int nIndexCount)
{

}

bool CParticleSystemMgr::ReadParticleDefinitions(CUtlBuffer& buf, const char* pFileName, bool bPrecache, bool bDecommitTempMemory)
{
	return false;
}

void CParticleSystemMgr::AddParticleSystem(CDmxElement* pParticleSystem)
{

}

CDmxElement* CParticleSystemMgr::CreateParticleDmxElement(const DmObjectId_t& id)
{
	return nullptr;
}

CDmxElement* CParticleSystemMgr::CreateParticleDmxElement(const char* pParticleSystemName)
{
	return nullptr;
}

bool CParticleSystemMgr::WriteParticleConfigFile(CDmxElement* pParticleSystem, CUtlBuffer& buf, bool bPreventNameBasedLookup)
{
	return false;
}

void CParticleSystemMgr::BuildBatchList(int iRenderCache, IMatRenderContext* pRenderContext, CUtlVector< Batch_t >& batches)
{

}

void CParticleSystemMgr::AttachKillList(CParticleCollection* pParticles)
{

}

void CParticleSystemMgr::DetachKillList(CParticleCollection* pParticles)
{

}
