#include "psheet.h"

CSheet::CSheet() {
	memset(m_pSamples, 0, 0x100);
	memset(m_bClamp, 0, 0x40);
}

CSheet::CSheet(CUtlBuffer* buf) {

	SheetSequenceSample_t Samples[1024];
	float InterpValue[1024];
	float InterpKnot[1024];

	memset(this, 0, 0x184);

	int _nVar01 = buf->GetInt();
	bool _nVar01IsNotZero = _nVar01 != 0;
	int nCount = buf->GetInt();

	while (nCount != 0)
	{
		nCount--;
		int nSequence = buf->GetInt();
		if (nSequence > 64)
		{
			Warning("sequence number %d too high in sheet file!!!\n", nSequence);
			return;
		}

		m_bClamp[nSequence] = buf->GetInt() != 0;
		int numFrames = buf->GetInt();
		m_nNumFrames[nSequence] = numFrames;

		int nSeqSamples = (numFrames == 1) ? 1 : 1024;
		SheetSequenceSample_t* pSamples = new SheetSequenceSample_t[nSeqSamples];
		m_pSamples[nSequence] = pSamples;

		int nSomeVar = (int)buf->GetFloat();
		int iStackVar01 = 64;
		if (0 < numFrames)
		{
			int nFrame = 0;
			float fStackVar01 = 0.f;
			do {
				float fSomeValue = buf->GetFloat();
				InterpValue[nFrame] = nFrame;
				InterpKnot[nFrame] = (fStackVar01 / (float)nSomeVar) * 1024.f;
				Samples[nFrame].m_TexCoordData[1].m_flBottom_V1 = 0.f;

				float* pStackVar01 = &Samples[0].m_TexCoordData[0].m_flRight_U0;
				int iCount = 0;
				do
				{
					pStackVar01[-3] = buf->GetFloat();
					pStackVar01[-2] = buf->GetFloat();
					pStackVar01[-1] = buf->GetFloat();
					pStackVar01[0] = buf->GetFloat();

					pStackVar01 += 8;

					iCount++;
				} while (iCount < (_nVar01IsNotZero * 3 + 1));

				if (_nVar01 == 0.0) {
					Samples[nFrame].m_TexCoordData[1].m_flTop_V1 = Samples[nFrame].m_TexCoordData[0].m_flTop_V1;
					Samples[nFrame].m_TexCoordData[1].m_flRight_U1 = Samples[nFrame].m_TexCoordData[0].m_flRight_U1;
					Samples[nFrame].m_TexCoordData[1].m_flBottom_V0 = Samples[nFrame].m_TexCoordData[0].m_flBottom_V0;
					Samples[nFrame].m_TexCoordData[1].m_flLeft_U1 = Samples[nFrame].m_TexCoordData[0].m_flLeft_U1;
					Samples[nFrame].m_TexCoordData[1].m_flTop_V0 = Samples[nFrame].m_TexCoordData[0].m_flTop_V0;
					Samples[nFrame].m_TexCoordData[1].m_flRight_U0 = Samples[nFrame].m_TexCoordData[0].m_flRight_U0;
					Samples[nFrame].m_TexCoordData[1].m_flBottom_V1 = Samples[nFrame].m_TexCoordData[0].m_flBottom_V1;
					Samples[nFrame].m_TexCoordData[1].m_flLeft_U0 = Samples[nFrame].m_TexCoordData[0].m_flLeft_U0;
				}


				fStackVar01 += fSomeValue;
				m_flFrameSpan[nSequence] = fStackVar01;
				nFrame++;
				pStackVar01 += 0x11;
			} while (nFrame < numFrames);
		}

		int iInterpCount = 0;
		int iCap = 64;
		do {
			float fValueA;
			float fValueB;
			float fValueInterp;

			bool bVar20 = 0;
			float local_a4[8];

			GetInterpolationData(InterpKnot, InterpValue, numFrames, 1024, (float)iInterpCount, m_bClamp[nSequence] == false, &fValueA, &fValueB, &fValueInterp);

			fVar1 = fValueInterp;
			iInterpCount = iInterpCount + 1;
			tempVal01 = (float*)(&stack0xfffecf18 + (int)fValueA * 0x44);
			pSVar4 = local_e8 + 1;
			for (numFrames = 0x11; pCVar6 = pCStack_28, numFrames != 0; numFrames = numFrames + -1) {
				pSVar4->m_TexCoordData[0].m_flLeft_U0 = *tempVal01;
				tempVal01 = tempVal01 + 1;
				pSVar4 = (SheetSequenceSample_t*)&pSVar4->m_TexCoordData[0].m_flTop_V0;
			}
			pfVar10 = (float*)(&stack0xfffecf18 + (int)fValueB * 0x44);
			pSVar4 = local_e8;
			for (numFrames = 0x11; numFrames != 0; numFrames = numFrames + -1) {
				pSVar4->m_TexCoordData[0].m_flLeft_U0 = *pfVar10;
				pfVar10 = pfVar10 + 1;
				pSVar4 = (SheetSequenceSample_t*)&pSVar4->m_TexCoordData[0].m_flTop_V0;
			}
			pSVar4 = pCVar6->m_pSamples[uStack_20];
			*(float*)((int)pCStack_2c->m_pSamples + (int)&pSVar4->m_TexCoordData[1].m_flBottom_V1) =
				fVar1;
			puVar11 = (SheetSequenceSample_t*)
				((int)pCStack_2c->m_pSamples + (int)&pSVar4[-1].m_fBlendFactor);
			pCStack_2c = (CSheet*)(pCStack_2c->m_pSamples + 0x10);
			puVar11->m_TexCoordData[0].m_flLeft_U0 = local_e8[1].m_TexCoordData[0].m_flLeft_U0;
			puVar11->m_TexCoordData[0].m_flTop_V0 = local_e8[1].m_TexCoordData[0].m_flTop_V0;
			puVar11->m_TexCoordData[0].m_flRight_U0 = local_e8[1].m_TexCoordData[0].m_flRight_U0;
			puVar11->m_TexCoordData[0].m_flBottom_V0 = local_e8[1].m_TexCoordData[0].m_flBottom_V0;
			puVar11->m_TexCoordData[0].m_flLeft_U1 = local_e8[0].m_TexCoordData[0].m_flLeft_U0;
			puVar11->m_TexCoordData[0].m_flTop_V1 = local_e8[0].m_TexCoordData[0].m_flTop_V0;
			puVar11->m_TexCoordData[0].m_flRight_U1 = local_e8[0].m_TexCoordData[0].m_flRight_U0;
			puVar11->m_TexCoordData[0].m_flBottom_V1 = local_e8[0].m_TexCoordData[0].m_flBottom_V0;
			puVar11->m_TexCoordData[1].m_flLeft_U0 = local_e8[1].m_TexCoordData[1].m_flLeft_U0;
			puVar11->m_TexCoordData[1].m_flTop_V0 = local_e8[1].m_TexCoordData[1].m_flTop_V0;
			puVar11->m_TexCoordData[1].m_flRight_U0 = local_e8[1].m_TexCoordData[1].m_flRight_U0;
			puVar11->m_TexCoordData[1].m_flBottom_V0 = local_e8[1].m_TexCoordData[1].m_flBottom_V0;
			puVar11->m_TexCoordData[1].m_flLeft_U1 = local_e8[0].m_TexCoordData[1].m_flLeft_U0;
			puVar11->m_TexCoordData[1].m_flTop_V1 = local_e8[0].m_TexCoordData[1].m_flTop_V0;
			puVar11->m_TexCoordData[1].m_flRight_U1 = local_e8[0].m_TexCoordData[1].m_flRight_U0;
			puVar11->m_TexCoordData[1].m_flBottom_V1 = local_e8[0].m_TexCoordData[1].m_flBottom_V0;
			nSequence = uStack_20;
			numFrames = iStack_24;
			m_samplesToo = ppSStack_50;
			this = pCStack_28;
			pCVar6 = pCStack_2c;

		} while (iInterpCount < nSeqSamples);
	}


	int iVar13 = 0;
	do {
		if (m_pSamples[iVar13] != (SheetSequenceSample_t*)0x0) {
			if (iVar13 != -1) {
				int nSequence = -0x40;
				do {
					if (*(int*)(m_bClamp + nSequence * 4) == 0) {
						*(SheetSequenceSample_t**)(m_bClamp + nSequence * 4) =
							m_pSamples[iVar13];
						m_bSequenceCopyOfAnotherSequence[nSequence] = m_bClamp[iVar13];
						m_flFrameSpan[nSequence] = (float)m_nNumFrames[iVar13];
						*(int*)((int)m_nNumFrames + nSequence) = 1;
					}
					nSequence = nSequence + 1;
				} while (nSequence != 0);
			}
			break;
		}
		iVar13 = iVar13 + 1;
	} while (iVar13 < 64);

}

CSheet::~CSheet() 
{
	for (int i = 0; i < 64; i++) {
		if (m_pSamples[i] && !m_bSequenceCopyOfAnotherSequence[i]) {
			delete[] m_pSamples[i];
		}
	}
}