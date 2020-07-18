#include <CalculateModule.h>

CalculateModule::CalculateModule(const Summary& input)
    : result{input}
{

}
//======================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

