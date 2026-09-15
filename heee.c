#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rpc_result(int player_choice) {
    int computer = rand() % 3;
    if (player_choice == computer) return 0;   
    else if ((player_choice==0 && computer==2) ||
             (player_choice==1 && computer==0) ||
             (player_choice==2 && computer==1)) return 1; 
    else return -1; 
}

const char* truth_or_dare() {
    int spin = rand()%6;

    static char truth[3][200] = {
        "What is your biggest fear?",
        "Have you ever lied to your best friend?",
        "What is your most embarrassing moment?"
    };

    static char dare[3][200] = {
        "Do 10 pushups right now!",
        "Sing a song loudly!",
        "Dance for 30 seconds!"
    };

    if(spin<=1) return truth[rand()%3];
    else if(spin<=3) return dare[rand()%3];
    else return "Safe!";
}

void kbc(){
    printf("namaskar deviyon or sajjano me amitab bachchan aapka swagat karta hun kaun banega lakhpati me\n");

    char name[50],ans1,ans2,ans3,ans4,ans5;
    printf("mahashay apna naam batayein\n");
    scanf("%s",name);

    int dhanrasi=0;

    char qb[5][500]={
    "1-who is known as the father of Indian constitution?\n(a)B R Ambedkar (b)Mahatma Gandhi\n(c)Raja Ram mohan roy (d)Rabindra nath Tagore\n",
    "\n2-when is the earth day celebrated?\n(a)23 april (b)22 april\n(c)4 june (d)19 october\n",
    "\n3-who demanded for constituent assembly?\n(a)BN Rao (b)Jawaharlal Nehru\n(c)Mahatma Gandhi (d)stafford cripps\n",
    "\n4-which day is celebrated as world standards day?\n(a)june 26 (b)oct 14\n(c)sep 19 (d)june 16\n",
    "\n5-what is India's rank on Henley Passport Index?\n(a)22th (b)45th\n(c)85th (d)67th\n"
    };

    printf("%s",qb[0]);
    scanf(" %c",&ans1);

    if(ans1=='a'){ dhanrasi+=5000; printf("sahi jawab! dhanrasi=%d\n",dhanrasi);}
    else { printf("galat jawab! aap jeete %d\n",dhanrasi); return; }

    printf("%s",qb[1]);
    scanf(" %c",&ans2);

    if(ans2=='b'){ dhanrasi+=50000; printf("sahi jawab! dhanrasi=%d\n",dhanrasi);}
    else { printf("galat jawab! aap jeete %d\n",dhanrasi); return; }

    printf("%s",qb[2]);
    scanf(" %c",&ans3);

    if(ans3=='a'){ dhanrasi+=100000; printf("sahi jawab! dhanrasi=%d\n",dhanrasi);}
    else { printf("galat jawab! aap jeete %d\n",dhanrasi); return; }

    printf("%s",qb[3]);
    scanf(" %c",&ans4);

    if(ans4=='b'){ dhanrasi+=250000; printf("sahi jawab! dhanrasi=%d\n",dhanrasi);}
    else { printf("galat jawab! aap jeete %d\n",dhanrasi); return; }

    printf("%s",qb[4]);
    scanf(" %c",&ans5);

    if(ans5=='c'){ dhanrasi+=500000; printf("CONGRATULATIONS! aap jeet gaye %d\n",dhanrasi);}
    else { printf("galat jawab! aap jeete %d\n",dhanrasi); }
}

int ttt_check_winner(int board[9]) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (int i=0;i<8;i++) {
        if (board[wins[i][0]] != 0 &&
            board[wins[i][0]] == board[wins[i][1]] &&
            board[wins[i][1]] == board[wins[i][2]]) {
            return board[wins[i][0]];
        }
    }
    return 0; 
}

void display_ttt_board(int board[9]) {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) printf("\n-----------\n");
        
        if (board[i] == 0) printf(" %d ", i);
        else if (board[i] == 1) printf(" X ");
        else printf(" O ");
        
        if ((i + 1) % 3 != 0) printf("|");
    }
    printf("\n\n");
}

int is_board_full(int board[9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) return 0;
    }
    return 1;
}

int get_computer_move(int board[9]) {
    int move;
    do {
        move = rand() % 9;
    } while (board[move] != 0);
    return move;
}

