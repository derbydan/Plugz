//-------------------------------------------------------------------------------------------------------
// VST Plug-Ins SDK
// Version 2.4		$Date: 2006/11/13 09:08:27 $
//
// Category     : 
// Filename     : stwidth.h
// Created by   : Dan Roth
// Description  : Stereo Widener
//
// � 2006, Steinberg Media Technologies, All Rights Reserved
//-------------------------------------------------------------------------------------------------------

#ifndef __stwidth__
#define __stwidth__

#include "audioeffectx.h"

//-------------------------------------------------------------------------------------------------------
class StWidth : public AudioEffectX
{
public:
	StWidth(audioMasterCallback audioMaster);
	~StWidth();

	// Processing
	virtual void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames);
	virtual void processDoubleReplacing(double** inputs, double** outputs, VstInt32 sampleFrames);

	// Program
	virtual void setProgramName(char* name);
	virtual void getProgramName(char* name);

	// Parameters
	virtual void setParameter(VstInt32 index, float value);
	virtual float getParameter(VstInt32 index);
	virtual void getParameterLabel(VstInt32 index, char* label);
	virtual void getParameterDisplay(VstInt32 index, char* text);
	virtual void getParameterName(VstInt32 index, char* text);

	virtual bool getEffectName(char* name);
	virtual bool getVendorString(char* text);
	virtual bool getProductString(char* text);
	virtual VstInt32 getVendorVersion();

protected:
	float fWidth;
	float fBal;
	float degrees = 0;
	enum { kWidth, kBal, knumparams };
	char programName[kVstMaxProgNameLen + 1];
};

#endif
#pragma once

