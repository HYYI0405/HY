#include <stdio.h>
#include <stdlib.h>

typedef struct t_rec {
	struct t_rec *front;
	int id;
	char name[16];
	double ave;
	int game;
	struct t_rec *next;
} Student;
Student *head = NULL;
Student *tail = NULL;

void ShowList() {
	Student *p;
	printf("Items in the list\n");
	p = head;
	while ( p != NULL) {
		printf("%4d %16s %4.3lf %4d \n", p->id, p->name,p->ave, p->game);
		p = p->next;
	}
	return;
}
void ShowList1() {
	Student *p;
	printf("Items in the list\n");
	p = tail;
	while ( p != NULL) {
		printf("%4d %16s %4.3lf %4d \n", p->id, p->name,p->ave, p->game);
		p = p->front;
	}
	return;
}

void Append(int n, char *s, double d, int g) {
	Student *p;
	if (head == NULL) {
		head = (Student *) malloc(sizeof(Student));
		head ->front = NULL;
		head->id = n;
		head->game =g;
		head->ave = d;
		strcpy(head->name, s);
		head->next = NULL;
	}
	else {
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = (Student *) malloc(sizeof(Student));
		p->next->front = p;
		p = p->next;
		p->id = n;
		p->game =g;
		p->ave = d;
		strcpy(p->name, s);
		p->next = NULL;
		tail = p;
	}
	return;
}

void TwoAve(char *s) {
	Student *p;
	double m1,m2,Ave=0;
	p = head;
	while(p !=NULL) {
		if(strcmp(s,p->next->name)==0) {
			m1 = p->ave;
			m2 = p->next->ave;
			Ave = m1+m2;
			printf("%4.3lf \n",Ave);
			break;
		}
		p = p->next;
	}
}

main() {
	Student *m;
	Append(1, "애니프로스트", 0.986, 98);
	Append(4, "잭말론", 0.567, 43);
	Append(2, "호레시오케인", 0.452, 87);
	Append(3, "맥테일러", 0.876, 43);
	Append(8, "길그리썸", 0.365, 89);
	Append(9, "브렌다리존스", 0.789, 43);
	Append(6, "칼라이트만", 0.212, 69);
	Append(5, "질리안포스터", 0.333, 38);
	Append(7, "올리비아벤슨", 0.756, 67);
	Append(10, "엘리엇스테이블러", 0.555, 54);
	ShowList();
	ShowList1();
	getchar();
}
