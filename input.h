#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int getInteger(int* integer, char* message, char* messageMistake, int min, int max);
int getString(char* chain, char* message, char* messageMistake, int max);
int getCharacter(char* character, char* message);
int getFloat(float* number, char* message, char* messageMistake, float min, float max);

#endif // INPUT_H_INCLUDED
