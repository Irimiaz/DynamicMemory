#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
int add_last(void **arr, int *len, data_structure *data)
{	
	unsigned int contor = 0;
	unsigned int lung = 0;
	if((*arr) == NULL) {
		*arr = malloc(data->header->len + sizeof(unsigned char) + sizeof(unsigned int)); ///daca este null vom insera mai intai tipul, apoi lungimea si apoi data, dupa ce am alocat memorie
		memcpy((*arr),(void *)&data->header->type, sizeof(unsigned char));
		memcpy((*arr) + sizeof(unsigned char),(void *)&data->header->len, sizeof(unsigned int));
		memcpy((*arr) + sizeof(unsigned char) + sizeof(unsigned int),data->data, data->header->len);
		
	}
	else {
		for(int i = 0; i < *len; i++) {
			lung = *((unsigned int*)((char *)(*arr) + contor + sizeof(unsigned char))); /// daca nu este null, parcurgem arr pana la final si introducem acolo tipul, lungimea si data
			contor = sizeof(unsigned char) + sizeof(unsigned int) + contor;             /// mai intai realocam memorie pentru a putea introduce datele noi
			contor = contor + lung;
		}
		*arr = realloc(*arr, contor + sizeof(unsigned char) + sizeof(unsigned int) + data->header->len);
		memcpy((*arr) + contor,(void *)&data->header->type, sizeof(unsigned char));
		memcpy((*arr) + sizeof(unsigned char) + contor,(void *)&data->header->len, sizeof(unsigned int));
		memcpy((*arr) + sizeof(unsigned char) + sizeof(unsigned int) + contor,data->data, data->header->len);
		
	} 


	(*len)++; 
	return 0;
}

