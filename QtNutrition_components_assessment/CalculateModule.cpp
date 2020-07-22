#include "mainwindow.h"

CalculateModule::CalculateModule(const QVector<QList<QDoubleSpinBox*>>& input, int comp_num)
    : input{input}
{
    calcInit(comp_num);


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


        }





    }



}
//======================================================================================================
void CalculateModule::calcInit(int comp_num)
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
void CalculateModule::calcRecountProteins(int col, double* protein, double comp) // col вместо sign
{
    if (result.comp_num == 1)
    {

    }
}
//======================================================================================================
const Summary& CalculateModule::getResult() const
{
    return result;
}

