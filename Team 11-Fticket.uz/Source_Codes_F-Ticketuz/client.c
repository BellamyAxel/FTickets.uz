#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444


#define MN_METRIC "1000"

#define MN_MATCH_LIST "1110"
#define MN_CHOOSE_STADIUM  "1111"
#define MN_CHOOSE_SEAT "1112"

#define DELIMITER_MN '#'
#define DELIMITER_ENTITY '*'
#define DELIMITER_ENTRY '|'

int match_id=0;
int ticket_id=0;


void matches();
void stadium_select();

void reserve(int id){
	int option1;
	printf("\n\nAvailable tickets:\n");
	if (id==1){
	printf("  ticket_id | sector | row  | seat | match_id | ticket_price");
	printf("\n1.  6101    |   A    |  1   |   12 |   5101   |      785.00 ");
	printf("\n2.  6102    |   A    |  2   |   13 |   5101   |      765.00 ");
	printf("\n3.  6103    |   A    |  3   |   14 |   5101   |      755.00 ");
	printf("\n4.  6104    |   A    |  4   |   15 |   5101   |      745.00 ");
	printf("\n5.  6105    |   A    |  5   |   16 |   5101   |      745.00 \n\n");
	
	printf("0. Cancel\n");
	printf("..>");
	scanf("%d", &option1);
	//stadium_select(option1);
	}

	if (id==2){
	printf("  ticket_id | sector | row  | seat | match_id | ticket_price");
	printf("\n1.  6101    |   A    |  1   |   12 |   5102   |      785.00 ");
	printf("\n2.  6102    |   A    |  2   |   13 |   5102   |      765.00 ");
	printf("\n3.  6103    |   A    |  3   |   14 |   5102   |      755.00 ");
	printf("\n4.  6104    |   A    |  4   |   15 |   5102   |      745.00 ");
	printf("\n5.  6105    |   A    |  5   |   16 |   5102   |      745.00 \n\n");
	printf("0. Cancel\n");
	printf("..>");
	scanf("%d", &option1);
	//stadium_select(option1);
	}
	
	if (id==3){
	printf("  ticket_id | sector | row  | seat | match_id | ticket_price");
	printf("\n1.  6101    |   A    |  1   |   12 |   5103   |      785.00 ");
	printf("\n2.  6102    |   A    |  2   |   13 |   5103   |      765.00 ");
	printf("\n3.  6103    |   A    |  3   |   14 |   5103   |      755.00 ");
	printf("\n4.  6104    |   A    |  4   |   15 |   5103   |      745.00 ");
	printf("\n5.  6105    |   A    |  5   |   16 |   5103   |      745.00 \n\n");
	printf("..>");
	scanf("%d", &option1);
	//stadium_select(option1);
	}

	if (id==4){
	printf("  ticket_id | sector | row  | seat | match_id | ticket_price");
	printf("\n1.  6101    |   A    |  1   |   12 |   5104   |      785.00 ");
	printf("\n2.  6102    |   A    |  2   |   13 |   5104   |      765.00 ");
	printf("\n3.  6103    |   A    |  3   |   14 |   5104   |      755.00 ");
	printf("\n4.  6104    |   A    |  4   |   15 |   5104   |      745.00 ");
	printf("\n5.  6105    |   A    |  5   |   16 |   5104   |      745.00 \n\n");
	printf("0. Cancel\n");
	printf("..>");
	scanf("%d", &option1);
	//stadium_select(option1);
	}

	if (id==5){
	printf("  ticket_id | sector | row  | seat | match_id | ticket_price");
	printf("\n1.  6101    |   A    |  1   |   12 |   5105   |      785.00 ");
	printf("\n2.  6102    |   A    |  2   |   13 |   5105   |      765.00 ");
	printf("\n3.  6103    |   A    |  3   |   14 |   5105   |      755.00 ");
	printf("\n4.  6104    |   A    |  4   |   15 |   5105   |      745.00 ");
	printf("\n5.  6105    |   A    |  5   |   16 |   5105   |      745.00 \n\n");
	printf("0. Cancel\n");
	printf("..>");
	scanf("%d", &option1);
	//stadium_select(option1);
	}

	system("clear");
	printf("\n\tSelected Game:\n");
	switch(match_id){
		case 1:{ 

			printf("1. Pakhtakor - Bunyodkor  11/09/2019\n"); 
			switch(option1){

				case 1:{ printf(" 1. sector A | row 1 | seat 12 | match %d | price 785.00 \n",match_id);break;}
				case 2:{printf(" 2. sector A | row 2 | seat 13 | match %d | price 765.00 \n",match_id);break;}
				case 3:{printf(" 3. sector A | row 3 | seat 14 | match %d | price 755.00 \n",match_id);break;}
				case 4:{printf(" 4. sector A | row 4 | seat 15 | match %d | price 745.00 \n",match_id);break;}
				case 5:{printf(" 5. sector A | row 5 | seat 16 | match %d | price 745.00 \n",match_id);break;}

			}break;}
		case 2:{ printf("2. Lokomotiv - Metallurg  17/09/2019\n"); 
		switch(option1){

				case 1:{ printf(" 1. sector A | row 1 | seat 12 | match %d | price 785.00 \n",match_id);break;}
				case 2:{printf(" 2. sector A | row 2 | seat 13 | match %d | price 765.00 \n",match_id);break;}
				case 3:{printf(" 3. sector A | row 3 | seat 14 | match %d | price 755.00 \n",match_id);break;}
				case 4:{printf(" 4. sector A | row 4 | seat 15 | match %d | price 745.00 \n",match_id);break;}
				case 5:{printf(" 5. sector A | row 5 | seat 16 | match %d | price 745.00 \n",match_id);break;}

			}
		break;}
		case 3:{ printf("3. Navbahor  - Andijan    18/09/2019\n");
		switch(option1){

				case 1:{ printf(" 1. sector A | row 1 | seat 12 | match %d | price 785.00 \n",match_id);break;}
				case 2:{printf(" 2. sector A | row 2 | seat 13 | match %d | price 765.00 \n",match_id);break;}
				case 3:{printf(" 3. sector A | row 3 | seat 14 | match %d | price 755.00 \n",match_id);break;}
				case 4:{printf(" 4. sector A | row 4 | seat 15 | match %d | price 745.00 \n",match_id);break;}
				case 5:{printf(" 5. sector A | row 5 | seat 16 | match %d | price 745.00 \n",match_id);break;}

			}
		 break;}
		case 4:{ printf("4. Buhoro    - Shurtan    19/09/2019\n"); 
		switch(option1){

				case 1:{ printf(" 1. sector A | row 1 | seat 12 | match %d | price 785.00 \n",match_id);break;}
				case 2:{printf(" 2. sector A | row 2 | seat 13 | match %d | price 765.00 \n",match_id);break;}
				case 3:{printf(" 3. sector A | row 3 | seat 14 | match %d | price 755.00 \n",match_id);break;}
				case 4:{printf(" 4. sector A | row 4 | seat 15 | match %d | price 745.00 \n",match_id);break;}
				case 5:{printf(" 5. sector A | row 5 | seat 16 | match %d | price 745.00 \n",match_id);break;}

			}
		break;}
		case 5:{ printf("5. Mashal    - Qizilqum   20/09/2019\n"); 
		switch(option1){

				case 1:{ printf(" 1. sector A | row 1 | sear 12 | match %d | price 785.00 \n",match_id); break;}
				case 2:{printf(" 2. sector A | row 2 | sear 13 | match %d | price 765.00 \n",match_id);break;}
				case 3:{printf(" 3. sector A | row 3 | sear 14 | match %d | price 755.00 \n",match_id);break;}
				case 4:{printf(" 4. sector A | row 4 | sear 15 | match %d | price 745.00 \n",match_id);break;}
				case 5:{printf(" 5. sector A | row 5 | sear 16 | match %d | price 745.00 \n",match_id);break;}

			}
		break;}


	}
	
	ticket_id=option1;
	if (option1==0) matches();


}


