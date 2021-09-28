#include "GeneralUtils.h"

using namespace std;

string GeneralUtils::resolveCalculationType(int calculationTypeNumber) {
    string calculationTypeText;
    if (calculationTypeNumber == 0) {
        calculationTypeText = "Galutinis (vid.)";
    }
    else {
        calculationTypeText = "Galutinis (med.)";
    }
    return calculationTypeText;
}

