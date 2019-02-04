#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mysql.h>



#define PORT 4444

// method ids 

#define MN_METRIC "1000"

#define MN_MATCH_LIST "1110"
#define MN_CHOOSE_STADIUM  "1111"
#define MN_CHOOSE_SEAT "1112"

#define DELIMITER_MN '#'
#define DELIMITER_ENTITY '*'
#define DELIMITER_ENTRY '|'
char match_id[100];
char ticket_id[100];
char result1[10];
//some parts of code were taken from botirjon nasridinov. / 19/12/2018. 
//Copyright © 2018 Orient Software Team. All rights reserved.
//
typedef struct Match {
    int id;
    int stadium_id;
    char * stadium_name;
} Match;
  


void connectDatabase();


/*
void match(int m){
	connectDatabase();
	switch(m){

	case 1: {


	if (mysql_query(conn, "select * from Matches")) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	exit(1);
	}
	res = mysql_use_result(conn);
	/* output table name */
/*	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	printf("%s \n", row[0]);
	/* close connection */
/*	mysql_free_result(res);
	mysql_close(conn);
	


		select stadium_name 
			from Stadiums, Matches
			where Matches.match_id = 1 AND 
			Stadiums.stadium_id = Matches.stadium_id

			stadium_name= query;

			ticket(1);}

	case 2:

	case 3:

	case 4:

	case 5:
	} 


}
*/
/*void ticket (int t){



	select ticket_id , seat, sector , row, ticket_price from Tickets where ticket_status=1 AND match_id=1;
	connectDatabase()
	send

}
*/
/*
void reserve(int r){

	1: 

}

*/

