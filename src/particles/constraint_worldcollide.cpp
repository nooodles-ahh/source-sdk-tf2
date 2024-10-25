#include "builtin_constraints.h"

void CWorldCollideContextData::CalculatePlanes() {

}

void CWorldCollideContextData::SetBaseTrace(int nIndex, Vector* rayStart, Vector* traceDir, int nCollisionGroup, bool bKeepMisses) {

}

bool C_OP_WorldCollideConstraint::EnforceConstraint(int nStartBlock, int nNumBlocks, 
	CParticleCollection* pParticles, void* pContext, int nNumValidParticlesInLastChunk) {

	size_t stride_pFv0 = 0; // uVar35
	FourVectors* pFv0 = pParticles->Get4VAttributePtrForWrite(nStartBlock, &stride_pFv0); // pauVar33

	size_t stride_pFltx0 = 0;
	fltx4* pFltx0 = pParticles->GetM128AttributePtrForWrite(nStartBlock, &stride_pFltx0); // local_30

	fltx4 fltx1;
	float fl27, fl28, fl29, fl30;
	fl27 = Four_Zeros.m128_f32[0];
	fl28 = Four_Zeros.m128_f32[1];
	fl29 = Four_Zeros.m128_f32[2];
	fl30 = Four_Zeros.m128_f32[3];
	fltx1 = Four_Zeros;

	IMatRenderContext* pRenderContext = (IMatRenderContext*)pContext;

	int nNumIndices = pRenderContext->GetMaxIndicesToRender(); // TODO: x2 check this
	bool b0 = false; // bVar31

	while (nNumBlocks != 0) {

		if (nNumIndices > 0) {

			int n0 = 0, n1 = 0;

			while (n0 < n1) {

				int n2 = 0; // = movmskps(local_30, auVar39)
				if (n2 != 0) {



				}
			}
		}

		*pFv0 = pFv0[stride_pFv0 * 3];
		pFltx0 = pFltx0 + (stride_pFltx0 & 0xffffffff); // TODO: this may not work right on x64
		nNumBlocks--;
	}

	return b0;
}

uint32 C_OP_WorldCollideConstraint::GetReadAttributes() {
	return 9;
}

uint64 C_OP_WorldCollideConstraint::GetReadControlPointMask() {
	return 1;
}

size_t C_OP_WorldCollideConstraint::GetRequiredContextBytes() {
	return 0x1f10;
}

uint32 C_OP_WorldCollideConstraint::GetWrittenAttributes() {
	return 1;
}

void C_OP_WorldCollideConstraint::SetupConstraintPerFrameData(CParticleCollection* pParticles, void* pContext) {

}