void afisare(void **arr, int len) {
	if((*arr) == NULL) {
		//printf("Nu este introdusa nicio dedicatie!\n");
		return;
	}
	unsigned char tip;
	unsigned int contor = 0;
	unsigned int lung = 0;
	for(int i = 0; i < len; i++) {
			lung = *((unsigned int*)((char *)(*arr) + contor + sizeof(unsigned char)));
			tip = *((unsigned char*)((char *)(*arr) + contor));

			if(tip == 1) {
				unsigned char litera = *((unsigned char*)((char *)(*arr) + contor + 5)); ///primul nume
				int dim1 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1));
					dim1 ++;
				}
				char *nume1 = malloc(dim1 * sizeof(char));
				memcpy(nume1, (*arr) + contor + 5, dim1);
				//printf("primul nume este %s\n", nume1);

				int8_t ban1 = 0; /// primul ban
				ban1 = *((int8_t*)((char *)(*arr) + contor + 5 + dim1));
				//printf("primul ban este %"PRId8"\n", ban1);
				int8_t ban2 = 0; /// al doilea ban
				ban2 = *((int8_t*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int8_t) ));
				//printf("al doilea ban este %"PRId8"\n", ban2);

				litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int8_t) + sizeof(int8_t)));
				int dim2 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int8_t) + sizeof(int8_t) + dim2));
					dim2 ++;
				}
				char *nume2 = malloc(dim2 * sizeof(char));
				memcpy(nume2, (*arr) + contor + 5 + dim1 + sizeof(int8_t) + sizeof(int8_t), dim2);
				
				///afisarea propriu zisa
				printf("Tipul %hhu\n",tip);
				printf("%s pentru %s\n", nume1, nume2);
				printf("%"PRId8"\n", ban1);
				printf("%"PRId8"\n\n", ban2);
				free(nume1);
				free(nume2);
			}
			else if(tip == 2) {
				unsigned char litera = *((unsigned char*)((char *)(*arr) + contor + 5)); ///primul nume
				int dim1 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1));
					dim1 ++;
				}
				char *nume1 = malloc(dim1 * sizeof(char));
				memcpy(nume1, (*arr) + contor + 5, dim1);
				//printf("primul nume este %s\n", nume1);

				int16_t ban1 = 0; /// primul ban
				ban1 = *((int16_t*)((char *)(*arr) + contor + 5 + dim1));
				//printf("primul ban este %"PRId8"\n", ban1);
				int32_t ban2 = 0; /// al doilea ban
				ban2 = *((int32_t*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int16_t) ));
				//printf("al doilea ban este %"PRId8"\n", ban2);

				litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int16_t) + sizeof(int32_t)));
				int dim2 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int16_t) + sizeof(int32_t) + dim2));
					dim2 ++;
				}
				char *nume2 = malloc(dim2 * sizeof(char));
				memcpy(nume2, (*arr) + contor + 5 + dim1 + sizeof(int16_t) + sizeof(int32_t), dim2);
				
				///afisarea propriu zisa
				printf("Tipul %hhu\n",tip);
				printf("%s pentru %s\n", nume1, nume2);
				printf("%"PRId16"\n", ban1);
				printf("%"PRId32"\n\n", ban2);
				free(nume1);
				free(nume2);
			}
			else if(tip == 3) {
				unsigned char litera = *((unsigned char*)((char *)(*arr) + contor + 5)); ///primul nume
				int dim1 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1));
					dim1 ++;
				}
				char *nume1 = malloc(dim1 * sizeof(char));
				memcpy(nume1, (*arr) + contor + 5, dim1);
				//printf("primul nume este %s\n", nume1);

				int32_t ban1 = 0; /// primul ban
				ban1 = *((int32_t*)((char *)(*arr) + contor + 5 + dim1));
				//printf("primul ban este %"PRId8"\n", ban1);
				int32_t ban2 = 0; /// al doilea ban
				ban2 = *((int32_t*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int32_t) ));
				//printf("al doilea ban este %"PRId8"\n", ban2);

				litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int32_t) + sizeof(int32_t)));
				int dim2 = 0;
				while(litera != '\0') {
					litera = *((unsigned char*)((char *)(*arr) + contor + 5 + dim1 + sizeof(int32_t) + sizeof(int32_t) + dim2));
					dim2 ++;
				}
				char *nume2 = malloc(dim2 * sizeof(char));
				
				memcpy(nume2, (*arr) + contor + 5 + dim1 + sizeof(int32_t) + sizeof(int32_t), dim2);
				
				///afisarea propriu zisa
				printf("Tipul %hhu\n",tip);
				printf("%s pentru %s\n", nume1, nume2);
				printf("%"PRId32"\n", ban1);
				printf("%"PRId32"\n\n", ban2);
				free(nume1);
				free(nume2);
			}


			contor = sizeof(unsigned char) + sizeof(unsigned int) + contor;
			contor = contor + lung;


		}
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	if(index >= (*len)) {
		add_last(&(*arr), len, data);
		return 0;
	}
	unsigned int contor1 = 0;
	unsigned int lung = 0;
	for(int i = 0; i < index; i++) { ///parcurgem arr pana in pozitia la care vrem sa stergem datele
			lung = *((unsigned int*)((char *)(*arr) + contor1 + sizeof(unsigned char)));
			contor1 = sizeof(unsigned char) + sizeof(unsigned int) + contor1;
			contor1 = contor1 + lung;
	}
	void *aux = NULL;
	unsigned int contor2 = 0;
	unsigned int lung2 = 0;
	for(int i = 0; i < *len; i++) { ///parcurgem arr pana in pozitia la carse vrem sa stergem datele
			lung2 = *((unsigned int*)((char *)(*arr) + contor2 + sizeof(unsigned char)));
			contor2 = sizeof(unsigned char) + sizeof(unsigned int) + contor2;
			contor2 = contor2 + lung2;
	}
	aux = malloc(contor2 - contor1);
	memcpy(aux, (char *)(*arr) + contor1, contor2 - contor1);
	*arr = realloc(*arr, contor2 + 5 + data->header->len);
	memcpy((*arr) + contor1,(void *)&data->header->type, sizeof(unsigned char));
	memcpy((*arr) + sizeof(unsigned char) + contor1,(void *)&data->header->len, sizeof(unsigned int));
	memcpy((*arr) + sizeof(unsigned char) + sizeof(unsigned int) + contor1,data->data, data->header->len);
	memcpy((char *)(*arr) + contor1 + 5 + data->header->len, aux, contor2 - contor1);
	(*len)++;
	free(aux);
	return 0;
}

