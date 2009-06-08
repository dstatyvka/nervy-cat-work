// -*- mode: c++; coding: cp1251 -*-
#include "TList.h"
#include "TNode.h"

#include <cstring>
#include <fstream>
#include <cmath>

//***********************************
//***********************************/
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TListTerm
//***********************************
//***********************************/

TListTerm::TListTerm(void)
{
  head = NULL;
  next = NULL;
}

TListTerm::~TListTerm(void)
{
  TNodeTerm *p = head;

  while (p!=NULL)
  {
    TNodeTerm *pp = p -> GetNext();
    delete p;
    p=pp;
  }
}

//---------------------------------------

TNodeTerm *TListTerm::GetHead()
{
  return head;
}

//---------------------------------------

void TListTerm::SetNext(TListTerm*node)
{
  next = node;
}

//------------------------------------

double TListTerm::GetEntropy()
{
  return entropy;
}

//------------------------------------

bool TListTerm::GetFactorNexus()
{
  return FactorNexus;
}

//------------------------------------

int TListTerm::GetFreq()
{
  return freq;
}

//------------------------------------

int TListTerm::GetIndex()
{
  return index;
}

//------------------------------------

int TListTerm::GetCountRelations()
{
  return CountRelations;
}

//------------------------------------

bool TListTerm::GetCheck()
{
  return check;
}

//------------------------------------

int TListTerm::GetGroupDependancy()
{
  return GroupDependancy;
}

//------------------------------------

int TListTerm::GetValenceRel()
{
  return ValenceRel;
}

//------------------------------------

double TListTerm::GetConnectivitiOfTerm()
{
  return ConnectivitiOfTerm;
}

//------------------------------------

bool TListTerm::GetLeafNode()
{
  return LeafNode;
}

//------------------------------------

int TListTerm::GetFunctionalWeightOfTerm()
{
  return FunctionalWeightOfTerm;
}

//------------------------------------

bool TListTerm::GetCheck2()
{
  return check2;
}

//------------------------------------

void TListTerm::SetFreq(int d)
{
  freq=d;
}

//------------------------------------

void TListTerm::SetEntropy(double d)
{
  entropy=d;
}

//------------------------------------

void TListTerm::SetFactorNexus(bool d)
{
  FactorNexus=d;
}

//------------------------------------

void TListTerm::SetIndex(int d)
{
  index=d;
}

//------------------------------------

void TListTerm::SetCountRelations(int d)
{
  CountRelations=d;
}

//---------------------------------------

void TListTerm::SetCheck(bool d)
{
  check=d;
}

//---------------------------------------

void TListTerm::SetGroupDependancy(int d)
{
  GroupDependancy=d;
}

//---------------------------------------

void TListTerm::SetValenceRel(int d)
{
  ValenceRel=d;
}

//---------------------------------------

void TListTerm::SetConnectivitiOfTerm(double d)
{
  ConnectivitiOfTerm=d;
}

//---------------------------------------


void TListTerm::SetLeafNode(bool d)
{
  LeafNode=d;
}

//---------------------------------------

void TListTerm::SetFunctionalWeightOfTerm(int d)
{
  FunctionalWeightOfTerm=d;
}

//---------------------------------------

void TListTerm::SetCheck2(bool d)
{
  check2=d;
}

//---------------------------------------

