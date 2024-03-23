#include "CSpinner.h"

#include "CUtils.h"

int CSpinner::spin()
{
    int result = CUtils::randInt(10);
    return result;
}
