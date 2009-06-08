// -*- mode: c++; coding: cp1251 -*-
#include "TNode.h"
#include <cstring>

//****************************************************
//****************************************************
//****************************************************

TNodeDef::TNodeDef(void)
{
  strcpy(term,'\0');
  strcpy(synonym,'\0');
  next = NULL;
}

//------------------------------------

TNodeDef::TNodeDef(const char word_value[512],
		   const char synonym_value[512])
{
  strcpy(term,word_value);
  strcpy(synonym,synonym_value);
  next = NULL;
}
//------------------------------------

TNodeDef::~TNodeDef(void)
{
}
//------------------------------------

const char *TNodeDef::GetTerm()
{
	return term;
}

//------------------------------------

const char *TNodeDef::GetSynonym()
{
	return synonym;
}

//------------------------------------

void TNodeDef::SetTerm(const char d[512])
{
	strcpy(term,d);
}

//------------------------------------

void TNodeDef::SetSynonym(const char d[512])
{
	strcpy(synonym,d);
}

//------------------------------------

TNodeDef *TNodeDef::GetNext()
{
	return next;
}
//------------------------------------

void TNodeDef::SetNext(TNodeDef*node)
{
	next = node;
}
//------------------------------------
//****************************************************
//****************************************************

TNodeTerm::TNodeTerm(void)
{
  strcpy(term,'\0');
  next = NULL;
}

//------------------------------------

TNodeTerm::TNodeTerm(const char word_value[512])
{
  strcpy(term,word_value);
  next = NULL;
}
//------------------------------------

TNodeTerm::~TNodeTerm(void)
{
}
//------------------------------------

const char *TNodeTerm::GetTerm()
{
	return term;
}

void TNodeTerm::SetTerm(const char d[512])
{
	strcpy(term,d);
}

//------------------------------------

TNodeTerm *TNodeTerm::GetNext()
{
	return next;
}
//------------------------------------

void TNodeTerm::SetNext(TNodeTerm*node)
{
	next = node;
}
//------------------------------------

//****************************************************
//****************************************************

TRelation::TRelation(void)
{
  index_of_relation = 0;
  index_of_term=0;
  direction = 0;
  next = NULL;
}

//------------------------------------

TRelation::TRelation(int index_of_relation_value, 
			 int index_of_term_value,
			 int direction_value)
{
  index_of_relation = index_of_relation_value;
  index_of_term = index_of_term_value;
  direction = direction_value;
  next = NULL;
}
//------------------------------------

TRelation::~TRelation(void)
{
}
//------------------------------------

int TRelation::GetIndex_of_relation()
{
	return index_of_relation;
}

//------------------------------------

int TRelation::GetIndex_of_term()
{
	return index_of_term;
}

//------------------------------------
int TRelation::GetDirection()
{
	return direction;
}
//------------------------------------

void TRelation::SetIndex_of_relation(int d)
{
	index_of_relation = d;
}

//------------------------------------

void TRelation::SetIndex_of_term(int d)
{
	index_of_term = d;
}

//------------------------------------

void TRelation::SetDirection(int d)
{
	direction = d;
}

//------------------------------------
//------------------------------------

void TRelation::SetNext(TRelation*node)
{
	next = node;
}
//------------------------------------

//****************************************************************

//****************************************************

TRelation_weight::TRelation_weight(void)
{
  index_of_term1 = 0;
  index_of_term2 = 0;
  next = NULL;
}

//------------------------------------

TRelation_weight::TRelation_weight(int index_of_term1_value, 
					 int index_of_term2_value)
{
  index_of_term1 = index_of_term1_value;
  index_of_term2 = index_of_term2_value;
  MinWay=-1;
  next = NULL;
}
//------------------------------------

TRelation_weight::~TRelation_weight(void)
{
}
//------------------------------------

int TRelation_weight::GetIndex_of_term1()
{
	return index_of_term1;
}

//------------------------------------

int TRelation_weight::GetIndex_of_term2()
{
	return index_of_term2;
}

//------------------------------------

int TRelation_weight::GetMinWay()
{
	return MinWay;
}

//------------------------------------

double TRelation_weight::GetPowerOfSamantikRelation()
{
	return PowerOfSamantikRelation;
}

//------------------------------------

double TRelation_weight::GetCountAggregateTerm()
{
	return CountAggregateTerm;
}

//------------------------------------

bool TRelation_weight::GetValenceRel()
{
	return ValenceRel;
}

//------------------------------------

int TRelation_weight::GetCo_Occurrence()
{
	return Co_Occurrence;
}

//------------------------------------
//------------------------------------
//------------------------------------
//------------------------------------

void TRelation_weight::SetIndex_of_term1(int d)
{
	index_of_term1 = d;
}

//------------------------------------

void TRelation_weight::SetIndex_of_term2(int d)
{
	index_of_term2 = d;
}

//------------------------------------

void TRelation_weight::SetNext(TRelation_weight*node)
{
	next = node;
}
//------------------------------------

void TRelation_weight::SetMinWay(int d)
{
	MinWay = d;
}

//------------------------------------

void TRelation_weight::SetPowerOfSamantikRelation(double d)
{
	PowerOfSamantikRelation = d;
}

//------------------------------------

void TRelation_weight::SetCountAggregateTerm(double d)
{
	CountAggregateTerm = d;
}

//------------------------------------

void TRelation_weight::SetValenceRel(bool d)
{
	ValenceRel = d;
}

//------------------------------------

void TRelation_weight::SetCo_Occurrence(int d)
{
	Co_Occurrence = d;
}

//------------------------------------