void TListTerm::AddLast(const char term_value[512])
{
  if (head==NULL)
  {
    TNodeTerm *node = new TNodeTerm(term_value);
    head=node;
    return;
  }
  else
  {
    for (TNodeTerm *p=head;p!=NULL; p=p->GetNext())
    {
      if (p->GetNext()==NULL)
      {
	TNodeTerm *node = new TNodeTerm(term_value);
	p->SetNext(node);
	return;
      }
    }
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TListDef
//***********************************
//***********************************/

TListDef::TListDef(void)
{
  head = NULL;
  next = NULL;
}

TListDef::~TListDef(void)
{
  TNodeDef *p = head;

  while (p!=NULL)
  {
    TNodeDef *pp = p -> GetNext();
    delete p;
    p=pp;
  }
}

//---------------------------------------

TNodeDef *TListDef::GetHead()
{
  return head;
}

//---------------------------------------

void TListDef::SetNext(TListDef*node)
{
  next = node;
}

//---------------------------------------


void TListDef::Show(const char curdir[512])
{
  std::string filename = curdir;
  filename += "_ResultDef.txt";

  std::ofstream o(filename.c_str());
	
  o <<GetIndex()<<"\t";

  for(TNodeDef *p=head; p!=NULL; p=p->GetNext())
  {
    o <<p->GetTerm()<<std::endl;
  }
}

//---------------------------------------

void TListDef::AddLast(int index_value, 
		       const char term_value[512],
		       const char synonym_value[512])
{
  if (head==NULL)
  {
    TNodeDef *node = new TNodeDef(term_value, synonym_value);
    head=node;
    SetIndex(index_value);
    return;
  }
  else
  {
    for (TNodeDef *p=head;p!=NULL; p=p->GetNext())
    {
      if (p->GetNext()==NULL)
      {
	TNodeDef *node = new TNodeDef(term_value, 
				      synonym_value);
	p->SetNext(node);
	return;
      }
    }
  }
}

//---------------------------------------

int TListDef::GetIndex()
{
  return index;
}

//---------------------------------------

void TListDef::SetIndex(int d)
{
  index = d;
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TList_Definition

TList_Definition::TList_Definition(void)
{
  head_Definition = NULL;
}

//---------------------------------------

TList_Definition::~TList_Definition(void)
{
  TListDef *p = head_Definition;
  delete p;
}

//---------------------------------------

TListDef *TList_Definition::GetHead()
{
  return head_Definition;
}

//---------------------------------------
//---------------------------------------

void TList_Definition::AddLast_List(int index, const char term[512], const char synonym[512])
{
  TListDef *node = new TListDef(); 
  node->AddLast(index, term, synonym);  
	
  if (head_Definition==NULL)
  {	
    head_Definition=node;
  }else
  {
    TListDef *p = 0;
    for (p=head_Definition; p->GetNext()!=NULL; p=p->GetNext())
    {}
    p->SetNext(node);
  }
}

//---------------------------------------
void TList_Definition::AddLast_Word(const char term[512])
{
  TListDef *p=head_Definition;
  while(p->GetNext()!=NULL)
    p=p->GetNext();
  p->AddLast(0, term, "");
}
//---------------------------------------

void TList_Definition::Show(const char curdir[512])
{
  std::string filename = curdir;
  filename += "_ResultDef.txt";

  std::ofstream o(filename.c_str());
	
  for(TListDef *p=head_Definition; p!=NULL; p=p->GetNext())
  {
    o <<p->GetIndex()<<"\t";
    for(TNodeDef *p2=p->GetHead(); p2!=NULL; p2=p2->GetNext())
    {
      o  <<p2->GetTerm()<<"\t"
	 <<p2->GetSynonym()<< std::endl;
    }
    o <<"--------------------"<<std::endl;
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TList_TermList
//***********************************
//***********************************/

TList_TermList::TList_TermList(void)
{
  head_Term = NULL;
}

//---------------------------------------

TList_TermList::~TList_TermList(void)
{
  TListTerm *p = head_Term;
  delete p;
}

//---------------------------------------

TListTerm *TList_TermList::GetHead()
{
  return head_Term;
}

//---------------------------------------
//---------------------------------------

void TList_TermList::AddLast_List(int index, 
				  char term[512], 
				  int freq)
{
  TListTerm *node = new TListTerm(); 
  node->AddLast(term); 
  node->SetFreq(freq);
  node->SetIndex(index);
  node->SetEntropy(0);
  node->SetFactorNexus(0);
  node->SetCountRelations(0);
  node->SetCheck(0);
  node->SetGroupDependancy(0);
  node->SetValenceRel(0);
  node->SetConnectivitiOfTerm(0);
  node->SetLeafNode(0);
  node->SetFunctionalWeightOfTerm(0);
  node->SetCheck2(0);
	
  if (head_Term==NULL)
  {	
    head_Term=node;
  }else
  {
    TListTerm *p = 0;
    for (p=head_Term; 
	 p->GetNext()!=NULL; 
	 p=p->GetNext())
    {}
    p->SetNext(node);
  }
}

//---------------------------------------
void TList_TermList::AddLast_Word(char term[512])
{
  TListTerm *p=head_Term;
  for (p; p->GetNext()!=NULL; p=p->GetNext())
  {}
  p->AddLast(term);
}
//---------------------------------------

void TList_TermList::Show(char curdir[512])
{
  strcat(curdir,"_ResultTerm.txt");

  std::ofstream o(curdir);
	
  for(TListTerm *p=head_Term; p!=NULL; p=p->GetNext())
  {
    o <<p->GetIndex()<<"\t"
      <<p->GetHead()->GetTerm()<<"\t\t"
      <<"T1="<<p->GetFreq()<<"\t"
      <<"T2="<<p->GetEntropy()<<"\t"
      <<"T3="<<p->GetFactorNexus()<<"\t"
      <<"RelCount="<<p->GetCountRelations()<<"\t"
      <<"T4="<<p->GetGroupDependancy()<<"\t"
      <<"T5="<<p->GetValenceRel()<<"\t"
      <<"T6="<<p->GetConnectivitiOfTerm()<<"\t"
      <<"T7="<<p->GetLeafNode()<<"\t"
      <<"T8="<<p->GetFunctionalWeightOfTerm()<<std::endl;
    /*<<p->GetFreq()<<"\t"
      <<p->GetEntropy()<<"\t"
      <<p->GetFactorNexus()<<"\t"
      <<p->GetCountRelations()<<"\t"
      <<p->GetGroupDependancy()<<"\t"
      <<p->GetValenceRel()<<"\t"
      <<p->GetConnectivitiOfTerm()<<"\t"
      <<p->GetLeafNode()<<"\t"
      <<p->GetFunctionalWeightOfTerm()<<std::endl;*/
    o <<"--------------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
  }
}

//---------------------------------------
//������� ��������� ���������� ���� �� ��������� ������� � ����������� 
bool TList_TermList::STRSTR_TermsInDef(TListTerm * term,
				       TListDef * Definition)
{
  TNodeTerm *ptrTerm;
  TNodeDef *ptrDef2;

  for (TNodeDef *ptrDef = Definition->GetHead(); 
       ptrDef!=NULL; 
       ptrDef=ptrDef->GetNext())
  {
    if (ptrDef!=Definition->GetHead())//��������� ������������ �������
    {
      ptrDef2=ptrDef;
		
      ptrTerm = term->GetHead(); //���������� ������ ����� ������� �.�. � ��� ���� ������
      ptrTerm = ptrTerm->GetNext(); //����� ������ ����� �������

      //���� ������ ����� ������� ��������� �� ������ � �����������
      if ((strcmp(ptrTerm->GetTerm(), ptrDef->GetTerm())==0))
      {
	while (ptrTerm) //���� �� ���������� ��� ����� �������
	{
	  if ((ptrDef2->GetNext()!=NULL)&&
	      (ptrTerm->GetNext()!=NULL)) //���� ���� ��������� ��������
	  {
	    ptrDef2=ptrDef2->GetNext();// ����� ��������� ����� �����������
	    ptrTerm=ptrTerm->GetNext();// ����� ��������� ����� �������
					
	    //��������� ������� ����� ������� ������� � ������������
	    //�.�. � ��� � �������� ��� ��������
	    while (strcmp(ptrDef2->GetTerm()," ")==0)
	    {
	      /*if ((ptrDef2!=NULL)&&(ptrDef2->GetNext()!=NULL))
		{*/
	      ptrDef2=ptrDef2->GetNext();
	      //}else {break;}
	    }
					
	    if((strcmp(ptrTerm->GetTerm(), ptrDef2->GetTerm())!=0))
	    {
	      break; // ���� ����� �� ��������� ����� ��������� ����� ����������� � ����� ����
	    }else
	    {
	      if((strcmp(ptrTerm->GetTerm(), ptrDef2->GetTerm())==0)&&
		 (ptrTerm->GetNext()==NULL)) //���� ����� ��������� � ������ ����������
	      {
		return true;
	      }
	    }
	  }else 
	  {
	    if(ptrTerm->GetNext()==NULL)
	    {
	      return true;
	    }
	    else
	      if (ptrDef2->GetNext()==NULL)
	      {
		return false;
	      }
	  }
	}
      }
    }
  }
  return false;
}

//---------------------------------------
//������� ��������� ��������� �������� �������� ��� ���� ��������
void TList_TermList::CalculationEntropy()
{
  int total=0;
	
  //��������� ����� ������ ��������
  for(TListTerm* p = GetHead(); p!=NULL; p=p->GetNext())
  {
    total++;
  }

  //��������� �������� ��������
  for(TListTerm* p = GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetEntropy( -(double(p->GetFreq())/double(total)) * log( double(p->GetFreq())/double(total) ) );
  }
}

//---------------------------------------
//������� ��������� ��������� ��������� ������� ��� ���� ��������
void TList_TermList::ConnectivityOfTerm()
{
  int count=0; //���������� ��������
  int TotalRelCount=0; // ������������ ���������� ������
	
  //������� ����� ���������� ��������
  for(TListTerm * p = GetHead(); p!=NULL; p=p->GetNext())
  {
    count=count++;
  }

  TotalRelCount=count*(count-1)/2; //������������ ���������� ������

  //������� ��������� ������� �������
  for(TListTerm * p2 = GetHead(); p2!=NULL; p2=p2->GetNext())
  {
    p2->SetConnectivitiOfTerm(double(p2->GetCountRelations())/double(TotalRelCount));
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TList_Relation
//***********************************
//***********************************/

TList_Relation::TList_Relation(void)
{
  head_Rel = NULL;
}

TList_Relation::~TList_Relation(void)
{
  TRelation *p = head_Rel;

  while (p!=NULL)
  {
    TRelation *pp = p -> GetNext();
    delete p;
    p=pp;
  }
}

//---------------------------------------

TRelation *TList_Relation::GetHead()
{
  return head_Rel;
}

//---------------------------------------

void TList_Relation::Show(char curdir[512])
{
  strcat(curdir,"_Relation.txt");

  std::ofstream o(curdir);

  int index_of_term = 1;
  o <<"**** Index of term **** "<<index_of_term<<std::endl;
	
  for(TRelation *p=head_Rel; p!=NULL; p=p->GetNext())
  {
    if(p->GetIndex_of_relation()!=-1)
    {
      o <<p->GetIndex_of_relation()<<"\t"
	<<p->GetIndex_of_term()<<"\t"
	<<p->GetDirection()<< std::endl;
    }else
    {
      if(p->GetNext()!=NULL)
      {
	index_of_term++;
	o <<"**** Index of term **** "<<index_of_term<<std::endl;
      }else
      {
	o <<"********* Finita *********"<<std::endl;
      }
    }
  }
}

//---------------------------------------
//---------------------------------------

void TList_Relation::AddLast_Relation(int index_of_relation_value, 
				      int index_of_term_value,
				      int direction_value)
{
  if (head_Rel==NULL)
  {
    TRelation *node = new TRelation(index_of_relation_value, 
				    index_of_term_value,
				    direction_value);
    head_Rel=node;
    return;
  }
  else
  {
    for (TRelation *p=head_Rel;p!=NULL; p=p->GetNext())
    {
      if (p->GetNext()==NULL)
      {
	TRelation *node = new TRelation(
					index_of_relation_value, 
					index_of_term_value, 
					direction_value);
	p->SetNext(node);
	return;
      }
    }
  }
}

//---------------------------------------

void TList_Relation::Identification_of_relation(
						TList_TermList &Terms, 
						TList_Definition &Definitions)
{
  int index_of_relation_value=0;
	
  //��������� ������ ������� ��������
  for(TListTerm *p=Terms.GetHead();p!=NULL;p=p->GetNext())
  {
    //���������� ��� � �������� �����������
    //���������� �����������
    for(TListDef *ptrDef1=Definitions.GetHead();
	ptrDef1!=NULL;
	ptrDef1=ptrDef1->GetNext())
    {
      int x=ptrDef1->GetIndex();

      TNodeDef * ptrDef2=ptrDef1->GetHead();
			
      //�������� ������� ����������� ��� ����� ��������
      if ((x!=0)&& (fmod(x, 2)!=0)&& // ����������� ������������ �����
	  (strcmp(p->GetHead()->GetTerm(),ptrDef2->GetTerm())==0)||   
	  (strcmp(p->GetHead()->GetTerm(),ptrDef2->GetSynonym())==0)) 
      {
	if (ptrDef2==ptrDef1->GetHead())
	  // �������� ������ �������
	{
	  //��������� ����� 0 == "������������"
	  AddLast_Relation(index_of_relation_value, 
			   p->GetIndex(),
			   0);
	  index_of_relation_value++;
	}
	//
	//�������� ������� �������� � ����������� ����� �������
	//
	for(TListTerm *ptrTerm=Terms.GetHead();
	    ptrTerm!=NULL;
	    ptrTerm=ptrTerm->GetNext())
	{
	  if(Terms.STRSTR_TermsInDef(ptrTerm,
				     ptrDef1)) //���� �� ����� ������ � �����������
	  {
	    AddLast_Relation(index_of_relation_value, 
			     ptrTerm->GetIndex(),
			     1);
	    index_of_relation_value++;
	  }
	}
      }
    }
    AddLast_Relation(-1, 0, 0);
  }
}

//---------------------------------------
//---------------------------------------

void TList_Relation::Factor_of_Nexus(TList_TermList &TERMS)
{
	
  unsigned int Count_rel_total=0;
  int Count_rel=0;
  int Count_term=0;
  double factor_of_nexus;

  //������� ����� ���������� ��������
  TListTerm *pp=TERMS.GetHead();
  while(pp->GetNext()!=NULL)
    pp=pp->GetNext();
	
  Count_term=int(pp->GetIndex());
		
  //���������� �������� ���������� ���� ��� ������� ��������
  for(pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    Count_rel=0;

    //���������� ������������ ������� � ������������ ������ �������� +
    //���������� �������� � ����������� ��������� �������
    TRelation *p=head_Rel;
    for(; p!=NULL; p=p->GetNext())
    {
			
      if((p->GetIndex_of_term()==pp->GetIndex())&&
	 (p->GetDirection()!=0))
      {
	//���������� ������������ ������� � ������������ ������ ��������	
	Count_rel++;
	Count_rel_total++;
      }
			
      if ((p->GetIndex_of_term()==pp->GetIndex())&&(p->GetDirection()==0))
      {
	while (p->GetIndex_of_relation()!=-1)
	{
	  if(p->GetDirection()!=0)
	  {
	    //���������� ������������ �������� � ����������� ��������� �������
	    Count_rel++;
	    Count_rel_total++;
	  }
	  p=p->GetNext();
	}
				
      }			
    }	
		
    //���������� ������������ �������� � ����� ����������� � ��������
    //�������������� �����
    int count_t=0; //���������� �������� � ������� �����������
    //��� ������������� � ��������� ��������
    bool flag=false;  //������� ��������� ������� � ������� �����������
		
    for(p=head_Rel;
	p!=NULL;
	p=p->GetNext())
    {
      if (p->GetIndex_of_relation()!=-1)
      {
	//���� ������� ������ �� �������� �������� ��� ������������
	//����������� ������� �������� �������� �����������
	if((p->GetIndex_of_term()!=pp->GetIndex())&&
	   (p->GetDirection()!=0))
	{
	
	  count_t++;
	}
					
	//���� ������� ������ �� �������� ������������, �� ������
	//�������� ��� ����������� ��� ����������� ���������� �������� ������
	if((p->GetIndex_of_term()==pp->GetIndex())&&
	   (p->GetDirection()!=0))
	{
	  flag=true;
	}
      }
      else		
	//���� ������ �������� ����������� ������ �����
	if (p->GetIndex_of_relation()==-1)
	{
	  if (flag==true)
	  {
	    Count_rel=Count_rel + count_t;
	    Count_rel_total=Count_rel_total + count_t;
	  }
	  count_t=0;
	  flag=false;
	}
    }
    pp->SetCountRelations(Count_rel);
  }
  /////////////////////////////////////////////////////////
  //������������ ������� ���������� ������ ����� ���������
  /////////////////////////////////////////////////////////
  factor_of_nexus=double(Count_rel_total)/double(Count_term);

  for(pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    //������������ ���������� ����
    if (pp->GetCountRelations()>=factor_of_nexus)
    {
      pp->SetFactorNexus(1);
    }
    else
    {
      pp->SetFactorNexus(0);
    }	
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::CalculationGroupDependancy(TListTerm * pTerm,
						TListTerm * pTermHead, 
						TRelation * head_Rel)
{
  //���� ����� ������ ��� �� ������� ��� ������������� ������ ����������� ����
  if((pTerm->GetCheck()!=1)&&(pTerm->GetCheck2()!=1)) //������ �������� ����� ��� ��������� �8
  {
    //�������� ������ ������ ������ ����������� ����
    pTerm->SetCheck(1);

    for(TRelation *pRelation=head_Rel;
	pRelation!=NULL;
	pRelation=pRelation->GetNext())
    {
      //���� � ����� ������� ���� �����������
      if ((pRelation->GetDirection()==0)&&
	  (pRelation->GetIndex_of_term()==pTerm->GetIndex()))
      {
	//���� �� ���������� �����������
	while (pRelation->GetIndex_of_relation()!=-1)
	{
	  //���� �� � �����������, �� ��� �� ������������ ������,
	  //�� ������ (�.�. ���������� ��������) � ���� �� ��� ��
	  //������� � ������ ����������� ����
	  if(pRelation->GetDirection()!=0)
	  {
	    TListTerm *pTerm_temp = pTermHead;
	    for(; 
		pTerm_temp!=NULL; 
		pTerm_temp = pTerm_temp->GetNext())
	    {
	      //���� ����� ������ ������
	      if (pRelation->GetIndex_of_term()==
		  pTerm_temp->GetIndex())
	      {
		break;
	      }
	    }
	    //���������� �������� ��� �� ������� ���� ����� ��� ��������� �������
	    //�� ����� ���������� �������
	    CalculationGroupDependancy(pTerm_temp, pTermHead, head_Rel);
	  }
	  //��������� ����� �����������
	  pRelation=pRelation->GetNext();
	}
	break; //���� ����������� ������� ����������� ���������� ������ ������ ���
      }
    }
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::GroupDependancy(TList_TermList &TERMS)
{
  for(TListTerm *pTerm=TERMS.GetHead(); 
      pTerm!=NULL; 
      pTerm=pTerm->GetNext())
  {
    //������� ��� ������� ������ ����������� ���� ������
    CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
			
    int CountCheck=0;
    //��������� ���������� �����, ������� ���� �������� � ������ � ������� �����
    for(TListTerm *pTerm_temp=TERMS.GetHead(); 
	pTerm_temp!=NULL; 
	pTerm_temp=pTerm_temp->GetNext())
    {
      if (pTerm_temp->GetCheck()==1)
      {
	CountCheck=CountCheck+1;
	pTerm_temp->SetCheck(0);
      }
    }
    pTerm->SetGroupDependancy(CountCheck); 
    //�� �� �������� 1 �.�. ���� ������� ����� ����������� ����� ������ �����������
  }	
}


//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------


bool TList_Relation::MarkDef(TRelation *TempRel, TListTerm * pTermHead)
{
  bool recursion=false;

  for(TRelation *pRelation=TempRel;
      pRelation->GetIndex_of_relation()!=-1;
      pRelation=pRelation->GetNext())
  {
    //������� ��� ������� ����������� ������
    for(TListTerm *pTerm=pTermHead; 
	pTerm!=NULL; 
	pTerm=pTerm->GetNext())
    {
      if (pRelation->GetIndex_of_term()==pTerm->GetIndex())
      {
	if ((pTerm->GetCheck()!=1)&&(pTerm->GetCheck2()!=1)) //������ �������� ����� ��� ��������� �8
	{
	  pTerm->SetCheck(1);
	  recursion=true;
	}
	break;
      }			
    }
  }
  if (recursion)
  {
    return true;
  }else return false;
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::CheckDef(TListTerm * pTermHead, 
			      TRelation *head_Rel)
{
  TRelation *pTempRel=NULL;

  bool def=false; //���� �� ������ �����������
  bool recursion=false; //���� �� ��������� - ��������� �� �������� �����.
  bool markDef=false;

  for(TRelation *pRelation=head_Rel;
      pRelation!=NULL;
      pRelation=pRelation->GetNext())
  {
    if (pRelation->GetIndex_of_relation()!=-1)
    {

      if ((pRelation->GetDirection()==0)&&(def==false))
      {
	pTempRel=pRelation; //���������� ������ �����������
	def=true;
      }
			
      //�������� ���� �� � ����������� ���������� �������
      for(TListTerm *pTempTerm=pTermHead; 
	  pTempTerm!=NULL; 
	  pTempTerm=pTempTerm->GetNext())
      {
	if (pRelation->GetIndex_of_term()==pTempTerm->GetIndex())
	{
	  //���� �� ����� ���������� ������
	  if (pTempTerm->GetCheck()==1)
	  {
	    //���������� �������� ��������� ������� �����������
	    if (MarkDef(pTempRel, pTermHead))
	    {
	      recursion=true;
	      markDef=true;
	    }
	  }
	  break; //������ �������� � ����� � ����������� ��������
	}
      }
      //���� ����������� �������� ������ ���������� �������
      //��������� ��� �� ���������� �����������
      if(markDef==true)
      {
	for(pRelation;
	    pRelation->GetIndex_of_relation()!=-1;
	    pRelation=pRelation->GetNext())
	{}
	markDef=false;
      }
    }else def=false; // ����������� �����������
  }
  if(recursion==true)
  {
    //���� ��� ������� ������ => ��������� ������ �����
    recursion=false;
    CheckDef(pTermHead, head_Rel);
		
  }
}


//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::ValenceRelevance(TList_TermList &TERMS)
{
  int CountCheck;

  //��������� ������� � �������� T5
  for(TListTerm *pTerm=TERMS.GetHead(); 
      pTerm!=NULL; 
      pTerm=pTerm->GetNext())
  {
    CountCheck=0; //�������� ������� ��������� ������ �� ������ ��������
    //��� ���� ����� ������ ��� ����������� � ���� ������ ���� ���� �� ���� ����
    if(pTerm->GetCountRelations()!=0)
    {
      //���� ������ ����������� �� �����
      if (pTerm->GetGroupDependancy()!=0)
      {
	//������� ��� ������� ������ ����������� ���� ������
	CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
      }
      //�������� ��� �����������
      //���� � ����������� ����� ���������� ������
      //�������� ��� ������� ����������� ������
      CheckDef(TERMS.GetHead(), head_Rel);
			
      //��������� ���������� �����, ������� ���� �������� � ������ � ������� �����
      for(TListTerm *pTerm_temp=TERMS.GetHead(); 
	  pTerm_temp!=NULL; 
	  pTerm_temp=pTerm_temp->GetNext())
      {
	if (pTerm_temp->GetCheck()==1)
	{
	  CountCheck=CountCheck+1;
	  pTerm_temp->SetCheck(0);
	}
      }
    }else {CountCheck=1;}
    pTerm->SetValenceRel(CountCheck);
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::LeafNodeParamOfTerm(TList_TermList &TERMS)
{
  bool recursion=false;

  //���������� ������ �������� � ���� ������ � ����������� ������ ==1 ��� ����������� ==0
  for (TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    if ((p->GetCountRelations()==1)||
	(p->GetCountRelations()==0))
    {
      //�������� ���� ������ �.�. �� ���������� ���������� ���������� ������
      p->SetLeafNode(1);
      recursion=true;
    }
  }
	
  //���� ��� ������ � ������� ���� �� ���� ���� ��:
  if (recursion==true)
  {
    PruningOfLeafNode(TERMS);		
  }


}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::PruningOfLeafNode(TList_TermList &TERMS)
{
  bool recursion=false;
  bool LeafDef=false;
  int Count_rel;
	
  //���������� ������� � ��� ������� ������� ������� ���������� ������
  for(TListTerm *ptr=TERMS.GetHead(); ptr!=NULL; ptr=ptr->GetNext())
  {
    if (ptr->GetLeafNode()!=1)//���� ���� ���� ��� �� ��������
    {
      Count_rel=0; //��������� �������� ���������� ������
      LeafDef=false;
      //��� ������� ������� ������� ���������� ������
      //���������� ����� �� 2, ����� ������, ��� ��� �� ����
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      //���������� ������������ ������� � ������������ ������ �������� +
      //���������� �������� � ����������� ��������� �������
      TRelation *p=head_Rel;
      for(; p!=NULL; p=p->GetNext())
      {
	//���� ������������ ������ ������ �� ����� �� ����������� 
	if (p->GetDirection()==0)
	{
	  for(TListTerm *ptr1=TERMS.GetHead(); ptr1!=NULL; ptr1=ptr1->GetNext())
	  {
	    if ((ptr1->GetIndex()==p->GetIndex_of_term())&&
		ptr1->GetLeafNode()==1)
	    {
	      LeafDef=true;
	    }
	  }
	}
			
	if((p->GetIndex_of_term()==ptr->GetIndex())&&
	   (p->GetDirection()!=0)&&(LeafDef==false))
	{
	  //���������� ������������ ������� � ������������ ������ ��������	
	  Count_rel++;
	  if (Count_rel>=2)
	  {
	    break;
	  }
	}
			
	if ((p->GetIndex_of_term()==ptr->GetIndex())&&(p->GetDirection()==0))
	{
	  while (p->GetIndex_of_relation()!=-1)
	  {	
	    //������� ���������� ������
	    //� ������������ �������
	    for(TListTerm *ptr2=TERMS.GetHead(); ptr2!=NULL; ptr2=ptr2->GetNext())
	    {
	      if((p->GetIndex_of_term()==ptr2->GetIndex())&&
		 (ptr2->GetLeafNode()!=1))
	      {
		if(p->GetDirection()!=0)
		{
		  //���������� ������������ �������� � �����������
		  //��������� �������
		  Count_rel++;
		  if (Count_rel>=2)
		  {	
		    break;
		  }
		}		
	      }
	    }
	    p=p->GetNext();		
	    if (Count_rel>=2)
	    {	
	      break;
	    }
	  }
	}			
      }
		
      if (Count_rel<2) //�������������� ����� ���� ������ ���� ������� ����� ���� ������
      {
	//���������� ������������ �������� � ����� ����������� � ��������
	//�������������� �����
	int count_t=0; //���������� �������� � ������� �����������
	//��� ������������� � ��������� ��������
	bool flag=false;  //������� ��������� ������� � ������� �����������
		
	for(p=head_Rel;
	    p!=NULL;
	    p=p->GetNext())
	{
	  if (p->GetIndex_of_relation()!=-1)
	  {
	    //���� ������� ������ �� �������� �������� ��� ������������
	    //���� ������� ������ �� ���������� ��������� ������������ ������
	    //����������� ������� �������� �������� �����������
					
	    if((p->GetIndex_of_term()!=ptr->GetIndex())&&
	       (p->GetDirection()!=0))
	    {
	      for(TListTerm *ptr3=TERMS.GetHead(); ptr3!=NULL; ptr3=ptr3->GetNext())
	      {
		if ((ptr3->GetIndex()==p->GetIndex_of_term())&&
		    (ptr3->GetLeafNode()==0))
		{
		  count_t++;
		}
	      }
	    }
					
	    //���� ������� ������ �� �������� ������������, �� ������
	    //�������� ��� ����������� ��� ����������� ���������� �������� ������
	    if((p->GetIndex_of_term()==ptr->GetIndex())&&
	       (p->GetDirection()!=0))
	    {
	      flag=true;
	    }
	  }
	  else		
	    //���� ������ �������� ������������ ������ �����
	    if (p->GetIndex_of_relation()==-1)
	    {
	      if (flag==true)
	      {
		Count_rel=Count_rel + count_t;
		if (Count_rel>=2)
		{
		  break;
		}
	      }
	      count_t=0;
	      flag=false;
	    }
	}
      }
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      //���� ��� ���� - �������� ���
      if (Count_rel<=1)
      {
	ptr->SetLeafNode(1);
	recursion = true;
      }
    }//end if (ptr->GetLeafNode()!=1)//���� ���� ���� ��� �� ��������
  }

  //���� �� �������� �����, ���� ���������� ��������� �����
  if (recursion==true)
  {
    recursion=false;
    PruningOfLeafNode(TERMS);	
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

void TList_Relation::CalculationFunctionalWeigth(TList_TermList &TERMS)
{
  //���������� ������ (����������� �����) ������� ���������� ���
  //���������� ��������� �3 (���������� ����)

  //��������� ����� ����� ������ �����
  int TotalCountTerm=0;
  TListTerm *p=TERMS.GetHead();
  for(; p!=NULL; p=p->GetNext())
  {
    TotalCountTerm++; //����� ���������� �������� �����
  }

  //��� ���������� �8 ���������� ��������� ��������� ��������:
  //Mmax - ����� ������ � ������������ �� �������� ������� ���������� ����� ����� ��������
  //��������������� �������
	
  //���������� ��� ����� ������ � 0
  for (p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetCheck(0);
    p->SetCheck2(0);
  }
	
  int CountCheck; //������� ������
  int CountMax=0; //������� ��� ���������� ������������� �������� ��������� �����

  //��������� ������������ ����� ������ � ������� ����� ����� �������� ������ �������
  for (p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetCheck2(1); //������� ������� �� ����� (�� �����)

    ///////////////////////////////////////////////////////
			

    //��������� ������� � �������� T8 ����� ������� ��� �5
    for(TListTerm *pTerm=TERMS.GetHead(); 
	pTerm!=NULL; 
	pTerm=pTerm->GetNext())
    {
      CountCheck=0; //�������� ������� ��������� ������ �� ������ ��������
      //��� ���� ����� ������ ��� ����������� � ���� ������ ���� ���� �� ���� ����
      if((pTerm->GetCountRelations()!=0)&&(pTerm->GetCheck2()!=1))
      {
	//���� ������ ����������� �� �����
	if (pTerm->GetGroupDependancy()!=0)
	{
	  //������� ��� ������� ������ ����������� ���� ������
	  CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
	}
	//�������� ��� �����������
	//���� � ����������� ����� ���������� ������
	//�������� ��� ������� ����������� ������
	CheckDef(TERMS.GetHead(), head_Rel);
			
	//��������� ���������� �����, ������� ���� �������� � ������ � ������� �����
	for(TListTerm *pTerm_temp=TERMS.GetHead(); 
	    pTerm_temp!=NULL; 
	    pTerm_temp=pTerm_temp->GetNext())
	{
	  if (pTerm_temp->GetCheck()==1)
	  {
	    CountCheck=CountCheck+1;
	    pTerm_temp->SetCheck(0);
	  }
	}

      }else {CountCheck=1;}
      //���������� � ������������ ��������� �������� ����������
      if (CountMax<CountCheck)
      {
	CountMax=CountCheck;
      }
    }
    ///////////////////////////////////////////////////////
		
    //������ ��������� �������������� ��� �������				
    p->SetFunctionalWeightOfTerm(p->GetCountRelations()*(TotalCountTerm-CountMax));
		
    CountMax=0;
    p->SetCheck2(0); //���������� ������� � ����
  }
}
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//�������� ������ TList_Relation_weight
//***********************************
//***********************************/


TList_Relation_weight::TList_Relation_weight(void)
{
  head_Rel = NULL;
}

TList_Relation_weight::~TList_Relation_weight(void)
{
  TRelation_weight *p = head_Rel;

  while (p!=NULL)
  {
    TRelation_weight *pp = p -> GetNext();
    delete p;
    p=pp;
  }
}

//---------------------------------------

TRelation_weight *TList_Relation_weight::GetHead()
{
  return head_Rel;
}

//---------------------------------------

void TList_Relation_weight::Show(char curdir[512])
{
  strcat(curdir,"_Relation_weight.txt");

  std::ofstream o(curdir);

  o <<"**** Relation of terms (START) **** "<<std::endl;
	
  for(TRelation_weight *p=head_Rel; p!=NULL; p=p->GetNext())
  {
    o <<p->GetIndex_of_term1()<<"\t"
      <<p->GetIndex_of_term2()<<"\t"
      <<p->GetMinWay()<<"\t"
      <<p->GetPowerOfSamantikRelation()<<"\t"	
      <<p->GetCountAggregateTerm()<<"\t"
      <<p->GetValenceRel()<<"\t"
      <<p->GetCo_Occurrence()<<std::endl;

    if(p->GetNext()==NULL)
    {
      o <<"********* Finita *********"<<std::endl;
    }
  }
}

//---------------------------------------
//---------------------------------------

void TList_Relation_weight::AddLast_Relation(int index_of_term1_value, 
					     int index_of_term2_value,
					     int MinWay)
{
  TRelation_weight *node=new TRelation_weight(index_of_term1_value, index_of_term2_value);
  node->SetMinWay(MinWay);
  node->SetCountAggregateTerm(0);
  node->SetPowerOfSamantikRelation(0);
  node->SetValenceRel(0);
  node->SetCo_Occurrence(0);

  if (head_Rel==NULL)
  {		
    head_Rel=node;
    return;
  }
  else
  {
    for (TRelation_weight *p=head_Rel; p!=NULL; p=p->GetNext())
    {
      if (p->GetNext()==NULL)
      {
	p->SetNext(node);
	return;
      }
    }
  }
}

//---------------------------------------
//---------------------------------------

void TList_Relation_weight::First_fill(TList_TermList &TERMS, TList_Relation &Relations)
{
  int tempIndex=0; //�������� ����� �������, ��� �������� ���� �����������
  bool flag=false;

  for(TListTerm *pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    //���������� ������������ ������� � ������������ ������ �������� +
    //���������� �������� � ����������� ��������� �������
    TRelation *p=Relations.GetHead();
    for(;
	p!=NULL;
	p=p->GetNext())
    {	
      flag=false;
      if (p->GetDirection()==0)
      {
	tempIndex=p->GetIndex_of_term();
      }

      if((p->GetIndex_of_term()==pp->GetIndex())&&
	 (p->GetDirection()!=0))
      {
	//���������� ������������ ������� � ������������ ������ ��������	
	for(TRelation_weight  *ptr1=head_Rel; ptr1!=NULL; ptr1=ptr1->GetNext())
	{
	  if(  ((ptr1->GetIndex_of_term1()==pp->GetIndex())&&
		(ptr1->GetIndex_of_term2()==tempIndex)) || 
	       ((ptr1->GetIndex_of_term2()==pp->GetIndex())&&
		(ptr1->GetIndex_of_term1()==tempIndex)) )
	  {
	    flag=true; //���� ����� ����� ��� ���� ��������� ��
	    break;
	  }
	}
	if (flag==false)
	{
	  AddLast_Relation(pp->GetIndex(), tempIndex, 0);
	}
      }
			
      if ((p->GetIndex_of_term()==pp->GetIndex())&&(p->GetDirection()==0))
      {
	while (p->GetIndex_of_relation()!=-1)
	{
	  if(p->GetDirection()!=0)
	  {
	    //���������� ������������ �������� � ����������� ��������� �������
	    for(TRelation_weight  *ptr1=head_Rel; ptr1!=NULL; ptr1=ptr1->GetNext())
	    {
	      if(  ((ptr1->GetIndex_of_term1()==p->GetIndex_of_term())&&
		    (ptr1->GetIndex_of_term2()==tempIndex)) || 
		   ((ptr1->GetIndex_of_term2()==p->GetIndex_of_term())&&
		    (ptr1->GetIndex_of_term1()==tempIndex)) )
	      {
		flag=true; //���� ����� ����� ��� ���� ��������� ��
		break;
	      }
	    }
	    if (flag==false)
	    {
	      AddLast_Relation(p->GetIndex_of_term(), tempIndex, 0);
	    }
	  }
	  p=p->GetNext();
	}
				
      }			
    }	
		
    //���������� ������������ �������� � ����� ����������� � ��������
    //�������������� �����
		
    TRelation *p2=Relations.GetHead();
		
    for(p=Relations.GetHead();
	p!=NULL;
	p=p->GetNext())
    {
      flag=false;

      if ((p->GetIndex_of_relation()==-1)&&(p->GetNext()!=NULL))
      {
	while (p->GetIndex_of_relation()==-1)
	{
	  p=p->GetNext();
	}
	if (p!=NULL) p2=p->GetNext();
      }

      if (p->GetIndex_of_relation()!=-1)
      {					
	//���� ������� ������ �� �������� ������������
	if((p->GetIndex_of_term()==pp->GetIndex())&&
	   (p->GetDirection()!=0))
	{
	  while((p2->GetIndex_of_relation()!=-1)&&(p2!=NULL))
	  {
	    if ((p2->GetIndex_of_term()!=p->GetIndex_of_term())&&
		(p2->GetDirection()!=0))
	    {
	      for(TRelation_weight  *ptr1=head_Rel; ptr1!=NULL; ptr1=ptr1->GetNext())
	      {
		if(  ((ptr1->GetIndex_of_term1()==p->GetIndex_of_term())&&
		      (ptr1->GetIndex_of_term2()==p2->GetIndex_of_term())) || 
		     ((ptr1->GetIndex_of_term2()==p->GetIndex_of_term())&&
		      (ptr1->GetIndex_of_term1()==p2->GetIndex_of_term())) )
		{
		  flag=true; //���� ����� ����� ��� ���� ��������� ��
		  break;
		}
	      }
	      if (flag==false)
	      {
		AddLast_Relation(p->GetIndex_of_term(), 
				 p2->GetIndex_of_term(), 0);
	      }
	    }
	    p2=p2->GetNext();
	    if(p2==NULL)
	    {break;}
	  }
	}
      }
    }
  }
}

//---------------------------------------
//---------------------------------------

//����� ������������ ���� ����� ����� ���������
void TList_Relation_weight::Min_Way(TList_TermList &TERMS, TList_Relation &Relations)
{
  //��������� ���������� ��������
  int TotalCountTerm=0;
  TListTerm *p=TERMS.GetHead(); 
  for(;
      p->GetNext()!=NULL; 
      p=p->GetNext())
  {}
  TotalCountTerm=int(p->GetIndex());
	
	
  //������� ������ ��� �������� ��������� �������� �����
  int** MasRel1;
  MasRel1 = new int* [2000];
  
  for (int k=1; k<=2000; k++) MasRel1[k]=new int [2000];
	
  //������ ������
  int** MasRel2;
  MasRel2 = new int* [2000];
  for (int m=1; m<=2000; m++) MasRel2[m]=new int [2000];

  //������������� ��������
  for (int i=1; i<=TotalCountTerm; i++)
  {
    for (int j=1; j<=TotalCountTerm; j++)
    {
      if (i==j)
      {
	MasRel1[i][j]=0;
	MasRel2[i][j]=0;
      }
      else
      {
	MasRel1[i][j]=30000;
	MasRel2[i][j]=30000;
      }
    }
  }
  //���� ����� ��������� ���� ����� - ������� �� � ������
	
  First_fill(TERMS, Relations);

  for(TRelation_weight* ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    MasRel1[ptr->GetIndex_of_term1()][ptr->GetIndex_of_term2()]=ptr->GetMinWay()+1;
    MasRel2[ptr->GetIndex_of_term1()][ptr->GetIndex_of_term2()]=ptr->GetMinWay()+1;
		
    MasRel1[ptr->GetIndex_of_term2()][ptr->GetIndex_of_term1()]=ptr->GetMinWay()+1;
    MasRel2[ptr->GetIndex_of_term2()][ptr->GetIndex_of_term1()]=ptr->GetMinWay()+1;
  }
	
  bool exist=true;

  //�������� �������� ������ ��� ������ ����������� ����� ����� ���������     
  for (int k=1; k<=TotalCountTerm; k++)
  {	
    for (int i=1; i<=TotalCountTerm; i++)
    {
      for (int j=1; j<=TotalCountTerm; j++)
      {
	if ((MasRel2[i][k] + MasRel2[k][j]) < MasRel1[i][j]) //���� ����� ���� ������ �������
	{
	  if (MasRel2[i][j]==30000) 
	  {
	    exist=false;
	  }else 
	  {	
	    exist=true;
	  }
					
	  MasRel1[i][j] = MasRel2[i][k] + MasRel2[k][j];
	  MasRel1[j][i] = MasRel1[i][j];
					
	  if (exist==false) //���� ����� ����� ��� �� ���� - ������� ��
	  {
	    AddLast_Relation(i, j, MasRel1[i][j]); //��������� ����� �����
	    exist=true;
	  }
	}
      }
    }

    for (int i=1; i<=TotalCountTerm; i++)
    {
      for (int j=1; j<=TotalCountTerm; j++)
      {
	MasRel2[i][j] = MasRel1[i][j]; //���������� ������� �������� ����
      }
    }
  }
	
  //������� ����������� ���� � ������ ������ � ������ ����
  for(TRelation_weight* ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    ptr->SetMinWay( MasRel1[ptr->GetIndex_of_term1()][ptr->GetIndex_of_term2()] );
  }

	
}

//---------------------------------------
//---------------------------------------

void TList_Relation_weight::PowerOfSamantikRelation(TList_TermList &TERMS, TList_Relation &Relations)
{
  Min_Way(TERMS, Relations);
	
  //������� ���� ������������� ����� ��� ������ ����� � ������ ������
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    //���������� ���� ������������� �����
    ptr->SetPowerOfSamantikRelation( double(1) / (ptr->GetMinWay()) );
  }
}

//---------------------------------------
//---------------------------------------

//R2 ���������� ����� �������� �������� �������
void TList_Relation_weight::CountTermWithFreq(TList_TermList &TERMS, TList_Relation &Relations)
{
  double aver_freq=0;
  int sum=0, count_term=0;
	
  //��������� ������� ������� �������� 
  for(TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    count_term++;
    sum=sum+p->GetFreq();
  }
  aver_freq=double(sum)/double(count_term);
	
  int  CountTermInDef; //����� ����������� �������� � ���� ������������ 
  bool Relation;		 //������� ���������������� �����

  //������ ����� ������
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    Relation=false;

    TList_Relation Newborn1; //������ � ������������� 1 �������
    int indexN1=0;
    TList_Relation Newborn2; //������ � ������������� 2 �������
    int indexN2=0;

    //��������� ����� ���������� �������� � ������������ ��������
    CountTermInDef=0;
    for(TRelation *ptr2=Relations.GetHead(); ptr2!=NULL; ptr2=ptr2->GetNext())
    {
      if ( ( ptr->GetIndex_of_term1()==ptr2->GetIndex_of_term() ) &&
	   (ptr2->GetDirection()==0) )
      {
	Newborn1.AddLast_Relation(indexN1,ptr2->GetIndex_of_term(),0);
	indexN1++;
				
	while( (ptr2!=NULL) && (ptr2->GetIndex_of_relation()!=-1) )
	{
	  //���� ���� ���������������� �����
	  if (ptr2->GetIndex_of_term()==ptr->GetIndex_of_term2())
	  {
	    Relation=true;
	    break;
	  }

	  if (ptr2->GetDirection()!=0)
	  {
	    CountTermInDef++;
	    Newborn1.AddLast_Relation(indexN1,ptr2->GetIndex_of_term(),1);
	    indexN1++;
	  }
	  ptr2=ptr2->GetNext();
	}

      }
			
      if ( ( ptr->GetIndex_of_term2()==ptr2->GetIndex_of_term() ) &&
	   (ptr2->GetDirection()==0) )
      {
	Newborn2.AddLast_Relation(indexN2,ptr2->GetIndex_of_term(),0);
	indexN2++;

	while( (ptr2!=NULL) && (ptr2->GetIndex_of_relation()!=-1) )
	{
	  //���� ���� ���������������� �����
	  if (ptr2->GetIndex_of_term()==ptr->GetIndex_of_term1())
	  {
	    Relation=true;
	    break;
	  }


	  if (ptr2->GetDirection()!=0)
	  {
	    CountTermInDef++;
	    Newborn2.AddLast_Relation(indexN2,ptr2->GetIndex_of_term(),1);
	    indexN2++;
	  }
	  ptr2=ptr2->GetNext();
	}

      }
    }
		
    if (Relation==false)
    {
      //��������� ���������� ����� ��������
      double sum1=0; //���������
      int count_twin_value=0; //������� ���������� ��������
      bool check;
      for(TRelation *ptr2=Newborn1.GetHead(); ptr2!=NULL; ptr2=ptr2->GetNext())
      {
	check=false;
	for(TRelation *ptr3=Newborn2.GetHead(); ptr3!=NULL; ptr3=ptr3->GetNext())
	{
	  if (
	      (ptr2->GetDirection()!=0)&&(ptr3->GetDirection()!=0) &&
	      (ptr2->GetIndex_of_term()==ptr3->GetIndex_of_term())
	      )
	  {
	    for(TListTerm *p=TERMS.GetHead();
		p!=NULL;
		p=p->GetNext())
	    {
	      if (p->GetIndex()==ptr2->GetIndex_of_term())
	      {
		if (p->GetFreq() > aver_freq)
		{
		  sum1 = sum1 + double(1)/double(p->GetFreq());
		  count_twin_value++;
		}else
		{
		  sum1 = sum1 + 1;
		  count_twin_value++;
		}
		check=true;
		break;
	      }
	    }
	    if (check==true)//��������� ����������
	    {break;}
	  }
	}
      }
      //��������� R2
      if ( (sum1!=0) && (CountTermInDef!=0) ) //��������� �������������
      {
	ptr->SetCountAggregateTerm( double(sum1) / double(CountTermInDef-count_twin_value) );
      } else
      {
	ptr->SetCountAggregateTerm(0);
      }
    }else //���� ���� ���������������� �����
    {
      ptr->SetCountAggregateTerm(1);
    }
  }
}

//---------------------------------------
//---------------------------------------

//R3 ������������� �����
void TList_Relation_weight::ValenceRelevanceOfRelations(TList_TermList &TERMS)
{
  bool RelevanceOfTerm1=false;
	
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    RelevanceOfTerm1=false;
    //�������� ������ ������ �� �������������
    for(TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
    {
      if ((ptr->GetIndex_of_term1()==p->GetIndex())&&
	  (p->GetValenceRel()>0))
      {
	RelevanceOfTerm1=true;
	break;
      }
    }

    if (RelevanceOfTerm1==true)
    {
      //�������� ������ ������ �� �������������
      for(TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
      {
	if ((ptr->GetIndex_of_term2()==p->GetIndex())&&
	    (p->GetValenceRel()>0))
	{
	  ptr->SetValenceRel(1);
	  break;
	}

      }
    } else 
    {
      ptr->SetValenceRel(0);
    }
  }
}
 
//---------------------------------------
//---------------------------------------

//R4 ��������������� �������� � ������
void TList_Relation_weight::Co_OccurrenceOfTerms(TList_TermList &TERMS, TList_Definition &Paragraph)
{
  //��������� �������� ��� ������� ��������� � ������� ������ �������� �1 � �2
  int count1=0, count2=0;
  int Total=0; //����� ������� ������������� ��������

  //���������� ������ ������ � ��� ������ �� ���������� ���� ��������������� �������� �1 � �2
  for (TRelation_weight *pr=head_Rel; pr!=NULL; pr=pr->GetNext())
  {
    //������������� ��������� � ������� ��������
    for (TListDef *pp = Paragraph.GetHead(); pp!=NULL; pp=pp->GetNext())
    {
      //�������� ������� � ��������� ������� �1
      for (TListTerm *pt = TERMS.GetHead(); pt!=NULL; pt=pt->GetNext())
      {
	if (pt->GetIndex()==pr->GetIndex_of_term1())
	{
	  count1=STRSTR_TermsInParagraph(pt, pp);
	  break;
	}
      }

      //�������� ������� � ��������� ������� �2
      for (TListTerm *pt = TERMS.GetHead(); pt!=NULL; pt=pt->GetNext())
      {
	if (pt->GetIndex()==pr->GetIndex_of_term2())
	{
	  count2=STRSTR_TermsInParagraph(pt, pp);
	  break;
	}
      }

      //��������� ����� ���������� ������� � ������� ����������� ��� �������
      if ((count1!=0)&&(count2!=0))
      {
	Total=Total + 1;
      }
			
      count1=0;
      count2=0;
    }

    pr->SetCo_Occurrence(Total);
    Total=0;
  }
}

//---------------------------------------
//---------------------------------------

int TList_Relation_weight::STRSTR_TermsInParagraph(TListTerm * term, TListDef * Paragraph)
{
  TNodeTerm *ptrTerm;
  TNodeDef *ptrPar2;

  for (TNodeDef *ptrPar = Paragraph->GetHead(); 
       ptrPar!=NULL; 
       ptrPar=ptrPar->GetNext())
  {
    ptrPar2=ptrPar;
		
    ptrTerm = term->GetHead();//����� ������ ����� �������
    ptrTerm = ptrTerm->GetNext();//���������� ������ ����� ������� �.�. � ��� ���� ������

    //���� ������ ����� ������� ��������� �� ������ � ���������
    if ((strcmp(ptrTerm->GetTerm(), ptrPar->GetTerm())==0))
    {
      while (ptrTerm) //���� �� ���������� ��� ����� �������
      {
	if ((ptrPar2->GetNext()!=NULL)&&
	    (ptrTerm->GetNext()!=NULL)) //���� ���� ��������� ��������
	{
	  ptrPar2=ptrPar2->GetNext();// ����� ��������� ����� ���������
	  ptrTerm=ptrTerm->GetNext();// ����� ��������� ����� �������
						
	  //��������� ������� ����� ������� ������� � ������������
	  //�.�. � ��� � �������� ��� ��������
	  while (strcmp(ptrPar2->GetTerm()," ")==0)
	  {
	    /*if ((ptrPar2!=NULL)||(ptrPar2->GetNext()!=NULL))
	      {*/
	    ptrPar2=ptrPar2->GetNext();
	    //}else {break;}
	  }
				
	  if((strcmp(ptrTerm->GetTerm(), ptrPar2->GetTerm())!=0))
	  {
	    break; // ���� ����� �� ��������� ����� ��������� ����� ����������� � ����� ����
	  }else
	  {
	    if((strcmp(ptrTerm->GetTerm(), ptrPar2->GetTerm())==0)&&
	       (ptrTerm->GetNext()==NULL)) //���� ����� ��������� � ������ ����������
	    {
	      return 1;
	      break;
	    }
	  }
	}else 
	{
	  if(ptrTerm->GetNext()==NULL)
	  {
	    return 1;
	    break;
	  }
	  else
	    if (ptrPar2->GetNext()==NULL)
	    {
	      return 0;
	    }
	}
      }
    }
  }
  return 0;
}
