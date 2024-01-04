#include <Arduino.h>

#define A 13
#define B 12
#define C 11
#define D 10
#define E 9
#define F 8
#define G 7
//#define DP 6

int valor = 0;

// Criando a tabela de conversão, usou const para salvar na memória flash
const byte tabela_7seg[10][7] = 
{
  //A B C D E F G
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9
};

void converteValorDisplay(byte valor);

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  //pinMode(DP, OUTPUT);
}

void loop() {
  converteValorDisplay(valor++);
  delay(1000);
  if (valor > 9)
  {
    valor = 0;
  }
  
}

void converteValorDisplay(byte valor){
  byte pino = 13;

  for (byte i = 0; i < 7; i++)
  {
    digitalWrite(pino, tabela_7seg[valor][i]);
    pino--;
  }
  
}
