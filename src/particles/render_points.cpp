#include "builtin_renderops.h"
#include "materialsystem/imesh.h"

void C_OP_RenderPoints::InitializeContextData(CParticleCollection* pParticles, void* pContext) {

	C_OP_RenderPointsContext_t* pData = (C_OP_RenderPointsContext_t*)pContext;
	pData->m_VisibilityData.m_bUseVisibility = false;							// pContext + 0xc (12b)
	pData->m_VisibilityData.m_flCameraBias = VisibilityInputs.m_flCameraBias;	// pContext + 0x8 (8b)
}

void C_OP_RenderPoints::Render(IMatRenderContext* pRenderContext, CParticleCollection* pParticles, void* pContext) {

	int nParticlesInBatch = 0;

	IMesh* pMesh;
	CMeshBuilder builder;
	IMaterial* pMat = pParticles->m_pDef->GetMaterial();
	C_OP_RenderPointsContext_t* pData = (C_OP_RenderPointsContext_t*)pContext;

	pParticles->GetRenderList(pRenderContext, 1, &nParticlesInBatch, &pData->m_VisibilityData);

	pRenderContext->Bind(pMat);
	pMesh = pRenderContext->GetDynamicMesh();


}