void stadium_select(int match){
	
	system("clear");
	switch(match){
		//system("clear");
		case 1:{ printf("1. Pakhtakor - Bunyodkor  11/09/2019\n"); match_id=1; break;}
		case 2:{ printf("2. Lokomotiv - Metallurg  17/09/2019\n"); match_id=2; break;}
		case 3:{ printf("3. Navbahor  - Andijan    18/09/2019\n"); match_id=3; break;}
		case 4:{ printf("4. Buhoro    - Shurtan    19/09/2019\n"); match_id=4; break;}
		case 5:{ printf("5. Mashal    - Qizilqum   20/09/2019\n"); match_id=5; break;}
		
		case 6:{ printf("\nExitting! Thank you for using our services!!\n\n"); exit(1); break;}
		default: matches();
		}
		reserve(match_id);
}


void matches(){

int match1;
	system("clear");
	printf("\nUpcoming Events/matches:\n");
    printf("1. Pakhtakor - Bunyodkor  11/09/2019\n");
    printf("2. Lokomotiv - Metallurg  17/09/2019\n");
    printf("3. Navbahor  - Andijan    18/09/2019\n");
    printf("4. Buhoro    - Shurtan    19/09/2019\n");
    printf("5. Mashal    - Qizilqum	  20/09/2019\n\n");

    printf("6.EXIT\n");
    printf("..>"); 
	scanf("%d", &match1);
	stadium_select(match1);

}




