// -*- mode: c++; coding: cp1251 -*-
#pragma once

#include "TNode.h"
#include "fstream.h"

//*********************************************************//

class TListDef
{
public:
	TListDef();
	~TListDef();

 void AddLast(int index_value, 
			  char word_value[512],
			  char synonym_value[512]);

 void Show(char curdir[512]);

 void SetNext(TListDef * node);
 TListDef* GetNext(){return next;};

 TNodeDef *GetHead();

 void SetIndex(int d);
 int GetIndex();

private:
	int index;
	TNodeDef * head;
	TListDef * next;
};

//**********************************************************//

class TListTerm
{
public:
	TListTerm();
	~TListTerm();

 void AddLast(char word_value[512]);

 void Show(char curdir[512]);

 void SetNext(TListTerm * node);
 TListTerm* GetNext(){return next;};

 TNodeTerm *GetHead();

 void SetIndex(int d);
 void SetFreq(int d);
 void SetEntropy(double d);
 void SetFactorNexus(bool d);
 void SetCountRelations(int d);
 void SetCheck(bool d);
 void SetGroupDependancy(int d);
 void SetValenceRel(int d);
 void SetConnectivitiOfTerm(double d);
 void SetFunctionalWeightOfTerm(int d);
 void SetLeafNode(bool d);
 void SetCheck2(bool d);
	
 int GetIndex();
 int GetFreq();
 double GetEntropy();
 bool GetFactorNexus();
 int GetCountRelations();
 bool GetCheck();
 int GetGroupDependancy();
 int GetValenceRel();
 double GetConnectivitiOfTerm();
 bool GetLeafNode();
 int GetFunctionalWeightOfTerm();
 bool GetCheck2();

private:
	int index;
	int freq; //T1						//Частота
	double entropy; //T2				//Энтропия
	bool FactorNexus; //T3				//Показатель ядра
	int CountRelations;					//Фактическое количество связей термина
	bool check;							//Используется для определения принадлежности вершины
										//к группе зависимости ядра
	int GroupDependancy;//T4			//Мощность группы зависимости ядра	
	int ValenceRel; //T5				//Степень релевантности
	double ConnectivitiOfTerm; //T6		//Связность термина
	bool LeafNode; //T7					//Листовой параметр термина
	int FunctionalWeightOfTerm; //T8	//Функциональный вес термина
	bool check2;						//Используется для временного удаления вершины из графа
	TNodeTerm * head;
	TListTerm * next;
};

//**********************************************************//
//**********************************************************//

class TList_Definition
{
public:
	TList_Definition();
	~TList_Definition();

	TListDef *GetHead();

	void AddLast_List(int index, char term[512], char synonym[512]);
	void AddLast_Word(char term[512]);
	void Show(char curdir[512]);
	
private:
	TListDef * head_Definition;
};

//**********************************************************//

class TList_TermList
{
public:
	TList_TermList();
	~TList_TermList();

	TListTerm *GetHead();

	//Добавление нового списка в список
	void AddLast_List(int index, 
					  char term[512],
					  int freq);

	void AddLast_Word(char term[512]);
	void Show(char curdir[512]);
	//данная процедура позволяет найти термин в формулировке определения
	bool STRSTR_TermsInDef(TListTerm * term, 
						   TListDef * Definition);
	//Данная процедура расчитывает энтропию для каждого термина
	void CalculationEntropy(); //T2
	
	//Данная процедура расчитывает связность каждого термина
	void ConnectivityOfTerm(); //T6

private:
	TListTerm * head_Term;
};

//*********************************************************//

class TList_Relation
{
public:
	TList_Relation();
	~TList_Relation();

 void AddLast_Relation(int index_of_relation_value, 
					   int index_of_term_value,
					   int direction_value);

 void Show(char curdir[512]);

 TRelation *GetHead();

	//Определение связей
	void Identification_of_relation(TList_TermList &Terms, 
								 TList_Definition &Definitions);
	
	//Данная процедура определяет показатель ядра (количество 
	//инцендентных дуг> или < среднего числа инцендентных дуг графа)
	void Factor_of_Nexus(TList_TermList &TERMS); //T3

	//Данные процедуры определяют мощность зависимости группы ядра (параметр Т4)
	void CalculationGroupDependancy(TListTerm * pTerm, 
									TListTerm * pTermHead, 
									TRelation *head_Rel);
	void GroupDependancy(TList_TermList &TERMS); //T4

	void ValenceRelevance(TList_TermList &TERMS); //Т5

	//отметить термины в определении с метки TempRel
	bool MarkDef(TRelation *TempRel, TListTerm * pTermHead);
	
	//Если в определении есть отмеченный термин - отмечаем остальные
	void CheckDef(TListTerm * pTermHead, TRelation *head_Rel);

	//Расчитываем листовой показатель терминов (параметр Т7)
	void LeafNodeParamOfTerm(TList_TermList &TERMS);
	
	//Отсечение листов графа
	void PruningOfLeafNode(TList_TermList &TERMS);

	//Данная процедура считает функциональный вес термина
	void CalculationFunctionalWeigth(TList_TermList &TERMS);

private:
	TRelation * head_Rel;
};

//**********************************************************//
//**********************************************************//

class TList_Relation_weight
{
public:
	TList_Relation_weight();
	~TList_Relation_weight();

 void AddLast_Relation(int index_of_term1_value, 
					   int index_of_term2_value,
					   int MinWay);

 //Первое заполнение массива
 void First_fill(TList_TermList &TERMS, TList_Relation &Relations);
 
 //Поиск минимального пути между всеми вершинами
 void Min_Way(TList_TermList &TERMS, TList_Relation &Relations);

 //R1 Сила семантической связи
 void PowerOfSamantikRelation(TList_TermList &TERMS, TList_Relation &Relations);

 //R2 Количество общих терминов учитывая частоту
 void CountTermWithFreq(TList_TermList &TERMS, TList_Relation &Relations);

 //R3 Релевантность связи
 void ValenceRelevanceOfRelations(TList_TermList &TERMS);

 //R4 Релевантность связи
 void Co_OccurrenceOfTerms(TList_TermList &TERMS, TList_Definition &Paragraph);

 //Функция позволит определить количество вхождений термина в параграф
 int STRSTR_TermsInParagraph(TListTerm * term, TListDef * Definition);

 void Show(char curdir[512]);

 TRelation_weight *GetHead();

private:
	TRelation_weight * head_Rel;
};

//**********************************************************//
//**********************************************************//
