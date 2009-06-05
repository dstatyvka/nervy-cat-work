// -*- mode: c++; coding: cp1251 -*-
#include "TNode.h"
#include "TList.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "process.h"
#include "io.h"

//������ ���� ������ 
	TList_TermList TERMS; 
	TList_Definition Definitions;
	TList_Relation Relations;
	TList_Relation_weight Relation_weight;
	TList_Definition Paragraph;

	ifstream *is = NULL;

void main(int argc, char* argv[])
{
	//*****************************************************
	//*****************************************************
	//***** ��������� ��������� ������� ����� ������ ******
	//*****************************************************
	//*****************************************************
	char Way1[512],	Way2[512], Way3[512], Way4[512];
	cout<<argv[1]<<endl;
	cout<<argv[2]<<endl;
	cout<<argv[3]<<endl;
	
	is = new ifstream();
	//��������� ��������� ����
	is->open(argv[1], ios::nocreate);	
	
		if (is->is_open()!=0)
		{	
			cout<<"====================="<<endl;
		
			//=========������ ����� �� ������=========
			char buf_word[512], buf_term[512];
			char ch;
			char buf[512];
			int i=0, freq=0, num=1;
			bool end_of_string=false;
			strcpy(buf_term,"");
		do
		{
			//��������� ��������� ������ ��������� �����
			is->get(ch);

			//���� �� ����� ����� - ��������� � ������
			if ((ch!='*')&&(ch!='@')&&(ch!='\n')&&
			    (!is->eof()))
			{
				buf_word[i]=ch;
				i++;
			}
			
			//������� �����
			else
			{
			buf_word[i]=0;
			i=0;
			
			if (ch=='*') //������� �����
			{
				strcat(buf_term,buf_word);
			}

			if((ch=='\n')&&(freq==0)&&
				(end_of_string==false)&&
				(buf_word[i]!=0)) //������� �������
			{
				freq=atoi(buf_word);
				//������� ������ � ��� ������� � ������
				TERMS.AddLast_List(num, buf_term, freq);
				num++;
				freq=0;
				end_of_string=true;
					// ��������� ��������� ������� �� ����
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
		cout<<"READ FROM KURS COMPLITE"<<endl;
	//*****************************************************
	//*****************************************************
	//****** ��������� ������������ ������� �������� ******
	//*****************************************************
	//*****************************************************
	
		cout<<"====================="<<endl;
		//��������� ��������� ����
		is->open(argv[2], ios::nocreate);

		if (is->is_open())
		{
			//=========������ ����� �� ������=========
			char buf_word[512];
			char buf_synonym[512];
			char ch;
			int i=0, index=0;
			bool fin_of_term=false;

			strcpy(buf_word,"");
			strcpy(buf_synonym,"");

		do
		{
			//��������� ��������� ������ �� ��������� �����
			is->get(ch);

			//���� �� ����� ����� ��������� � ������
			if ((ch!=' ')&&(ch!='.')&&(ch!='!')&&(ch!='?')&&
				(ch!=':')&&(ch!=',')&&(ch!='\t')&&(ch!='+')&&
				(ch!='"')&&(ch!='�')&&(ch!='�')&&(ch!='�')&&
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
			//������� �����
			else
			{
				//����������� �� �����������
				if ((fin_of_term==false)&&(ch!='*'))
				{
					//���� ��� ������ ����������, �� ������ ���
					//� ������
					if ((isalnum(ch)==0)&&(ch!='\n')&&
						(ch!='|')&&(ch!='('))
					{
						buf_word[i]=ch;
						i++;
					}
					//���� ������ ��� �� �������� 
					//� ��� �� �������
					if (ch=='|')
					{
						buf_word[i]=0;
						//������� ������� � ����� �������
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
						//��������� �������
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
									//������� ������� � ����� ��������
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
					//���� ����� ������, �� ���������� ���� ������ ������� 
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
		cout<<"READ FROM DEFINITION FILE COMPLITE"<<endl;
		cout<<"====================="<<endl;
		
		//*************************************************//
		//***** ��������� ������ ����� ��������� **********//
		//*************************************************//
		
		Relations.Identification_of_relation(TERMS, Definitions);

		cout<<"Identification_of_relation COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//***** ���������� ��������� �������� **************//
		//*************************************************//
		
		TERMS.CalculationEntropy();

		cout<<"CalculationEntropy COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//***** ���������� ���������� ���� �������� *******//
		//*************************************************//
		
		Relations.Factor_of_Nexus(TERMS);

		cout<<"Factor_of_Nexus COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//** ���������� �������� ������ ����������� ���� **//
		//*************************************************//
			
		Relations.GroupDependancy(TERMS);

		cout<<"GroupDependancy COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//**** ���������� ������� ������������� ������� ***//
		//*************************************************//
			
		Relations.ValenceRelevance(TERMS);

		cout<<"ValenceRelevance COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//**** ���������� ��������� ��������� ������� *****//
		//*************************************************//

		TERMS.ConnectivityOfTerm();

		cout<<"ConnectivityOfTerm COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//**** ���������� ��������� ��������� ������� *****//
		//*************************************************//

		Relations.LeafNodeParamOfTerm(TERMS);

		cout<<"LeafNodeParamOfTerm COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//**** ���������� ��������������� ���� ������� ****//
		//*************************************************//

		Relations.CalculationFunctionalWeigth(TERMS);

		cout<<"CalculationFunctionalWeigthOfTerm COMPLITE"<<endl;

		//*************************************************//
		//*************************************************//
		//**** ���������� ���� ������������� ����� ********//
		//*************************************************//

		Relation_weight.PowerOfSamantikRelation(TERMS, Relations);

		cout<<"Relation_weight COMPLITE"<<endl;

		//***************************************************************//
		//***************************************************************//
		//* ���������� ���������� ����� ������� �������� ������� ********//
		//***************************************************************//

		Relation_weight.CountTermWithFreq(TERMS, Relations);

		cout<<"CountTermWithFreq COMPLITE"<<endl;

		//***************************************************************//
		//***************************************************************//
		//* ���������� ���������� ����� ������� �������� ������� ********//
		//***************************************************************//

		Relation_weight.ValenceRelevanceOfRelations(TERMS);

		cout<<"ValenceRelevanceOfRelations COMPLITE"<<endl;

		//***************************************************************//
		//***************************************************************//
		//****** ����������� ��������������� �������� � ������ ***********//
		//***************************************************************//
		
			//*****************************************************
			//*****************************************************
			//****** ��������� ���� ������ ************************
			//*****************************************************
			//*****************************************************
			
			cout<<"====================="<<endl;//��������� ��������� ����
			
			is->open(argv[3], ios::nocreate);
	
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
						 (ch!='"')&&(ch!='�')&&(ch!='�')&&(ch!='�')&&
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

			cout<<"READ FROM KURS_2 COMPLITE"<<endl;
			cout<<"====================="<<endl;
		
		Relation_weight.Co_OccurrenceOfTerms(TERMS, Paragraph);

		cout<<"Co_OccurrenceOfTerms COMPLITE"<<endl;

		

		//***************************************************************/
		//***************************************************************/
		//***************************************************************//
		//==================================================
		//----------�������� �������----------------

			strcpy(Way1,argv[1]);
			strcpy(Way2,argv[2]);
			strcpy(Way3,argv[1]);
			strcpy(Way4,argv[3]);

		//����������� ���������� �� ����� ���������� �����
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

			cout<<"SHOW OF FILE COMPLITE"<<endl;
			
			/////////////////////////////////////////////////////////////////////////////////////////
		}

	//**************************************************************
	//**************************************************************
	//**************************************************************
	//**************************************************************
	//**************************************************************

	//��������� ����������
		
	//������� � ���������
	//���� ���������� ����
		if(_access(Way1, 0)!=-1)
		//�������� ����������
			_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way1, NULL );
			
	cout<<"SHOW KURS COMPLITE"<<endl;
		
	//��������� ����� �����������
	//���� ���������� ����
		if(_access(Way2, 0)!=-1)
		//�������� ����������
			_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way2, NULL );

	cout<<"SHOW DEFINITION COMPLITE"<<endl;

	//��������� ���������
	//���� ���������� ����
		if(_access(Way3, 0)!=-1)
		//�������� ����������
			_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way3, NULL );

	cout<<"SHOW RELATION_WEIGHT COMPLITE"<<endl;

	//��������� ���������
	//���� ���������� ����
		if(_access(Way4, 0)!=-1)
		//�������� ����������
			_spawnlp(_P_NOWAIT, /*_P_OVERLAY,*/ "notepad.exe", "notepad.exe", Way4, NULL );

	cout<<"SHOW KURS COMPLITE"<<endl;
}
