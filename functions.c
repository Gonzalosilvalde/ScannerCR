#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <omp.h>
#include "functions.h"



void concatenateArray(char *final, char *strings[], int n) {
    for (int i = 0; i < n; i++) {
        strcat(final, strings[i]);
    }
}

char * getType(int value) {
    char * type;
    switch (value) {
        case 0: type = "i32 "; break;
        case 1: type = "i16 "; break;
        case 2: type = "i64 "; break;
        case 3: type = "u32 "; break;
        case 4: type = "u16 "; break;
        case 5: type = "u64 "; break;
        case 6: type = "f32 "; break;
        case 7: type = "f64 "; break;
        case 8: type = "String "; break;
        case 9: type = "char "; break;
        case 10: type = "bool "; break;
        case 11: type = "struct" ; break;
        default: type = ""; break;
    }
    return type;
}

void typeSwitch(char*final, int type){
    
    strcat(final, "-> ");
    strcat(final, getType(type));
    strcat(final, " {");

}

char* getEndNumber(char* number) {
	int len = strlen(number);
	char* numero = (char*) malloc(len + 1);
    	if (numero == NULL) return NULL;

    		int j = 0;
    		for (int i = len - 1; i >= 0; i--) {
        		if (!isdigit(number[i])) {
          	  		break;
        		} else {
        	    		numero[j++] = number[i];
        		}
    		}
    		numero[j] = '\0';

    		for (int k = 0; k < j / 2; k++) {
        		char temp = numero[k];
        		numero[k] = numero[j - k - 1];
        		numero[j - k - 1] = temp;
    		}

    	return numero;
}

void deleteQuotes(char * stringq) {
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '\'') || (stringq[reader] == '\"')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

char *replace(const char *string, const char *search, const char *replacement) {
    if (string == NULL || search == NULL || replacement == NULL) {
        return NULL;
    }

    int longitudBusqueda = strlen(search);
    int longitudReemplazo = strlen(replacement);
    const char *posicion;
    const char *inicio = string;
    int nuevaLongitud = 0;

    while ((posicion = strstr(inicio, search)) != NULL) {
        nuevaLongitud += posicion - inicio + longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }
    nuevaLongitud += strlen(inicio);

    char *nuevoString = (char *)malloc(nuevaLongitud + 1);
    if (nuevoString == NULL) {
        free(nuevoString);
        return NULL;
    }
    
    nuevoString[0] = '\0';

    char *destino = nuevoString;
    inicio = string;

    while ((posicion = strstr(inicio, search)) != NULL) {
        int longitudSegmento = posicion - inicio;
        strncpy(destino, inicio, longitudSegmento);
        destino += longitudSegmento;
        strcpy(destino, replacement);
        destino += longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }

    strcpy(destino, inicio);

    return nuevoString;
}

void replaceSemicolon(char *string) {
    if (string == NULL) {
        return;
    }

    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == ';' && string[i + 1] == '\n') {
            string[i] = ',';
        }
    }
}

int isNumber(char * stringq) {
        for (int i = 0; stringq[i]!='\0';i++){
                if(isdigit(stringq[i]) == 0){
                        return 0;
                }
        }
        return 1;
}

int searchString(char **arr, char *toFind, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], toFind) == 0) {
            return 1;
        }
    }
    return 0;
}

char *insertTabsBetweenBraces( char *input) {
    if (input == NULL) {
        return NULL;
    }

    int input_length = strlen(input);
    int countCurly = 0;
    int count = 0;

    int max_output_length = input_length * 2;
    char *output = (char *)malloc((max_output_length + 1) * sizeof(char));

    if (output == NULL) {
        return NULL;
    }

    for (int i = 0; i < input_length; i++) {
        if (input[i] == '{') {
            countCurly++;
        } else if (input[i] == '}') {
            countCurly--;
        }

        if (input[i] != '\\' && input[i] != '\n') {
            output[count++] = input[i];

        }  else if (input[i] == '\n' && input[i + 1] == '}') {
            output[count++] = input[i];
            for (int j = 0; j < countCurly-1; j++) {
                output[count++] = '\t';
            }
        } else if (input[i] == '\n') {
            output[count++] = input[i];
            for (int j = 0; j < countCurly; j++) {
                output[count++] = '\t';
            }
        } else {
            output[count++] = input[i];
            output[count++] = input[i + 1];
            i++;
        }
    }

    output[count] = '\0';

    return output;
}

char* getStringFromExp(char* str) {
    int len = strlen(str);
    char* subString = NULL;
    char* delimitadores[4] = {"<", ">", ">=", "<="};
    int i, j, k, pos;
    for (i = 0; i < 4; i++) {
        char* ptr = strstr(str, delimitadores[i]);
        if (ptr != NULL) {
            pos = ptr - str + strlen(delimitadores[i]);
            subString = (char*)malloc(len - pos + 1);
            if (subString == NULL) {
                printf("Error allocating memory\n");
                exit(1);
            }
            for (j = pos, k = 0; j < len; j++, k++) {
                subString[k] = str[j];
            }
            subString[k] = '\0';
            break;
        }
    }
    return subString;
}