int delete_at(void **arr, int *len, int index)
{
	if(index >= *len)
		return 0;
	void *aux = NULL;
	unsigned int contor = 0;
	unsigned int lung = 0;
	for(int i = 0; i < index; i++) { ///parcurgem arr pana in pozitia la care vrem sa stergem datele
			lung = *((unsigned int*)((char *)(*arr) + contor + sizeof(unsigned char)));
			contor = sizeof(unsigned char) + sizeof(unsigned int) + contor;
			contor = contor + lung;
	}
	aux = malloc(sizeof(char) * contor); ///construim un pointer void in care vom pune cap la cap toate datele
	memcpy(aux, *arr, contor); ///copiem datele pana la index
	unsigned int lungime;
	lungime = *((unsigned int*)((char *)(*arr) + contor + sizeof(unsigned char)));
	int contor3 = contor + lungime + 5;
	unsigned int contor2 = 0;
	unsigned int lung2 = 0;
	for(int i = 0; i < *len; i++) {
			lung2 = *((unsigned int*)((char *)(*arr) + contor2 + sizeof(unsigned char)));
			contor2 = sizeof(unsigned char) + sizeof(unsigned int) + contor2;
			contor2 = contor2 + lung2; //parcurgem arr pana la final
	}
	aux = realloc(aux, contor2 - 5 - lungime);
	int diferenta = contor2 - contor3 ;
	memcpy((char *)aux + contor, (char *)*arr + contor3, diferenta); ///inseram restul de date, de dupa index
	
	*arr = realloc(*arr, contor2 -5 - lungime);
	memcpy((char *)(*arr), aux, contor2 -5 - lungime); ///copiem toate datele inapoi in arr
	
	(*len)--;
	free(aux);
	return 0;
}

void find(void *data_block, int len, int index) 
{
	if(index < 0 || index >= len)
		return;
	unsigned int contor = 0;
	unsigned int lung = 0;
	for(int i = 0; i < index; i++) {
			lung = *((unsigned int*)((char *)(data_block) + contor + sizeof(unsigned char)));
			contor = sizeof(unsigned char) + sizeof(unsigned int) + contor;
			contor = contor + lung; 
	}
	unsigned int lungime = 0;
	lungime = *((unsigned int*)((char *)data_block + contor + sizeof(unsigned char)));
	void *aux = NULL;
	aux = malloc(sizeof(char *) * lungime + 5);
	memcpy(aux, (char *)data_block + contor, lungime + 5);
	afisare(&aux, 1);
	free(aux);	
}


