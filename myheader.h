#include"var.h" // include variable  header file



// log in
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*
void wel()
{	
	system("COLOR F0");
	PlaySound(TEXT("welcome.wav"),NULL, SND_SYNC );	
}
*/

// Play song function
int PLAYSONG(char song_Name[])
{
		song_Play_Flag = 1;
		PlaySound(TEXT(song_Name),NULL, SND_SYNC || SND_LOOP );	 // song play function
		return 0;
}

// pause song function
int pause_Song()
{
	song_Play_Flag = 0;
	PlaySound(0,0,0);
	return 0;
}
int pause_Song_r()
{
	song_Play_Flag = 0;
	PlaySound(0,0,0);
	return 0;
}
// all song are listed function
int list_Dir(char a[])
{	
	int auto_increment = 1;
	upper=1;	
	char *dir_Path = "D:\\p2\\";
	char *folder_name = a;
	
	strcpy(destination,dir_Path);
	strcat(destination,folder_name);
	strcat(destination,"\\");

	if((dir = opendir (destination)) != NULL)
	{
		/* print all the files and directories within directory */
	  	while ((ent = readdir(dir)) != NULL)
		{
  		
  			if ( !strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
    		{
        		continue;
    		}
    		
			printf ("\t\t\t\t %d:%s\n", auto_increment, ent->d_name);
    		
			auto_increment++;
			upper =	auto_increment;
		}

		printf("\n\n");
	
		printf("\t\t\t\t f.Favourite Song\n");
		printf("\t\t\t\t n..Next-Song \n");
		printf("\t\t\t\t p..Previous-Song \n");
		printf("\t\t\t\t r..Random Play\n");
		printf("\t\t\t\t s..Stop\n");
		printf("\t\t\t\t b..Back \n");
		closedir (dir);	
	}
	else
	{
  		/* could not open directory */
  		return 0;
	}
	return 0;
}
int list_Dir_r(char a[])
{	
	int auto_increment = 1;
	upper=1;	
	char *dir_Path = "D:\\p2\\";
	char *folder_name = a;
	
	strcpy(destination,dir_Path);
	strcat(destination,folder_name);
	strcat(destination,"\\");

	if((dir = opendir (destination)) != NULL)
	{
		/* print all the files and directories within directory */
	  	while ((ent = readdir(dir)) != NULL)
		{
  		
  			if ( !strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
    		{
        		continue;
    		}
    		
			printf ("\t\t\t\t %d:%s\n", auto_increment, ent->d_name);
    		
			auto_increment++;
			upper =	auto_increment;
		}

		printf("\n\n");
	
	
		printf("\t\t\t\t n..Next Rendom Song \n");
		printf("\t\t\t\t p..Previous Rendom Song \n");
		printf("\t\t\t\t s..Stop\n");
		printf("\t\t\t\t b..Back \n");
		closedir (dir);	
	}
	else
	{
  		/* could not open directory */
  		return 0;
	}
	return 0;
}

char fetch_Song(int song_Number,char *val = NULL)
{	
	int auto_increment = 1;

	char return_Song_Path[500];

 	if ((dir = opendir(destination))!= NULL & val == NULL)
	{
	/* print all the files and directories within directory */
	
	  	while ((ent = readdir (dir)) != NULL)  // end  for linklist node
		{
				if ( !strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
		    	{
		        	continue;
		    	}  
		    	
				if(auto_increment == song_Number)
				{		
					current_Song_Number=song_Number;
					strcpy(current_Song,ent->d_name);
					strcat(destination,ent->d_name);
					PLAYSONG(destination);
				}
		    	auto_increment++;  
		}
		
			closedir (dir);	
	} 
	if(val != NULL)
	{
		int index = 0;
		
		while(val[index])
		{     
     	
		 	if(val[index] == '\\')
			{
	 			val[index] = '/';
 			}
     	
			index++;
		}
		
		len = strlen(val);	
		if( val[len-1] == '\n')
    	val[len-1] = 0;
    
		strcpy(current_Song,val);
	
		PlaySound(TEXT(val),NULL, SND_SYNC || SND_LOOP || SND_FILENAME );
	}
	else 
	{
  		/* could not open directory */
  		return 0;
	}
}
// mainmenu
void Mainmenu()
{
	printf("\n\n*********************************************************************************************************************\n");
	printf(" \n\n \t\t\t\t\t<<==========--Welcome to Music--==========>> \n");
	printf("\n\n\t\t\t\t\t 1..My PlayList\n");
	printf("\n\t\t\t\t\t 2..Random Play\n");
	printf("\n\t\t\t\t\t 3..Favourite Play\n");
	printf("\n\t\t\t\t\t 4..Exit\n");
	printf("\n\n***********************************************************************************************************************\n");
	printf("\n\t\t\t\t Enter choice ::");
}

//song type
void Songtype()
{
	printf("\n\n***********************************************************************************************************************\n");
	printf("\n\n\t\t\t\t<<============My PlayList =================>>");
	printf("\n\n\t\t\t\t1..Gujrati Song\n");
	printf("\n\t\t\t\t2..Hindi Song\n");
	printf("\n\t\t\t\t3..English Song\n");
	printf("\n\t\t\t\t4..Back");
	printf("\n\n***********************************************************************************************************************\n");
	printf("\n\n\t\t\t\tEnter choice ::");
}

//inner song menu
void Innersong()
{
	printf("\n\n*******************************************************************************************************************\n");
	printf("\n\n\t\t\t\t<<============My SONGS =================>>");
	printf("\n\n\t\t\t\t1..Songs");
	printf("\n\n\t\t\t\t2..Back");
	printf("\n\n**********************************************************************************************************************\n");
	printf("\n\n\t\t\t\tEnter Your Choice ::");	
}

void Gujratisong()
{
	printf("\n\n*********************************************************************************************************************\n");
	list_Dir("gujrati song");	
	printf("\n\n*********************************************************************************************************************\n");
}

//hindi song function
void Hindisong()
{
	printf("\n\n*********************************************************************************************************************\n");
	list_Dir("hindi song");	
	printf("\n\n*********************************************************************************************************************\n");
}

//english song function
void Englishsong()
{
	printf("\n\n*********************************************************************************************************************\n");
	list_Dir("english song");
	printf("\n\n*********************************************************************************************************************\n");
}

// favourite song function
void fav()
{
	list_Dir("fav");
}

//rendom song function
void random()
{
	list_Dir_r("random");
}

//play random song
int play_randomm(int random_num)
{	song_Play_Flag = 1; 
	fetch_Song(random_num);	
}

//rendom function4

void printRandoms()
{
	
    int i;
	
    	for (i = 0; i < count; i++)
    	{
			num = (rand()%(upper - lower + 1)) + lower;
    	}  
		if(back==1)
    	{
    		 play_randomm(num);   
		} 

    //play_randomm(num);    
}

//to play next song function
void next()
{
	int next_Song = current_Song_Number + 1;
	if(next_Song == total_songs)
	{
		strcpy(title,"No song is Available/n");
		pause_Song();
		next_Song = 1;	
	}
	else
	{				
		fetch_Song(next_Song);
	}
}

//to play previous song function
void pre()
{
	int previous_Song = current_Song_Number - 1;
	if(previous_Song < 0)
	{
		strcpy(title,"No song is Available/n");
		pause_Song();
		previous_Song=1;
	}
	else
	{
		fetch_Song(previous_Song);
	}
}

// song are add into favorite
void add_To_favorite(char fname[])
{
	//printf("%s",current_Song);
	fp=fopen(fname,"a");	
	strcat(destination,current_Song);
	fprintf(fp,"%s\n",destination);
	printf("\n%s..song added to favorite",current_Song);
	fclose(fp);
}
int play_favorite(char *val)
{		
	song_Play_Flag = 1;
	fetch_Song(1,val);
	return 0;
}

// favorite song read function
void read_song(char fname[],int favsong)
{
	fp=fopen(fname,"r");	
    int i=1;
	char line[200];
	while (fgets(line,sizeof line,fp) != NULL ) 
    {      	
		  if(favsong!= NULL  &&  i==favsong)
		  {
      		play_favorite(line);	
      	  }
      	  else printf("%d: %s ",i,line);
	    	i++;
    }
    printf("\n\n\n\n");
	printf("\t\t\t\t s..Stop\n");
	printf("\t\t\t\t b..Back \n");
	fclose (fp);	
}


