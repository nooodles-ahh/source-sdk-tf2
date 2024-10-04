#include "particles.h"

class CSheet
{
public:
	CUtlReferenceList<CSheet> m_References;
};

float s_pRandomFloats[1] = { 1.f };

CParticleCollection::CParticleCollection()
{}

CParticleCollection::~CParticleCollection()
{}

void* CParticleCollection::operator new(size_t nSize)
{
    return ::operator new(nSize);
}

void* CParticleCollection::operator new(size_t size, int nBlockUse, const char* pFileName, int nLine)
{
    return ::operator new(size, nBlockUse, pFileName, nLine);
}

void CParticleCollection::operator delete(void* pData)
{
    ::operator delete(pData);
}

void CParticleCollection::operator delete(void* p, int nBlockUse, const char* pFileName, int nLine)
{
    ::operator delete(p, nBlockUse, pFileName, nLine);
}

int CParticleCollection::GetHighestControlPoint(void)const
{
    return 0;
}

bool CParticleCollection::Init(char const*)
{
    return false;
}

bool CParticleCollection::Init(class CParticleSystemDefinition*)
{
    return false;
}

void CParticleCollection::SkipToTime(float f)
{}

IMaterial* CParticleSystemDefinition::GetMaterial(void)const
{
    return nullptr;
}

CParticleSystemDefinition* CParticleSystemMgr::FindParticleSystem(char const* name)
{
    return nullptr;
}


void CParticleCollection::Restart(void)
{}

char const* CParticleCollection::GetName(void)const
{
    return nullptr;
}

char const* CParticleSystemDefinition::GetName(void)const
{
    return nullptr;
}

void CParticleCollection::Simulate(float f, bool b)
{}

bool CParticleCollection::IsFinished(void)
{
    return true;
}

bool CParticleCollection::HasMoved() const
{
    return false;
}


void CParticleCollection::Render(class IMatRenderContext*, bool, void*)
{}

void CParticleCollection::StopEmission(bool,bool,bool)
{}

void CParticleCollection::SetDormant(bool)
{}

bool CParticleCollection::UsesPowerOfTwoFrameBufferTexture(bool)const 
{
    return false;
}

bool CParticleCollection::UsesFullFrameBufferTexture(bool)const 
{
    return false;
}

bool CParticleCollection::IsTranslucent(void)const 
{
    return false;
}

bool CParticleCollection::IsTwoPass(void)const
{
    return false;
}

void CParticleCollection::BloatBoundsUsingControlPoint(void)
{}

void CParticleCollection::GetControlPointAtTime(int, float, class Vector*)const
{}