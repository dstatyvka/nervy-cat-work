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
//Описание класса TListTerm
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
//Описание класса TListDef
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
//Описание класса TList_Definition

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
//Описание класса TList_TermList
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
//функция позволяет определить было ли вхождение термина в определение 
bool TList_TermList::STRSTR_TermsInDef(TListTerm * term,
				       TListDef * Definition)
{
  TNodeTerm *ptrTerm;
  TNodeDef *ptrDef2;

  for (TNodeDef *ptrDef = Definition->GetHead(); 
       ptrDef!=NULL; 
       ptrDef=ptrDef->GetNext())
  {
    if (ptrDef!=Definition->GetHead())//пропустим наименование термина
    {
      ptrDef2=ptrDef;
		
      ptrTerm = term->GetHead(); //пропускаем первое слово термина т.к. в нем весь термин
      ptrTerm = ptrTerm->GetNext(); //берем первое слово термина

      //если первое слово термина совпадает со словом в определении
      if ((strcmp(ptrTerm->GetTerm(), ptrDef->GetTerm())==0))
      {
	while (ptrTerm) //пока не просмотрим все слова термина
	{
	  if ((ptrDef2->GetNext()!=NULL)&&
	      (ptrTerm->GetNext()!=NULL)) //если есть следующие элементы
	  {
	    ptrDef2=ptrDef2->GetNext();// берем следующее слово определения
	    ptrTerm=ptrTerm->GetNext();// берем следующее слово термина
					
	    //пропустим пробелы между словами термина в определениях
	    //т.к. у нас в терминах нет пробелов
	    while (strcmp(ptrDef2->GetTerm()," ")==0)
	    {
	      /*if ((ptrDef2!=NULL)&&(ptrDef2->GetNext()!=NULL))
		{*/
	      ptrDef2=ptrDef2->GetNext();
	      //}else {break;}
	    }
					
	    if((strcmp(ptrTerm->GetTerm(), ptrDef2->GetTerm())!=0))
	    {
	      break; // если слова не совпадают берем следующее слово определения и снова сюда
	    }else
	    {
	      if((strcmp(ptrTerm->GetTerm(), ptrDef2->GetTerm())==0)&&
		 (ptrTerm->GetNext()==NULL)) //если слово совпадает и термин закончился
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
//функция позволяет вычислить значение энтропии для всех терминов
void TList_TermList::CalculationEntropy()
{
  int total=0;
	
  //Определим сумму частот терминов
  for(TListTerm* p = GetHead(); p!=NULL; p=p->GetNext())
  {
    total++;
  }

  //расчитаем энтропию терминов
  for(TListTerm* p = GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetEntropy( -(double(p->GetFreq())/double(total)) * log( double(p->GetFreq())/double(total) ) );
  }
}

//---------------------------------------
//функция позволяет вычислить связность термина для всех терминов
void TList_TermList::ConnectivityOfTerm()
{
  int count=0; //количество терминов
  int TotalRelCount=0; // всевозможное количество связей
	
  //Считаем общее количество терминов
  for(TListTerm * p = GetHead(); p!=NULL; p=p->GetNext())
  {
    count=count++;
  }

  TotalRelCount=count*(count-1)/2; //всевозможное количество связей

  //Считаем связность каждого термина
  for(TListTerm * p2 = GetHead(); p2!=NULL; p2=p2->GetNext())
  {
    p2->SetConnectivitiOfTerm(double(p2->GetCountRelations())/double(TotalRelCount));
  }
}

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//Описание класса TList_Relation
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
	
  //перебираю список списков терминов
  for(TListTerm *p=Terms.GetHead();p!=NULL;p=p->GetNext())
  {
    //сравниваем его с термином определения
    //перебираем определения
    for(TListDef *ptrDef1=Definitions.GetHead();
	ptrDef1!=NULL;
	ptrDef1=ptrDef1->GetNext())
    {
      int x=ptrDef1->GetIndex();

      TNodeDef * ptrDef2=ptrDef1->GetHead();
			
      //проверим наличие определений для наших терминов
      if ((x!=0)&& (fmod(x, 2)!=0)&& // определение обработанных строк
	  (strcmp(p->GetHead()->GetTerm(),ptrDef2->GetTerm())==0)||   
	  (strcmp(p->GetHead()->GetTerm(),ptrDef2->GetSynonym())==0)) 
      {
	if (ptrDef2==ptrDef1->GetHead())
	  // выделяем первый элемент
	{
	  //добавляем связь 0 == "эквивалентны"
	  AddLast_Relation(index_of_relation_value, 
			   p->GetIndex(),
			   0);
	  index_of_relation_value++;
	}
	//
	//Проверим наличие терминов в определении этого термина
	//
	for(TListTerm *ptrTerm=Terms.GetHead();
	    ptrTerm!=NULL;
	    ptrTerm=ptrTerm->GetNext())
	{
	  if(Terms.STRSTR_TermsInDef(ptrTerm,
				     ptrDef1)) //есть ли такой термин в определении
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

  //Считаем общее количество терминов
  TListTerm *pp=TERMS.GetHead();
  while(pp->GetNext()!=NULL)
    pp=pp->GetNext();
	
  Count_term=int(pp->GetIndex());
		
  //Рассчитаем значение показателя ядра для каждого элемента
  for(pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    Count_rel=0;

    //Количество употреблений термина в определениях других терминов +
    //количество терминов в определении заданного термина
    TRelation *p=head_Rel;
    for(; p!=NULL; p=p->GetNext())
    {
			
      if((p->GetIndex_of_term()==pp->GetIndex())&&
	 (p->GetDirection()!=0))
      {
	//Количество употреблений термина в определениях других терминов	
	Count_rel++;
	Count_rel_total++;
      }
			
      if ((p->GetIndex_of_term()==pp->GetIndex())&&(p->GetDirection()==0))
      {
	while (p->GetIndex_of_relation()!=-1)
	{
	  if(p->GetDirection()!=0)
	  {
	    //Количество употреблений терминов в определении заданного термина
	    Count_rel++;
	    Count_rel_total++;
	  }
	  p=p->GetNext();
	}
				
      }			
    }	
		
    //Количество употреблений терминов в одном определении с термином
    //Дистрибутивная связь
    int count_t=0; //количество терминов в текущем определении
    //без определяемого и заданного терминов
    bool flag=false;  //Наличие заданного термина в текущем определении
		
    for(p=head_Rel;
	p!=NULL;
	p=p->GetNext())
    {
      if (p->GetIndex_of_relation()!=-1)
      {
	//Если текущий термин не является заданным или определяемым
	//увеличиваем счетчик терминов текущего определения
	if((p->GetIndex_of_term()!=pp->GetIndex())&&
	   (p->GetDirection()!=0))
	{
	
	  count_t++;
	}
					
	//Если текищий термин не является определяемым, но найден
	//отмечаем это определение как определение содержащее заданный термин
	if((p->GetIndex_of_term()==pp->GetIndex())&&
	   (p->GetDirection()!=0))
	{
	  flag=true;
	}
      }
      else		
	//если список терминов определения достиг конца
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
  //Рассчитываем среднее количество связей между терминами
  /////////////////////////////////////////////////////////
  factor_of_nexus=double(Count_rel_total)/double(Count_term);

  for(pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    //Рассчитываем показатель ядра
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
  //Если такой термин еще не отмечен как принадлежащий группе зависимости ядра
  if((pTerm->GetCheck()!=1)&&(pTerm->GetCheck2()!=1)) //второй аргумент нужен для параметра Т8
  {
    //отмечаем термин меткой группы зависимости ядра
    pTerm->SetCheck(1);

    for(TRelation *pRelation=head_Rel;
	pRelation!=NULL;
	pRelation=pRelation->GetNext())
    {
      //Если у этого термина есть определение
      if ((pRelation->GetDirection()==0)&&
	  (pRelation->GetIndex_of_term()==pTerm->GetIndex()))
      {
	//Пока не закончится определение
	while (pRelation->GetIndex_of_relation()!=-1)
	{
	  //если мы в определении, но это не определяемый термин,
	  //Но термин (т.е. необходима проверка) и если он еще не
	  //включен в группу зависимости ядра
	  if(pRelation->GetDirection()!=0)
	  {
	    TListTerm *pTerm_temp = pTermHead;
	    for(; 
		pTerm_temp!=NULL; 
		pTerm_temp = pTerm_temp->GetNext())
	    {
	      //Если такой термин найден
	      if (pRelation->GetIndex_of_term()==
		  pTerm_temp->GetIndex())
	      {
		break;
	      }
	    }
	    //Рекурсивно вызываем эту же функцию чтоб найти все зависимые термины
	    //от вновь найденного термина
	    CalculationGroupDependancy(pTerm_temp, pTermHead, head_Rel);
	  }
	  //Следующее слово определения
	  pRelation=pRelation->GetNext();
	}
	break; //если определение термина просмотрена перебирать дальше смысла нет
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
    //Пометим все вершины группы зависимости ядра меткой
    CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
			
    int CountCheck=0;
    //Посчитаем количество меток, занесем этот параметр в термин и обнулим метки
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
    //Мы не вычитаем 1 т.к. сама вершина также принадлежит своей группе зависимости
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
    //отметим все термины определения меткой
    for(TListTerm *pTerm=pTermHead; 
	pTerm!=NULL; 
	pTerm=pTerm->GetNext())
    {
      if (pRelation->GetIndex_of_term()==pTerm->GetIndex())
      {
	if ((pTerm->GetCheck()!=1)&&(pTerm->GetCheck2()!=1)) //второй аргумент нужен для параметра Т8
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

  bool def=false; //было ли начало определения
  bool recursion=false; //были ли изменения - запускать ли проверку снова.
  bool markDef=false;

  for(TRelation *pRelation=head_Rel;
      pRelation!=NULL;
      pRelation=pRelation->GetNext())
  {
    if (pRelation->GetIndex_of_relation()!=-1)
    {

      if ((pRelation->GetDirection()==0)&&(def==false))
      {
	pTempRel=pRelation; //запоминаем начало определения
	def=true;
      }
			
      //проверим есть ли в определении отмеченные термины
      for(TListTerm *pTempTerm=pTermHead; 
	  pTempTerm!=NULL; 
	  pTempTerm=pTempTerm->GetNext())
      {
	if (pRelation->GetIndex_of_term()==pTempTerm->GetIndex())
	{
	  //если мы нашли отмеченный термин
	  if (pTempTerm->GetCheck()==1)
	  {
	    //необходимо отметить остальные термины определения
	    if (MarkDef(pTempRel, pTermHead))
	    {
	      recursion=true;
	      markDef=true;
	    }
	  }
	  break; //термин проверен о слова в определении отмечены
	}
      }
      //Если определение содержит только отмеченные термины
      //промотаем его до следующего определения
      if(markDef==true)
      {
	for(pRelation;
	    pRelation->GetIndex_of_relation()!=-1;
	    pRelation=pRelation->GetNext())
	{}
	markDef=false;
      }
    }else def=false; // определение закончилось
  }
  if(recursion==true)
  {
    //если был отмечен термин => проверяем список снова
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

  //переберем термины и вычислим T5
  for(TListTerm *pTerm=TERMS.GetHead(); 
      pTerm!=NULL; 
      pTerm=pTerm->GetNext())
  {
    CountCheck=0; //обнуляем счетчик связанных вершин на каждой итерации
    //Для того чтобы термин был релевантным у него должна быть хотя бы одна дуга
    if(pTerm->GetCountRelations()!=0)
    {
      //Если группа зависимости не пуста
      if (pTerm->GetGroupDependancy()!=0)
      {
	//Пометим все вершины группы зависимости ядра меткой
	CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
      }
      //Проверим все определения
      //Если в определение попал отмеченный термин
      //Помечаем все термины определения меткой
      CheckDef(TERMS.GetHead(), head_Rel);
			
      //Посчитаем количество меток, занесем этот параметр в термин и обнулим метки
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

  //Перебираем список терминов и ищем термин с количеством связей ==1 или количеством ==0
  for (TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    if ((p->GetCountRelations()==1)||
	(p->GetCountRelations()==0))
    {
      //Отмечаем этот термин т.к. он отсекается зациклиным отсеканием листов
      p->SetLeafNode(1);
      recursion=true;
    }
  }
	
  //если был найден и отсечен хотя бы один лист то:
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
	
  //Перебираем термины и для каждого термина считаем количество связей
  for(TListTerm *ptr=TERMS.GetHead(); ptr!=NULL; ptr=ptr->GetNext())
  {
    if (ptr->GetLeafNode()!=1)//если этот лист еще не отброшен
    {
      Count_rel=0; //начальное значение количества связей
      LeafDef=false;
      //Для каждого термина считаем количество связей
      //Достаточно дойти до 2, чтобы понять, что это не лист
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      //Количество употреблений термина в определениях других терминов +
      //количество терминов в определении заданного термина
      TRelation *p=head_Rel;
      for(; p!=NULL; p=p->GetNext())
      {
	//если определяемый термин отсеян то связь не добавляется 
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
	  //Количество употреблений термина в определениях других терминов	
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
	    //считаем количество связей
	    //с неотсечеными листами
	    for(TListTerm *ptr2=TERMS.GetHead(); ptr2!=NULL; ptr2=ptr2->GetNext())
	    {
	      if((p->GetIndex_of_term()==ptr2->GetIndex())&&
		 (ptr2->GetLeafNode()!=1))
	      {
		if(p->GetDirection()!=0)
		{
		  //Количество употреблений терминов в определении
		  //заданного термина
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
		
      if (Count_rel<2) //Дистрибутивные связи ищем только если найдено менее двух связей
      {
	//Количество употреблений терминов в одном определении с термином
	//Дистрибутивная связь
	int count_t=0; //количество терминов в текущем определении
	//без определяемого и заданного терминов
	bool flag=false;  //Наличие заданного термина в текущем определении
		
	for(p=head_Rel;
	    p!=NULL;
	    p=p->GetNext())
	{
	  if (p->GetIndex_of_relation()!=-1)
	  {
	    //Если текущий термин не является заданным или определяемым
	    //Если текущий термин не отсекается цикличным сбрасыванием листов
	    //увеличиваем счетчик терминов текущего определения
					
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
					
	    //Если текущий термин не является определяемым, но найден
	    //отмечаем это определение как определение содержащее заданный термин
	    if((p->GetIndex_of_term()==ptr->GetIndex())&&
	       (p->GetDirection()!=0))
	    {
	      flag=true;
	    }
	  }
	  else		
	    //если список терминов опрежделения достиг конца
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
      //если это лист - отмечаем его
      if (Count_rel<=1)
      {
	ptr->SetLeafNode(1);
	recursion = true;
      }
    }//end if (ptr->GetLeafNode()!=1)//если этот лист еще не отброшен
  }

  //Если мы отсекали листы, граф необходимо проверить снова
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
  //количество связей (инцидентных ребер) вершины определено при
  //нахождении параметра Т3 (показателя ядра)

  //Посчитаем общее число вершин графа
  int TotalCountTerm=0;
  TListTerm *p=TERMS.GetHead();
  for(; p!=NULL; p=p->GetNext())
  {
    TotalCountTerm++; //общее количество терминов графа
  }

  //Для вычисления Т8 необходимо вычислить последний параметр:
  //Mmax - число вершин в максимальном по величине связном компоненте графа после удаления
  //рассматриваемой вершины
	
  //Выставляем все метки вершин в 0
  for (p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetCheck(0);
    p->SetCheck2(0);
  }
	
  int CountCheck; //счетчик связей
  int CountMax=0; //счетчик для вычисления максимального связного фрагмента графа

  //определим максимальное число вершин в связном графе после удаления каждой вершины
  for (p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    p->SetCheck2(1); //удаляем вершину из графа (на время)

    ///////////////////////////////////////////////////////
			

    //переберем термины и вычислим T8 через функции для Т5
    for(TListTerm *pTerm=TERMS.GetHead(); 
	pTerm!=NULL; 
	pTerm=pTerm->GetNext())
    {
      CountCheck=0; //обнуляем счетчик связанных вершин на каждой итерации
      //Для того чтобы термин был релевантным у него должна быть хотя бы одна дуга
      if((pTerm->GetCountRelations()!=0)&&(pTerm->GetCheck2()!=1))
      {
	//Если группа зависимости не пуста
	if (pTerm->GetGroupDependancy()!=0)
	{
	  //Пометим все вершины группы зависимости ядра меткой
	  CalculationGroupDependancy(pTerm, TERMS.GetHead(), head_Rel);
	}
	//Проверим все определения
	//Если в определение попал отмеченный термин
	//Помечаем все термины определения меткой
	CheckDef(TERMS.GetHead(), head_Rel);
			
	//Посчитаем количество меток, занесем этот параметр в термин и обнулим метки
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
      //сравниваем с максимальным значением связного компонента
      if (CountMax<CountCheck)
      {
	CountMax=CountCheck;
      }
    }
    ///////////////////////////////////////////////////////
		
    //Теперь расчитаем функциональный вес термина				
    p->SetFunctionalWeightOfTerm(p->GetCountRelations()*(TotalCountTerm-CountMax));
		
    CountMax=0;
    p->SetCheck2(0); //возвращаем вершину в граф
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
//Описание класса TList_Relation_weight
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
  int tempIndex=0; //запомним индех термина, для которого дано определение
  bool flag=false;

  for(TListTerm *pp=TERMS.GetHead();
      pp!=NULL;
      pp=pp->GetNext())
  {
    //Количество употреблений термина в определениях других терминов +
    //количество терминов в определении заданного термина
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
	//Количество употреблений термина в определениях других терминов	
	for(TRelation_weight  *ptr1=head_Rel; ptr1!=NULL; ptr1=ptr1->GetNext())
	{
	  if(  ((ptr1->GetIndex_of_term1()==pp->GetIndex())&&
		(ptr1->GetIndex_of_term2()==tempIndex)) || 
	       ((ptr1->GetIndex_of_term2()==pp->GetIndex())&&
		(ptr1->GetIndex_of_term1()==tempIndex)) )
	  {
	    flag=true; //если такая связь уже была отсеиваем ее
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
	    //Количество употреблений терминов в определении заданного термина
	    for(TRelation_weight  *ptr1=head_Rel; ptr1!=NULL; ptr1=ptr1->GetNext())
	    {
	      if(  ((ptr1->GetIndex_of_term1()==p->GetIndex_of_term())&&
		    (ptr1->GetIndex_of_term2()==tempIndex)) || 
		   ((ptr1->GetIndex_of_term2()==p->GetIndex_of_term())&&
		    (ptr1->GetIndex_of_term1()==tempIndex)) )
	      {
		flag=true; //если такая связь уже была отсеиваем ее
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
		
    //Количество употреблений терминов в одном определении с термином
    //Дистрибутивная связь
		
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
	//Если текищий термин не является определяемым
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
		  flag=true; //если такая связь уже была отсеиваем ее
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

//Поиск минимального пути между всеми вершинами
void TList_Relation_weight::Min_Way(TList_TermList &TERMS, TList_Relation &Relations)
{
  //Посчитаем количество терминов
  int TotalCountTerm=0;
  TListTerm *p=TERMS.GetHead(); 
  for(;
      p->GetNext()!=NULL; 
      p=p->GetNext())
  {}
  TotalCountTerm=int(p->GetIndex());
	
	
  //Объявим массив для хранения отношений терминов графа
  int** MasRel1;
  MasRel1 = new int* [2000];
  
  for (int k=1; k<=2000; k++) MasRel1[k]=new int [2000];
	
  //второй массив
  int** MasRel2;
  MasRel2 = new int* [2000];
  for (int m=1; m<=2000; m++) MasRel2[m]=new int [2000];

  //инициализация массивов
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
  //Если между терминами есть связь - занесем ее в массив
	
  First_fill(TERMS, Relations);

  for(TRelation_weight* ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    MasRel1[ptr->GetIndex_of_term1()][ptr->GetIndex_of_term2()]=ptr->GetMinWay()+1;
    MasRel2[ptr->GetIndex_of_term1()][ptr->GetIndex_of_term2()]=ptr->GetMinWay()+1;
		
    MasRel1[ptr->GetIndex_of_term2()][ptr->GetIndex_of_term1()]=ptr->GetMinWay()+1;
    MasRel2[ptr->GetIndex_of_term2()][ptr->GetIndex_of_term1()]=ptr->GetMinWay()+1;
  }
	
  bool exist=true;

  //Применим алгоритм Флойда для поиска минимальных путей между вершинами     
  for (int k=1; k<=TotalCountTerm; k++)
  {	
    for (int i=1; i<=TotalCountTerm; i++)
    {
      for (int j=1; j<=TotalCountTerm; j++)
      {
	if ((MasRel2[i][k] + MasRel2[k][j]) < MasRel1[i][j]) //если новый путь короче старого
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
					
	  if (exist==false) //если такой связи еще не было - создаем ее
	  {
	    AddLast_Relation(i, j, MasRel1[i][j]); //добавляем новую связь
	    exist=true;
	  }
	}
      }
    }

    for (int i=1; i<=TotalCountTerm; i++)
    {
      for (int j=1; j<=TotalCountTerm; j++)
      {
	MasRel2[i][j] = MasRel1[i][j]; //записываем матрицу прошлого шага
      }
    }
  }
	
  //запишем минимальные пути в список связей с длиной пути
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
	
  //запишем силу семантической связи для каждой связи в список связей
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    //определяем силу семантической связи
    ptr->SetPowerOfSamantikRelation( double(1) / (ptr->GetMinWay()) );
  }
}

//---------------------------------------
//---------------------------------------

//R2 Количество общих терминов учитывая частоту
void TList_Relation_weight::CountTermWithFreq(TList_TermList &TERMS, TList_Relation &Relations)
{
  double aver_freq=0;
  int sum=0, count_term=0;
	
  //посчитаем среднюю частоту терминов 
  for(TListTerm *p=TERMS.GetHead(); p!=NULL; p=p->GetNext())
  {
    count_term++;
    sum=sum+p->GetFreq();
  }
  aver_freq=double(sum)/double(count_term);
	
  int  CountTermInDef; //общее количестово терминов в двух определениях 
  bool Relation;		 //наличие непосредственной связи

  //список весов связей
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    Relation=false;

    TList_Relation Newborn1; //список с определениями 1 термина
    int indexN1=0;
    TList_Relation Newborn2; //список с определениями 2 термина
    int indexN2=0;

    //определим общее количество терминов в определениях терминов
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
	  //если есть непосредственная связь
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
	  //если есть непосредственная связь
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
      //определим количество общих терминов
      double sum1=0; //числитель
      int count_twin_value=0; //счетчик одинаковых значений
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
	    if (check==true)//исключаем повторения
	    {break;}
	  }
	}
      }
      //посчитаем R2
      if ( (sum1!=0) && (CountTermInDef!=0) ) //исключаем бесконечности
      {
	ptr->SetCountAggregateTerm( double(sum1) / double(CountTermInDef-count_twin_value) );
      } else
      {
	ptr->SetCountAggregateTerm(0);
      }
    }else //если есть непосредственная связь
    {
      ptr->SetCountAggregateTerm(1);
    }
  }
}

//---------------------------------------
//---------------------------------------

//R3 Релевантность связи
void TList_Relation_weight::ValenceRelevanceOfRelations(TList_TermList &TERMS)
{
  bool RelevanceOfTerm1=false;
	
  for(TRelation_weight *ptr=head_Rel; ptr!=NULL; ptr=ptr->GetNext())
  {
    RelevanceOfTerm1=false;
    //проверим первый термин на релевантность
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
      //проверим второй термин на релевантность
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

//R4 Совстречаемость терминов в тексте
void TList_Relation_weight::Co_OccurrenceOfTerms(TList_TermList &TERMS, TList_Definition &Paragraph)
{
  //объявляем счетчики для частоты появления в текущем абзаце терминов №1 и №2
  int count1=0, count2=0;
  int Total=0; //общий счетчик встречаимости терминов

  //перебираем список связей и для каждой по параграфам ищем совстречаемость теримнов №1 и №2
  for (TRelation_weight *pr=head_Rel; pr!=NULL; pr=pr->GetNext())
  {
    //Просматриваем параграфы в поисках терминов
    for (TListDef *pp = Paragraph.GetHead(); pp!=NULL; pp=pp->GetNext())
    {
      //Проверим наличие в параграфе термина №1
      for (TListTerm *pt = TERMS.GetHead(); pt!=NULL; pt=pt->GetNext())
      {
	if (pt->GetIndex()==pr->GetIndex_of_term1())
	{
	  count1=STRSTR_TermsInParagraph(pt, pp);
	  break;
	}
      }

      //Проверим наличие в параграфе термина №2
      for (TListTerm *pt = TERMS.GetHead(); pt!=NULL; pt=pt->GetNext())
      {
	if (pt->GetIndex()==pr->GetIndex_of_term2())
	{
	  count2=STRSTR_TermsInParagraph(pt, pp);
	  break;
	}
      }

      //Определим общее количество абзацев в которых встречаются оба термина
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
		
    ptrTerm = term->GetHead();//берем первое слово термина
    ptrTerm = ptrTerm->GetNext();//пропускаем первое слово термина т.к. в нем весь термин

    //если первое слово термина совпадает со словом в параграфе
    if ((strcmp(ptrTerm->GetTerm(), ptrPar->GetTerm())==0))
    {
      while (ptrTerm) //пока не просмотрим все слова термина
      {
	if ((ptrPar2->GetNext()!=NULL)&&
	    (ptrTerm->GetNext()!=NULL)) //если есть следующие элементы
	{
	  ptrPar2=ptrPar2->GetNext();// берем следующее слово параграфа
	  ptrTerm=ptrTerm->GetNext();// берем следующее слово термина
						
	  //пропустим пробелы между словами термина в определениях
	  //т.к. у нас в терминах нет пробелов
	  while (strcmp(ptrPar2->GetTerm()," ")==0)
	  {
	    /*if ((ptrPar2!=NULL)||(ptrPar2->GetNext()!=NULL))
	      {*/
	    ptrPar2=ptrPar2->GetNext();
	    //}else {break;}
	  }
				
	  if((strcmp(ptrTerm->GetTerm(), ptrPar2->GetTerm())!=0))
	  {
	    break; // если слова не совпадают берем следующее слово определения и снова сюда
	  }else
	  {
	    if((strcmp(ptrTerm->GetTerm(), ptrPar2->GetTerm())==0)&&
	       (ptrTerm->GetNext()==NULL)) //если слово совпадает и термин закончился
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
