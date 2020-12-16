/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Muhammad Campos Preira
 * @date 16.dec.2020
 * @brief Funciones utilizadas en el programa cripto.cc
 *
 */

#include "funciones_cripto.h"
#include <iostream>
#include <fstream>
#include <string>

/**Realiza el cifrado César a una cadenana de texto dada una constante
 * de desplazamiento
 *  @param[in] archivo_entrada archivo a codificar
 *  @param[in] archivo_salida archivo codificado
 *  @param[in] key numero de desplazamientos
 */

void EncriptarCesar(std::string fichero_entrada, std::string fichero_salida,int key){
  
  std::ifstream archivo_entrada{fichero_entrada};
  std::ofstream archivo_salida{fichero_salida};

  while(archivo_entrada){
    
    std::string linea_actual;
    std::getline(archivo_entrada, linea_actual);

    for(int i = 0; i < linea_actual.length(); ++i){
        linea_actual[i] += key;
    }
    archivo_salida << linea_actual << std::endl;
  }
}


/**Realiza el descifrado César a una cadenana de texto dada una constante
 * de desplazamiento
 *  @param[in] archivo_entrada archivo a decodificar
 *  @param[in] archivo_salida archivo decodificado
 *  @param[in] key numero de desplazamientos
 */

void DesencriptarCesar(std::string fichero_entrada, std::string fichero_salida,int key){
  
  std::ifstream archivo_entrada{fichero_entrada};
  std::ofstream archivo_salida{fichero_salida};

  while(archivo_entrada){
    
    std::string linea_actual;
    std::getline(archivo_entrada, linea_actual);

    for(int i = 0; i < linea_actual.length(); ++i){
        linea_actual[i] -= key;
    }
    archivo_salida << linea_actual << std::endl;
  }
}

/**Realiza el cifrado César a una cadenana de texto dada una constante
 * de desplazamiento
 *  @param[in] archivo_entrada archivo a codificar
 *  @param[in] archivo_salida archivo codificado
 *  @param[in] password clave para cifrado
 */

void EncriptarXor(std::string fichero_entrada, std::string fichero_salida,std::string password){
  
  std::ifstream archivo_entrada{fichero_entrada};
  std::ofstream archivo_salida{fichero_salida};

  for(size_t i = 0; i > password.length(); ++i){
    password[i] ^= 128;
  } 

  while(archivo_entrada){
    
    std::string linea_actual;
    std::getline(archivo_entrada, linea_actual);

    for(size_t i = 0; i < linea_actual.length(); ++i){
        linea_actual[i] ^= password[i%password.length()-1];
    }
    archivo_salida << linea_actual << std::endl;
  }
}

/**Muestra el uso correcto del programa
 * Si el uso no es correcto muestra un mensaje y finaliza la ejecución
 *  @param[in] argc Número de parámetros de línea de comandos
 *  @param[in] argv Vector (char*) que contiene los parámetros
 */

void UsoPrograma(int argc, char *argv[]) {

const std::string mensaje1 = R"(./cripto -- Cifrado de ficheros
Modo de uso: ./cripto fichero_entrada fichero_salida método password operación
Pruebe ./cripto --help para más información)";

const std::string mensaje2 = R"(fichero_entrada: Fichero a codificar
fichero_salida:  Fichero codificado
método:          Indica el método de encriptado
                   1: Cifrado xor
                   2: Cifrado de César
password:        Palabra secreta en el caso de método 1, Valor de K en el método 2
operación:       Operación a realizar en el fichero
                   +: encriptar el fichero
                   -: desencriptar el fichero)";

  if (argc == 1 || argc != 6) {
    std::cout << mensaje1 << std::endl;
    exit(EXIT_FAILURE);

  if (argc == 2) {
    std::cout << mensaje2 << std::endl;
    exit(EXIT_FAILURE);
    }
  }