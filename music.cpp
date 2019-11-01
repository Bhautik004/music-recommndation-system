// MUSIC RECOMMENDATION SYSTEM

#include"myhead.h"
#include"myheader.h"

int main()
{
	int mainemenu,songtype,innersong,gujratisong,rendomsong,favsong,hindisong,englishsong;
  // char hindisong,englishsong,s;	
	system("COLOR 0A");
	printf("\n\n*********************************************************************************************************************\n");
	printf("\n\n\t\t\t\t\t<<====== LOGIN ======>>");
	
	FILE *fp2;
	
	//printf("\n\t\t\tSEARCH MEMBER");
	fp2=fopen("search.txt","r");
	if(fp2==NULL)
	{
		fp2=fopen("search.txt","w");
	}
	rewind(fp2);
	printf("\nEnter your name::");
	scanf("%s",name);


	printf("\n\n*********************************************************************************************************************\n");
	strcat(path,"D:\\p2\\fav\\");
	strcat(path,name);	
	m:		
		do{
			system("cls");
			while(fread(b,sizeof(b),1,fp2))
			{
				if(strcmp(b,name)==0)
				{
					t=1;
					printf("\n hello %s",name);
				}
			}	
			fclose(fp2);
			if(t==0)
			{
				printf("\nhello new user %s",name);
				fp2=fopen("search.txt","a");
				fseek(fp2,0, SEEK_END);
				fwrite(name,sizeof(name),1,fp2);
				fclose(fp2);
			}
			Mainmenu();
			scanf("%d",&mainemenu);
			switch(mainemenu)
			{
					case 1: // my palylist
					do{
						system("cls");
						Songtype();
						scanf("%d",&songtype);
						switch(songtype)
						{
							case 1: // gujratisong
							do{
								system("cls");
								Innersong();
							
								scanf("%d",&innersong);
								switch(innersong)
								{
									case 1: //gujrati song wise 
										do{
											system("cls");
											
											Gujratisong();
											if(title_Flag == 1)
											{
												printf("\n%s....\n",title);
											}
											
											if(song_Play_Flag == 1 )
											{
												printf("%s is playing....\n",current_Song);
											}	
											
											scanf("%d",&gujratisong);	
											if(song_Play_Flag == 1 || song_Play_Flag == 0 )
											{
												gets(stop);
												
												if(strcmp(stop,"s")==0 || strcmp(stop,"S")==0)
												{
													pause_Song();
													continue;
												}	
												if(strcmp(stop,"b")==0 || strcmp(stop,"B")==0)
												{
													pause_Song();
													break;
												}
												if(strcmp(stop,"n")==0 || strcmp(stop,"N")==0)
												{
													next();		
												}
												if(strcmp(stop,"p")==0 || strcmp(stop,"P")==0)
												{
														pre();
												}
												if(strcmp(stop,"f")==0 || strcmp(stop,"F")==0)
												{
													  add_To_favorite(path);
												}
												if(strcmp(stop,"r")==0 || strcmp(stop,"R")==0)
												{
													  printRandoms();
												}
											
																							
											}
											 
											fetch_Song(gujratisong);
						
										}while(gujratisong!=100);			
									break;
									case 2: // back
											system("cls");
											Songtype();												
									break;
									
									default:
										printf("\nWrong choice");
									break;
								}						
							}while(innersong!=2);
								
							break;
							
							case 2: // hindi song
							do{
								system("cls");
								Innersong();
								scanf("%d",&innersong);
								switch(innersong)
								{
									case 1: // song wise
									do{
											system("cls");
											Hindisong();
											if(title_Flag == 1)
											{
												printf("\n%s....\n",title);
											}
											if(song_Play_Flag == 1)
											{
												printf("%s is playing....\n",current_Song);
											}
											
											scanf("%d",&hindisong);
											if(song_Play_Flag == 1 || song_Play_Flag == 0 )
											{
												gets(stop);
												
												if(strcmp(stop,"s")==0 || strcmp(stop,"S")==0)
												{
													pause_Song();
													continue;
												}	
												if(strcmp(stop,"b")==0 || strcmp(stop,"B")==0)
												{
													pause_Song();
													break;
												}
												if(strcmp(stop,"n")==0 || strcmp(stop,"N")==0)
												{
													next();		
												}
												if(strcmp(stop,"p")==0 || strcmp(stop,"P")==0)
												{
														pre();
												}
												if(strcmp(stop,"f")==0 || strcmp(stop,"F")==0)
												{
													  add_To_favorite(path);
												}
												if(strcmp(stop,"r")==0 || strcmp(stop,"R")==0)
												{
													  printRandoms();
												}												
											}
											
											fetch_Song(hindisong);
						
										}while(hindisong!=100);
					
									break;
									
									case 2: // back
											system("cls");	
											Songtype();												
									break;
									
									default:
										printf("\nWrong choice");
									break;
								}
									}while(innersong!=2);
							
							break;
							
							case 3: // englishsong
							do{
								system("cls");
								Innersong();
								scanf("%d",&innersong);
								switch(innersong)
								{
									case 1: // song wise
										do{
											system("cls");
											Englishsong();
											if(title_Flag == 1)
											{
												printf("\n%s....\n",title);
											}
											if(song_Play_Flag == 1)
											{
												printf("%s is playing....\n",current_Song);
											}
											
											scanf("%d",&englishsong);
											if(song_Play_Flag == 1 || song_Play_Flag == 0 )
											{
												gets(stop);
												
												if(strcmp(stop,"s")==0 || strcmp(stop,"S")==0)
												{
													pause_Song();
													continue;
												}	
												if(strcmp(stop,"b")==0 || strcmp(stop,"B")==0)
												{
													pause_Song();
													break;
												}
												if(strcmp(stop,"n")==0 || strcmp(stop,"N")==0)
												{
													next();		
												}
												if(strcmp(stop,"p")==0 || strcmp(stop,"P")==0)
												{
													pre();
												}
												if(strcmp(stop,"f")==0 || strcmp(stop,"F")==0)
												{
													  add_To_favorite(path);
												}
												if(strcmp(stop,"r")==0 || strcmp(stop,"R")==0)
												{
													  printRandoms();
												}
											
																							
											}
											
											fetch_Song(englishsong);
						
										}while(englishsong!=100);
										
									break;
									
									case 2: // back
											system("cls");
											Songtype();												
									break;
									
									default:
										printf("\nWrong choice");
									break;
									
								}
							}while(innersong!=2);
							break;
							
							case 4 : // back
								
							break;
							
							default:
							printf("\nWrong choice");
							break;
						}
						if(songtype!=4)
						getch();
					}while(songtype!=4);
					break;
					
					case 2: // random paly
						do{
											
											system("cls");
											random();						
											printRandoms();
											back=1;
											if(title_Flag == 1)
											{
												printf("\n%s....\n",title);
											}
											if(song_Play_Flag == 1)
											{
												printf("%s is playing....\n",current_Song);
											}
											
											scanf("%d",&rendomsong);
											gets(stop);
											
											if(song_Play_Flag == 1 )
											{
												//gets(stop);
												if(strcmp(stop,"s")==0 || strcmp(stop,"S")==0)
												{
												
														back=0;
														pause_Song();
														continue;	
												}
												
												if(strcmp(stop,"b")==0 || strcmp(stop,"B")==0)
												{
													pause_Song();
													break;
												}
												
												if(strcmp(stop,"n")==0 || strcmp(stop,"N")==0)
												{
													next();		
												}
												if(strcmp(stop,"p")==0 || strcmp(stop,"P")==0)
												{
													pre();
												}
												
																								
											}
											fetch_Song(rendomsong);
						
										}while(rendomsong!=100);
										
					break;
					
					case 3: // fav
						do{
											system("cls");
											read_song(path,NULL);
																	
											if(title_Flag == 1)
											{
												printf("\n%s....\n",title);
											}
											
											if(song_Play_Flag == 1)
											{
												printf("%s is playing....\n",current_Song);
											}				
											
											scanf("%d",&favsong);
											
											read_song(path,favsong);
						
											if(song_Play_Flag == 1)
											{
												gets(stop);
												//flushall();
												if(strcmp(stop,"s")==0 || strcmp(stop,"S")==0)
												{
													pause_Song();
													continue;
												}	
												if(strcmp(stop,"b")==0 || strcmp(stop,"B")==0)
												{
													pause_Song();
													system("cls");
													goto m;
													break;
												}
												if(strcmp(stop,"n")==0 || strcmp(stop,"N")==0)
												{
													next();		
												}
												if(strcmp(stop,"p")==0 || strcmp(stop,"P")==0)
												{
														pre();
												}
												if(strcmp(stop,"f")==0 || strcmp(stop,"F")==0)
												{
													  add_To_favorite(path);
												}
												if(strcmp(stop,"r")==0 || strcmp(stop,"R")==0)
												{
													  printRandoms();
												}								
											}
											
											//	fetch_fav(favsong);
									}while(favsong!=100);
					break;	
					
					case 4: // exit
					exit(0);
					break;
					
					default:
					printf("\nWrong choice");
					break;
			}
			if(mainemenu!=4 && songtype!=4 && innersong!=3 && gujratisong!=6 && hindisong!=6 && englishsong!=6)
				getch();
		}while(mainemenu!=4);
}


