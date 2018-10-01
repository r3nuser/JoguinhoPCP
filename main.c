#include <stdlib.h>
#include <stdio.h>

typedef struct relativeDim{
	int a_len;
	int b_len;
} RDimension;

void showSymbols(char **symbols, RDimension *rd);
void mergePiece(char **symbols, RDimension *rd, int index);
char **createSymbols();
void alocate_space(char **symbols, RDimension new_rd);
void add_0(char **symbols, RDimension *rd);
void add_1(char **symbols, RDimension *rd);
void add_2(char **symbols, RDimension *rd);
void add_3(char **symbols, RDimension *rd);
void add_4(char **symbols, RDimension *rd);
void add_5(char **symbols, RDimension *rd);
void add_6(char **symbols, RDimension *rd);
void add_7(char **symbols, RDimension *rd);
void add_8(char **symbols, RDimension *rd);
void add_9(char **symbols, RDimension *rd);
void add_10(char **symbols, RDimension *rd);
void gameloop(char **symbols, RDimension *rd);
FILE* openFile(char *name, char *mode);
void closeFile(FILE* f);
void writePass(FILE* f, int pass);

void writePass(FILE* f, int pass){
	fprintf(f, "%d\n", pass);
}

void closeFile(FILE* f){
	fclose(f);
}

FILE* openFile(char *name, char *mode){
	return fopen(name, mode);
}

void showSymbols(char **symbols, RDimension *rd){
	int i = 0,
	    maxdim = rd->a_len > rd->b_len ? rd->a_len : rd->b_len;

	for( i = 0 ; i < maxdim ; i++ ){
		if( i < rd->a_len && i < rd->b_len )
			if(symbols[0][i] == symbols[1][i]) continue;
		if( i < rd->a_len  ) printf("[ %c |", symbols[0][i]);
		else printf("[   |");
		if( i < rd->b_len  ) printf(" %c ]", symbols[1][i]);
		else printf("   ]");
		printf("\n");
	}
}

void mergePiece(char **symbols, RDimension *rd, int index){
	switch( index ){
		case 0:
			add_0(symbols, rd);
			break;
		case 1:
			add_1(symbols, rd);
			break;
		case 2:
			add_2(symbols, rd);
			break;
		case 3:
			add_3(symbols, rd);
			break;
		case 4:
			add_4(symbols, rd);
			break;
		case 5:
			add_5(symbols, rd);
			break;
		case 6:
			add_6(symbols, rd);
			break;
		case 7:
			add_7(symbols, rd);
			break;
		case 8:
			add_8(symbols, rd);
			break;
		case 9:
			add_9(symbols, rd);
			break;
		case 10:
			add_10(symbols, rd);
			break;
	}
}

void alocate_space(char **symbols, RDimension new_rd){
	symbols[0] = realloc(symbols[0], new_rd.a_len);
	symbols[1] = realloc(symbols[1], new_rd.b_len);
}
void add_0(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 10;
	new_rd.b_len += 2;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = 'S';
	rd->a_len++;
	symbols[0][rd->a_len] = '[';
	rd->a_len++;
	symbols[0][rd->a_len] = '1';
        rd->a_len++;
	symbols[0][rd->a_len] = '1';
        rd->a_len++;
	symbols[0][rd->a_len] = '1';
        rd->a_len++;
	symbols[0][rd->a_len] = '1';
        rd->a_len++;
	symbols[0][rd->a_len] = '1';
        rd->a_len++;
	symbols[0][rd->a_len] = 'X';
        rd->a_len++;
	symbols[0][rd->a_len] = ']';
        rd->a_len++;
	symbols[0][rd->a_len] = '[';
        rd->a_len++;
	symbols[1][rd->b_len] = 'S';
	rd->b_len++;
	symbols[1][rd->b_len] = '[';
	rd->b_len++;
}
void add_1(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 2;
	new_rd.b_len += 1;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = '1';
	rd->a_len++;
	symbols[0][rd->a_len] = 'X';
	rd->a_len++;
	symbols[1][rd->b_len] = 'X';
	rd->b_len++;
}
void add_2(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 1;
	new_rd.b_len += 1;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = 'A';
	rd->a_len++;
	symbols[1][rd->b_len] = 'X';
	rd->b_len++;
}
void add_3(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 2;
	new_rd.b_len += 3;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = 'A';
	rd->a_len++;
	symbols[0][rd->a_len] = '1';
	rd->a_len++;
	symbols[1][rd->b_len] = '1';
	rd->b_len++;
	symbols[1][rd->b_len] = '1';
	rd->b_len++;
	symbols[1][rd->b_len] = 'A';
	rd->b_len++;
}
void add_4(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 1;
	new_rd.b_len += 1;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = '1';
	rd->a_len++;
	symbols[1][rd->b_len] = '1';
	rd->b_len++;
}
void add_5(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 2;
	new_rd.b_len += 2;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = '[';
	rd->a_len++;
	symbols[0][rd->a_len] = 'B';
	rd->a_len++;
	symbols[1][rd->b_len] = '[';
	rd->b_len++;
	symbols[1][rd->b_len] = 'A';
	rd->b_len++;
}
void add_6(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 1;
	new_rd.b_len += 1;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = ']';
	rd->a_len++;
	symbols[1][rd->b_len] = ']';
	rd->b_len++;
}
void add_7(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 1;
	new_rd.b_len += 1;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = '[';
	rd->a_len++;
	symbols[1][rd->b_len] = '[';
	rd->b_len++;
}
void add_8(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 2;
	new_rd.b_len += 2;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = '1';
	rd->a_len++;
	symbols[0][rd->a_len] = 'B';
	rd->a_len++;
	symbols[1][rd->b_len] = 'B';
	rd->b_len++;
	symbols[1][rd->b_len] = '1';
	rd->b_len++;
}
void add_9(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 9;
	new_rd.b_len += 9;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = 'A';
	rd->a_len++;
	symbols[0][rd->a_len] = ']';
	rd->a_len++;
	symbols[1][rd->b_len] = 'B';
	rd->b_len++;
	symbols[1][rd->b_len] = ']';
	rd->b_len++;
}
void add_10(char **symbols, RDimension *rd){
	RDimension new_rd = *rd;
	new_rd.a_len += 10;
	new_rd.b_len += 10;
	alocate_space(symbols, new_rd);
	symbols[0][rd->a_len] = 'E';
	rd->a_len++;
	symbols[1][rd->b_len] = '[';
	rd->b_len++;
	symbols[1][rd->b_len] = '1';
	rd->b_len++;
	symbols[1][rd->b_len] = 'A';
	rd->b_len++;
	symbols[1][rd->b_len] = ']';
	rd->b_len++;
	symbols[1][rd->b_len] = 'E';
	rd->b_len++;
}

char **createSymbols(){
	char **symbols = (char**) malloc(sizeof(char) * 2);
	symbols[0] = NULL;
	symbols[1] = NULL;
	return symbols;
}

void gameloop(char **symbols, RDimension *rd){
	int index = 0;
	FILE* f;
	printf("\nInsira o numero da peça:\n");
	printf("Insira -1 para sair...\n");
	scanf("%d", &index);
	if( index == -1 ) return;
	mergePiece(symbols, rd, index);
	system("clear");
	showSymbols(symbols, rd);
	f = openFile("passos.txt", "a");
	writePass(f, index);
	closeFile(f);
	gameloop(symbols, rd);
}

int main(void){
	char **symbols = createSymbols(symbols);
	RDimension *rd = (RDimension*) malloc(sizeof(RDimension));
	gameloop(symbols, rd);
	return 0;
}