void ifCreation(char* final, char* in, char* out){
    
    char* parts[] = {"if (", in, "){\n", out, "\n}"};
    int n = sizeof(parts)/sizeof(parts[0]);
    concatenateArray(final, parts, n);
}

void funCreation(char* final, char* name, char* in){
    char* parts[] = {name, "(", in, ")"};
    int n = sizeof(parts)/sizeof(parts[0]);
    concatenateArray(final, parts, n);

}




char * transformDollarVarsInsideParentheses(const char *str) {
    int paren_level = 0;
    size_t result_capacity = 128;
    size_t result_length = 0;
    char *result = malloc(result_capacity);
    if (!result) {
        fprintf(stderr, "Error al asignar memoria para el resultado.\n");
        return "";
    }
    result[0] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            paren_level++;
        } else if (str[i] == ')') {
            if (paren_level > 0)
                paren_level--;
        } else if (str[i] == '$' && paren_level > 0) {
            int start = i;
            i++;
            while (str[i] != '\0' && (isalnum((unsigned char)str[i]) || str[i] == '_')) {
                i++;
            }
            int var_len = i - start;
            int line_len = 2 * var_len + 13;
            while (result_length + line_len >= result_capacity) {
                result_capacity *= 2;
                char *temp = realloc(result, result_capacity);
                if (!temp) {
                    fprintf(stderr, "Error al realocar memoria.\n");
                    free(result);
                    return "";
                }
                result = temp;
            }
            int written = snprintf(result + result_length, result_capacity - result_length,
                                   "let %.*s_val = %.*s;\n", var_len - 1, str + start + 1,
                                   var_len, str + start);
            if (written < 0) {
                fprintf(stderr, "Error en snprintf.\n");
                free(result);
                return "";
            }
            result_length += written;
            i--;
        }
    }
    return result;
}

char *trim(char *str) {
    while (isspace((unsigned char)*str)) str++;
    if (*str == '\0')
        return str;
    
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;
    *(end + 1) = '\0';
    return str;
}

char * transformVariadic(const char * str){
    
    char *input = strdup(str);
    if (!input) return NULL;

    char *resultado = malloc(strlen(str) + 1);
    if (!resultado) {
        free(input);
        return NULL;
    }
    resultado[0] = '\0';

    char *token = strtok(input, ",");
    int primerToken = 1;
    while (token != NULL) {
        char *t = trim(token);

        char *dosPuntos = strchr(t, ':');
        if (dosPuntos) {
            *dosPuntos = '\0';
        }
        t = trim(t);

        if (strcmp(t, "$__VA_ARGS__") == 0) {
            t = "$($args)*";
        }

        if (!primerToken) {
            strcat(resultado, ", ");
        }
        primerToken = 0;
        strcat(resultado, t);

        token = strtok(NULL, ",");
    }

    free(input);
    return resultado;}


char *wrapInParentheses(const char *str) {
    size_t len = strlen(str);
    char *result = malloc(len + 3);
    if (result == NULL) {
        return NULL;
    }
    
    result[0] = '(';
    strcpy(result + 1, str);
    result[len + 1] = ')';
    result[len + 2] = '\0';
    
    return result;
}

void toLowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char) str[i]); 
    }
}

char * transformStringOutput(const char *input) {
    size_t len = strlen(input);
    char *result = malloc(len * 2 + 100);
    if(result == NULL) {
        return NULL;
    }
    result[0] = '\0';

    char *copy = strdup(input);
    if(copy == NULL) {
        free(result);
        return NULL;
    }
    
    char *token = strtok(copy, " ");
    int count = 0;
    
    while(token != NULL) {
        count++;
        if(count % 2 == 1) {
            strcat(result, token);
        } else {
            strcat(result, " = lateout(reg) ");
            strcat(result, token);
            strcat(result, ",\n");
        }
        token = strtok(NULL, " ");
    }
    
    free(copy);
    return result;
}

char * transformStringInput(const char *input) {
    size_t len = strlen(input);
    char *result = malloc(len * 2 + 100);
    if(result == NULL) {
        return NULL;
    }
    result[0] = '\0';

    char *copy = strdup(input);
    if(copy == NULL) {
        free(result);
        return NULL;
    }
    
    char *token = strtok(copy, " ");
    int count = 0;
    
    while(token != NULL) {
        count++;
        if(count % 2 == 1) {
            strcat(result, token);
        } else {
            strcat(result, " = inout(reg) ");
            strcat(result, token);
            strcat(result, ",\n");
        }
        token = strtok(NULL, " ");
    }
    
    free(copy);
    return result;
}


