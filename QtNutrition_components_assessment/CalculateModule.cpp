#include <CalculateModule.h>

CalculateModule::CalculateModule(const QVector<QList<QDoubleSpinBox*>>& input)
    : input{input}
{

}
//======================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

