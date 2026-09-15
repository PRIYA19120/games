#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void playTruthDare();
void kbc();
void rpc();
void ttt();

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

void rpc(){
    int choice;
    printf("0 rock 1 paper 2 scissor\n");
    scanf("%d",&choice);

    srand(time(0));
    int random = rand()%3;

    printf("Computer: %d\n",random);

    if(choice==random)
        printf("Draw\n");
    else if((choice==0 && random==2)||(choice==1 && random==0)||(choice==2 && random==1))
        printf("You win\n");
    else
        printf("Computer win\n");
}

void playTruthDare(){
    int c;
    printf("\nTruth and Dare Game\n");
    printf("Press Enter to spin...\n");
    fflush(stdout);

    while((c = getchar()) != '\n' && c != EOF);

    srand(time(NULL));
    int spin = rand() % 6;

    char truth[3][200] = {
        "What is your biggest fear?",
        "Have you ever lied to your best friend?",
        "What is your most embarrassing moment?"
    };

    char dare[3][200] = {
        "Do 10 pushups right now!",
        "Sing a song loudly!",
        "Dance for 30 seconds!"
    };

    if(spin <= 1){
        printf("TRUTH!\n");
        printf("Your question: %s\n", truth[rand() % 3]);
    }
    else if(spin <= 3){
        printf("DARE!\n");
        printf("Your dare: %s\n", dare[rand() % 3]);
    }
    else{
        printf("SAFE!\n");
    }
}

void ttt(){
    char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int p=1,ch,r,c,count=0,i;

    while(1){
        printf("\n%c | %c | %c\n", b[0][0], b[0][1], b[0][2]);
        printf("--|---|--\n");
        printf("%c | %c | %c\n", b[1][0], b[1][1], b[1][2]);
        printf("--|---|--\n");
        printf("%c | %c | %c\n\n", b[2][0], b[2][1], b[2][2]);

        printf("Player %d enter: ",p);
        scanf("%d",&ch);

        r=(ch-1)/3;
        c=(ch-1)%3;

        if(b[r][c]!='X' && b[r][c]!='O'){
            if(p==1) b[r][c]='X';
            else b[r][c]='O';
            count++;
        } else {
            printf("Wrong move\n");
            continue;
        }

        for(i=0;i<3;i++){
            if(b[i][0]==b[i][1] && b[i][1]==b[i][2]) goto win;
            if(b[0][i]==b[1][i] && b[1][i]==b[2][i]) goto win;
        }
        if(b[0][0]==b[1][1] && b[1][1]==b[2][2]) goto win;
        if(b[0][2]==b[1][1] && b[1][1]==b[2][0]) goto win;

        if(count==9){
            printf("Draw\n");
            break;
        }

        p=(p==1)?2:1;
        continue;

        win:
        printf("Player %d wins\n",p);
        break;
    }
}

int main(int argc, char *argv[]){
    int choice;

    if(argc > 1){
        choice = atoi(argv[1]);
    } else {
        printf("choose game:\n");
        printf("1. kbc\n");
        printf("2. rpc\n");
        printf("3. truth & dare\n");
        printf("4. tic tac toe\n");
        scanf("%d", &choice);
    }

    if(choice==1) kbc();
    else if(choice==2) rpc();
    else if(choice==3) playTruthDare();
    else if(choice==4) ttt();
    else printf("invalid choice");

    return 0;
}
