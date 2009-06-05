// -*- mode: c++; coding: cp1251 -*-
#pragma once

//*******************************************

class TNodeDef
{
public:
	TNodeDef(void);
	TNodeDef(//int index_value, 
			char term_value[512],
			 char synonym_value[512]);
	~TNodeDef(void);

 char *GetTerm();
 char *GetSynonym();

 void SetTerm(char d[512]);
 void SetSynonym(char d[512]);
 
 void SetNext(TNodeDef * node);

 TNodeDef *GetNext();

private:
 char term[512];
 char synonym[512];
 TNodeDef * next;
};

//*********************************************************

//*******************************************

class TNodeTerm
{
public:
	TNodeTerm(void);
	TNodeTerm(char term_value[512]);
	~TNodeTerm(void);
 
 char *GetTerm();
 
 void SetTerm(char d[512]);
 
 void SetNext(TNodeTerm * node);

 TNodeTerm *GetNext();

private:
 char term[512];
 TNodeTerm * next;
};

//*********************************************************

//*******************************************

class TRelation
{
public:
	TRelation(void);
	TRelation(int index_of_relation_value, 
			  int index_of_term_value,
			  int direction_value);
	~TRelation(void);

 int GetIndex_of_relation();
 int GetIndex_of_term();
 int GetDirection();
 bool GetCheckR() {return check;};

 void SetIndex_of_relation(int d);
 void SetIndex_of_term(int d);
 void SetDirection(int d);
 void SetCheckR(bool d) {check = d;};
  
 void SetNext(TRelation * node);

 TRelation *GetNext(){return next;};

private:
 int index_of_relation;
 int index_of_term;
 int direction;
 TRelation * next;
 bool check;
};

//*********************************************************

//*******************************************

class TRelation_weight
{
public:
	TRelation_weight(void);
	TRelation_weight(int index_of_term1_value, 
			  int index_of_term2_value);
	~TRelation_weight(void);

 int GetIndex_of_term1();
 int GetIndex_of_term2();
 int GetMinWay();
 double GetPowerOfSamantikRelation();
 double GetCountAggregateTerm();
 bool GetValenceRel();
 int GetCo_Occurrence();

 void SetIndex_of_term1(int d);
 void SetIndex_of_term2(int d);
 void SetMinWay(int d);
 void SetPowerOfSamantikRelation(double d);
 void SetCountAggregateTerm(double d);
 void SetValenceRel(bool d);
 void SetCo_Occurrence(int d);
  
 void SetNext(TRelation_weight * node);

 TRelation_weight *GetNext(){return next;};

private:
 int index_of_term1;
 int index_of_term2;
 int MinWay;
 double PowerOfSamantikRelation; //R1		//сила семантической связи
 double CountAggregateTerm;		 //R2	    //связь через определения понятий опираясь на частоту
 bool ValenceRel;				 //R3		//Релевантность связи
 int Co_Occurrence;				 //R4		//совстречаемость терминов

 TRelation_weight * next;
};

//*********************************************************
