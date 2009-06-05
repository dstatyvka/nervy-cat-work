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
	int freq; //T1						//�������
	double entropy; //T2				//��������
	bool FactorNexus; //T3				//���������� ����
	int CountRelations;					//����������� ���������� ������ �������
	bool check;							//������������ ��� ����������� �������������� �������
										//� ������ ����������� ����
	int GroupDependancy;//T4			//�������� ������ ����������� ����	
	int ValenceRel; //T5				//������� �������������
	double ConnectivitiOfTerm; //T6		//��������� �������
	bool LeafNode; //T7					//�������� �������� �������
	int FunctionalWeightOfTerm; //T8	//�������������� ��� �������
	bool check2;						//������������ ��� ���������� �������� ������� �� �����
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

	//���������� ������ ������ � ������
	void AddLast_List(int index, 
					  char term[512],
					  int freq);

	void AddLast_Word(char term[512]);
	void Show(char curdir[512]);
	//������ ��������� ��������� ����� ������ � ������������ �����������
	bool STRSTR_TermsInDef(TListTerm * term, 
						   TListDef * Definition);
	//������ ��������� ����������� �������� ��� ������� �������
	void CalculationEntropy(); //T2
	
	//������ ��������� ����������� ��������� ������� �������
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

	//����������� ������
	void Identification_of_relation(TList_TermList &Terms, 
								 TList_Definition &Definitions);
	
	//������ ��������� ���������� ���������� ���� (���������� 
	//������������ ���> ��� < �������� ����� ������������ ��� �����)
	void Factor_of_Nexus(TList_TermList &TERMS); //T3

	//������ ��������� ���������� �������� ����������� ������ ���� (�������� �4)
	void CalculationGroupDependancy(TListTerm * pTerm, 
									TListTerm * pTermHead, 
									TRelation *head_Rel);
	void GroupDependancy(TList_TermList &TERMS); //T4

	void ValenceRelevance(TList_TermList &TERMS); //�5

	//�������� ������� � ����������� � ����� TempRel
	bool MarkDef(TRelation *TempRel, TListTerm * pTermHead);
	
	//���� � ����������� ���� ���������� ������ - �������� ���������
	void CheckDef(TListTerm * pTermHead, TRelation *head_Rel);

	//����������� �������� ���������� �������� (�������� �7)
	void LeafNodeParamOfTerm(TList_TermList &TERMS);
	
	//��������� ������ �����
	void PruningOfLeafNode(TList_TermList &TERMS);

	//������ ��������� ������� �������������� ��� �������
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

 //������ ���������� �������
 void First_fill(TList_TermList &TERMS, TList_Relation &Relations);
 
 //����� ������������ ���� ����� ����� ���������
 void Min_Way(TList_TermList &TERMS, TList_Relation &Relations);

 //R1 ���� ������������� �����
 void PowerOfSamantikRelation(TList_TermList &TERMS, TList_Relation &Relations);

 //R2 ���������� ����� �������� �������� �������
 void CountTermWithFreq(TList_TermList &TERMS, TList_Relation &Relations);

 //R3 ������������� �����
 void ValenceRelevanceOfRelations(TList_TermList &TERMS);

 //R4 ������������� �����
 void Co_OccurrenceOfTerms(TList_TermList &TERMS, TList_Definition &Paragraph);

 //������� �������� ���������� ���������� ��������� ������� � ��������
 int STRSTR_TermsInParagraph(TListTerm * term, TListDef * Definition);

 void Show(char curdir[512]);

 TRelation_weight *GetHead();

private:
	TRelation_weight * head_Rel;
};

//**********************************************************//
//**********************************************************//
