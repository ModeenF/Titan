#include "EMMediaUtility.h"

#include "EMGlobals.h"
#include "Media/EMMediaFormat.h"

#include "Media/EMBeMediaUtility.h"


EMMediaUtility*	gMediaUtility = NULL;;

EMMediaUtility::EMMediaUtility()
{
	gMediaUtility = this;
}

EMMediaUtility::~EMMediaUtility()
{
}
