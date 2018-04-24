#include <stdio.h>
#include <stdlib.h>
#define zero 0
typedef struct st {
   int hakbun;
   char name[10];
   int score;
   int hak;
   char hakj;
}student;
int n, m, count;
student people[100], temp;
int main() {

   selectmenu();



   return 0;
}

printIntro() {
   printf(" -------------------------------\n");
   printf(" |   성적 처리 프로그램입니다  |\n ");
   printf("|   1. 성적 입력하기          |\n ");
   printf("|   2. 성적 정리하기          |\n ");
   printf("|   3. 성적 조회하기          |\n ");
   printf("|   4. 학점 부여하기          |\n ");
   printf("|   5. 성적 내보내기          |\n ");
   printf("|   6. 프로그램 종료          |\n ");
   printf("------------------------------- \n ");
   printf(" \n ");
}

selectmenu() {
   while (1)
   {
      printIntro();
      int select;
      printf("메뉴를 선택하세요\n");
      scanf_s("%d", &select);
      if (select == 1) {
         printf("성적을 처리할 학생들이 몇 명입니까??\n");
         scanf_s("%d", &count);
         inputdata(count,0,0);
      }
      else if (select == 2)
         buble();
      else if (select == 3)
         outdata(count);
      else if (select == 4)
         hakdata(count);
      else if (select == 5)
         fileoutput(count);
      else if (select == 6)
         break;
   }

}


inputdata(int count,int i, int j) {
   int p = 0;
      p = count + p;
   int m = 0;
      m = i + m;
   for (m; m < p; i++) {
      printf("%d번째 학생의 학번을 입력하고 Enter를 누르세요\n", m + 1);
      scanf_s("%d", &people[m].hakbun);
      printf("%d번째 학생의 이름을 입력하고 이름끝에 -를 입력한 후, Enter를 누르세요\n", m + 1);
      for (j = 0; j < 10; j++) {
         scanf_s("%c", &people[m].name[j]);
         if (people[m].name[j] == '-')
            break;
      }
      printf("%d번째 학생의 점수를 입력하고 Enter를 누르세요\n", m + 1);
      scanf_s("%d", &people[m].score);
      printf("\n");
   }
}

buble() {
   for (n = 0; n < count - 1; n++) {
      for (m = n + 1; m < count; m++) {
         if (people[n].score < people[m].score) {
            temp = people[n];
            people[n] = people[m];
            people[m] = temp;
         }
      }
   }
   int p;
   for (p = 1; p < count; p++) {
      people[p].hak = p;
   }


}

outdata(int count) {
   int p = 0;
   int   q = 0;
   printf("\n");
   printf("               성적처리(등수순)                \n");
   printf("\n");
   printf("    학번       이름       점수       등수      \n");
   printf("===============================================\n");

   for (p = 0; p < count; p++) {

      printf("%d       ", people[p].hakbun);
      for (q = 1; q < 10; q++) {
         if (people[p].name[q] == '-')
            break;
         printf("%c", people[p].name[q]);

      }
      printf("       ");
      printf("%d       ", people[p].score);
      printf("%d       ", people[p].hak + 1);
      printf("%c       ", people[p].hakj);
      printf("\n");
   }
}

hakdata(int count) {
   int p = 0;
   int   q = 0;
   int b = 0;
   printf("\n");
   printf("                   성적처리(학점 출력)                    \n");
   printf("\n");
   printf("    학번       이름       점수       등수       학점      \n");
   printf("==========================================================\n");

   for (p = 0; p < count; p++) {
      double k;
      k = people[p].hak / count * 100;
      if (k < 20)
         people[p].hakj = 'A';
      else if (k < 50)
         people[p].hakj = 'B';
      else if (k < 70)
         people[p].hakj = 'C';
      else
         people[p].hakj = 'D';
   }

   for (p = 0; p < count; p++) {

      printf("%d       ", people[p].hakbun);
      for (q = 1; q < 10; q++) {
         if (people[p].name[q] == '-')
            break;
         printf("%c", people[p].name[q]);

      }
      printf("       ");
      printf("%d       ", people[p].score);
      printf("%d       ", people[p].hak + 1);
      printf("%c       ", people[p].hakj);
      printf("\n");
   }

}

fileoutput(int count) {
   errno_t err;
   FILE *out;
   int p = 0;
   int   q = 0;
   err = fopen_s(&out, "score.txt", "wt");
   if (err == 0)
      puts("file open success\n");
   else {
      puts("file open fail\n");
      return -1;
   }
   fputs("\n", out);
   fputs("               성적처리(등수순)               \n", out);
   fputs("\n", out);
   fputs("    학번       이름       점수       등수       학점      \n", out);
   fputs("==========================================================\n", out);

   for (p = 0; p < count; p++) {

      fprintf(out, "%d       ", people[p].hakbun);
      for (q = 1; q < 10; q++) {
         if (people[p].name[q] == '-')
            break;
         fprintf(out, "%c", people[p].name[q]);

      }
      fputs("       ", out);
      fprintf(out, "%d       ", people[p].score);
      fprintf(out, "%d       ", people[p].hak + 1);
      fprintf(out, "%c       ", people[p].hakj);
      fputs("\n", out);
   }

   fclose(out);
}