void play_tic_tac_toe() {
    int board[9] = {0};
    int move, computer_move;
    int winner = 0;
    
    printf("\n=== Tic Tac Toe - Player vs Computer ===\n");
    printf("You are X, Computer is O\n");
    
    while (1) {
        display_ttt_board(board);
        
        winner = ttt_check_winner(board);
        if (winner == 1) {
            printf("*** You won! ***\n");
            break;
        } else if (winner == 2) {
            printf("*** Computer won! ***\n");
            break;
        } else if (is_board_full(board)) {
            printf("*** It's a Draw! ***\n");
            break;
        }
        
        
        printf("Your turn (0-8): ");
        if (scanf("%d", &move) != 1 || move < 0 || move > 8 || board[move] != 0) {
            while (getchar() != '\n');
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[move] = 1;
        
        
        winner = ttt_check_winner(board);
        if (winner == 1) {
            display_ttt_board(board);
            printf("*** You won! ***\n");
            break;
        }
        
        if (is_board_full(board)) {
            display_ttt_board(board);
            printf("*** It's a Draw! ***\n");
            break;
        }
        
        
        computer_move = get_computer_move(board);
        printf("Computer chose position %d\n", computer_move);
        board[computer_move] = 2;
        
        
        winner = ttt_check_winner(board);
        if (winner == 2) {
            display_ttt_board(board);
            printf("*** Computer won! ***\n");
            break;
        }
        
        if (is_board_full(board)) {
            display_ttt_board(board);
            printf("*** It's a Draw! ***\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));
    int choice = 0;
    
    
    if (argc > 1) {
        choice = atoi(argv[1]);
        if (choice < 1 || choice > 4) {
            choice = 0;
        }
    }
    
    
    if (choice > 0) {
        if (choice == 1) {
            int player;
            printf("Enter your choice (0=rock, 1=paper, 2=scissors): ");
            if (scanf("%d", &player) != 1) {
                printf("Invalid input!\n");
                return 0;
            }
            int result = rpc_result(player);
            if (result == 0) printf("Result: Draw\n");
            else if (result == 1) printf("Result: You win!\n");
            else printf("Result: You lose.\n");
        } else if (choice == 2) {
            const char *result = truth_or_dare();
            printf("Truth or Dare: %s\n", result);
        } else if (choice == 3) {
            int q;
            char ans;
            printf("Enter question number (0-4): ");
            if (scanf("%d", &q) != 1) {
                printf("Invalid input!\n");
                return 0;
            }
            if (q < 0 || q > 4) {
                printf("Invalid question number.\n");
                return 0;
            }
            while (getchar() != '\n');
            printf("Enter answer (a/b/c): ");
            if (scanf(" %c", &ans) != 1) {
                printf("Invalid input!\n");
                return 0;
            }
            int ok = kbc_check_answer(q, ans);
            printf(ok ? "Correct answer!\n" : "Wrong answer.\n");
        } else if (choice == 4) {
            play_tic_tac_toe();
        }
        printf("\nThanks for playing!\n");
        return 0;
    }
    
    
    while (1) {
        printf("\n=== Test Menu ===\n");
        printf("1. Rock Paper Scissors\n");
        printf("2. Truth or Dare\n");
        printf("3. KBC answer check\n");
        printf("4. Tic Tac Toe winner check\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            int player;
            printf("Enter your choice (0=rock, 1=paper, 2=scissors, 9=Back): ");
            if (scanf("%d", &player) != 1) {
                while (getchar() != '\n');
                printf("Invalid input!\n");
                continue;
            }
            if (player == 9) continue;  // back to menu
            int result = rpc_result(player);
            if (result == 0) printf("Result: Draw\n");
            else if (result == 1) printf("Result: You win!\n");
            else printf("Result: You lose.\n");
        } else if (choice == 2) {
            int backOpt;
            printf("Press 9 to go Back or any other number to spin: ");
            if (scanf("%d", &backOpt) != 1) {
                while (getchar() != '\n');
                printf("Invalid input!\n");
                continue;
            }
            if (backOpt == 9) continue;  // back to menu
            const char *result = truth_or_dare();
            printf("Truth or Dare: %s\n", result);
        } else if (choice == 3) {
            int q;
            char ans;
            printf("Enter question number (0-4, 9=Back): ");
            if (scanf("%d", &q) != 1) {
                while (getchar() != '\n');
                printf("Invalid input!\n");
                continue;
            }
            if (q == 9) continue;  // back to menu
            if (q < 0 || q > 4) {
                printf("Invalid question number.\n");
                continue;
            }
            while (getchar() != '\n');  // clear buffer
            printf("Enter answer (a/b/c): ");
            if (scanf(" %c", &ans) != 1) {
                printf("Invalid input!\n");
                continue;
            }
            int ok = kbc_check_answer(q, ans);
            printf(ok ? "Correct answer!\n" : "Wrong answer.\n");
        } else if (choice == 4) {
            play_tic_tac_toe();
        } else {
            printf("Invalid menu choice.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}
