#include "mainwindow.h"
#include <cmath>

CalculateModule::CalculateModule(const QVector<QVector<QDoubleSpinBox*>>& input, uint32_t comp_num) noexcept
    : input{input}
{
    calcInit(comp_num);

    /// ВЫЧИСЛЕНИЯ БЕЛКОВ
    try
    {
        for (int row = 0; row < AMI; ++row)
        {
            if (comp_num == 1)
            {
                result.recount[row][0] = calcRecountProteins(0, result.protein, result.comp[row][0]);
            }
            if (comp_num == 2)
            {
                for (uint32_t col = 0; col < comp_num; ++col)
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
            }
            if (comp_num == 3)
            {
                for (uint32_t col = 0; col < comp_num; ++col)
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
            }
            if (comp_num == 4)
            {
                for (uint32_t col = 0; col < comp_num; ++col)
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
            }
            if (comp_num == 5)
            {
                for (uint32_t col = 0; col < comp_num; ++col)
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
            }

            result.akp[row]                 = calcAKP(row, result.prop, result.recount);
            result.aminoacidskor[row]       = calcAminoacidskor(result.akp[row], result.fao_voz2007[row]);
            result.fatty_acid_per_100g[row] = calcFattyAcidPer100g(result.fao_voz2007[row], result.akp[row]);
        }

    }
    catch (std::exception& ex)
    {
        qDebug() << ex.what();
    }

    // search for minimal aminoacidskor
    double min_aminoacidskor = 999.0;
    for (int row = 0; row < AMI; ++row)
    {
        if (result.aminoacidskor[row] < min_aminoacidskor)
            min_aminoacidskor = result.aminoacidskor[row];
    }

    for (int row = 0; row < AMI; ++row)
    {
        result.koef_ration[row] = calcKoefRation(min_aminoacidskor, result.aminoacidskor[row]);
    }

    /// ВЫЧИСЛЕНИЯ ЛИПИДОВ
    try
    {
        for (int row = 0; row < LIP_PROP; ++row)
        {
            if (comp_num == 1)
                result.recount_lip[row][0] = calcRecoutLip(0, result.lipids, result.ultimate[row][0]);
            if (comp_num == 2)
            {
                for (uint32_t col = 0; col < result.comp_num; ++col)
                    result.recount_lip[row][col] = calcRecoutLip(col, result.lipids, result.ultimate[row][col]);
            }
            if (comp_num == 3)
            {
                for (uint32_t col = 0; col < result.comp_num; ++col)
                    result.recount_lip[row][col] = calcRecoutLip(col, result.lipids, result.ultimate[row][col]);
            }
            if (comp_num == 4)
            {
                for (uint32_t col = 0; col < result.comp_num; ++col)
                    result.recount_lip[row][col] = calcRecoutLip(col, result.lipids, result.ultimate[row][col]);
            }
            if (comp_num == 5)
            {
                for (uint32_t col = 0; col < result.comp_num; ++col)
                    result.recount_lip[row][col] = calcRecoutLip(col, result.lipids, result.ultimate[row][col]);
            }
            result.ratio_calc[row]        = calcRatioCalc(row, result.prop, result.recount_lip);
            result.lip_balance_ratio[row] = calcLipBalanceRatio(result.ratio_calc[row], result.fao_voz2008[row]);
            calcFattyAcidCompliance(result.lip_balance_ratio, &result.fattyAcidComplianceResult2,
                                                              &result.fattyAcidComplianceResult2);
        }
    }
    catch (std::exception& ex)
    {
        qDebug() << ex.what();
    }

    result.kras                        = calcKRAS(calcAminoacidskorSum(result.aminoacidskor), min_aminoacidskor);
    result.biological_value            = calcBiologicalValue(result.kras);
    result.amino_acid_comp_ratio_coef  = calcAminoAcidCompRatioCoef(result.koef_ration, result.akp);
    result.comparable_redundancy_ratio = calcComparableRedundancyRatio(result.akp, min_aminoacidskor, result.fao_voz2007);
    result.balance_index               = calcBalanceIndex(result.fatty_acid_per_100g);
    result.k_general                   = calcBalanceIndexGeneral(result.balance_index, result.biological_value, result.amino_acid_comp_ratio_coef);
}
//================================================================================================================================
void CalculateModule::calcInit(uint32_t comp_num) noexcept
{
    result.comp_num = comp_num;

    if (comp_num == 1)
    {
        result.prop[0] = 1.0;
    }
    if (comp_num == 2)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 3)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 4)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 5)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    //------------------------------------------------------------------------------------------
    if (comp_num == 1)
    {
        result.protein[0] = input[1][0]->value();
    }
    if (comp_num == 2)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 3)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 4)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 5)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    //------------------------------------------------------------------------------------------

    for (uint32_t row = 2; row < AMI+2; ++row)
    {
        if (comp_num == 1)
        {
            result.comp[row-2][0] = input[row][0]->value();
        }
        if (comp_num == 2)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.comp[row-2][col] = input[row][col]->value();
        }
        if (comp_num == 3)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.comp[row-2][col] = input[row][col]->value();
        }
        if (comp_num == 4)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.comp[row-2][col] = input[row][col]->value();
        }
        if (comp_num == 5)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.comp[row-2][col] = input[row][col]->value();
        }
    }
    //------------------------------------------------------------------------------------------
    if (comp_num == 1)
    {
        result.lipids[0] = input[11][0]->value();
    }
    if (comp_num == 2)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 3)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 4)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 5)
    {
        for (uint32_t i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    //------------------------------------------------------------------------------------------
    for (uint32_t row = 12; row < LIP_PROP+12; ++row)
    {
        if (comp_num == 1)
        {
            result.ultimate[row-12][0] = input[row][0]->value();
        }
        if (comp_num == 2)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.ultimate[row-12][col] = input[row][col]->value();
        }
        if (comp_num == 3)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.ultimate[row-12][col] = input[row][col]->value();
        }
        if (comp_num == 4)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.ultimate[row-12][col] = input[row][col]->value();
        }
        if (comp_num == 5)
        {
            for (uint32_t col = 0; col < comp_num; ++col)
                result.ultimate[row-12][col] = input[row][col]->value();
        }
    }
}
//================================================================================================================================
double CalculateModule::calcRecountProteins(uint32_t col, double protein[], double comp) const // col вместо sign
{
    if (result.comp_num == 1)
        return comp * 100 / protein[0];
    //----------------------------------
    if (result.comp_num == 2 && col == 0)
        return comp * 100 / protein[0];
    if (result.comp_num == 2 && col == 1)
        return comp * 100 / protein[1];
    //----------------------------------
    if (result.comp_num == 3 && col == 0)
        return comp * 100 / protein[0];
    if (result.comp_num == 3 && col == 1)
        return comp * 100 / protein[1];
    if (result.comp_num == 3 && col == 2)
        return comp * 100 / protein[2];
    //----------------------------------
    if (result.comp_num == 4 && col == 0)
        return comp * 100 / protein[0];
    if (result.comp_num == 4 && col == 1)
        return comp * 100 / protein[1];
    if (result.comp_num == 4 && col == 2)
        return comp * 100 / protein[2];
    if (result.comp_num == 4 && col == 3)
        return comp * 100 / protein[3];
    //----------------------------------
    if (result.comp_num == 5 && col == 0)
        return comp * 100 / protein[0];
    if (result.comp_num == 5 && col == 1)
        return comp * 100 / protein[1];
    if (result.comp_num == 5 && col == 2)
        return comp * 100 / protein[2];
    if (result.comp_num == 5 && col == 3)
        return comp * 100 / protein[3];
    if (result.comp_num == 5 && col == 4)
        return comp * 100 / protein[4];

    throw CalcException(1);
}
//================================================================================================================================
double CalculateModule::calcAKP(uint32_t row, double prop[], double recount[][MAX_COMP]) const
{
    if (result.comp_num == 1)
        return recount[row][0];
    if (result.comp_num == 2)
        return (prop[0] * recount[row][0]) + (prop[1] * recount[row][1]);
    if (result.comp_num == 3)
        return (prop[0] * recount[row][0]) + (prop[1] * recount[row][1]) + (prop[2] * recount[row][2]);
    if (result.comp_num == 4)
        return (prop[0] * recount[row][0]) + (prop[1] * recount[row][1]) + (prop[2] * recount[row][2])
               + (prop[3] * recount[row][3]);
    if (result.comp_num == 5)
        return (prop[0] * recount[row][0]) + (prop[1] * recount[row][1]) + (prop[2] * recount[row][2])
               + (prop[3] * recount[row][3]) + (prop[4] * recount[row][4]);

    throw CalcException(2);
}
//================================================================================================================================
double CalculateModule::calcAminoacidskor(double akp, const double fao_voz2007) const noexcept
{
    return akp / fao_voz2007 * 100;
}
//================================================================================================================================
double CalculateModule::calcFattyAcidPer100g(double akp, const double fao_voz2007) const noexcept
{
    if (fao_voz2007 <= akp)
        return fao_voz2007 / akp;
    else
        return akp / fao_voz2007;
}
//================================================================================================================================
double CalculateModule::calcRecoutLip(uint32_t row, double lipids[], double ultimate) const
{
    if (result.comp_num == 1)
        return ultimate * 100 / lipids[0];
    //----------------------------------
    if (result.comp_num == 2 && row == 0)
        return ultimate * 100 / lipids[0];
    if (result.comp_num == 2 && row == 1)
        return ultimate * 100 / lipids[1];
    //----------------------------------
    if (result.comp_num == 3 && row == 0)
        return ultimate * 100 / lipids[0];
    if (result.comp_num == 3 && row == 1)
        return ultimate * 100 / lipids[1];
    if (result.comp_num == 3 && row == 2)
        return ultimate * 100 / lipids[2];
    //----------------------------------
    if (result.comp_num == 4 && row == 0)
        return ultimate * 100 / lipids[0];
    if (result.comp_num == 4 && row == 1)
        return ultimate * 100 / lipids[1];
    if (result.comp_num == 4 && row == 2)
        return ultimate * 100 / lipids[2];
    if (result.comp_num == 4 && row == 3)
        return ultimate * 100 / lipids[3];
    //----------------------------------
    if (result.comp_num == 5 && row == 0)
        return ultimate * 100 / lipids[0];
    if (result.comp_num == 5 && row == 1)
        return ultimate * 100 / lipids[1];
    if (result.comp_num == 5 && row == 2)
        return ultimate * 100 / lipids[2];
    if (result.comp_num == 5 && row == 3)
        return ultimate * 100 / lipids[3];
    if (result.comp_num == 5 && row == 4)
        return ultimate * 100 / lipids[4];

    throw CalcException(3);
}
//================================================================================================================================
double CalculateModule::calcKoefRation(double min_aminoacidskor, double aminoacidskor) const noexcept
{
    return min_aminoacidskor / aminoacidskor;
}
//================================================================================================================================
double CalculateModule::calcRatioCalc(uint32_t row, double prop[], double recount_lip[][MAX_COMP]) const
{
    if (result.comp_num == 1)
        return recount_lip[row][0];
    if (result.comp_num == 2)
        return (prop[0] * recount_lip[row][0]) + (prop[1] * recount_lip[row][1]);
    if (result.comp_num == 3)
        return (prop[0] * recount_lip[row][0]) + (prop[1] * recount_lip[row][1]) + (prop[2] * recount_lip[row][2]);
    if (result.comp_num == 4)
        return (prop[0] * recount_lip[row][0]) + (prop[1] * recount_lip[row][1]) + (prop[2] * recount_lip[row][2])
               + (prop[3] * recount_lip[row][3]);
    if (result.comp_num == 5)
        return (prop[0] * recount_lip[row][0]) + (prop[1] * recount_lip[row][1]) + (prop[2] * recount_lip[row][2])
               + (prop[3] * recount_lip[row][3]) + (prop[4] * recount_lip[row][4]);

    throw CalcException(4);
}
//================================================================================================================================
double CalculateModule::calcLipBalanceRatio(double ratio_calc, const double fao_voz2008) const noexcept
{
    if (ratio_calc <= fao_voz2008)
        return ratio_calc / fao_voz2008;
    else
        return fao_voz2008 / ratio_calc;
}
//================================================================================================================================
void CalculateModule::calcFattyAcidCompliance
(double lip_balance_ratio[], double* fattyAcidComplianceResult1, double* fattyAcidComplianceResult2) const noexcept
{
    double multi1, multi2;
    multi1 = multi2 = 1.0;

    for (int i = 0; i < 3; ++i)
        multi1 *= lip_balance_ratio[i];

    *fattyAcidComplianceResult1 = pow(multi1, 1.0 / 3.0);

    for (int i = 0; i < 5; i++)
        multi2 *= lip_balance_ratio[i];

    *fattyAcidComplianceResult2 = pow(multi2, 1.0 / 5.0);
}
//================================================================================================================================
double CalculateModule::calcAminoacidskorSum(double aminoacidskor[]) const noexcept
{
    double sum = 0.0;
    for(int i = 0; i < AMI; i++)
    {
        sum += *aminoacidskor;
        aminoacidskor++;
    }
    return sum;
}
//================================================================================================================================
double CalculateModule::calcKRAS(double aminoacidskor_sum, double min_aminoacidskor) const noexcept
{
    return (aminoacidskor_sum - (min_aminoacidskor * AMI)) / AMI;
}
//================================================================================================================================
double CalculateModule::calcBiologicalValue(double kras)  const noexcept
{
    return 100 - kras;
}
//================================================================================================================================
double CalculateModule::calcAminoAcidCompRatioCoef(double koef_ration[], double akp[]) const noexcept
{
    double numerator = 0.0;
    double denominator = 0.0;
    for (int row = 0; row < AMI; ++row)
    {
        numerator += koef_ration[row] * akp[row];
        denominator += akp[row];
    }
    return numerator / denominator;
}
//================================================================================================================================
double CalculateModule::calcComparableRedundancyRatio(double akp[], double min_aminoacidskor, const double fao_voz2007[]) const noexcept
{
    double numerator = 0.0;
    for(int row = 0; row < AMI; ++row)
    {
        numerator += akp[row] - min_aminoacidskor / 100 * fao_voz2007[row];
    }
    return numerator / (min_aminoacidskor / 100);
}
//================================================================================================================================
double CalculateModule::calcBalanceIndex(double fatty_acid_per_100g[]) const noexcept
{
    double temp = 1.0;
    for(int i = 0; i < AMI; ++i)
    {
        temp *= fatty_acid_per_100g[i];
    }
    return pow(temp, 1.0/9.0);
}
//================================================================================================================================
double CalculateModule::calcBalanceIndexGeneral(double balance_index, double biological_value, double amino_acid_comp_ratio_coef) const noexcept
{
    double temp = (balance_index / 1) * (biological_value / 100) * (amino_acid_comp_ratio_coef / 1);
    return pow(temp, 1.0/3.0);
}

//================================================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