int main()
{


	//now create sockets

	int sockfd, ret, n_client=0;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	memset(buffer,0,strlen(buffer)); 

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		printf("[-]Error in connection\n");
		exit(1);
	}
	printf("[+]Server Socket created!\n" );

	memset (&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	//serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	serverAddr.sin_addr.s_addr = inet_addr("192.168.43.89");


	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (ret<0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bound to port %d\n",4444 );

	if (listen(sockfd,10)==0){
		printf("listening...Connecting to database\n"); 
	} else {
		printf("[-]Error in binding.\n");}
		
	while(1){

		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket<0) {
			exit (1);
		}

		printf("Connection accepted from %s: %d \n", inet_ntoa(newAddr.sin_addr), ntohs (newAddr.sin_port) );
		n_client++;
		if(childpid=fork()==0) {
			close(sockfd);
			int l=0;
			while(l!=1){
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, ":exit")==0){
					printf("Disconnected from %s: %d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				} else {

					// TODO: - PROCESS REQUEST

					// READ THE BUFFER UNTIL #
					/*
					char mn[4];
					int i = 0;
					while(buffer[i] != '#') {
						mn[i] = buffer[i];
						i++;
					}

					i++;
				*/

					// MN = READ VALUE PARSED TO INTEGER AND COPY THE REMAINING INTO ANOTHER BUFFER (SECOND BUFFER)

					// COMPARE MN WITH METHOD IDS

					// APPLY THE APPROPRIATE READ RULE FOR THE SECOND BUFFER (BETTER TO MAKE SEPARATE FUNCTIONS)

					/*for(int j=0; bbuffer[j] != '*'; j++ ){
					
						for(int k=0; bbuffer[j] != '|'; k++){


						}
					}
					*/

					printf("Client %d: \t%s\n",n_client, buffer );
					char buffer1[100]="Sorry, the operation cannot be completed: \nUnfortunately this seat has already been reserved";
					char buffer2[100]="Operation successfull";
					char *ch;  
					//ch = strtok(buffer, "#");  //to tokenize the string by delimiter
					int k=0;
					strtok_r(buffer,"#", &ch);
					printf("Value in first buffer: %s\n",buffer );
					printf("In second one : %s\n",ch );
					//while(ch != NULL){ 
					strcpy(match_id, buffer);
					strcpy(ticket_id, ch);
					//printf("%s\n", match_id);
					//printf("%s\n",ticket_id );
					l++;
					connectDatabase();
						
					// 	printf("%s\n",ch ); ch=strtok(NULL, ",");strcpy(buffer2, ch);}
					 //	printf("first buffer: %s\n", buffer1);
					 	//printf("second buffer: %s\n", buffer2);
					 	

					//int j=0;
					//while(buffer[j]!="#"){ strcat(buffer1, buffer[j]); j++;}
					//for(j; j<=strlen(buffer); j++){strcat(buffer2, buffer[j]);}
					



					/*if (buffer=="start")
					{
						/* code */
					//}
					//if (buffer=="match1")
					//{
						/* code */
					//}
					//if (buffer=="ticket1")
					//{
						/* code */
					//} 









/*
    Match match;
    match.id = 12;
    match.stadium_id = 23;
    match.stadium_name = "Maracano";
    
    printf("%lu\n", strlen(match.stadium_name));

    char * buffer;
    buffer = (char *) malloc(2 * sizeof(int) + strlen(match.stadium_name) + 1);
    memcpy(buffer, &match.id, sizeof(int));
    memcpy(&buffer[sizeof(int)], &match.stadium_id, sizeof(int));
    memcpy(&buffer[2 * sizeof(int)], match.stadium_name, strlen(match.stadium_name) + 1);
    
    int * id = (int*)malloc(sizeof(int));
    memcpy(id, buffer, sizeof(int));
    
    int * stadium_id = (int*)malloc(sizeof(int));
    memcpy(stadium_id, buffer + sizeof(int), sizeof(int));
    
    char * stadium_name = (char*)malloc(strlen(match.stadium_name) + 1);
    memcpy(stadium_id, buffer + 2 * sizeof(int), strlen(match.stadium_name) + 1);

    char example[100];
    strcpy(example, " ");
    strcat(example, "");
   	strcat(example, "years old.");
    printf("%s\n", example);
*/
    //printf("id=%d\nstadium_id=%d\nstadium_name=%s\n", *id, *stadium_id, stadium_name);
    









					if(strcmp(result1, "0")==0)	send(newSocket, buffer1, strlen(buffer1),0);
					else send(newSocket, buffer2, strlen(buffer2),0);
					
					bzero (buffer, sizeof(buffer));
				}

			}

		}

	}

	close (newSocket);
	printf("OK that sucks\n" );



	return 0;
}


void connectDatabase(){

//mysql connect
	char query[200]="select ticket_status from Tickets where ticket_id = ";
	char query1[100]=" AND match_id = ";
	char query2[200]=" update Tickets set ticket_status = 0 where ticket_id = ";
	char query3[200]="  AND match_id = ";
	strcat(query, ticket_id);
	strcat(query, query1);
	strcat(query, match_id);
	printf("%s\n", query);
	
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "localhost";
	char *user = "root";
	char *password = "root"; /* set me first */
	char *database = "ticket";
	unsigned int port = 0;
	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server,
	user, password, database, port, NULL, 0)) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	exit(1);
	}

	//
/* send SQL query */

	if (mysql_query(conn, query)) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	exit(1);
	}
	res = mysql_use_result(conn);
	/* output table name */
	
	memset(result1,0,strlen(result1)); 
	printf("The availability of the seat/ticket: ");
	while ((row = mysql_fetch_row(res)) != NULL)
	{printf("%s \n", row[0]); strcpy(result1, row[0]);}
	/* close connection */
	if(strcmp(result1, "1")==0){
		strcat(query2, ticket_id);
		strcat(query2, query3);
		strcat(query2, match_id);

	if (mysql_query(conn, query2)) {
		
	printf("%s\n", query2);
	fprintf(stderr, "%s\n", mysql_error(conn));
	exit(1);
	}
	}
	res = mysql_use_result(conn);



	mysql_free_result(res);
	mysql_close(conn);
	



}



//gcc -o server $(mysql_config --cflags) server.c $(mysql_config --libs)   : use this to compile! thanks :)

