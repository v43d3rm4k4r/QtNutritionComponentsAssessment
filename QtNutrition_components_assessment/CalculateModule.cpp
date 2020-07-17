#include <CalculateModule.h>

CalculateModule::CalculateModule(const Summary& input, MainWindow* parent)
    : MainWindow{parent}, result{input}
{

}
//======================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