void citire(data_structure **corp) {
	int tip;
	(*corp) = NULL; 
	*corp = malloc(sizeof(data_structure)); /// aloc memorie pentru data_structure si pentru cele 2 nume
	(*corp)->header = malloc(sizeof(head));
	char* nume1 = malloc(255 * sizeof(char));
	char* nume2 = malloc(255 * sizeof(char));
	scanf("%d",&tip);
	(*corp)->header->type = tip;
	int contor = 0;
	if(tip == 1){
		int8_t ban1;
		int8_t ban2;
		scanf("%s",nume1);
		scanf("%" SCNd8, &ban1);
		scanf("%" SCNd8, &ban2); /// citesc cele 2 nume si cele 2 numere
		scanf("%s",nume2);
		//printf("%s %"PRId8" %"PRId8" %s\n",nume1, ban1, ban2, nume2); // le afisez
		(*corp)->header->len = strlen(nume1) + 1 + strlen(nume2) + 1 + 2; // aflu dimensiunea totala ale celor 2 numere + nume
		(*corp)->data = malloc((*corp)->header->len); /// aloc memorie pentru data, acolo unde se vor memora cele 2 numere si cele 2 nume


		memcpy((*corp)->data, nume1, strlen(nume1) + 1); ///copiez cele 2 numere in data, fiecare pe rand
		contor = contor + strlen(nume1) + 1;
		memcpy((char *)((*corp)->data)+ contor, &ban1, 1);
		contor++;
		memcpy((char *)((*corp)->data) + contor, &ban2, 1);
		contor++;
		memcpy((char *)((*corp)->data) + contor, nume2, strlen(nume2) + 1);
		contor = contor + strlen(nume2) + 1;
		free(nume1);
		free(nume2);

	}
	else if(tip == 2){
		int16_t ban1;
		int32_t ban2;
		scanf("%s",nume1);
		scanf("%" SCNd16, &ban1);
		scanf("%" SCNd32, &ban2);
		scanf("%s",nume2);
		//printf("%s %"PRId16" %"PRId32" %s\n",nume1, ban1, ban2, nume2);
		(*corp)->header->len = strlen(nume1) + 1 + strlen(nume2) + 1 + 6;
		(*corp)->data = malloc((*corp)->header->len);

		memcpy((*corp)->data, nume1, strlen(nume1) + 1); ///copiez cele 2 numere in data, fiecare pe rand
		contor = contor + strlen(nume1) + 1;
		memcpy((char *)((*corp)->data)+ contor, &ban1, sizeof(int16_t));
		contor = contor + sizeof(int16_t);
		memcpy((char *)((*corp)->data) + contor, &ban2, sizeof(int32_t));
		contor = contor + sizeof(int32_t);
		memcpy((char *)((*corp)->data) + contor, nume2, strlen(nume2) + 1);
		contor = contor + strlen(nume2) + 1;
		free(nume1);
		free(nume2);
	
	}
	else if(tip == 3){
		int32_t ban1;
		int32_t ban2;
		scanf("%s",nume1);
		scanf("%" SCNd32, &ban1);
		scanf("%" SCNd32, &ban2);
		scanf("%s",nume2);
		//printf("%s %"PRId32" %"PRId32" %s\n",nume1, ban1, ban2, nume2);
		(*corp)->header->len = strlen(nume1) + 1 + strlen(nume2) + 1 + 8;
		(*corp)->data = malloc((*corp)->header->len);

		memcpy((*corp)->data, nume1, strlen(nume1) + 1); ///copiez cele 2 numere in data, fiecare pe rand
		contor = contor + strlen(nume1) + 1;
		memcpy((char *)((*corp)->data)+ contor, &ban1, sizeof(int32_t));
		contor = contor + sizeof(int32_t);
		memcpy((char *)((*corp)->data) + contor, &ban2, sizeof(int32_t));
		contor = contor + sizeof(int32_t);
		memcpy((char *)((*corp)->data) + contor, nume2, strlen(nume2) + 1);
		contor = contor + strlen(nume2) + 1;
		free(nume1);
		free(nume2);
	}
}

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = NULL;
	int len = 0;
	data_structure* corp = NULL;

	char *comanda = malloc(255 * sizeof(char));
	while(1) {
		scanf("%s",comanda);
		if(strcmp(comanda,"exit") == 0)
			break;
		if(strcmp(comanda,"print") == 0)
			afisare(&arr, len);
		if(strcmp(comanda,"insert_at") == 0){
			int index = 0;
			scanf("%d", &index);
			citire(&corp);
			add_at(&arr, &len, corp, index);
			free(corp->data);
			free(corp->header);
			free(corp);
		}
		if(strcmp(comanda,"insert") == 0) {
			citire(&corp);
			add_last(&arr, &len, corp);
			free(corp->data);
			free(corp->header);
			free(corp);
		}
		if(strcmp(comanda,"delete_at") == 0) {
			int index = 0;
			scanf("%d", &index);
			delete_at(&arr, &len, index);
		}
		if(strcmp(comanda,"find") == 0) {
			int index = 0;
			scanf("%d", &index);
			find(arr, len, index);
		}
	}
	free(comanda);
	free(arr);
	return 0;
}
