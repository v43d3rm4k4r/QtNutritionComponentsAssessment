#include "mainwindow.h"

CalculateModule::CalculateModule(const QVector<QList<QDoubleSpinBox*>>& input, int comp_num)
    : input{input}
{
    calcInit(comp_num);

    try
    {
        for (int row = 0; row < AMI; ++row)
        {
            if (comp_num == 1)
            {
                result.recount[row][0] = calcRecountProteins(0, result.protein, result.comp[row][0]);
            }
            for (int col = 0; col < comp_num; ++col)
            {
                if (comp_num == 2)
                {
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                }
                if (comp_num == 3)
                {
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                }
                if (comp_num == 4)
                {
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                }
                if (comp_num == 5)
                {
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                    result.recount[row][col] = calcRecountProteins(col, result.protein, result.comp[row][col]);
                }

                result.akp[row] = calcAKP(result.prop, result.recount, row);
                result.aminoacidskor[row] = calcAminoacidskor(result.akp[row], result.fao_voz2007[row]);

            }
        }

    }
    catch (std::exception& ex)
    {
        qDebug() << ex.what();
    }





}
//======================================================================================================
void CalculateModule::calcInit(int comp_num) noexcept
{
    result.comp_num = comp_num;

    if (comp_num == 1)
    {
        result.prop[0] = 1.0;
    }
    if (comp_num == 2)
    {
        for (int i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 3)
    {
        for (int i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 4)
    {
        for (int i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    if (comp_num == 5)
    {
        for (int i = 0; i < comp_num; ++i)
            result.prop[i] = input[0][i]->value();
    }
    //------------------------------------------------------------------------------------------
    if (comp_num == 1)
    {
        result.protein[0] = input[1][0]->value();
    }
    if (comp_num == 2)
    {
        for (int i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 3)
    {
        for (int i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 4)
    {
        for (int i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    if (comp_num == 5)
    {
        for (int i = 0; i < comp_num; ++i)
            result.protein[i] = input[1][i]->value();
    }
    //------------------------------------------------------------------------------------------
    for (int row = 2; row < AMI; ++row)
    {
        if (comp_num == 1)
        {
            result.comp[row][0] = input[row][0]->value();
        }
        if (comp_num == 2)
        {
            for (int col = 0; col < comp_num; ++col)
                result.comp[row][col] = input[row][col]->value();
        }
        if (comp_num == 3)
        {
            for (int col = 0; col < comp_num; ++col)
                result.comp[row][col] = input[row][col]->value();
        }
        if (comp_num == 4)
        {
            for (int col = 0; col < comp_num; ++col)
                result.comp[row][col] = input[row][col]->value();
        }
        if (comp_num == 5)
        {
            for (int col = 0; col < comp_num; ++col)
                result.comp[row][col] = input[row][col]->value();
        }
    }
    //------------------------------------------------------------------------------------------
    if (comp_num == 1)
    {
        result.lipids[0] = input[11][0]->value();
    }
    if (comp_num == 2)
    {
        for (int i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 3)
    {
        for (int i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 4)
    {
        for (int i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    if (comp_num == 5)
    {
        for (int i = 0; i < comp_num; ++i)
            result.lipids[i] = input[11][i]->value();
    }
    //------------------------------------------------------------------------------------------
    for (int row = 12; row < LIP_PROP; ++row)
    {
        if (comp_num == 1)
        {
            result.ultimate[row][0] = input[row][0]->value();
        }
        if (comp_num == 2)
        {
            for (int col = 0; col < comp_num; ++col)
                result.ultimate[row][col] = input[row][col]->value();
        }
        if (comp_num == 3)
        {
            for (int col = 0; col < comp_num; ++col)
                result.ultimate[row][col] = input[row][col]->value();
        }
        if (comp_num == 4)
        {
            for (int col = 0; col < comp_num; ++col)
                result.ultimate[row][col] = input[row][col]->value();
        }
        if (comp_num == 5)
        {
            for (int col = 0; col < comp_num; ++col)
                result.ultimate[row][col] = input[row][col]->value();
        }
    }
}
//======================================================================================================
double CalculateModule::calcRecountProteins(int col, double* protein, double comp) // col вместо sign
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
//======================================================================================================
double CalculateModule::calcAKP(double* prop, double recount[][MAX_COMP], int row)
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
//======================================================================================================
double CalculateModule::calcAminoacidskor(double akp, double fao_voz2007) noexcept
{
    return akp / fao_voz2007 * 100;
}

//======================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