int main(int argc, char const *argv[])
{


	int option;


	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	system("clear");
	printf("\t\tF-Ticket.uz reservation system\n\n" );
	printf("\n\t1.Start\n\t2.EXIT\n\n..>");
    scanf("%d", &option);
	//while(option!=1 || option!=2){
	/*	printf("1.Start\n2.EXIT\n\n..>");
		scanf("%s", &option);
		if(option== '1') break;
		if(option=='2') {  printf("Exitting! See you in paradise!!\n"); exit(1);}
		
	}
	*/
	if(option== 1) matches();
	if(option== 2) {  printf("\nExitting! Thank you for using our services!!\n\n");  exit(1);}
	//}

	int choise;
	printf("Do you want to continue?\n" );
	printf("\t1.YES\n\t2.NO\n..>");
	scanf("%d",&choise);
	if(choise==2) {matches(); printf("Do you want to continue?\n" );
	printf("\t1.YES\n\t2.NO\n..>");scanf("%d",&choise);}

	printf("Checking the availability...");
	//printf("Checking the availability...");
	fflush(stdout);
	sleep(1);
	printf("....");
	fflush(stdout);
	sleep(1);
	printf("....");
	

	memset(buffer,0,strlen(buffer)); //clear the entire content of buffer string
			char snum[5];
			char snum1[5];
			//itoa(match_id,snum,10);
			sprintf(snum,"%d", match_id); //concatenate string and integer
			sprintf(snum1,"%d", ticket_id);
			//itoa(ticket_id,snum1,10);
			//scanf("%s", &buffer[0]);
			strcat(buffer, snum);
			strcat(buffer, "#");
			strcat(buffer, snum1);
			printf("%s\n",buffer );
			char buffer1[100];
			char buffer2[100];
			memset(buffer1,0,strlen(buffer1));
			memset(buffer2,0,strlen(buffer2));

			char *ch;  
			//ch = strtok(buffer, "#");  //to tokenize the string by delimiter
			int k=0;
			//strtok_r(buffer,"#", &ch);
					//printf("first buffer %s\n",buffer );
					//printf("second one %s\n",ch );
					
			//while(ch != NULL){
				//	strcpy(buffer1, ch );
				//	 printf("%s\n",ch ); ch=strtok(NULL, ",");
						
				//		strcpy(buffer2, ch); 
				//		}
						//printf("first buffer: %s\n", buffer1);
					 	//printf("second buffer: %s\n", buffer2);
			//getch();

			//for (int i = 0; i < strlen(buffer); ++i)
			//{
			//	printf(buffer[i]);
				
			//}

	/*char buffer1[100];
					char buffer2[100];
					int j=0;
					while(buffer[j]!='#'){ strcat(buffer1, buffer[j]); j++;}
					for(j; j<=strlen(buffer); j++){strcat(buffer2, buffer[j]);}
				printf("%s\n",buffer);
				printf("%s\n",buffer1);
*/
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket<0){
		printf("[-]Error in connection\n");
		exit(1);
	}
	//printf("[+]clientSocket created!\n" );

	memset (&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	//serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_addr.s_addr = inet_addr("192.168.43.89");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (ret<0)
	{
		printf("[-]Error in connection\n" );
		exit(1);
	}
		//printf("[+]Connected to Server\n");
		
		//strcpy(buffer, option) ;
		//printf("Events:\t");
		int l=0;
		while(l!=1)
		{
			//char snum[5];
			//char snum1[5];
			//itoa(match_id,snum,10);
			//snprintf(snum,10,"%d", match_id);
			//snprintf(snum1,10,"%d", ticket_id);
			//itoa(ticket_id,snum1,10);
			//scanf("%s", &buffer[0]);
			//strcat(buffer, snum);
			//strcat(buffer, "#");
			//strcat(buffer, snum1);
			
			//char option1[10]='start';
			//send(clientSocket, option1, strlen(option1),0);
			send(clientSocket, buffer, strlen(buffer),0);

			if(strcmp(buffer, ":exit")==0)
			{
				close(clientSocket);
				printf("[-]Disconnected from server\n");
				exit(1);
			}

			if(recv(clientSocket, buffer, 1024, 0)<0)
			{
				printf("[-]Error in receiving data\n");
			} else {

				
				//int j=0;
				//while(j!=5){
				//	while(strcmp(buffer, "#")!=0)
				//		while(strcmp(buffer, "*")!=0){printf("%s",buffer);}

					printf("Server: %s\n",buffer ); l++; 	


				
			}


		}



	return 0;
}
