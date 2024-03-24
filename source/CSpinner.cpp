#include "CSpinner.h"

#include "CUtils.h"

int CSpinner::Spin()
{
    int result = CUtils::RandInt(10);
    return result;
}
