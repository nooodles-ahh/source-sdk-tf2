#pragma once
#include "utlobjectreference.h"
#include "utlbuffer.h"

struct SheetSampleTextureCoords_t {
	float m_flLeft_U0;
	float m_flTop_V0;
	float m_flRight_U0;
	float m_flBottom_V0;

	float m_flLeft_U1;
	float m_flTop_V1;
	float m_flRight_U1;
	float m_flBottom_V1;
};

struct SheetSequenceSample_t {
	SheetSampleTextureCoords_t m_TexCoordData[2];
	float m_flBlendFactor;
};

class CSheet {
public:

	CSheet();
	CSheet(CUtlBuffer* buf);

	CUtlReferenceList<CSheet> m_References;
	SheetSequenceSample_t* m_pSamples[64];

	bool m_bClamp[64];
	bool m_bSequenceCopyOfAnotherSequence[64];
	
	int m_nNumFrames[64];
	float m_flFrameSpan[64];
};