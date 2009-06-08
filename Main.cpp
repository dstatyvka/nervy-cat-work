// -*- mode: c++; coding: cp1251 -*-
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
// #include <ctype>
// #include "process.h"
// #include "io.h"

#include "TNode.h"
#include "TList.h"

//Создаю свои списки 
TList_TermList TERMS; 
TList_Definition Definitions;
TList_Relation Relations;
TList_Relation_weight Relation_weight;
TList_Definition Paragraph;

std::ifstream *is = NULL;

int main(int argc, char* argv[])
{
	//*****************************************************
	//*****************************************************
	//***** Считываем частотный словарь курса лекций ******
	//*****************************************************
	//*****************************************************
	char Way1[512],	Way2[512], Way3[512], Way4[512];
	std::cout<<argv[1]<<std::endl;
	std::cout<<argv[2]<<std::endl;
	std::cout<<argv[3]<<std::endl;
	
	is = new std::ifstream();
	//Открываем выбранный файл
	is->open(argv[1], std::ios_base::in);
	
		if (is->is_open()!=0)
		{	
		  std::cout<<"====================="<<std::endl;
		
			//=========Разбор файла по словам=========
			char buf_word[512], buf_term[512];
			char ch;
			char buf[512];
			int i=0, freq=0, num=1;
			bool end_of_string=false;
			strcpy(buf_term,"");
		do
		{
			//Считываем следующий символ открытого файла
			is->get(ch);

			//Если не конец слова - добавляем к буферу
			if ((ch!='*')&&(ch!='@')&&(ch!='\n')&&
			    (!is->eof()))
			{
				buf_word[i]=ch;
				i++;
			}
			
			//Считано слово
			else
			{
			buf_word[i]=0;
			i=0;
			
			if (ch=='*') //Считали слово
			{
				strcat(buf_term,buf_word);
			}

			if((ch=='\n')&&(freq==0)&&
				(end_of_string==false)&&
				(buf_word[i]!=0)) //Считали частоту
			{
				freq=atoi(buf_word);
				//Заносим термин и его частоту в список
				TERMS.AddLast_List(num, buf_term, freq);
				num++;
				freq=0;
				end_of_string=true;
					// разбиваем составные термины на узлы
					//***************************
					strcpy(buf,"");
					int len=strlen(buf_term);
					int k=-1;
					for (int j=0; j<len; j++)
					{
						k++;
						if (buf_term[j]!=' ')
						{
							buf[k]=buf_term[j];
							buf[k+1]='\0';
						}
						else
						{
							TERMS.AddLast_Word(buf);
							strcpy(buf,"");
							k=-1;
						}
						if (j==(len-1))
						{
							TERMS.AddLast_Word(buf);
							strcpy(buf,"");
						}
					}
					strcpy(buf_word,"");
					strcpy(buf_term,"");
					//***************************
			}
			if (ch=='@')
			{
				strcpy(buf_word,"");
				strcpy(buf_term,"");
				end_of_string=false;
			}
			}
		}
		while (!is->eof());
		}
		is->close();
		std::cout<<"READ FROM KURS COMPLITE"<<std::endl;
	//*****************************************************
	//*****************************************************
	//****** Считываем обработанный словарь терминов ******
	//*****************************************************
	//*****************************************************
	
		std::cout<<"====================="<<std::endl;
		//Открываем выбранный файл
		is->open(argv[2], std::ios_base::in);

		if (is->is_open())
		{
			//=========Разбор файла по словам=========
			char buf_word[512];
			char buf_synonym[512];
			char ch;
			int i=0, index=0;
			bool fin_of_term=false;

			strcpy(buf_word,"");
			strcpy(buf_synonym,"");

		do
		{
			//Считываем следующий символ из открытого файла
			is->get(ch);

			//Если не конец слова добавляем к буферу
			if ((ch!=' ')&&(ch!='.')&&(ch!='!')&&(ch!='?')&&
				(ch!=':')&&(ch!=',')&&(ch!='\t')&&(ch!='+')&&
				(ch!='"')&&(ch!='»')&&(ch!='«')&&(ch!='“')&&
				(ch!='>')&&(ch!='<')&&(ch!='/')&&(ch!='*')&&
				(ch!='(')&&(ch!=')')&&(ch!='[')&&(ch!=']')&&
				(ch!='{')&&(ch!='}')&&(ch!='#')&&(ch!='?')&&
				(ch!=';')&&(ch!='$')&&(ch!='%')&&(ch!='^')&&
				(ch!='&')&&(ch!='=')&&(ch!='|')&&(ch!='~')&&
				(ch!='`')&&(ch!='\n')&&(ch!='-')&&
				(!is->eof()))
			{
				buf_word[i]=ch;
				i++;
			}
			//Считано слово
			else
			{
				//Избавляемся от разделителя
				if ((fin_of_term==false)&&(ch!='*'))
				{
					//Если это символ пунктуации, то влепим его
					//в термин
					if ((isalnum(ch)==0)&&(ch!='\n')&&
						(ch!='|')&&(ch!='('))
					{
						buf_word[i]=ch;
						i++;
					}
					//Если термин еще не добавлен 
					//и это не синоним
					if (ch=='|')
					{
						buf_word[i]=0;
						//отсечем пробелы в конце термина
						/******/
						int j;
						j=i-1;	
						while (((buf_word[j])==' ')||((buf_word[j])=='\t'))
						{
							buf_word[j]=0;
							j--;
						}
						/******/
						i=0;
						Definitions.AddLast_List(index, buf_word, buf_synonym);
						strcpy(buf_synonym,"");
						strcpy(buf_word,"");
						index++;
						fin_of_term=true;
					}else
					{
						//считываем синоним
						if (ch=='(')
						{
							int j=0;
							while (ch!=')')
							{
								is->get(ch);
								if (ch!=')')
								{
									buf_synonym[j]=ch;
									j++;
								}else
								{
									buf_synonym[j]=0;
									//отсечем пробелы в конце синонима
									/******/
									int k;
									k=j-1;	
									while (((buf_word[k])==' ')||((buf_word[k])=='\t'))
									{
										buf_synonym[k]=0;
										k--;
									}
									/******/
								}
							}
						}
					}
					//Если конец строки, то выставляем флаг нового термина 
				}else
				{
					if(fin_of_term==true)
					{
						if ((i>=1)||(isalnum(buf_word[i-1])!=0))
						{
							buf_word[i]=0;
							i=0;
							Definitions.AddLast_Word(buf_word);
						}
						if ((ch!='\n')&&(isalnum(ch)==0))
						{
							strcpy(buf_word,"");
							buf_word[0]=ch;
							buf_word[1]=0;
							Definitions.AddLast_Word(buf_word);
						}
					}
				}

				if((ch=='\n')&&(fin_of_term==true))
				{
					fin_of_term=false;
					buf_word[i]=0;
					i=0;
					strcpy(buf_word, "");
				}
			}
		}
		while (!is->eof());
		
		is->close();
		std::cout<<"READ FROM DEFINITION FILE COMPLITE"<<std::endl;
		std::cout<<"====================="<<std::endl;
		
		//*************************************************//
		//***** Установку связей между терминами **********//
		//*************************************************//
		
		Relations.Identification_of_relation(TERMS, Definitions);

		std::cout<<"Identification_of_relation COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//***** Вычисление энтропиии терминов **************//
		//*************************************************//
		
		TERMS.CalculationEntropy();

		std::cout<<"CalculationEntropy COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//***** Вычисление показателя ядра терминов *******//
		//*************************************************//
		
		Relations.Factor_of_Nexus(TERMS);

		std::cout<<"Factor_of_Nexus COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//** вычисление мощности группы зависимости ядра **//
		//*************************************************//
			
		Relations.GroupDependancy(TERMS);

		std::cout<<"GroupDependancy COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//**** Вычисление степени релевантности термина ***//
		//*************************************************//
			
		Relations.ValenceRelevance(TERMS);

		std::cout<<"ValenceRelevance COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//**** Вычисление параметра связности термина *****//
		//*************************************************//

		TERMS.ConnectivityOfTerm();

		std::cout<<"ConnectivityOfTerm COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//**** Вычисление листового параметра термина *****//
		//*************************************************//

		Relations.LeafNodeParamOfTerm(TERMS);

		std::cout<<"LeafNodeParamOfTerm COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//**** Вычисление функционального веса термина ****//
		//*************************************************//

		Relations.CalculationFunctionalWeigth(TERMS);

		std::cout<<"CalculationFunctionalWeigthOfTerm COMPLITE"<<std::endl;

		//*************************************************//
		//*************************************************//
		//**** Вычисление силы семантической связи ********//
		//*************************************************//

		Relation_weight.PowerOfSamantikRelation(TERMS, Relations);

		std::cout<<"Relation_weight COMPLITE"<<std::endl;

		//***************************************************************//
		//***************************************************************//
		//* Вычисление количества общих понятий учитывая частоту ********//
		//***************************************************************//

		Relation_weight.CountTermWithFreq(TERMS, Relations);

		std::cout<<"CountTermWithFreq COMPLITE"<<std::endl;

		//***************************************************************//
		//***************************************************************//
		//* Вычисление количества общих понятий учитывая частоту ********//
		//***************************************************************//

		Relation_weight.ValenceRelevanceOfRelations(TERMS);

		std::cout<<"ValenceRelevanceOfRelations COMPLITE"<<std::endl;

		//***************************************************************//
		//***************************************************************//
		//****** Определение совстречаимости терминов в тексте ***********//
		//***************************************************************//
		
			//*****************************************************
			//*****************************************************
			//****** Считываем курс лекций ************************
			//*****************************************************
			//*****************************************************
			
			std::cout<<"====================="<<std::endl;//Открываем выбранный файл
			
			is->open(argv[3], std::ios_base::in);
	
			if (is->is_open())
			{
	
				char buf_word[512];
				strcpy(buf_word,"");
				char ch;
				int i=0, index=0;
				bool first=true;

				do
				{
					is->get(ch);

					if ((ch!=' ')&&(ch!='.')&&(ch!='!')&&(ch!='?')&&
						 (ch!=':')&&(ch!=',')&&(ch!='\t')&&(ch!='+')&&
						 (ch!='"')&&(ch!='»')&&(ch!='«')&&(ch!='“')&&
						 (ch!='>')&&(ch!='<')&&(ch!='/')&&(ch!='*')&&
						 (ch!='(')&&(ch!=')')&&(ch!='[')&&(ch!=']')&&
						 (ch!='{')&&(ch!='}')&&(ch!='#')&&(ch!='?')&&
						 (ch!=';')&&(ch!='$')&&(ch!='%')&&(ch!='^')&&
						 (ch!='&')&&(ch!='=')&&(ch!='|')&&(ch!='~')&&
						 (ch!='`')&&(ch!='\n')&&
						 (!is->eof()))
					{
						buf_word[i]=ch;
						i++;
					}
					else
					{
						if (!is->eof())
						{
							buf_word[i]=0;
							i=0;
							
							if (first==true)
							{
								Paragraph.AddLast_List(index,buf_word,"");
								index++;
								strcpy(buf_word,"");
								first=false;
								
								char temp[2];
								temp[0]=ch;
								temp[1]=0;
								Paragraph.AddLast_Word(temp);
							}
							else
							{
								Paragraph.AddLast_Word(buf_word);
								strcpy(buf_word,"");
								
								char temp[2];
								temp[0]=ch;
								temp[1]=0;
								Paragraph.AddLast_Word(temp);
							}

							if(ch=='\n')
							{
								first=true;
							}
						}
					}
				}
				while (!is->eof());
			
			}
			is->close();
			delete is;

			std::cout<<"READ FROM KURS_2 COMPLITE"<<std::endl;
			std::cout<<"====================="<<std::endl;
		
		Relation_weight.Co_OccurrenceOfTerms(TERMS, Paragraph);

		std::cout<<"Co_OccurrenceOfTerms COMPLITE"<<std::endl;

		

		//***************************************************************/
		//***************************************************************/
		//***************************************************************//
		//==================================================
		//----------Сохраним словарь----------------

			strcpy(Way1,argv[1]);
			strcpy(Way2,argv[2]);
			strcpy(Way3,argv[1]);
			strcpy(Way4,argv[3]);

		//Отбрасываем расширение от имени выбранного файла
		for(i=strlen(Way1);i>3;i--)
		{
			if(Way1[i]=='.')
			{
				Way1[i]=0;
				break;
			}
		}

		for(i=strlen(Way2);i>3;i--)
		{
			if(Way2[i]=='.')
			{
				Way2[i]=0;
				break;
			}
		}

		for(i=strlen(Way3);i>3;i--)
		{
			if(Way3[i]=='.')
			{
				Way3[i]=0;
				break;
			}
		}

		for(i=strlen(Way4);i>3;i--)
		{
			if(Way4[i]=='.')
			{
				Way4[i]=0;
				break;
			}
		}

			TERMS.Show(Way1);
			
			Relations.Show(Way2);

			Relation_weight.Show(Way3);
			
			Paragraph.Show(Way4);

			std::cout<<"SHOW OF FILE COMPLITE"<<std::endl;
			
			/////////////////////////////////////////////////////////////////////////////////////////
		}

	//**************************************************************
	//**************************************************************
	//**************************************************************
	//**************************************************************
	//**************************************************************

	//Открываем результаты
		
	// //термины и параметры
	// //если существует файл
	// 	if(_access(Way1, 0)!=-1)
	// 	//Показать результаты
	// 		_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way1, NULL );
			
	// std::cout<<"SHOW KURS COMPLITE"<<std::endl;
		
	// //Отношения между параметрами
	// //если существует файл
	// 	if(_access(Way2, 0)!=-1)
	// 	//Показать результаты
	// 		_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way2, NULL );

	// std::cout<<"SHOW DEFINITION COMPLITE"<<std::endl;

	// //параметры отношений
	// //если существует файл
	// 	if(_access(Way3, 0)!=-1)
	// 	//Показать результаты
	// 		_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way3, NULL );

	// std::cout<<"SHOW RELATION_WEIGHT COMPLITE"<<std::endl;

	// //параметры отношений
	// //если существует файл
	// 	if(_access(Way4, 0)!=-1)
	// 	//Показать результаты
	// 		_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way4, NULL );

	// std::cout<<"SHOW KURS COMPLITE"<<std::endl;
	return 0;
}
