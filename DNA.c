#include <stdio.h>
#include<stdlib.h>


void insert_pos_sequence(int index, char A[]);
void remove_pos(int pos);
void display_all();
void display_pos(int pos);
void clip_pos(int pos,int start,int end);
void copy(int pos1,int pos2);
void swap(int pos1,int start1,int pos2,int start2);
void maxOverlap(int pos1,int pos2);
void quit();
char* str_pos_copy(char*);
int strcmp(const char *s1, const char *s2);
char sequence[200][200];

int main() {
    FILE *fptr;
    char temp[10000];
    char seq[10000];
    int seq_pos[10000];
    int i = 0, r;

    while (i < 200) {
        sequence[i++][0] = '#';
    }

    fptr = fopen("/home/irem/testhwiki.txt", "r");
    if (fptr == NULL) {
        puts("error while opening file");
        exit(1);
    } else {

        char in[] = "insert";
        char rem[] = "remove";
        char dis[] = "display";
        char sw[] = "swap";
        char q[] = "quit";
        char c[] = "clip";
        char co[] = "copy";
        char disall[] = "display-all";
        char max[] = "max-overlap";

        while (r = fscanf(fptr, "%s \n", temp) != EOF) {
           // printf("%s ------------------- \n", temp);
            if (strcmp(temp, in) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                fscanf(fptr, " %s \n", seq);
                insert_pos_sequence(*(seq_pos), seq);

            } else if (strcmp(temp, rem) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                remove_pos(*(seq_pos));

            } else if (strcmp(temp, dis) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                display_pos(*(seq_pos));

            } else if (strcmp(temp, disall) == 0) {
                display_all();

            } else if (strcmp(temp, c) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                int a=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                int b=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                clip_pos(a, b, *(seq_pos ));

            } else if (strcmp(temp, co) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                int a= *(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                copy(a, *(seq_pos ));

            } else if (strcmp(temp, sw) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                int a=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                int b=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                int   c=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                swap(a , b , c ,*(seq_pos ) );

            } else if (strcmp(temp, max) == 0) {
                fscanf(fptr, "%i \n", seq_pos);
                int a=*(seq_pos);
                fscanf(fptr, "%i \n", seq_pos);
                maxOverlap(a, *(seq_pos));

            } else {
                printf("GİDİYORUM BÜTÜN AŞKLAR YÜREĞİMDE...");
                quit();
            }
        }
        fclose(fptr);
        return 0;
    }
}





void insert_pos_sequence(int index,char A[]){
    int i=0;
    while(A[i]!=NULL){
        sequence[index][i++]=A[i];
    }
}

void remove_pos(int pos){
    int i=0;
    if(sequence[pos]==NULL || sequence[pos][0]=='#')
        printf("EMPTY POSITION");
    else
        for(i=0;sequence[pos][i]!=NULL;i++) {
            // printf("%c", sequence[pos][i], i);
            sequence[pos][i] = NULL;
        }
    sequence[pos][0]='#';
    printf("\n");
}


void display_all(){
    for(int i=0;sequence[i]!=NULL&& i<200;i++) {
        for (int j = 0; j < sequence[i][j] != NULL && j<200; j++) {
            printf("%c", sequence[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void display_pos(int pos){
    if(sequence[pos]==NULL || sequence[pos][0]=='#')
        printf("EMPTY POSITION \n ");
    else
        for(int j=0;sequence[pos][j]!=NULL;j++)
            printf("%c",sequence[pos][j]);

    printf("\n");
}

void clip_pos(int pos,int start,int end){
    char temp[200];
    if(start<0 || sizeof(sequence[200])<start || sizeof(sequence[200])<end || end <start) {
        printf("INDEX OUT OF BOUNDS");
    }else {
        for (int i = start,j=0; i  <= end &j<200; i++,j++) {
            temp[j]=sequence[pos][i];
            sequence[pos][j] = temp[j];
        }

        for(int i=end-1;i<200-end;i++)
            sequence[pos][i]=NULL;
    }
    printf("\n");
}
void copy(int pos1,int pos2){
    if(sequence[pos1]==NULL ) {
        printf("EMPTY POSITION");
    }else if( pos1>200 || pos2>200) {
        printf("INDEX OUT OF BOUNDS");
    }else{
        char *temp = str_pos_copy(sequence[pos1]);
        for (int j = 0; *(temp+j)!=NULL; j++) {
            sequence[pos2][j] = *(temp + j);
        }
    }
    printf("\n");
}

void swap(int pos1,int start1,int pos2,int start2) {
    if (sequence[pos1] == NULL || sequence[pos2] == NULL || sizeof(sequence[200]) < start1 ||
        sizeof(sequence[200]) < start2) {
        printf("ERROR");
    } else {
        for (int i = start1, j = start2; i < 200 && j < 200; i++, j++) {
            char temp = sequence[pos1][i];
            sequence[pos1][i] = sequence[pos2][j];
            sequence[pos2][j] = temp;
        }
    }
}

void maxOverlap(int pos1,int pos2){
    char * temp= str_pos_copy(sequence[pos1]);
    char * temp2= str_pos_copy(sequence[pos2]);
    char overlap[200];
    int length=0,j=0;
    for (int i=0;i<200;i++){
        if(temp[j]==temp2[i]){
            overlap[i]=temp2[i];
            length++;
            j++;
        }else{
            j++;
        }
    }

    if(length==0) printf("NO OVERLAP.");
    else printf("MAX-OVERLAP %s \nLength of max overlap : %d",overlap,length);
    printf("\n");
}

void quit(){
    exit(0);
}

char* str_pos_copy(char *to) {
    char *tmp=to;
    return tmp;
}

int strcmp(const char *s1, const char *s2){
    int result = 0;
    while (!(result = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2) ++s1, ++s2;
    if (result < 0)
        result = -1;
    else if (result > 0)
        result = 1 ;
    return result;
}

