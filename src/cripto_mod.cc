/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file cripto.cc
 * @author MuhammadCampos Preira
 * @date 16.dec.2020
 * @brief Encripta o desencripta un archivo usando el método XOR o César,
 * guardando la salida en otro archivo.
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include "funciones_cripto.h"


void EncriptarCesar(std::string fichero_entrada, std::string fichero_salida, int key);
void DesencriptarCesar(std::string fichero_entrada, std::string fichero_salida, int key);
void EncriptarXor(std::string fichero_entrada, std::string fichero_salida, int key);
void UsoPrograma(int argc, char *argv[]);
void ContadorA(std::string fichero_entrada);


/** Función principal
 *  @param[in] argc Número de parámetros de línea de comandos
 *  @param[in] argv Vector que contiene los parámetros de la linea de comandos
 */

int main(int argc, char* argv[]){

  std::string fichero_entrada{argv[1]};
  std::string fichero_salida{argv[2]};
  std::string password = argv[4];
  int metodo{argv[3][0]};
  int key = 0;
  char operacion{argv[5][0]};

  if (metodo == '2') 
    key = std::stoi(password);

  if (metodo == '2') {
    if (operacion == '+') {
      EncriptarCesar(fichero_entrada, fichero_salida, key);
    } else if (operacion == '-') {
      DesencriptarCesar(fichero_entrada, fichero_salida, key);
    }
  }

  if (metodo == '1') {
    if (operacion == '+' || operacion == '-') {
      EncriptarXor(fichero_entrada, fichero_salida, password);
    }
  }

  ContadorA(fichero_entrada);


  return 0;
}
