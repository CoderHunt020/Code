#include<conio.h>
#include<stdio.h>
char board[3][3];
int i,j,flag;
int winCondition();
void game_board();
int main(){
	int player=1,choice;
	char mark,count='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=count;
			count++;
		}
	}
	do{
		game_board();
		player = (player % 2) ? 1 : 2;
        printf("\tPlayer %d chance:  ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if(choice == 1 && board[0][0] == '1' )
        	board[0][0] = mark;
        else if(choice == 2 && board[0][1] == '2' )
        	board[0][1] = mark;
        else if(choice == 3 && board[0][2] == '3' )
        	board[0][2] = mark;
        else if(choice == 4 && board[1][0] == '4' )
        	board[1][0] = mark;
        else if(choice == 5 && board[1][1] == '5' )
        	board[1][1] = mark;
        else if(choice == 6 && board[1][2] == '6' )
        	board[1][2] = mark;
        else if(choice == 7 && board[2][0] == '7' )
        	board[2][0] = mark;
        else if(choice == 8 && board[2][1] == '8' )
        	board[2][1] = mark;
        else if(choice == 9 && board[2][2] == '9' )
        	board[2][2] = mark;
        else
        {
            printf("Invalid move ");
            player--;
            getch();
        }
		flag=winCondition();
		player++;
	}while(flag==-1);
	game_board(); 
    if (flag == 1)
        printf("\t\aPlayer %d win ", --player);
    else
        printf("\t\aGame draw");
    getch();
    return 0;
}
int winCondition(){
	if(board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return 1;
	else if(board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return 1;
	else if(board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return 1;
	else if(board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return 1;
	else if(board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return 1;
	else if(board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return 1;
	else if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return 1;
	else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return 1;
	else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && 
	        board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' && 
			board[2][2] != '9' ){
		return 0;
	}
	else
		return -1;			
}

void game_board(){
	system("cls");
	printf("\n\n\n\tTic Tac Toe Game\n\n\n");
	printf("\tPlayer 1 use X\n\tPlayer 2 use O\n\n\n");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<3;j++){
			if(j!=2){
				printf("\t%c  ",board[i][j]);
			}
			else{
				printf("\t%c   ",board[i][j]);
			}
		}
		printf("\n");
	}
}
