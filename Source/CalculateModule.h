/*
 * CalculateModule.h
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#pragma once

#include <iostream>
#include <QVector>
#include <QList>
#include <QDoubleSpinBox>
#include <QDebug>

#define AMI 9      // количество аминокислот
#define LIP_PROP 5 // липидные хар-ки (аналог аминокислот)
#define MAX_COMP 5 // максимальное количество компонентов
//======================================================================================================
struct Summary
{
    uint32_t comp_num = 0; // кол-во компонентов

    double fao_voz2007[AMI] = {3.9, 1.5, 3.0, 5.9, 4.5, 2.2, 2.3, 0.6, 3.8};
    double fao_voz2008[LIP_PROP] = {33.33, 33.33, 33.33, 6.67, 26.67};

    /*БЕЛКИ*/
    double protein[MAX_COMP] = {0.0}; // кол-во белка на 100г каждого компонента
    double comp[AMI][MAX_COMP] = {{0.0}}; // для аминокислот

    /*ЛИПИДЫ*/
    double lipids[MAX_COMP] = {0.0};
    double ultimate[LIP_PROP][MAX_COMP] = {{0.0}};

    /*БЕЛКИ*/
    double akp[AMI] = {0.0};
    double aminoacidskor[AMI] = {0.0};
    double koef_ration[AMI] = {0.0};
    double fatty_acid_per_100g[AMI] = {0.0};
    double prop[MAX_COMP] = {0.0}; // для пропорций, если компонентов > 1
    double recount[AMI][LIP_PROP] = {{0.0}}; // для пересчёта аминокилот
    /*коэффициент разбалансированности, биологическая ценность,
        коэффициент рациональности аминокислотного состава,
        индекс сбалансированности, показатель сопоставимой избыточности и
        коэффициент сбалансированности всей белковой составляющей(вычисляются 1 раз в конце)*/
    double kras = 0.0;
    double biological_value = 0.0; // bc
    double amino_acid_comp_ratio_coef = 0.0; // r
    double comparable_redundancy_ratio = 0.0; // g
    double balance_index = 0.0; // s
    double k_general = 0.0;

    /*ЛИПИДЫ*/
    double recount_lip[LIP_PROP][MAX_COMP] = {{0.0}};
    double ratio_calc[LIP_PROP] = {0.0};
    double lip_balance_ratio[LIP_PROP] = {0.0};
    double fattyAcidComplianceResult1 = 0.0;
    double fattyAcidComplianceResult2 = 0.0;
};
//======================================================================================================
class CalcException : public std::exception
{
    char* _what;

public:
    CalcException(uint32_t func_num) : _what{nullptr}
    {
        if (func_num == 1)
            strcpy(_what, "Error in calcRecountProteins()");

        if (func_num == 2)
            strcpy(_what, "Error in calcAKP()");

        if (func_num == 3)
            strcpy(_what, "Error in calcRecoutLip()");

        if (func_num == 4)
            strcpy(_what, "Error in calcRatioCalc()");
    }

    const char* what() const noexcept override
    {
        return _what;
    }
};
//======================================================================================================
class CalculateModule
{
    QVector<QVector<QDoubleSpinBox*>> input;
    Summary result;

    // CALCULATIONS
    void calcInit(uint32_t comp_num) noexcept;

    /*ВЫЧИСЛЕНИЯ БЕЛКОВ*/
    double calcRecountProteins(uint32_t col, double* protein, double comp) const;
    double calcAKP(uint32_t row, double* prop, double recount[][MAX_COMP]) const;
    double calcAminoacidskor(double akp, const double fao_voz2007) const noexcept;
    double calcFattyAcidPer100g(double akp, const double fao_voz2007) const noexcept;
    double calcKoefRation(double min_aminoacidskor, double aminoacidskor) const noexcept;

    double calcAminoacidskorSum(double aminoacidskor[]) const noexcept;
    double calcKRAS(double aminoacidskor_sum, double min_aminoacidskor) const noexcept;
    double calcBiologicalValue(double kras) const noexcept;
    double calcAminoAcidCompRatioCoef(double koef_ration[], double akp[]) const noexcept;
    double calcComparableRedundancyRatio(double akp[], double min_aminoacidskor, const double fao_voz2007[]) const noexcept;
    double calcBalanceIndex(double fatty_acid_per_100g[]) const noexcept;
    double calcBalanceIndexGeneral(double balance_index, double biological_value,double amino_acid_comp_ratio_coef) const noexcept;


    /*ВЫЧИСЛЕНИЯ ЛИПИДОВ*/
    double calcRecoutLip(uint32_t row, double result[], double ultimate) const;
    double calcRatioCalc(uint32_t row, double prop[], double recount_lip[][MAX_COMP]) const;
    double calcLipBalanceRatio(double ratio_calc, const double fao_voz2008) const noexcept;
    void   calcFattyAcidCompliance(double lip_balance_ratio[], double* fattyAcidComplianceResult1,
                                                                      double* fattyAcidComplianceResult2) const noexcept;

public:
    // вызываем в конструкторе все методы вычислений
    CalculateModule(const QVector<QVector<QDoubleSpinBox*>>& input, uint32_t comp_num) noexcept;

    const Summary& getResult() const;
};

