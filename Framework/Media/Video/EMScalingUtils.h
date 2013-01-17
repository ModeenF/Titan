/*******************************************************
* Creator: Martin Johansson
* Portability: Non_Native
*-------------------------------------------------------
*
*******************************************************/


#ifndef __EM_SCALING_UTILS
#define __EM_SCALING_UTILS

class EMMediaFormat;

class __declspec(dllexport) EMScalingUtils
{
public:
							EMScalingUtils();
							~EMScalingUtils();

	//bool InitScaleFunctions(int p_vSrcX, int p_vSrcY, int p_vDstX, int p_vDstY, int p_vBytesPerSourcePixel, int p_vBytesPerDestinationPixel, int p_vSkipBytesSrc, int p_vSkipBytesDst);
		// LOONTODO: convert to rects, use Haiku scaling for "free" acceleration
		// why was this commented out?
		// This code seems more like a work-in-progress rather than anything functional...
		// which is odd considering this is used elswhere in Titan...

			bool			InitScaleFunctions(EMMediaFormat*, EMMediaFormat*);

			void 			Scale(void *source, void *destination);

			void 			Lock();
			void 			Release();


};

#endif
