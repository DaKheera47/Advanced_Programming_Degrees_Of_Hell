#include "CSpinner.h"

#include "CUtils.h"

int CSpinner::spin()
{
    return CUtils::randInt(10);
}
